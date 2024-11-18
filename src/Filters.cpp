#include <Arduino.h>
#include "Filters.h"

Filters::Filters(){
}


void Filters::movAsize(uint16_t size) {
  delete[] bufferma; 
  bufferSizema = size;
  bufferma = new int[bufferSizema]; 
  indexma = 0;
  summa = 0;

  for (int i = 0; i < bufferSizema; i++) {
    bufferma[i] = 0;
  }
}

float Filters::movingAverage(int newReading) {
  summa -= bufferma[indexma];

  bufferma[indexma] = newReading;
  summa += newReading;

  indexma++;
  if (indexma >= bufferSizema) {
    indexma = 0;  
  }

  return (float)summa / bufferSizema;
}

void Filters::clearBuffermovA() {
  for(int i = 0; i < bufferSizema; i++) {
    bufferma[i] = 0;
  }
  
  indexma = 0;
  summa = 0;
}

float Filters::lowPass(float newReading, float alpha, float lastRead) {
    return alpha * newReading + (1 - alpha) * lastRead;
}

float Filters::highPass(float newReading, float alpha, float lastRead) {
    return alpha * (lastRead + newReading - lastRead);
}


