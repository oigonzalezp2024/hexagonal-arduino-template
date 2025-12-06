// hexagonal-arduino-template.ino (Archivo principal de Arduino)

#include "Infrastructure/LCDAdapter.h"
#include "Infrastructure/SimulatedUserRepository.h"
#include "Infrastructure/ArduinoTimer.h"
#include "Services/UserCycleService.h"
#include "Application/Controller.h"

LCDAdapter lcd_adapter(12, 11, 5, 4, 3, 2); 

SimulatedUserRepository repository;
ArduinoTimer arduino_timer;

UserCycleService concrete_service(&repository);
Controller concrete_control(&lcd_adapter, &concrete_service, &arduino_timer);

IController* control = &concrete_control; 

void setup()
{
    control->begin(16, 2);
}

void loop()
{
    control->update();
}
