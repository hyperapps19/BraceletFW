#include <Arduino.h>
#include <ButtonHandler.cpp>

#define LEFT_BTN D6
#define RIGHT_BTN D5

ButtonHandler left(LEFT_BTN);
ButtonHandler right(RIGHT_BTN);

const int trigPin = D7;

void emitSignal(void)
{
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    delay(2);
}

void emitMultipleSignals(uint n)
{
    for (uint i = 0; i < n; i++)
        emitSignal();
}

inline void morse_SHORT(void)
{
    emitMultipleSignals(1000000);
    delayMicroseconds(100);
}

inline void morse_LONG(void)
{
    emitMultipleSignals(300);
    delayMicroseconds(100);
}

void alarm(void)
{
    morse_SHORT();
    morse_SHORT();
    morse_SHORT();

    morse_LONG();
    morse_LONG();
    morse_LONG();

    morse_SHORT();
    morse_SHORT();
    morse_SHORT();
}

void ICACHE_RAM_ATTR leftBtnCallback(void)
{
    Serial.println("L");
    alarm();
}

void ICACHE_RAM_ATTR rightBtnCallback(void)
{
    Serial.println("R");
    alarm();
}
void setup()
{
    Serial.begin(115200);
    left.setCallback(leftBtnCallback);
    right.setCallback(rightBtnCallback);
}

void loop()
{
}