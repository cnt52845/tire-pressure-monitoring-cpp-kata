#pragma once

#include "sensor.h"

class Alarm {
public:
    Alarm() = default;
    void check()
    {
        auto psi_pressure_value = sensor.pop_next_pressure_psi_value();

        if (psi_pressure_value < LOW_PRESSURE_THRESHOLD ||
            psi_pressure_value > HIGH_PRESSURE_THRESHOLD) {
            alarm_on = true;
        }
    }
    bool is_alarm_on() const { return alarm_on; }

protected:
    Sensor sensor;
    bool   alarm_on{};

    constexpr static double LOW_PRESSURE_THRESHOLD  = 17;
    constexpr static double HIGH_PRESSURE_THRESHOLD = 21;
};
