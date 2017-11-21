#include "Arduino.h"
#include "Spectrum.h"

Spectrum::Spectrum(int reset, int strobe, int outA, int outB)
: m_resetPin(reset)
, m_strobePin(strobe)
, m_outPinA(outA)
, m_outPinB(outB)
{
}

void
Spectrum::setup()
{
  //Set spectrum Shield pin configurations
  pinMode(m_strobePin, OUTPUT);
  pinMode(m_resetPin, OUTPUT);
  pinMode(m_outPinA, INPUT);
  pinMode(m_outPinB, INPUT);
  digitalWrite(m_strobePin, HIGH);
  digitalWrite(m_resetPin, HIGH);

  //Initialize Spectrum Analyzers
  digitalWrite(m_strobePin, LOW);
  delay(1);
  digitalWrite(m_resetPin, HIGH);
  delay(1);
  digitalWrite(m_strobePin, HIGH);
  delay(1);
  digitalWrite(m_strobePin, LOW);
  delay(1);
  digitalWrite(m_resetPin, LOW);
}

void
Spectrum::readData(int A[7], int B[7])
{
  for (int freq = 0; freq<7; freq++)
  {
    int chA = analogRead(m_outPinA);
    int chB = analogRead(m_outPinB);
    int amp = (chA + chB) >> 1;
    A[freq] = chA;
    B[freq] = chB;
    m_amps[freq] = amp;
    digitalWrite(m_strobePin, HIGH);
    digitalWrite(m_strobePin, LOW);
  }
}

int
Spectrum::getAmp(int i)
{
  if(i > 6)
  {
    return -1;
  } else
  {
    return m_amps[i];
  }
}
