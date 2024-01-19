#pragma once

#include "sensor.h"

class Alarm {
public:
    Alarm() = default;
    void check()
    {
        double psi_pressure_value = sensor.pop_next_pressure_psi_value();

        if (psi_pressure_value < low_pressure_threshold ||
            high_pressure_threshold < psi_pressure_value) {
            alarm_on = true;
        }
    }
    bool is_alarm_on() { return alarm_on; }

protected:
    Sensor sensor;
    double low_pressure_threshold  = 17;
    double high_pressure_threshold = 21;
    bool   alarm_on{};
};
