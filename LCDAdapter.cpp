// LCDAdapter.cpp
#include "Infrastructure/LCDAdapter.h"

LCDAdapter::LCDAdapter(int rs, int en, int d4, int d5, int d6, int d7) 
    : lcd(rs, en, d4, d5, d6, d7) {}

void LCDAdapter::init(int cols, int rows) { 
    lcd.begin(cols, rows); 
}

void LCDAdapter::displayMessage(const char* message) { 
    lcd.clear(); 
    lcd.print(message); 
}

void LCDAdapter::displayUser(const User& user) {
    lcd.setCursor(0, 1);
    lcd.print("ID:");
    lcd.print(user.getUserId());
    lcd.print(" Name:");
    lcd.print(user.getName());
    int cursorPos = 6 + String(user.getUserId()).length() + 6 + String(user.getName()).length();
    for (int i = cursorPos; i < 16; ++i) {
        lcd.print(" ");
    }
}
