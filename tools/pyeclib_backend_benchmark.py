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



# Parse input arguments

parser = argparse.ArgumentParser(
    description='Benchmark tool to compare the encode and decode performande of ISA-L and Chocolate Cloud backends')
parser.add_argument(
    '-k',
    type=int,
    help='Number of data fragments',
    required=True)
parser.add_argument(
    '-m', 
    type=int, 
    help='Number of parity fragments', 
    required=True)
parser.add_argument(
    '-s', 
    type=float, 
    help='Data size (MB)', 
    required=True)
parser.add_argument(
    '-num', 
    type=int, 
    help='Number of measurements', 
    required=False,
    default=1000)


args = parser.parse_args(sys.argv[1:])

num_iterations = args.num


schemes = []

schemes.append(ECScheme(args.k, args.m, "isa_l_rs_vand", "ISA-L"))
schemes.append(ECScheme(args.k, args.m, "chocolate_cloud_rs", "Chocolate Cloud RS"))
#schemes.append(ECScheme(args.k, args.m, "chocolate_cloud_systematic_rlnc", "Chocolate Cloud Systematic RLNC"))
#schemes.append(ECScheme(args.k, args.m, "chocolate_cloud_full_rlnc", "Chocolate Cloud Full RLNC"))



#MB = 1024*1024
MB = 1E6
data_size_bytes = (int)(args.s * MB)
    


# Instantiate the timers
encode_timer = timer()
decode_timer = timer()

# Generate a new string 
file_str = ''.join(random.choice(string.ascii_uppercase + string.digits) for x in range(data_size_bytes))
print("Input data ready")

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