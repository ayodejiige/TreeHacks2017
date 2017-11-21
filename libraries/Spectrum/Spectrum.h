#ifndef SPECTRUM_H
#define SPECTRUM_H

class Spectrum
{
public:
    Spectrum(int reset, int strobe, int outA, int outB);
    void setup();
    void readData(int A[7], int B[7]);
    int getAmp(int i);
private:
    int m_resetPin;
    int m_strobePin;
    int m_outPinA;
    int m_outPinB;
    int m_amps[7];
};
#endif
