#include "MdMeasureDistance.h"
#include "DrUltraSonic.h"
#include "M5All-In-One-Gadget.h"
#include <Arduino.h>

DrUltraSonic sonic = DrUltraSonic(ECHO_PIN, TRIG_PIN); // コンストラクタの呼び出し

double MdMeasureDistance::getDistance()
{
    double distance;
    Serial.print("distance");

    distance = sonic.measureReturnTime() * 340 * (0.000001) * 0.5 * 100; // m→cmなので100倍する
    
    Serial.println(distance);
    return distance;
}