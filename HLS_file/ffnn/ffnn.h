#ifndef FFNN_H
#define FFNN_H

#include <ap_fixed.h>

// ===== Data Types =====
typedef ap_fixed<16,8> fixed16_8;   // weight, bias, sum, layers
typedef ap_fixed<16,2> fixed16_2;   // window, input_vector, raw input

// ===== Network Size =====
#define WINDOW_SIZE    5
#define FEATURE_SIZE   9
#define INPUT_SIZE     (WINDOW_SIZE * FEATURE_SIZE)

#define L1  64
#define L2  32
#define L3  16
#define OUTPUT_SIZE  2

// ===== Sigmoid LUT =====
#define SIG_LUT_SIZE 512
extern const fixed16_2 sigmoid_lut[SIG_LUT_SIZE];

fixed16_8 relu_hls(fixed16_8 x);

// Sigmoid function using LUT
fixed16_2 sigmoid_hls(fixed16_8 x);

// ===== Weight & Bias (extern) =====
extern const fixed16_2 W1[L1][INPUT_SIZE];
extern const fixed16_2 b1[L1];

extern const fixed16_2 W2[L2][L1];
extern const fixed16_2 b2[L2];

extern const fixed16_2 W3[L3][L2];
extern const fixed16_2 b3[L3];


#define SIGMOID_LUT_SIZE 512
extern const fixed16_2 W4[OUTPUT_SIZE][L3];
extern const fixed16_2 b4[OUTPUT_SIZE];

// ===== Top Function =====
// window_buffer는 내부 static 으로 선언되어 있다고 가정
void ffnn_hls(fixed16_8 new_data[FEATURE_SIZE],
              fixed16_2 output[OUTPUT_SIZE],
              fixed16_8 dbg_layer1[L1],
              fixed16_8 dbg_layer2[L2],
              fixed16_8 dbg_layer3[L3],
              fixed16_8 dbg_layer4[2]);

#endif
