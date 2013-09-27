#ifndef _XOR_HD_CODE_DEFS_H
#define _XOR_HD_CODE_DEFS_H



// I made these by hand...
int g_12_6_4_hd_code_parity_bms[] = { 1649, 3235, 2375, 718, 1436, 2872 };
int g_12_6_4_hd_code_data_bms[] = { 7, 14, 28, 56, 49, 35, 13, 26, 52, 41, 19, 38 };
int g_10_5_3_hd_code_parity_bms[] = { 1425, 1571, 3270, 2348, 2648 };
int g_10_5_3_hd_code_data_bms[] = { 3, 6, 12, 24, 17, 10, 20, 5, 9, 18, 7, 28 };

// The rest were generated via the "goldilocks" code algorithm
int g_6_6_3_hd_code_parity_bms[] = { 3, 48, 36, 24, 9, 6 };
int g_6_6_3_hd_code_data_bms[] = { 17, 33, 36, 24, 10, 6 };
int g_7_6_3_hd_code_parity_bms[] = { 67, 112, 36, 24, 9, 6 };
int g_7_6_3_hd_code_data_bms[] = { 17, 33, 36, 24, 10, 6, 3 };
int g_8_6_3_hd_code_parity_bms[] = { 67, 112, 164, 152, 9, 6 };
int g_8_6_3_hd_code_data_bms[] = { 17, 33, 36, 24, 10, 6, 3, 12 };
int g_9_6_3_hd_code_parity_bms[] = { 67, 112, 164, 152, 265, 262 };
int g_9_6_3_hd_code_data_bms[] = { 17, 33, 36, 24, 10, 6, 3, 12, 48 };
int g_10_6_3_hd_code_parity_bms[] = { 579, 112, 676, 152, 265, 262 };
int g_10_6_3_hd_code_data_bms[] = { 17, 33, 36, 24, 10, 6, 3, 12, 48, 5 };
int g_11_6_3_hd_code_parity_bms[] = { 579, 1136, 676, 152, 1289, 262 };
int g_11_6_3_hd_code_data_bms[] = { 17, 33, 36, 24, 10, 6, 3, 12, 48, 5, 18 };
int g_12_6_3_hd_code_parity_bms[] = { 579, 1136, 676, 2200, 1289, 2310 };
int g_12_6_3_hd_code_data_bms[] = { 17, 33, 36, 24, 10, 6, 3, 12, 48, 5, 18, 40 };
int g_13_6_3_hd_code_parity_bms[] = { 4675, 1136, 676, 6296, 1289, 2310 };
int g_13_6_3_hd_code_data_bms[] = { 17, 33, 36, 24, 10, 6, 3, 12, 48, 5, 18, 40, 9 };
int g_14_6_3_hd_code_parity_bms[] = { 4675, 9328, 676, 6296, 1289, 10502 };
int g_14_6_3_hd_code_data_bms[] = { 17, 33, 36, 24, 10, 6, 3, 12, 48, 5, 18, 40, 9, 34 };
int g_15_6_3_hd_code_parity_bms[] = { 4675, 9328, 17060, 6296, 17673, 10502 };
int g_15_6_3_hd_code_data_bms[] = { 17, 33, 36, 24, 10, 6, 3, 12, 48, 5, 18, 40, 9, 34, 20 };

