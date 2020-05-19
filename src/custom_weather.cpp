#include "globals.h"
#include "custom_weather.h"

#include <DirManager/dirman.h>
#include <Utils/files.h>
#include <PGE_File_Formats/file_formats.h>
#include <PGE_File_Formats/smbx64.h>
#include <fmt_format_ne.h>
#include <IniProcessor/ini_processing.h>

void LoadCustomWeather(int A, std::string cFileName);

void SaveWeatherDefaults()
{
    for(int A = 1; A <= maxWeatherType; A++)
    {
        WeatherDefaults.WeatherWidth[A] = WeatherWidth[A];
        WeatherDefaults.WeatherHeight[A] = WeatherHeight[A];
        WeatherDefaults.WeatherFrameAmount[A] = WeatherFrameAmount[A];
        WeatherDefaults.WeatherFrameSpeed[A] = WeatherFrameSpeed[A];
    }
}

void LoadWeatherDefaults()
{
    for(int A = 1; A <= maxWeatherType; A++)
    {
        WeatherWidth[A] = WeatherDefaults.WeatherWidth[A];
        WeatherHeight[A] = WeatherDefaults.WeatherHeight[A];
        WeatherFrameAmount[A] = WeatherDefaults.WeatherFrameAmount[A];
        WeatherFrameSpeed[A] = WeatherDefaults.WeatherFrameSpeed[A];
    }
}

void FindCustomWeathers(/*std::string cFilePath*/)
{
    DirMan searchDir(FileNamePath);
    std::set<std::string> existingFiles;
    std::vector<std::string> files;
    searchDir.getListOfFiles(files, {".txt"});
    for(auto &p : files)
        existingFiles.insert(FileNamePath + p);

    if(DirMan::exists(FileNamePath + FileName))
    {
        DirMan searchDataDir(FileNamePath + FileName);
        searchDataDir.getListOfFiles(files, {".png", ".gif"});
        for(auto &p : files)
            existingFiles.insert(FileNamePath + FileName  + "/"+ p);
    }

    for(int A = 1; A < maxWeatherType; ++A)
    {

        std::string WeatherPathBasegame = AppPath + fmt::format_ne("/config/weather/weather-{0}.txt", A);

        std::string WeatherIniPath = FileNamePath + fmt::format_ne("weather-{0}.ini", A);
        std::string WeatherIniPathC = FileNamePath + FileName + fmt::format_ne("/weather-{0}.ini", A);
        std::string WeatherPath = FileNamePath + fmt::format_ne("weather-{0}.txt", A);
        std::string WeatherPathC = FileNamePath + FileName + fmt::format_ne("/weather-{0}.txt", A);

        if(Files::fileExists(WeatherPathBasegame))
            LoadCustomWeather(A, WeatherPathBasegame);

        if(Files::fileExists(WeatherIniPath))
            LoadCustomWeather(A, WeatherIniPath);
        if(Files::fileExists(WeatherPath))
            LoadCustomWeather(A, WeatherPath);

        if(Files::fileExists(WeatherIniPathC))
            LoadCustomWeather(A, WeatherIniPathC);
        if(Files::fileExists(WeatherPathC))
            LoadCustomWeather(A, WeatherPathC);
    }
}

void LoadCustomWeather(int A, std::string cFileName)
{
    IniProcessing config(cFileName);
    if(!config.beginGroup("Weather"))
           config.beginGroup("General");


    config.read("width", WeatherWidth[A], WeatherWidth[A]);
    config.read("height", WeatherHeight[A], WeatherHeight[A]);

    if(WeatherWidth[A] <= 0) // Validate
        WeatherWidth[A] = 32;
    if(WeatherHeight[A] <= 0)
        WeatherHeight[A] = 32;

    config.read("frames", WeatherFrameAmount[A], WeatherFrameAmount[A]);
    if(WeatherFrameAmount[A] <= 0) // Validate
        WeatherFrameAmount[A] = 1;

    int frameDelay = 62;
    config.read("frame-delay", frameDelay, frameDelay);
    config.read("frame-speed", frameDelay, frameDelay);
    if(frameDelay <= 0) // validate
        frameDelay = 1;

   WeatherFrameSpeed[A] = int((double(frameDelay) / 1000.0) * 65.0);
    config.read("framespeed", WeatherFrameSpeed[A], WeatherFrameSpeed[A]);

    if(WeatherFrameSpeed[A] <= 0) // validate
        WeatherFrameSpeed[A] = 1;

    config.endGroup();
}
