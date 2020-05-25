#ifndef WEATHER_H
#define WEATHER_H

#include "location.h"

void UpdateWeatherFrames();

void UpdateWeatherPhysics();

void SpawnWeather(int A, Location_t Location_t, bool Shadow = false);

void KillWeather(int A);


#endif // WEATHER_H
