#include "DrUltraSonic.h"
#include <Arduino.h>

DrUltraSonic::DrUltraSonic(int echo_pin, int trig_pin) //コンストラクター
{
     m_echo_pin = echo_pin;
     m_trig_pin = trig_pin;
    pinMode(m_echo_pin, INPUT); //設定
    pinMode(m_trig_pin, OUTPUT); //設定
}

double DrUltraSonic::measureReturnTime()
{
    double t; // tはμ秒単位

    /*　超音波発生　*/
    digitalWrite(m_trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(m_trig_pin, LOW);

    /*　返ってくるまでの時間測定　*/
    t = pulseIn(m_echo_pin, HIGH); // ECHOピンのパルスがHIGHになった時間を変数tに格納
   
    return t;
}
