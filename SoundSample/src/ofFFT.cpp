//
//  ofFFT.cpp
//  SoundSample
//
//  Created by Takashi Mogi on 2015/08/03.
//
//
#include "ofFFT.h"

ofFFT::ofFFT(int bufsize) {
    sizeLog2 = (int)(log(bufsize)/log(2));
    size = 1 << sizeLog2;
    setup = vDSP_create_fftsetup(sizeLog2 + 1, FFT_RADIX3);
    buf = (float*) malloc(size * sizeof(float));
    comp.realp = (float*)calloc(size, sizeof(float));
    comp.imagp = (float*)calloc(size, sizeof(float));
}

void ofFFT::update(float *input) {
    for (int i=0; i<sizeLog2; i++) {
        
    }
}