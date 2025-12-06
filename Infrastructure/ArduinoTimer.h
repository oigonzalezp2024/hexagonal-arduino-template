// Infrastructure/ArduinoTimer.h
#ifndef ARDUINO_TIMER_H
#define ARDUINO_TIMER_H

// Corregido: Incluir Ports.h (donde está ITimer)
#include "../Domain/Ports.h" 
#include <Arduino.h> 

class ArduinoTimer : public ITimer {
public:
    unsigned long getTimeMs() const override {
        return millis(); 
    }
};

#endif // ARDUINO_TIMER_H
