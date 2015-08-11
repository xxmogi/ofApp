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
    fftInput.realp = (float*)calloc(size, sizeof(float));
    fftInput.imagp = (float*)calloc(size, sizeof(float));
    inputBuffer = (float*) calloc(size, sizeof(float));
    spectrum = (float *) calloc(size / 2, sizeof(float));
}

void ofFFT::update(float *input) {
    for (int i=0; i<sizeLog2; i++) {
        
    }
}

void  ofFFT::audioReceived(float * input, int bufferSize, int nChannels) {
    for(int i=0;i<bufferSize;i++) {
        inputBuffer[i] = input[i];
    }
    vDSP_fft_zrip(setup, &fftInput, 1 , sizeLog2, FFT_FORWARD);
    for(int j=0;j<size/2;j++) {
        float val = sqrt(pow(fftInput.realp[j], 2) + pow(fftInput.imagp[j],2));
        spectrum[j] = 10.0f * (float)log10(1 + val) * 2.0;
    }
}


float* ofFFT::getSpectrums() {
    return spectrum;
}

float* ofFFT::getSignals() {
    return inputBuffer;
}
