/*
 * TheXTech - A platform game engine ported from old source code for VB6
 *
 * Copyright (c) 2009-2011 Andrew Spinks, original VB6 code
 * Copyright (c) 2020-2020 Vitaly Novichkov <admin@wohlnet.ru>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "../globals.h"
#include "../global_constants.h"
#include "../graphics.h"
#include "../player.h"
#include "../sound.h"
#include "../change_res.h"
#include "../load_gfx.h"

#include <IniProcessor/ini_processing.h>

// Sets up the split lines
void SetupScreens()
{
    int sW = 800;
    int sH = 600;
    std::string mainIni = AppPath + "main.ini";
    IniProcessing config(mainIni);
    config.beginGroup("main");
    config.read("ScreenW", sW, 800);
    config.read("ScreenH", sH, 600);
    config.endGroup();

    switch(ScreenType)
    {
    case 0: // Follows Player 1
        vScreen[1].Height = sH;
        vScreen[1].Width = sW;
        vScreen[1].Left = 0;
        vScreen[1].Top = 0;
        vScreen[2].Visible = false;
        break;
    case 1: // Split Screen vertical
        vScreen[1].Height = sH / 2;
        vScreen[1].Width = sW;
        vScreen[1].Left = 0;
        vScreen[1].Top = 0;
        vScreen[2].Height = sH / 2;
        vScreen[2].Width = sW;
        vScreen[2].Left = 0;
        vScreen[2].Top = sH / 2;
        break;
    case 2: // Follows all players
        vScreen[1].Height = sH;
        vScreen[1].Width = sW;
        vScreen[1].Left = 0;
        vScreen[1].Top = 0;
        vScreen[2].Visible = false;
        break;
    case 3: // Follows all players. Noone leaves the screen
        vScreen[1].Height = sH;
        vScreen[1].Width = sW;
        vScreen[1].Left = 0;
        vScreen[1].Top = 0;
        vScreen[2].Visible = false;
        break;
    case 4: // Split Screen horizontal
        vScreen[1].Height = sH;
        vScreen[1].Width = sW / 2;
        vScreen[1].Left = 0;
        vScreen[1].Top = 0;
        vScreen[2].Height = sH;
        vScreen[2].Width = sW / 2;
        vScreen[2].Left = sW / 2;
        vScreen[2].Top = 0;
        break;
    case 5: // Dynamic screen detection
        vScreen[1].Height = sH;
        vScreen[1].Width = sW;
        vScreen[1].Left = 0;
        vScreen[1].Top = 0;
        vScreen[2].Visible = false;
        break;
    case 6: // VScreen Coop
        vScreen[1].Height = sH;
        vScreen[1].Width = sW;
        vScreen[1].Left = 0;
        vScreen[1].Top = 0;
        vScreen[2].Height = sH;
        vScreen[2].Width = sW;
        vScreen[2].Left = 0;
        vScreen[2].Top = 0;
        break;
    case 7:
        vScreen[1].Left = 0;
        vScreen[1].Width = 800;
        vScreen[1].Top = 0;
        vScreen[1].Height = 600;
        vScreen[2].Visible = false;
        break;
    case 8: // netplay
        vScreen[1].Left = 0;
        vScreen[1].Width = 800;
        vScreen[1].Top = 0;
        vScreen[1].Height = 600;
        vScreen[2].Visible = false;
        break;
//    End If
    }
}

void DynamicScreen()
{
    int sW = 800;
    int sH = 600;
    std::string mainIni = AppPath + "main.ini";
    IniProcessing config(mainIni);
    config.beginGroup("main");
    config.read("ScreenW", sW, 800);
    config.read("ScreenH", sH, 600);
    config.endGroup();

    int A = 0;
    GetvScreenAverage();

    for(A = 1; A <= numPlayers; A++)
    {
        if(Player[A].Effect == 6)
            return;
    }

    for(A = 1; A <= numPlayers; A++)
    {
        if(Player[A].Mount == 2)
            Player[A].Location.Height = 0;
    }

    if(CheckDead() == 0)
    {
        if(Player[1].Section == Player[2].Section)
        {
            if(level[Player[1].Section].Width - level[Player[1].Section].X > sW && (((vScreen[2].Visible == false && Player[2].Location.X + vScreenX[1] >= sW * 0.75 - Player[2].Location.Width / 2.0) || (vScreen[2].Visible == true && Player[2].Location.X + vScreenX[1] >= sW * 0.75 - Player[2].Location.Width / 2.0)) && (Player[1].Location.X < level[Player[1].Section].Width - sW * 0.75 - Player[1].Location.Width / 2.0)))
            {
                vScreen[2].Height = sH;
                vScreen[2].Width = sW / 2;
                vScreen[2].Left = sW / 2.0;
                vScreen[2].Top = 0;
                vScreen[1].Height = sH;
                vScreen[1].Width = sW / 2;
                vScreen[1].Left = 0;
                vScreen[1].Top = 0;
                GetvScreenAverage2();
                if(DScreenType != 1)
                    PlaySound(13);
                for(A = 1; A <= 2; A++)
                {
                    vScreen[A].TempDelay = 200;
                    vScreen[A].tempX = 0;
                    vScreen[A].TempY = -vScreenY[1] + sH * 0.5 - Player[A].Location.Y - vScreenYOffset - Player[A].Location.Height;
                }
                vScreen[2].Visible = true;
                DScreenType = 1;
            }
            else if(level[Player[1].Section].Width - level[Player[1].Section].X > sW && (((vScreen[2].Visible == false && Player[1].Location.X + vScreenX[1] >= sW * 0.75 - Player[1].Location.Width / 2.0) || (vScreen[2].Visible == true && Player[1].Location.X + vScreenX[2] >= sW * 0.75 - Player[1].Location.Width / 2.0)) && (Player[2].Location.X < level[Player[1].Section].Width - sW * 0.75 - Player[2].Location.Width / 2.0)))
            {
                vScreen[1].Height = sH;
                vScreen[1].Width = sW / 2;
                vScreen[1].Left = sW / 2.0;
                vScreen[1].Top = 0;
                vScreen[2].Height = sH;
                vScreen[2].Width = sW / 2;
                vScreen[2].Left = 0;
                vScreen[2].Top = 0;
                GetvScreenAverage2();
                if(DScreenType != 2)
                    PlaySound(13);
                for(A = 1; A <= 2; A++)
                {
                    vScreen[A].TempDelay = 200;
                    vScreen[A].tempX = 0;
                    vScreen[A].TempY = -vScreenY[1] + sH * 0.5 - Player[A].Location.Y - vScreenYOffset - Player[A].Location.Height;
                }
                DScreenType = 2;
                vScreen[2].Visible = true;
            }
            else if(level[Player[1].Section].Height - level[Player[1].Section].Y > sH && ((vScreen[2].Visible == false && Player[1].Location.Y + vScreenY[1] >= sH * 0.75 - vScreenYOffset - Player[1].Location.Height) || (vScreen[2].Visible == true && Player[1].Location.Y + vScreenY[2] >= sH * 0.75 - vScreenYOffset - Player[1].Location.Height)) && (Player[2].Location.Y < level[Player[1].Section].Height - sH * 0.75 - vScreenYOffset - Player[2].Location.Height))
            {
                vScreen[1].Height = sH / 2;
                vScreen[1].Width = sW;
                vScreen[1].Left = 0;
                vScreen[1].Top = sH / 2.0;
                vScreen[2].Height = sH / 2;
                vScreen[2].Width = sW;
                vScreen[2].Left = 0;
                vScreen[2].Top = 0;
                GetvScreenAverage2();
                if(DScreenType != 3)
                    PlaySound(13);
                for(A = 1; A <= 2; A++)
                {
                    vScreen[A].TempDelay = 200;
                    vScreen[A].TempY = 0;
                    vScreen[A].tempX = -vScreenX[1] + sW * 0.5 - Player[A].Location.X - Player[A].Location.Width * 0.5;
                }
                vScreen[2].Visible = true;
                DScreenType = 3;
            }
            else if(level[Player[1].Section].Height - level[Player[1].Section].Y > sH && ((vScreen[2].Visible == false && Player[2].Location.Y + vScreenY[1] >= sH * 0.75 - vScreenYOffset - Player[2].Location.Height) || (vScreen[2].Visible == true && Player[2].Location.Y + vScreenY[1] >= sH * 0.75 - vScreenYOffset - Player[2].Location.Height)) && (Player[1].Location.Y < level[Player[1].Section].Height - sH * 0.75 - vScreenYOffset - Player[1].Location.Height))
            {
                vScreen[1].Height = sH / 2;
                vScreen[1].Width = sW;
                vScreen[1].Left = 0;
                vScreen[1].Top = 0;
                vScreen[2].Height = sH / 2;
                vScreen[2].Width = sW;
                vScreen[2].Left = 0;
                vScreen[2].Top = sH / 2.0;
                GetvScreenAverage2();
                if(DScreenType != 4)
                    PlaySound(13);
                for(A = 1; A <= 2; A++)
                {
                    vScreen[A].TempDelay = 200;
                    vScreen[A].TempY = 0;
                    vScreen[A].tempX = -vScreenX[1] + sW * 0.5 - Player[A].Location.X - Player[A].Location.Width * 0.5;
                }
                vScreen[2].Visible = true;
                DScreenType = 4;
            }
            else
            {
                if(vScreen[2].Visible == true)
                {
                    if(DScreenType != 5)
                        PlaySound(13);
                    vScreen[2].Visible = false;
                    vScreen[1].Height = sH;
                    vScreen[1].Width = sW;
                    vScreen[1].Left = 0;
                    vScreen[1].Top = 0;
                    vScreen[1].tempX = 0;
                    vScreen[1].TempY = 0;
                    vScreen[2].tempX = 0;
                    vScreen[2].TempY = 0;
                }
                DScreenType = 5;
            }
            for(A = 1; A <= 2; A++)
            {
                if(vScreen[A].TempY > (vScreen[A].Height * 0.25))
                    vScreen[A].TempY = (vScreen[A].Height * 0.25);
                if(vScreen[A].TempY < -(vScreen[A].Height * 0.25))
                    vScreen[A].TempY = -(vScreen[A].Height * 0.25);
                if(vScreen[A].tempX > (vScreen[A].Width * 0.25) && !LevelWrap2[Player[A].Section])
                    vScreen[A].tempX = (vScreen[A].Width * 0.25);
                if(vScreen[A].tempX < -(vScreen[A].Width * 0.25) && !LevelWrap2[Player[A].Section])
                    vScreen[A].tempX = -(vScreen[A].Width * 0.25);
            }
        }
        else
        {
            vScreen[1].Height = sH / 2;
            vScreen[1].Width = sW;
            vScreen[1].Left = 0;
            vScreen[1].Top = 0;
            vScreen[2].Height = sH / 2;
            vScreen[2].Width = sW;
            vScreen[2].Left = 0;
            vScreen[2].Top = sH / 2.0;
            vScreen[1].tempX = 0;
            vScreen[1].TempY = 0;
            vScreen[2].tempX = 0;
            vScreen[2].TempY = 0;
            GetvScreenAverage2();
            if(DScreenType != 6)
                PlaySound(13);
            DScreenType = 6;
            vScreen[2].Visible = true;
        }
    }
    else
    {
        if(vScreen[2].Visible == true)
        {
            vScreen[2].Visible = false;
            vScreen[1].Visible = false;
            vScreen[1].Height = sH;
            vScreen[1].Width = sW;
            vScreen[1].Left = 0;
            vScreen[1].Top = 0;
            vScreen[1].Visible = true;
            vScreen[1].tempX = 0;
            vScreen[1].TempY = 0;
            vScreen[2].tempX = 0;
            vScreen[2].TempY = 0;
        }
    }
    for(A = 1; A <= numPlayers; A++)
    {
        if(Player[A].Mount == 2)
            Player[A].Location.Height = 128;
    }
}

void SetRes()
{
    int sW = 800;
    int sH = 600;
    std::string mainIni = AppPath + "main.ini";
    IniProcessing config(mainIni);
    config.beginGroup("main");
    config.read("ScreenW", sW, 800);
    config.read("ScreenH", sH, 600);
    config.endGroup();

//    GetCurrentRes(); // Dummy, useless
    resChanged = true;
    ChangeRes(sW, sH, 16, 60); // 800x600 pixels, 16 bit Color, 60Hz
    showCursor(0);
}
