#ifndef fog_h
#define fog_h
#include <Arduino.h>
class Fog {
  public:
    void FogInit();
    void FogOn();
    void FogOff();
    void FogAnalog(int inputValue);
  private:
    int mapToRange(int value);
};

#endif
