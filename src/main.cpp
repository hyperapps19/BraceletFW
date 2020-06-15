#include <Arduino.h>
#define LEFT_BTN D6
#define RIGHT_BTN D5

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
    emitMultipleSignals(100);
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
    detachInterrupt(digitalPinToInterrupt(LEFT_BTN));
}

void ICACHE_RAM_ATTR rightBtnCallback(void)
{
    Serial.println("R");
    detachInterrupt(digitalPinToInterrupt(RIGHT_BTN));
}
void setup()
{
    Serial.begin(115200);
    pinMode(LEFT_BTN, INPUT_PULLUP);
    pinMode(RIGHT_BTN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(LEFT_BTN), leftBtnCallback, RISING);
    attachInterrupt(digitalPinToInterrupt(RIGHT_BTN), rightBtnCallback, RISING);
}

void loop()
{
}