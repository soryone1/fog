#include "fog.h"

void Fog::FogInit() {
  pinMode(1, OUTPUT); // PB1 (OC1A) as output
  GTCCR = 0; // Reset timer 1 control registers
  TCCR1 = 0;
  TCCR1 = (1 << PWM1A) | (1 << COM1A0);
  TCCR1 |= (1 << CS10);
}

void Fog::FogOn() {
  TCCR1 |= (1 << COM1A0);
  OCR1C = 144;
  OCR1A = OCR1C / 2;
}

void Fog::FogOff() {
  TCCR1 &= ~(1 << COM1A0);
}
int Fog::mapToRange(int value) {
  if (value < 0) {
    return 0;
  }
  if (value > 1023) {
    return 1023;
  }
  return value;
}

void Fog::FogAnalog(int inputValue) {
  int mappedValue = mapToRange(inputValue);
  int ocr1cVal = map(inputValue, 0, 1023, 123, 144);

  if (ocr1cVal == 123 ) {
    TCCR1 &= ~(1 << COM1A0);
  } else {
    TCCR1 |= (1 << COM1A0);
    OCR1C = ocr1cVal;
    OCR1A = OCR1C / 2;
  }
}
