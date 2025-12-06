// LCDAdapter.h
#ifndef LCD_ADAPTER_H
#define LCD_ADAPTER_H

#include <LiquidCrystal.h>
#include "../Domain/Ports.h"

// ====================================
//        CAPA DE INFRAESTRUCTURA 💾
// ====================================

class LCDAdapter : public ILCDOutput {
private:
    LiquidCrystal lcd; 
public:
    LCDAdapter(int rs, int en, int d4, int d5, int d6, int d7); 
    void init(int cols, int rows) override;
    void displayMessage(const char* message) override;
    void displayUser(const User& user) override;
};

#endif // LCD_ADAPTER_H
