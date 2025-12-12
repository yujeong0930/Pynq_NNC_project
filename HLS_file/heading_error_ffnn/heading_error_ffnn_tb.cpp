#include <iostream>
#include "heading_error_ffnn.h"

int main() {

    const int NUM_TEST = 8;

    // 너가 준 데이터 5개
    fixed16_8 test_data[NUM_TEST][FEATURE_SIZE] = {
        { 1,0,0,-0.02,-0.02, 0 },
        { 1,0,0,-0.12,-0.07, 0},
        { 1,0,0,-0.09,-0.07, 0.1875},
        { 1,0,0,-0.09,-0.09, 0.1875},
        { 1,0,0,-0.12,-0.11, 0.1875},
        { 1,0,0,-0.11,-0.12, 0.1875},
        { 1,0,0,-0.12,-0.12, 0.1875},
        { 1,0,0,-0.13,-0.14, 0.1875}
    };

    fixed16_2 output[OUTPUT_SIZE];

    for(int t=0; t<NUM_TEST; t++){
        std::cout << "===== Test " << t+1 << " =====\n";

        top_heading_error_ffnn(test_data[t], output);
        
        std::cout << "Output: ";
        for(int i=0;i<OUTPUT_SIZE;i++){
            std::cout << (float)output[i] << " ";
        }
        std::cout << "\n\n";
    }

    return 0;
}