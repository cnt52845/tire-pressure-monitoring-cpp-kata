#pragma once

#include <cstdlib>
#include <ctime>

class Sensor {
public:
    Sensor() { srand(time(0)); }

    double pop_next_pressure_psi_value() const
    {
        auto pressure_telemetry_value = sample_pressure();
        return offset + pressure_telemetry_value;
    }

    static double sample_pressure()
    {
        // The reading of the pressure value from the sensor is simulated
        double pressure_telemetry_value = (float) rand() / ((float) RAND_MAX / (6));
        return pressure_telemetry_value;
    }

private:
    constexpr static int offset = 16;
};
