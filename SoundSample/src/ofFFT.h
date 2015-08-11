//
//  ofFFT.h
//  SoundSample
//
//  Created by Takashi Mogi on 2015/08/03.
//
//

#ifndef SoundSample_ofFFT_h
#define SoundSample_ofFFT_h

#include <Accelerate/Accelerate.h>
#include "ofMain.h"


class ofFFT  : public ofBaseApp{
    FFTSetup setup;
    int size;
    int sizeLog2;
    float *buf;
    float *window;
    
    float *inputBuffer;
    float *spectrum;
    
    
    DSPSplitComplex fftInput;
    
public:
    ofFFT(int size);
    ~ofFFT();
    void update(float *input);
    void audioReceived(float * input, int bufferSize, int nChannels);
    float* getSpectrums();
    float* getSignals();
};

#endif
