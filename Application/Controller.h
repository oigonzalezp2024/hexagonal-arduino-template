// Controller.h (Versión Final)

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Domain/Ports.h" 
// Ya no necesitamos <Arduino.h> aquí. ¡Victoria arquitectónica!

// ===================================
//          CAPA DE APLICACIÓN ⚙️
// ===================================

class Controller : public IController {

private:
    ILCDOutput* lcdOutput;
    IUserCycleService* cycleService;
    ITimer* timer; // 👈 NUEVO: Dependencia del puerto ITimer
    
    unsigned long lastUpdateTime = 0;
    const long updateInterval = 1000;

public:
    // 👈 CONSTRUCTOR CORREGIDO: Acepta 3 dependencias
    Controller(ILCDOutput* output, IUserCycleService* service, ITimer* timer) 
        : lcdOutput(output), 
          cycleService(service),
          timer(timer) // 👈 Almacena la implementación real o el Mock
    {}

    void begin(int cols, int rows) override
    {
        lcdOutput->init(cols, rows); 
        lcdOutput->displayMessage("System Ready!");
    }

    void update() override
    {
        unsigned long current_time = timer->getTimeMs(); // 👈 USA EL TIMER INYECTADO

        // 👈 CORRECCIÓN LÓGICA: Usar WHILE para capturar saltos de tiempo
        while (current_time - lastUpdateTime >= updateInterval)
        {
            lastUpdateTime += updateInterval;
            
            User user = cycleService->getNextUser(); 
            lcdOutput->displayUser(user); 
        }
    }
};

#endif // CONTROLLER_H