int g_6_6_4_hd_code_parity_bms[] = { 7, 56, 56, 11, 21, 38 };
int g_6_6_4_hd_code_data_bms[] = { 25, 41, 49, 14, 22, 38 };
int g_7_6_4_hd_code_parity_bms[] = { 71, 120, 120, 11, 21, 38 };
int g_7_6_4_hd_code_data_bms[] = { 25, 41, 49, 14, 22, 38, 7 };
int g_8_6_4_hd_code_parity_bms[] = { 71, 120, 120, 139, 149, 166 };
int g_8_6_4_hd_code_data_bms[] = { 25, 41, 49, 14, 22, 38, 7, 56 };
int g_9_6_4_hd_code_parity_bms[] = { 327, 376, 120, 395, 149, 166 };
int g_9_6_4_hd_code_data_bms[] = { 25, 41, 49, 14, 22, 38, 7, 56, 11 };
int g_10_6_4_hd_code_parity_bms[] = { 327, 376, 632, 395, 661, 678 };
int g_10_6_4_hd_code_data_bms[] = { 25, 41, 49, 14, 22, 38, 7, 56, 11, 52 };
int g_11_6_4_hd_code_parity_bms[] = { 1351, 1400, 632, 395, 1685, 678 };
int g_11_6_4_hd_code_data_bms[] = { 25, 41, 49, 14, 22, 38, 7, 56, 11, 52, 19 };
int g_13_6_4_hd_code_parity_bms[] = { 5447, 5496, 2680, 2443, 1685, 6822 };
int g_13_6_4_hd_code_data_bms[] = { 25, 41, 49, 14, 22, 38, 7, 56, 11, 52, 19, 44, 35 };
int g_14_6_4_hd_code_parity_bms[] = { 5447, 5496, 10872, 10635, 9877, 6822 };
int g_14_6_4_hd_code_data_bms[] = { 25, 41, 49, 14, 22, 38, 7, 56, 11, 52, 19, 44, 35, 28 };
int g_15_6_4_hd_code_parity_bms[] = { 21831, 5496, 27256, 27019, 9877, 6822 };
int g_15_6_4_hd_code_data_bms[] = { 25, 41, 49, 14, 22, 38, 7, 56, 11, 52, 19, 44, 35, 28, 13 };
int g_16_6_4_hd_code_parity_bms[] = { 21831, 38264, 27256, 27019, 42645, 39590 };
int g_16_6_4_hd_code_data_bms[] = { 25, 41, 49, 14, 22, 38, 7, 56, 11, 52, 19, 44, 35, 28, 13, 50 };
int g_17_6_4_hd_code_parity_bms[] = { 87367, 38264, 92792, 27019, 108181, 39590 };
int g_17_6_4_hd_code_data_bms[] = { 25, 41, 49, 14, 22, 38, 7, 56, 11, 52, 19, 44, 35, 28, 13, 50, 21 };
int g_18_6_4_hd_code_parity_bms[] = { 87367, 169336, 92792, 158091, 108181, 170662 };
int g_18_6_4_hd_code_data_bms[] = { 25, 41, 49, 14, 22, 38, 7, 56, 11, 52, 19, 44, 35, 28, 13, 50, 21, 42 };
int g_19_6_4_hd_code_parity_bms[] = { 349511, 169336, 354936, 158091, 108181, 432806 };
int g_19_6_4_hd_code_data_bms[] = { 25, 41, 49, 14, 22, 38, 7, 56, 11, 52, 19, 44, 35, 28, 13, 50, 21, 42, 37 };
int g_20_6_4_hd_code_parity_bms[] = { 349511, 693624, 354936, 682379, 632469, 432806 };
int g_20_6_4_hd_code_data_bms[] = { 25, 41, 49, 14, 22, 38, 7, 56, 11, 52, 19, 44, 35, 28, 13, 50, 21, 42, 37, 26 };


int g_5_5_3_hd_code_parity_bms[] = { 3, 12, 17, 6, 24 };
int g_5_5_3_hd_code_data_bms[] = { 5, 9, 10, 18, 20 };
int g_6_5_3_hd_code_parity_bms[] = { 35, 44, 17, 6, 24 };
int g_6_5_3_hd_code_data_bms[] = { 5, 9, 10, 18, 20, 3 };
int g_7_5_3_hd_code_parity_bms[] = { 35, 44, 81, 70, 24 };
int g_7_5_3_hd_code_data_bms[] = { 5, 9, 10, 18, 20, 3, 12 };
int g_8_5_3_hd_code_parity_bms[] = { 163, 44, 81, 70, 152 };
int g_8_5_3_hd_code_data_bms[] = { 5, 9, 10, 18, 20, 3, 12, 17 };
int g_9_5_3_hd_code_parity_bms[] = { 163, 300, 337, 70, 152 };
int g_9_5_3_hd_code_data_bms[] = { 5, 9, 10, 18, 20, 3, 12, 17, 6 };

int g_5_5_4_hd_code_parity_bms[] = { 7, 25, 14, 19, 28 };
int g_5_5_4_hd_code_data_bms[] = { 11, 13, 21, 22, 26 };
int g_6_5_4_hd_code_parity_bms[] = { 39, 57, 46, 19, 28 };
int g_6_5_4_hd_code_data_bms[] = { 11, 13, 21, 22, 26, 7 };
int g_7_5_4_hd_code_parity_bms[] = { 103, 57, 46, 83, 92 };
int g_7_5_4_hd_code_data_bms[] = { 11, 13, 21, 22, 26, 7, 25 };
int g_8_5_4_hd_code_parity_bms[] = { 103, 185, 174, 211, 92 };
int g_8_5_4_hd_code_data_bms[] = { 11, 13, 21, 22, 26, 7, 25, 14 };
int g_9_5_4_hd_code_parity_bms[] = { 359, 441, 174, 211, 348 };
int g_9_5_4_hd_code_data_bms[] = { 11, 13, 21, 22, 26, 7, 25, 14, 19 };
int g_10_5_4_hd_code_parity_bms[] = { 359, 441, 686, 723, 860 };
int g_10_5_4_hd_code_data_bms[] = { 11, 13, 21, 22, 26, 7, 25, 14, 19, 28 };

