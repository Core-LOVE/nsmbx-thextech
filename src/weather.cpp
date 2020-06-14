#include "globals.h"
#include "weather.h"
#include "collision.h"

void UpdateWeatherFrames()
{
    if(FreezeNPCs)
        return;
	
    For(A, 1, numWeather)
    {
        auto &w = Weather[A];
        if(WeatherFrameAmount[Weather[A].Type] > 0)
		{
			w.FrameCount += 1;
			if(w.FrameCount >= WeatherFrameSpeed[Weather[A].Type])
			{
				w.FrameCount = 0;
				w.Frame++;
				if(w.Frame >= WeatherFrameAmount[Weather[A].Type])
					w.Frame = 0;
			}
		}
    }
}

void UpdateWeatherPhysics()
{
	UpdateWeatherFrames();
	
    if(FreezeNPCs)
        return;


    For(A, 1, numWeather)
    {
        auto &w = Weather[A];
		w.LifeTimer--;
		if(w.Type == 1 && w.Location.SpeedY != -5)
            w.Location.SpeedY = -5;

    }
	
    int numScreens = 0;

    if(FrameSkip && !TakeScreen)
    {
        if(SDL_GetTicks() + floor(1000 * (1 - (cycleCount / 63.0))) > GoalTime) // Don't draw this frame
        {
            numScreens = 1;
            if(!LevelEditor)
            {
                if(ScreenType == 1)
                    numScreens = 2;
                if(ScreenType == 4)
                    numScreens = 2;
                if(ScreenType == 5)
                {
                    if(vScreen[2].Visible)
                        numScreens = 2;
                    else
                        numScreens = 1;
                }
                if(ScreenType == 8)
                    numScreens = 1;
            }
        }
    }

    for(int Z = 1; Z <= numScreens; Z++)
    {
        for(int A = 1; A <= numWeather; A++)
        {
            if(!vScreenCollision(Z, Weather[A].Location))
                KillWeather(A);
        }
    }

    for(int A = numWeather; A >= 1; --A)
    {
        if(Weather[A].LifeTimer <= 0)
            KillWeather(A);
    }	
}

void SpawnWeather(int A, Location_t Location, bool Shadow)
{
    if(numWeather >= maxWeathers - 4 || FreezeNPCs)
    {
        return;
    }
	
	numWeather++;
	Weather[numWeather].Shadow = Shadow;
    Weather[numWeather].Location.X = Location.X;
    Weather[numWeather].Location.Y = Location.Y;
	Weather[numWeather].Location.Width = WeatherWidth[A];
    Weather[numWeather].Location.Height = WeatherHeight[A];
    Weather[numWeather].Type = A;
    Weather[numWeather].LifeTimer = WeatherLife[A];
}

void KillWeather(int A)
{
    if(numWeather == 0)
        return;

    Weather[A] = Weather[numWeather];
    Weather_t &w = Weather[numWeather];
    w.Frame = 0;
    w.FrameCount = 0;
    w.LifeTimer = 0;
    w.Type = 0;
    numWeather -= 1;
}
