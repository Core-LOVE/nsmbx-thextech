#include "globals.h"
#include "custom_effects.h"

#include <DirManager/dirman.h>
#include <Utils/files.h>
#include <PGE_File_Formats/file_formats.h>
#include <PGE_File_Formats/smbx64.h>
#include <fmt_format_ne.h>
#include <IniProcessor/ini_processing.h>

void LoadCustomEffects(int A, std::string cFileName);

void SaveEffectDefaults()
{
    for(int A = 1; A <= maxEffectType; A++)
    {
        EffectDefaults.EffectWidth[A] = EffectWidth[A];
        EffectDefaults.EffectHeight[A] = EffectHeight[A];
        EffectDefaults.EffectFrameAmount[A] = EffectFrameAmount[A];
        EffectDefaults.EffectFrameSpeed[A] = EffectFrameSpeed[A];
    }
}

void LoadEffectDefaults()
{
    for(int A = 1; A <= maxEffectType; A++)
    {
        EffectWidth[A] = EffectDefaults.EffectWidth[A];
        EffectHeight[A] = EffectDefaults.EffectHeight[A];
        EffectFrameAmount[A] = EffectDefaults.EffectFrameAmount[A];
        EffectFrameSpeed[A] = EffectDefaults.EffectFrameSpeed[A];
    }
}

void FindCustomEffects(/*std::string cFilePath*/)
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

    for(int A = 1; A < maxEffectType; ++A)
    {

        std::string EffectsPathBasegame = AppPath + fmt::format_ne("/config/Effect/Effect-{0}.txt", A);

        std::string EffectsIniPath = FileNamePath + fmt::format_ne("Effect-{0}.ini", A);
        std::string EffectsIniPathC = FileNamePath + FileName + fmt::format_ne("/Effect-{0}.ini", A);
        std::string EffectsPath = FileNamePath + fmt::format_ne("Effect-{0}.txt", A);
        std::string EffectsPathC = FileNamePath + FileName + fmt::format_ne("/Effect-{0}.txt", A);

        if(Files::fileExists(EffectsPathBasegame))
            LoadCustomEffects(A, EffectsPathBasegame);

        if(Files::fileExists(EffectsIniPath))
            LoadCustomEffects(A, EffectsIniPath);
        if(Files::fileExists(EffectsPath))
            LoadCustomEffects(A, EffectsPath);

        if(Files::fileExists(EffectsIniPathC))
            LoadCustomEffects(A, EffectsIniPathC);
        if(Files::fileExists(EffectsPathC))
            LoadCustomEffects(A, EffectsPathC);
    }
}

void LoadCustomEffects(int A, std::string cFileName)
{
    IniProcessing config(cFileName);
    if(!config.beginGroup("Effects"))
           config.beginGroup("General");


    config.read("width", EffectWidth[A], EffectWidth[A]);
    config.read("height", EffectHeight[A], EffectHeight[A]);

    if(EffectWidth[A] <= 0) // Validate
        EffectWidth[A] = 32;
    if(EffectHeight[A] <= 0)
        EffectHeight[A] = 32;

    config.read("frames", EffectFrameAmount[A], EffectFrameAmount[A]);
    if(EffectFrameAmount[A] <= 0) // Validate
        EffectFrameAmount[A] = 1;

    int frameDelay = 62;
    config.read("frame-delay", frameDelay, frameDelay);
    config.read("frame-speed", frameDelay, frameDelay);
    if(frameDelay <= 0) // validate
        frameDelay = 1;

    EffectFrameSpeed[A] = int((double(frameDelay) / 1000.0) * 65.0);
    config.read("framespeed", EffectFrameSpeed[A], EffectFrameSpeed[A]);

    if(EffectFrameSpeed[A] <= 0) // validate
        EffectFrameSpeed[A] = 1;
    config.endGroup();
}
