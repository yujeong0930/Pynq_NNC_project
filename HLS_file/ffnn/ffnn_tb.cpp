#include <iostream>
#include "ffnn.h"

int main() {

    const int NUM_TEST = 8;

    // 너가 준 데이터 5개
    fixed16_8 test_data[NUM_TEST][FEATURE_SIZE] = {
        { 1,0,0,-0.02,-0.02,-0.8320,0.5547,10,10 },
        { 1,0,0,-0.12,-0.07,-0.8320,0.5547,10,10 },
        { 1,0,0,-0.09,-0.07,-0.8303,0.5573,10,11 },
        { 1,0,0,-0.09,-0.09,-0.8303,0.5573,10,11 },
        { 1,0,0,-0.12,-0.11,-0.8303,0.5573,10,11 },
        { 1,0,0,-0.11,-0.12,-0.8303,0.5573,10,12 },
        { 1,0,0,-0.12,-0.12,-0.8303,0.5573,10,12 },
        { 1,0,0,-0.13,-0.14,-0.8303,0.5573,10,12 }
    };

    fixed16_2 output[OUTPUT_SIZE];

    fixed16_8 dbg_layer1[L1];
    fixed16_8 dbg_layer2[L2];
    fixed16_8 dbg_layer3[L3];
    fixed16_8 dbg_layer4[2];

    for(int t=0; t<NUM_TEST; t++){
        std::cout << "===== Test " << t+1 << " =====\n";

        ffnn_hls(test_data[t], output, dbg_layer1, dbg_layer2, dbg_layer3,dbg_layer4);
        /*
        std::cout << "===== Layer1 Output =====" << std::endl;
        for(int i=0;i<L1;i++)
            std::cout << i << ": " << (float)dbg_layer1[i] << std::endl;

        std::cout << "\n===== Layer2 Output =====" << std::endl;
        for(int i=0;i<L2;i++)
            std::cout << i << ": " << (float)dbg_layer2[i] << std::endl;

        std::cout << "\n===== Layer3 Output =====" << std::endl;
        for(int i=0;i<L3;i++)
            std::cout << i << ": " << (float)dbg_layer3[i] << std::endl;
        */
        std::cout << "\n===== Layer4 Output =====" << std::endl;
        for(int i=0;i<2;i++)
            std::cout << i << ": " << (float)dbg_layer4[i] << std::endl;
        
        std::cout << "Output: ";
        for(int i=0;i<OUTPUT_SIZE;i++){
            std::cout << (float)output[i] << " ";
        }
        std::cout << "\n\n";
    }

    return 0;
}