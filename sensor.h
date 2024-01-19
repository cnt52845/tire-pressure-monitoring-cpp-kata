#pragma once

#include <cstdlib>
#include <ctime>

class Sensor {
public:
    Sensor() { srand(time(0)); }

    double pop_next_pressure_psi_value()
    {
        // The reading of the pressure value from the sensor is simulated
        double pressure = 16 + (float) rand() / ((float) RAND_MAX / (6));
        return pressure;
    }
};
