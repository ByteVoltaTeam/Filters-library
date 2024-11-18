#ifndef FILTERS_h
#define FILTERS_h

#include <Arduino.h> 

class Filters {
  	public:
      Filters();

      // movingAvarege
      float movingAverage(int newReading);
      void movAsize(uint16_t size);
      void clearBuffermovA();
      //-------------
      
      // High-Pass and Low-Pass filters
      float lowPass(float newRead, float alpha, float lastRead);
      float highPass(float newRead, float alpha, float lastRead);
      //---------------
    private: 
      // movingAvarage
      int* bufferma;          
      uint16_t bufferSizema;
      uint16_t indexma;            
      int summa;        
      //--------------      
};

#endif