#pragma once

#include <random>

class Sensor {
public:
    Sensor() : mt(rd()) {}

    double pop_next_pressure_psi_value() const
    {
        auto pressure_telemetry_value = sample_pressure();
        return OFFSET + pressure_telemetry_value;
    }

    double sample_pressure() const
    {
        // The reading of the pressure value from the sensor is simulated
        double pressure_telemetry_value = dist(mt);
        return pressure_telemetry_value;
    }

private:
    constexpr static int OFFSET = 16;

    std::random_device                       rd;
    mutable std::mt19937                     mt;
    mutable std::uniform_real_distribution<> dist{0, 6};
};