// Indexed by k
int * hd4_m5_parity[11] = { 0, 0, 0, 0, 0, g_5_5_4_hd_code_parity_bms, g_6_5_4_hd_code_parity_bms, g_7_5_4_hd_code_parity_bms, g_8_5_4_hd_code_parity_bms, g_9_5_4_hd_code_parity_bms, g_10_5_4_hd_code_parity_bms };
int * hd4_m5_data[11] = { 0, 0, 0, 0, 0, g_5_5_4_hd_code_data_bms, g_6_5_4_hd_code_data_bms, g_7_5_4_hd_code_data_bms, g_8_5_4_hd_code_data_bms, g_9_5_4_hd_code_data_bms, g_10_5_4_hd_code_data_bms };
int * hd4_m6_parity[21] = { 0, 0, 0, 0, 0, 0, g_6_6_4_hd_code_parity_bms, g_7_6_4_hd_code_parity_bms, g_8_6_4_hd_code_parity_bms, g_9_6_4_hd_code_parity_bms, g_10_6_4_hd_code_parity_bms, g_11_6_4_hd_code_parity_bms, g_12_6_4_hd_code_parity_bms, g_13_6_4_hd_code_parity_bms, g_14_6_4_hd_code_parity_bms, g_15_6_4_hd_code_parity_bms, g_16_6_4_hd_code_parity_bms, g_17_6_4_hd_code_parity_bms, g_18_6_4_hd_code_parity_bms, g_19_6_4_hd_code_parity_bms, g_20_6_4_hd_code_parity_bms };

int * hd4_m6_data[21] = { 0, 0, 0, 0, 0, 0, g_6_6_4_hd_code_data_bms, g_7_6_4_hd_code_data_bms, g_8_6_4_hd_code_data_bms, g_9_6_4_hd_code_data_bms, g_10_6_4_hd_code_data_bms, g_11_6_4_hd_code_data_bms, g_12_6_4_hd_code_data_bms, g_13_6_4_hd_code_data_bms, g_14_6_4_hd_code_data_bms, g_15_6_4_hd_code_data_bms, g_16_6_4_hd_code_data_bms, g_17_6_4_hd_code_data_bms, g_18_6_4_hd_code_data_bms, g_19_6_4_hd_code_data_bms, g_20_6_4_hd_code_data_bms };

int * hd3_m5_parity[11] = { 0, 0, 0, 0, 0, g_5_5_3_hd_code_parity_bms, g_6_5_3_hd_code_parity_bms, g_7_5_3_hd_code_parity_bms, g_8_5_3_hd_code_parity_bms, g_9_5_3_hd_code_parity_bms, g_10_5_3_hd_code_parity_bms };
int * hd3_m5_data[11] = { 0, 0, 0, 0, 0, g_5_5_3_hd_code_data_bms, g_6_5_3_hd_code_data_bms, g_7_5_3_hd_code_data_bms, g_8_5_3_hd_code_data_bms, g_9_5_3_hd_code_data_bms, g_10_5_3_hd_code_data_bms };
int * hd3_m6_parity[16] = { 0, 0, 0, 0, 0, 0, g_6_6_3_hd_code_parity_bms, g_7_6_3_hd_code_parity_bms, g_8_6_3_hd_code_parity_bms, g_9_6_3_hd_code_parity_bms, g_10_6_3_hd_code_parity_bms, g_11_6_3_hd_code_parity_bms, g_12_6_3_hd_code_parity_bms, g_13_6_3_hd_code_parity_bms, g_14_6_3_hd_code_parity_bms, g_15_6_3_hd_code_parity_bms };
int * hd3_m6_data[16] = { 0, 0, 0, 0, 0, 0, g_6_6_3_hd_code_data_bms, g_7_6_3_hd_code_data_bms, g_8_6_3_hd_code_data_bms, g_9_6_3_hd_code_data_bms, g_10_6_3_hd_code_data_bms, g_11_6_3_hd_code_data_bms, g_12_6_3_hd_code_data_bms, g_13_6_3_hd_code_data_bms, g_14_6_3_hd_code_data_bms, g_15_6_3_hd_code_data_bms };

int ** parity_bm_hd4 [7] = { 0, 0, 0, 0, 0, hd4_m5_parity, hd4_m6_parity };
int ** data_bm_hd4 [7] = { 0, 0, 0, 0, 0, hd4_m5_data, hd4_m6_data };
int ** parity_bm_hd3 [7] = { 0, 0, 0, 0, 0, hd3_m5_parity, hd3_m6_parity };
int ** data_bm_hd3 [7] = { 0, 0, 0, 0, 0, hd3_m5_data, hd3_m6_data };

#define PARITY_BM_ARY(k, m, hd) (hd == 3) ? parity_bm_hd3[m][k] : parity_bm_hd4[m][k]
#define DATA_BM_ARY(k, m, hd) (hd == 3) ? data_bm_hd3[m][k] : data_bm_hd4[m][k]

#endif
