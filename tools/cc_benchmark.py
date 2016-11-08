from pyeclib.ec_iface import ECDriver

import random
import string
import sys
import argparse
import time
import math



class timer:

    def __init__(self):
        self.start_time = 0
        self.end_time = 0

    def reset(self):
        self.start_time = 0
        self.end_time = 0

    def start(self):
        self.start_time = time.time()

    def stop(self):
        self.end_time = time.time()

    def curr_delta(self):
        return self.end_time - self.start_time

    def stop_and_return(self):
        self.end_time = time.time()
        return self.curr_delta()


class ECScheme:

    def __init__(self, k, m, ec_type, ec_name):
        self.k = k
        self.m = m
        self.ec_type = ec_type
        self.ec_name = ec_name

    def __str__(self):
        return "%s %d+%d" % (self.ec_name, self.k, self.m,)

class CodingScheme:
    
    def __init__(self, k, m):
        self.k = k
        self.m = m

    def __str__(self):
        return "%d+%d" % (self.k, self.m)


class Backend:
    
    def __init__(self, id, name):
        self.id = id
        self.name = name

    def __str__(self):
        return "%s" % (self.name)

def get_throughput_mbps(symbol_size_bytes, symbols_num, time_s):
    return ((symbol_size_bytes*symbols_num)/float(1E6)) / float(time_s)


parser = argparse.ArgumentParser(
    description='Benchmark tool to compare encode and decode performande of ISA-L and Chocolate Cloud backends on predefined coding configurations')
parser.add_argument(
    '-iter', 
    type=int, 
    help='Number of measurements', 
    required=False,
    default=10)


args = parser.parse_args(sys.argv[1:])

num_iterations = args.iter


schemes = [ 
    CodingScheme(4,2),
    CodingScheme(4,4),
    
    CodingScheme(5,1),
    CodingScheme(5,2),
    
    CodingScheme(6,2),
    CodingScheme(6,3),
    
    CodingScheme(8,3),
    CodingScheme(8,4),

    CodingScheme(9,3),
    CodingScheme(9,4),

    CodingScheme(10,4),
    CodingScheme(10,5),

    CodingScheme(12,3),
    CodingScheme(12,5),

    CodingScheme(20,3),
    CodingScheme(20,5),

    CodingScheme(20,10)
]


kB = 1024
MB = 1000*kB

symbol_size_bytes = [ 
    1*kB, 32*kB, 64*kB, 128*kB,
    1*MB, 2*MB, 5*MB, 10*MB #, 32*MB
]


backends = [
    Backend("isa_l_rs_vand", "ISA-L"),
    Backend("chocolate_cloud_rs", "Chocolate Cloud RS")
]



# Instantiate the timers
encode_timer = timer()
decode_timer = timer()

current_encode_throughputs = []
current_decode_throughputs = []


csv_file = open('./pyeclib_benchmark_set_high_schemes.csv','w+')
csv_file.write('Symbol size,K,M,Backend,PyECLib AVG Encode speed,PyECLib AVG Decode speed\n') # python will convert \n to os.linesep


# Generate a new string 
#file_str = ''.join(random.choice(string.ascii_uppercase + string.digits) for x in range(data_size_bytes))
#print("Input data ready")

for scheme in schemes:

    print("\nStarting new scheme: %s\n" % scheme)

    for symbol_size in symbol_size_bytes:

        #print("Symbol size: %d kB\n" % (symbol_size/kB))
        symbol_size_string = ""
        if(symbol_size > MB) :
            symbol_size_string += str(symbol_size/MB)
            symbol_size_string += "MB"
        else : 
            symbol_size_string += str(symbol_size/kB)
            symbol_size_string += "kB"
        
        data_size_bytes = symbol_size * scheme.k
        try:
            file_str = ''.join(random.choice(string.ascii_uppercase + string.digits) for x in range(data_size_bytes))
        except Exception as e:
            printf("Failed to allocate input data of %d MB" % (int(data_size_bytes/MB)))
            continue

        for backend in backends:

            try:
                ec_driver = ECDriver(k=scheme.k, m=scheme.m, ec_type=backend.id)
            except Exception as e:
                print("Failed to create EC driver for %s backend and %s coding" % (backend.name, scheme))
                continue

            sys.stdout.write('Starting ' + symbol_size_string + ' ' + str(scheme) + ' with ' + str(backend.name) + ': ')

            for i in range(num_iterations):

                if(i>0 and i % (num_iterations/10) == 0 ):
                    sys.stdout.write(str((i/10)) + '% ')
                    sys.stdout.flush()

                

                encode_duration = 0.0
                encode_timer.start()
                fragments = ec_driver.encode(file_str)
                encode_duration = encode_timer.stop_and_return()

                current_encode_throughputs.append(get_throughput_mbps(symbol_size, scheme.k, encode_duration))

                # Delete random scheme.k packets
                index_to_delete = []
                for j in range(scheme.m):
                    index = random.randint(0, len(fragments)-1)
                    fragments.pop(index)

                decode_duration = 0.0
                decode_timer.start()
                ec_driver.decode(fragments)
                decode_duration = decode_timer.stop_and_return()                

                current_decode_throughputs.append(get_throughput_mbps(symbol_size, scheme.k, decode_duration))

            encode_avg_speed = sum(current_encode_throughputs) / float(num_iterations)
            decode_avg_speed = sum(current_decode_throughputs) / float(num_iterations)

            

            print("Ready, encode: %.2lf MB/s, decode: %.2lf MB/s" % (encode_avg_speed, decode_avg_speed))
            csv_file.write(symbol_size_string + "," + str(scheme.k) + "," + str(scheme.m) + "," + backend.name + "," + str(encode_avg_speed) + "," + str(decode_avg_speed) + "\n")


            # Clear the arrays
            del current_encode_throughputs[:]
            del current_decode_throughputs[:]

        print(" ");
        csv_file.flush()


print("Ready")

csv_file.close() # you can omit in most cases as the destructor will call it





"""

for scheme in schemes:
    
    print("\nStarting benchmark of %s" % scheme)

    try:
        ec_driver = ECDriver(k=scheme.k, m=scheme.m, ec_type=scheme.ec_type)
    except Exception as e:
        print("Scheme %s is not defined (%s)." % (scheme, e))
        continue


    print("Backend instantiated")

    

    
    
    encode_duration = 0.0
    encode_timer.start()
    for i in range(args.num):
        ec_driver.encode(file_str)
        #print("Iteration %d ready" % i)
    encode_duration = encode_timer.stop_and_return()

    avg_encode_duration_s = encode_duration /float(num_iterations)
    #avg_encode_duration_ns = avg_encode_duration_s * 1E9
    avg_encode_throughput_MBps = args.s /float(avg_encode_duration_s);

    print("%s Average encode speed with %.2lf MB file: %.2lf MB/s" % (scheme, args.s, avg_encode_throughput_MBps))

"""    