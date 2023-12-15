#include "MdWBGTMonitor.h"
#include "DrTHSensor.h"
#include <Arduino.h>
#include "M5All-In-One-Gadget.h"

DrTHSensor drsensor;

void MdWBGTMonitor::init() // コンストラクター
{
    drsensor.init();
}

void MdWBGTMonitor::getWBGT(double *temperature, double *humidity, WbgtIndex *index)
{
    drsensor.getTempHumi(temperature, humidity);
    int calc_index = (int)(0.68 * *temperature + 0.12 * *humidity);

    if (15 >= calc_index)
    {
        *index = SAFE;
    }
    else if (24 >= calc_index)
    {
        *index = ATTENTION;
    }
    else if (27 >= calc_index)
    {
        *index = ALERT;
    }
    else if (30 >= calc_index)
    {
        *index = HIGH_ALERT;
    }
    else
    {
        *index = DANGER;
    }
}


