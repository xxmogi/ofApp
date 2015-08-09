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


class ofFFT {
    FFTSetup setup;
    int size;
    int sizeLog2;
    float *buf;
    float *window;
    
    DSPSplitComplex comp;
    
public:
    ofFFT(int size);
    void update(float *input);
};

#endif
