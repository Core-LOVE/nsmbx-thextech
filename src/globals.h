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

#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>
#include <vector>
#include <cstdlib>
#include <SDL2/SDL.h>

#include "frm_main.h"
#include "std_picture.h"
#include "gfx.h"

#include "location.h"
#include "range_arr.hpp"
#include "rand.h"
#include "floats.h"

#include "global_constants.h"
#include "controls.h"

//Option Explicit
//Public Declare Sub Sleep Lib "kernel32" (ByVal dwMilliseconds As Long)
//Public Declare Function BitBlt Lib "gdi32" (ByVal hDestDC As Long, ByVal X As Long, ByVal Y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hSrcDC As Long, ByVal xSrc As Long, ByVal ySrc As Long, ByVal dwRop As Long) As Long
//Public Declare Function StretchBlt Lib "gdi32" (ByVal hdc As Long, ByVal X As Long, ByVal Y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hSrcDC As Long, ByVal xSrc As Long, ByVal ySrc As Long, ByVal nSrcWidth As Long, ByVal nSrcHeight As Long, ByVal dwRop As Long) As Long
//Public Declare Function CreateCompatibleBitmap Lib "gdi32" (ByVal hdc As Long, ByVal nWidth As Long, ByVal nHeight As Long) As Long
//Public Declare Function CreateCompatibleDC Lib "gdi32" (ByVal hdc As Long) As Long
//Public Declare Function GetDC Lib "user32" (ByVal hWnd As Long) As Long
//Public Declare Function SelectObject Lib "gdi32" (ByVal hdc As Long, ByVal hObject As Long) As Long
//Public Declare Function DeleteObject Lib "gdi32" (ByVal hObject As Long) As Long
//Public Declare Function DeleteDC Lib "gdi32" (ByVal hdc As Long) As Long
//Public Declare Function GetKeyState Lib "user32" (ByVal nVirtKey As Long) As Integer
//'Public Declare Function mciSendString Lib "winmm.dll" Alias "mciSendStringA" (ByVal lpstrCommand As String, ByVal lpstrReturnString As String, ByVal uReturnLength As Integer, ByVal hwndCallback As Integer) As Integer
//Public Declare Function SetCursorPos Lib "user32" (ByVal X As Long, ByVal Y As Long) As Long
//Public Declare Function SetWindowPos Lib "user32" (ByVal hWnd As Long, ByVal hWndInsertAfter As Long, ByVal X As Long, ByVal Y As Long, ByVal cx As Long, ByVal cy As Long, ByVal wFlags As Long) As Long
//Private Declare Function GetSystemDirectory Lib "kernel32" Alias "GetSystemDirectoryA" (ByVal lpBuffer As String, ByVal nSize As Long) As Long
//Public Declare Function GetDesktopWindow Lib "user32.dll" () As Long
//Public Declare Function GetWindowDC Lib "user32.dll" (ByVal hWnd As Long) As Long
//Declare Function GetActiveWindow Lib "user32" () As Integer
//Public Declare Function GetTickCount& Lib "kernel32" ()
//Public OnlineDisc As Boolean

#define UNUSED(x) (void)x

//! Main window
extern FrmMain frmMain;
//! Container of "hardcoded" (no more) graphics
extern GFX_t GFX;

//! Showing that game is works. It gets false when closing a window or exiting a game by menu. To mean that application must be closed.
extern bool GameIsActive;
//! Path to game resources assets (by default it's ~/.PGE_Project/thextech/)
extern std::string AppPath;

extern void ReadMainIni();
/**
 * @brief Process internal events (mouse, keyboard, joysticks, window's update, OS communications, etc.)
 */
extern void DoEvents();

/**
 *  \brief Toggle whether or not the cursor is shown.
 *
 *  \param toggle 1 to show the cursor, 0 to hide it, -1 to query the current
 *                state.
 *
 *  \return 1 if the cursor is shown, or 0 if the cursor is hidden.
 */
extern int showCursor(int show);

extern Uint8 getKeyState(SDL_Scancode key);
extern Uint8 getKeyStateI(int key);

//Public Const KEY_PRESSED As Integer = &H1000    'For control information
const int KEY_PRESSED = 1;

/**
 * @brief Get name of key from a keycode
 * @param key Key code
 * @return Human-readable key name
 */
const char *getKeyName(int key);

struct KM_Key;
std::string getJoyKeyName(const KM_Key &key);

/**
 * @brief Rounding function that works same as in VB6
 * @param x Floating point value to round
 * @return rounded result
 */
extern int vb6Round(double x);

/**
 * @brief Rounding function that works same as in VB6
 * @param x Floating point value to round
 * @param decimals Round to a specific number of decimals
 * @return rounded result
 */
extern double vb6Round(double x, int decimals);

//'Saved Events
//Public numSavedEvents As Integer
extern int numSavedEvents;
//Public SavedEvents(1 To MaxSavedEvents) As String
extern RangeArr<std::string, 1, MaxSavedEvents> SavedEvents;
//Public BlockSwitch(1 To 4) As Boolean
extern RangeArrI<bool, 1, 4, false> BlockSwitch;
//'Public PowerUpUnlock(2 To 7) As Boolean
extern RangeArrI<bool, 2, 7, false> PowerUpUnlock;

//Public Const SWP_SHOWWINDOW = &H40
//const int SWP_SHOWWINDOW = 0x40;
//Public Const SWP_NOMOVE As Long = 2
//const long SWP_NOMOVE = 2;
//Public Const SWP_NOSIZE As Long = 1
//const long SWP_NOSIZE = 1;
//Public Const FLAGS = SWP_NOMOVE Or SWP_NOSIZE
//const long FLAGS = SWP_NOMOVE | SWP_NOSIZE;
//Public Const HWND_TOPMOST As Long = -1
//const long HWND_TOPMOST = -1;
//Public Const HWND_NOTOPMOST As Long = -2
//const long HWND_NOTOPMOST  = -2;
//Public myBackBuffer As Long 'Backbuffer
extern long myBackBuffer;
//Public myBufferBMP As Long 'Backbuffer
extern long myBufferBMP;
//Public AllCharBlock As Integer
extern int AllCharBlock;
//Public Const KEY_TOGGLED As Integer = &H1   'For control information
//const int KEY_TOGGLED = 0x01;
//Public LocalNick As String  'Online Nickname
//Public LocalCursor As Integer  'Online Cursor color
//Public ClientPassword As String  'Password client is connecting with
//Public ServerPassword As String  'Password game server wants the client to use
//Public ServerClear As Boolean
//Public StartMenu As Boolean
extern bool StartMenu;
//Public BlockFlash As Integer
extern int BlockFlash;
//Public ScrollRelease As Boolean
extern bool ScrollRelease;
//Public TakeScreen As Boolean
extern bool TakeScreen;
//Public LB As String  ' Line Break
extern std::string LB;
//Public EoT As String  ' End of Transmission for WINSOCK
extern std::string EoT;

//Public Type Controls 'Controls for the player
//moved into "controls.h"

//Public Type nPlayer  'online player type
//    Controls As Controls  'online players controls
//    Cursor As Integer
//    IsMe As Boolean  'True if this player is the local player
//    Nick As String
//    Active As Boolean  'True if a player is using this variable
//    ECurserX As Double  'Cursor X position
//    ECurserY As Double   'Cursor Y position
//End Type


//Public Type nPlay  'Netplay data type
//    Allow As Boolean
//    Mode As Integer  'Server or client
//    ServerIP As String 'Server's IP
//    ServerCon As Boolean 'Server is connected
//    ServerStr As String
//    ServerLocked As Boolean
//    ServerLoad1 As Double
//    ServerLoad As Boolean
//    ClientLocked(0 To 15) As Boolean
//    ClientIP(0 To 15) As String
//    ClientCon(0 To 15) As Boolean
//    ClientName(0 To 15) As String
//    ClientStr(0 To 15) As String
//    ClientRelease(0 To 15) As Integer
//    ClientPassword(0 To 15) As Boolean
//    ClientLoad1(0 To 15) As Double
//    Online As Boolean 'online or local
//    MySlot As Integer
//    MyControls As Controls
//    Player(0 To 15) As nPlayer
//    PlayerWaitCount As Integer
//    NPCWaitCount As Single
//End Type

//Public Type Location    'Holds location information for objects
//    X As Double
//    Y As Double
//    Height As Double
//    Width As Double
//    SpeedX As Double
//    SpeedY As Double
//End Type

//Public Type EditorControls      'Controls for the editor
struct EditorControls_t
{
//    Up As Boolean
    bool Up = false;
//    Down As Boolean
    bool Down = false;
//    Left As Boolean
    bool Left = false;
//    Right As Boolean
    bool Right = false;
//    Mouse1 As Boolean
    bool Mouse1 = false;
//End Type
};

//Public Type conKeyboard  'Input settings for the keyboard
struct ConKeyboard_t
{
//    Up As Integer
    int Up = 0;
//    Down As Integer
    int Down = 0;
//    Left As Integer
    int Left = 0;
//    Right As Integer
    int Right = 0;
//    Jump As Integer
    int Jump = 0;
//    AltJump As Integer
    int AltJump = 0;
//    Run As Integer
    int Run = 0;
//    AltRun As Integer
    int AltRun = 0;
//    Drop As Integer
    int Drop = 0;
//    Start As Integer
    int Start = 0;
//End Type
};

struct KM_Key
{
    int val = -1;
    int id = -1;
    int type = -1;
};

//Public Type conJoystick   'Input settings for the joystick
struct ConJoystick_t
{
// EXTRA
    enum CtrlTypes
    {
        NoControl=-1,
        JoyAxis=0,
        JoyBallX,
        JoyBallY,
        JoyHat,
        JoyButton
    };
    KM_Key Up;
    KM_Key Down;
    KM_Key Left;
    KM_Key Right;

//    Jump As Integer
    KM_Key Jump;
//    Run As Integer
    KM_Key Run;
//    Drop As Integer
    KM_Key Drop;
//    Start As Integer
    KM_Key Start;
//    AltJump As Integer
    KM_Key AltJump;
//    AltRun As Integer
    KM_Key AltRun;
//End Type
};

//Public conKeyboard(1 To 2) As conKeyboard  'player 1 and 2's controls
extern RangeArr<ConKeyboard_t, 1, 2> conKeyboard;

//Public conJoystick(1 To 2) As conJoystick
extern RangeArr<ConJoystick_t, 1, 2> conJoystick;

//Public useJoystick(1 To 2) As Integer
extern RangeArrI<int, 1, 2, 0> useJoystick;

//Public Type NPC 'The NPC Type
struct NPC_t
{
//    AttLayer As String
    std::string AttLayer;
//    Quicksand As Integer
    int Quicksand = 0;
//    RespawnDelay As Integeri
    int RespawnDelay = 0;
//    Bouce As Boolean
    bool Bouce = false;
//    Pinched1 As Integer  'getting smashed by a block
    int Pinched1 = 0;
//    Pinched2 As Integer
    int Pinched2 = 0;
//    Pinched3 As Integer
    int Pinched3 = 0;
//    Pinched4 As Integer
    int Pinched4 = 0;
//    MovingPinched As Integer 'required to be smashed
    int MovingPinched = 0;
//    NetTimeout As Integer 'for online
    int NetTimeout = 0;
//    RealSpeedX As Single 'the real speed of the NPC
    float RealSpeedX = 0.0f;
//    Wet As Integer ' greater then 0 of the NPC is in water
    int Wet = 0;
//    Settings As Integer
    int Settings = 0;
//    NoLavaSplash As Boolean 'true for no lava splash
    bool NoLavaSplash = false;
//    Slope As Integer 'the block that the NPC is on a slope with
    int Slope = 0;
//    Multiplier As Integer 'for upping the points the player recieves
    int Multiplier = 0;
//    TailCD As Integer 'if greater then 0 the player can't hit with it's tail
    int TailCD = 0;
//    Shadow As Boolean 'if true turn the NPC black and allow it to pass through walls.  only used for a cheat code
    bool Shadow = false;
//    TriggerActivate As String 'for events - triggers when NPC gets activated
    std::string TriggerActivate;
//    TriggerDeath As String 'triggers when NPC dies
    std::string TriggerDeath;
//    TriggerTalk As String 'triggers when you talk to the NPC
    std::string TriggerTalk;
//    TriggerLast As String 'trigger when this is the last NPC in a layer to die
    std::string TriggerLast;
//    Layer As String 'the layer name that the NPC is in
    std::string Layer;
//    Hidden As Boolean 'if the layer is hidden or not
    bool Hidden = false;
//    Legacy As Boolean 'Legacy Boss
    bool Legacy = false;
//    Chat As Boolean 'for talking to the NPC
    bool Chat = false;
//    Inert As Boolean 'the friendly toggle. makes the NPC not do anything
    bool Inert = false;
//    Stuck As Boolean 'the 'don't move' toggle. forces the NPC not to move
    bool Stuck = false;
//    DefaultStuck As Boolean
    bool DefaultStuck = false;
//    Text As String 'the text that is displayed when you talk to the NPC
    std::string Text;
//    oldAddBelt As Single
    float oldAddBelt = 0.0f;
//    PinchCount As Integer 'obsolete
    int PinchCount = 0;
//    Pinched As Boolean 'obsolete
    bool Pinched = false;
//    PinchedDirection As Integer 'obsolete
    int PinchedDirection = 0;
//    BeltSpeed As Single 'The speed of the object this NPC is standing on
    float BeltSpeed = 0.0f;
//    standingOnPlayer As Integer 'If this NPC is standing on a player in the clown car
    int standingOnPlayer = 0;
//    standingOnPlayerY As Integer
    int standingOnPlayerY = 0;
//    Generator As Boolean 'for spawning new NPCs
    bool Generator = false;
//    GeneratorTimeMax As Single
    float GeneratorTimeMax = 0.0f;
//    GeneratorTime As Single
    float GeneratorTime = 0.0f;
//    GeneratorDirection As Integer
    int GeneratorDirection = 0;
//    GeneratorEffect As Integer
    int GeneratorEffect = 0;
//    GeneratorActive As Boolean
    bool GeneratorActive = false;
//    playerTemp As Boolean
    bool playerTemp = false;
//    Location As Location 'collsion detection information
    Location_t Location;
//'the default values are used when De-Activating an NPC when it goes on screen
//    DefaultLocation As Location
    Location_t DefaultLocation;
//    DefaultDirection As Single
    float DefaultDirection = 0.0f;
//    DefaultType As Integer
    int DefaultType = 0;
//    DefaultSpecial As Integer
    int DefaultSpecial = 0;
//    DefaultSpecial2 As Integer
    int DefaultSpecial2 = 0;
    int DefaultSpecial3 = 0;
//    Type As Integer 'Defines what NPC this is.  1 for goomba, 2 for red goomba, etc.
    int Type = 0;
//    Frame As Integer 'The graphic to be shown
    int Frame = 0;
//    FrameCount As Single 'The counter for incrementing the frames
    float FrameCount = 0.0f;
//    Direction As Single 'The direction the NPC is walking
    float Direction = 0.0f;
//'Secial - misc variables used for NPC AI
//    Special As Double
    double Special = 0.0;
//    Special2 As Double
    double Special2 = 0.0;
//    Special3 As Double
    double Special3 = 0.0;
//    Special4 As Double
    double Special4 = 0.0;
//    Special5 As Double
    double Special5 = 0.0;
//    Special6 As Double
    double Special6 = 0.0;
// EXTRA: Special7 As Double
    double Special7 = 0.0;
    double Special8 = 0.0;
    double Special9 = 0.0;
    double Special10 = 0.0;
//    TurnAround As Boolean 'if the NPC needs to turn around
    bool TurnAround = false;
//    Killed As Integer 'Flags the NPC to die a specific way.
    int Killed = 0;
//    Active As Boolean 'If on screen
    bool Active = false;
//    Reset(1 To 2) As Boolean 'If it can display the NPC
    RangeArrI<bool, 1, 2, false> Reset;
//    TimeLeft As Integer 'Time left before reset when not on screen
    int TimeLeft = 0;
//    HoldingPlayer As Integer 'Who is holding it
    int HoldingPlayer = 0;
//    CantHurt As Integer 'Won't hurt the player
    int CantHurt = 0;
//    CantHurtPlayer As Integer
    int CantHurtPlayer = 0;
//    BattleOwner As Integer 'Owner of the projectile
    int BattleOwner = 0;
//    WallDeath As Integer
    int WallDeath = 0;
//    Projectile As Boolean 'If the NPC is a projectile
    int Projectile = 0;
//    Effect As Integer 'For starting / stopping effects
    int Effect = 0;
//    Effect2 As Double
    double Effect2 = 0.0; // When Effect 4, Used to store a destination position, must be in double!
//    Effect3 As Integer
    int Effect3 = 0;
//    Section As Integer 'what section of the level the NPC is in
    int Section = 0;
//    Damage As Single
    float Damage = 0.0f;
//    JustActivated As Integer 'The player that activated the NPC
    int JustActivated = 0;
//    Block As Integer 'Used when a P-Switch turns a block into a coint
    int Block = 0;
//    tempBlock As Integer
    int tempBlock = 0;
//    onWall As Boolean
    bool onWall = false;
//    TurnBackWipe As Boolean
    bool TurnBackWipe = false;
//    Immune As Integer 'time that the NPC is immune
    int Immune = 0;
    int BlockSpot = 0;
    bool IsGrabbable = false;
    bool Behind = false;
//End Type
};

//Public Type Player              'The player data type.
struct Player_t
{
    int StarManTimer = 0;
    float Red = 1.0f;
    float Green = 1.0f;
    float Blue = 1.0f;
//    DoubleJump As Boolean
    bool DoubleJump = false;
//    FlySparks As Boolean
    bool FlySparks = false;
//    Driving As Boolean
    bool Driving = false;
//    Quicksand As Integer
    int Quicksand = 0;
//    Bombs As Integer
    int Bombs = 0;
//    Slippy As Boolean
    bool Slippy = false;
//    Fairy As Boolean
    bool Fairy = false;
//    FairyCD As Integer
    int FairyCD = 0;
//    FairyTime As Integer
    int FairyTime = 0;
//    HasKey As Boolean
    bool HasKey = false;
//    SwordPoke As Integer
    int SwordPoke = 0;
//    Hearts As Integer
    int Hearts = 0;
//    CanFloat As Boolean
    bool CanFloat = false;
//    FloatRelease As Boolean
    bool FloatRelease = false;
//    FloatTime As Integer
    int FloatTime = 0;
//    FloatSpeed As Single
    float FloatSpeed = 0.0f;
//    FloatDir As Integer
    int FloatDir = 0;
//    GrabTime As Integer 'how long the player has been trying to grab an npc from above
    int GrabTime = 0;
//    GrabSpeed As Single
    float GrabSpeed = 0.0f;
//    VineNPC As Double 'the NPC that the player is climbing
    double VineNPC = 0.0;
//  EXTRA:  Fence BGO
    double VineBGO = 0.0;
//    Wet As Integer 'weather or not the player is under water
    int Wet = 0;
//    WetFrame As Boolean 'true if the play should be swimming
    bool WetFrame = false;
//    SwimCount As Integer 'cool down between swim strokes
    int SwimCount = 0;
//    NoGravity As Integer
    int NoGravity = 0;
//    Slide As Boolean 'true if the player is sliding
    bool Slide = false;
//    SlideKill As Boolean 'true if the player is sliding fast enough to kill an NPC
    bool SlideKill = false;
//    Vine As Integer 'greater then 0 if the player is climbing
    int Vine = 0;
//    NoShellKick As Integer 'dont kick a shell
    int NoShellKick = 0;
//    ShellSurf As Boolean 'true if surfing a shell
    bool ShellSurf = false;
//    StateNPC As Integer
    int StateNPC = 0;
//    Slope As Integer 'the block that the player is standing on when on a slope
    int Slope = 0;
//    Stoned As Boolean 'true of a statue form (tanooki suit)
    bool Stoned = false;
//    StonedCD As Integer 'delay before going back in to stone form
    int StonedCD = 0;
//    StonedTime As Integer 'how long the player can remain as a statue
    int StonedTime = 0;
//    SpinJump As Boolean 'true if spin jumping
    bool SpinJump = false;
//    SpinFrame As Integer 'frame for spinning
    int SpinFrame = 0;
    int SpinFrame2 = 0;
//    SpinFireDir As Integer 'for shooting fireballs while spin jumping
    int SpinFireDir = 0;
//    Multiplier As Integer 'for score increase for multiple hops
    int Multiplier = 0;
//    SlideCounter As Integer 'for creating the dust effect when sliding
    int SlideCounter = 0;
//    ShowWarp As Integer
    int ShowWarp = 0;
//    GroundPound As Boolean 'for purple yoshi pound
    bool GroundPound = false;
//    GroundPound2 As Boolean 'for purple yoshi pound
    bool GroundPound2 = false;
//    CanPound As Boolean 'for purple yoshi pound
    bool CanPound = false;
//    ForceHold As Integer  'force the player to hold an item for a specific amount of time
    int ForceHold = 0;
//'yoshi powers
//    YoshiYellow As Boolean
    bool YoshiYellow = false;
//    YoshiBlue As Boolean
    bool YoshiBlue = false;
//    YoshiRed As Boolean
    bool YoshiRed = false;
//    YoshiWingsFrame As Integer
    int YoshiWingsFrame = 0;
//    YoshiWingsFrameCount As Integer
    int YoshiWingsFrameCount = 0;
//'yoshi graphic display
//    YoshiTX As Integer
    int YoshiTX = 0;
//    YoshiTY As Integer
    int YoshiTY = 0;
//    YoshiTFrame As Integer
    int YoshiTFrame = 0;
//    YoshiTFrameCount As Integer
    int YoshiTFrameCount = 0;
//    YoshiBX As Integer
    int YoshiBX = 0;
//    YoshiBY As Integer
    int YoshiBY = 0;
//    YoshiBFrame As Integer
    int YoshiBFrame = 0;
//    YoshiBFrameCount As Integer
    int YoshiBFrameCount = 0;
//    YoshiTongue As Location
    Location_t YoshiTongue;
//    YoshiTongueX As Single
    float YoshiTongueX = 0.0f;
//    YoshiTongueLength As Integer 'length of yoshi's tongue
    int YoshiTongueLength = 0;
//    YoshiTonugeBool As Boolean
    bool YoshiTonugeBool = false;
//    YoshiNPC As Integer 'the NPC that is in yoshi's mouth
    int YoshiNPC = 0;
//    YoshiPlayer As Integer 'the player that is in yoshi's mouth
    int YoshiPlayer = 0;
    int YoshiSeeds = 0;
    int YoshiMelonType = 0;
    int YoshiMelonTimer = 0;
//    Dismount As Integer 'delay before you can remount
    int Dismount = 0;
//    NoPlayerCol As Integer
    int NoPlayerCol = 0;
//    Location As Location 'collision detection info
    Location_t Location;
//    Character As Integer 'luigi or mario
    int Character = 0;
//    Controls As Controls 'players controls
    Controls_t Controls;
//    Direction As Integer 'the way the player is facing
    int Direction = 0;
//    Mount As Integer '1 for boot, 2 for clown car, 3 for yoshi
    int Mount = 0;
//    MountType As Integer 'for different types of mounts. blue yoshi, red yoshi, etc
    int MountType = 0;
//    MountSpecial As Integer
    int MountSpecial = 0;
//    MountOffsetY As Integer
    int MountOffsetY = 0;
//    MountFrame As Integer 'GFX frame for the player's mount
    int MountFrame = 0;
//    State As Integer '1 for small mario, 2 for super, 3 for fire, 4 for racoon, 5 for tanooki, 6 for hammer
    int State = 0;
//    Frame As Integer
    int Frame = 0;
//    FrameCount As Single
    int FrameCount = 0;
//    Jump As Integer 'how long the player can jump for
    int Jump = 0;
//    CanJump As Boolean 'true if the player can jump
    bool CanJump = false;
//    CanAltJump As Boolean 'true if the player can alt jump
    bool CanAltJump = false;
//    Effect As Integer 'for various effects like shrinking/growing/warping
    int Effect = 0;
//    Effect2 As Double 'counter for the effects
    double Effect2 = 0.0;
//    DuckRelease As Boolean
    bool DuckRelease = false;
//    Duck As Boolean 'true if ducking
    bool Duck = false;
//    DropRelease As Boolean
    bool DropRelease = false;
//    StandUp As Boolean 'aid with collision detection after ducking
    bool StandUp = false;
//    StandUp2 As Boolean
    bool StandUp2 = false;
//    Bumped As Boolean 'true if hit by another player
    bool Bumped = false;
//    Bumped2 As Single
    float Bumped2 = 0.0f;
//    Dead As Boolean 'true if dead
    bool Dead = false;
//    TimeToLive As Integer 'for returning to the other play after dying
    int TimeToLive = 0;
//    Immune As Integer 'greater then 0 if immune, this is a counter
    int Immune = 0;
//    Immune2 As Boolean 'makes the player blink
    bool Immune2 = false;
//    ForceHitSpot3 As Boolean 'force hitspot 3 for collision detection
    bool ForceHitSpot3 = false;
//'for getting smashed by a block
//    Pinched1 As Integer
    int Pinched1 = 0;
//    Pinched2 As Integer
    int Pinched2 = 0;
//    Pinched3 As Integer
    int Pinched3 = 0;
//    Pinched4 As Integer
    int Pinched4 = 0;
//    NPCPinched As Integer 'must be > 0 for the player to get crushed
    int NPCPinched = 0;
//    m2Speed As Single
    float m2Speed = 0.0f;
//    HoldingNPC As Integer 'What NPC is being held
    int HoldingNPC = 0;
//    CanGrabNPCs As Boolean 'If the player can grab NPCs
    bool CanGrabNPCs = false;
//    HeldBonus As Integer 'the NPC that is in the player's container
    int HeldBonus = 0;
    int HeldBonusSpecial = 0;

//    Section As Integer 'What section of the level the player is in
    int Section = 0;
//    WarpCD As Integer 'delay before allowing the player to warp again
    int WarpCD = 0;
//    Warp As Integer 'the warp the player is using
    int Warp = 0;
//    FireBallCD As Integer 'How long the player has to wait before he can shoot again
    int FireBallCD = 0;
//    FireBallCD2 As Integer 'How long the player has to wait before he can shoot again
    int FireBallCD2 = 0;
//    TailCount As Integer 'Used for the tail swipe
    int TailCount = 0;
//    RunCount As Single 'To find how long the player has ran for
    float RunCount = 0.0f;
//    CanFly As Boolean 'If the player can fly
    bool CanFly = false;
//    CanFly2 As Boolean
    bool CanFly2 = false;
    bool CanFly3 = false;
//    FlyCount As Integer 'length of time the player can fly
    int FlyCount = 0;
//    RunRelease As Boolean 'The player let go of run and pressed again
    bool RunRelease = false;
//    JumpRelease As Boolean 'The player let go of run and pressed again
    bool JumpRelease = false;
//    StandingOnNPC As Integer 'The NPC the player is standing on
    int StandingOnNPC = 0;
//    StandingOnTempNPC As Integer 'The NPC the player is standing on
    int StandingOnTempNPC = 0;
//    UnStart As Boolean 'Player let go of the start button
    bool UnStart = false;
//    mountBump As Single 'Player hit something while in a mount
    float mountBump = 0.0f;
//    SpeedFixY As Single
    float SpeedFixY = 0.0f;
//    Flutter As Integer 'Yoshi's Flutter
    int Flutter = 0;

    int PropellerJump = 0;
//End Type
};

//Public Type Background  'Background objects
struct Background_t
{
//    Layer As String
    std::string Layer;
//    Hidden As Boolean
    bool Hidden = false;
//    Type As Integer
    int Type = 0;
//    Location As Location
    Location_t Location;
//EXTRA: make a custom sorting priority
    int SortPriority = -1;
//EXTRA: sub-priority
    double zOffset = 0.0;
//EXTRA: UID
    int uid = 0;
//End Type
};

//Public Type Water
struct Water_t
{
//    Layer As String
    std::string Layer;
//    Hidden As Boolean
    bool Hidden = false;
//    Buoy As Single 'not used
    float Buoy = 0.0f;
//    Quicksand As Boolean
    bool Quicksand = false;
//    Location As Location
    Location_t Location;
//End Type
};

struct BackgroundDefaults_t
{
    RangeArrI<bool, 0, maxBackgroundType, false> BackgroundFreeze;
    RangeArrI<bool, 0, maxBackgroundType, false> BackgroundFence;
    RangeArrI<bool, 0, maxBackgroundType, false> BackgroundNPCFence;
    RangeArrI<bool, 0, maxBackgroundType, false> Foreground;
    RangeArrI<bool, 0, maxBackgroundType, false> BackgroundWater;
    RangeArrI<int, 1, maxBackgroundType, 0> BackgroundWidth;
    RangeArrI<int, 1, maxBackgroundType, 0> BackgroundHeight;
    RangeArrI<int, 0, maxBackgroundType, 1> BackgroundFrameAmount;
    RangeArrI<int, 0, maxBackgroundType, 8> BackgroundFrameSpeed;
    RangeArrI<int, 0, maxBackgroundType, 8> BackgroundDoorEffect;
};

extern BackgroundDefaults_t BackgroundDefaults;

struct BlockDefaults_t
{
    RangeArrI<bool, 0, maxBlockType, false> BlockIsSizable;
    RangeArrI<bool, 0, maxBlockType, false> BlockPlayerNoClipping;
    RangeArrI<int, 0, maxBlockType, 0> BlockSlope;
    RangeArrI<int, 0, maxBlockType, 0> BlockSlope2;
    RangeArrI<int, 0, maxBlockType, 0> BlockWidth;
    RangeArrI<int, 0, maxBlockType, 0> BlockHeight;
    RangeArrI<bool, 0, maxBlockType, false> BlockOnlyHitspot1;
    RangeArrI<bool, 0, maxBlockType, false> BlockKills;
    RangeArrI<bool, 0, maxBlockType, false> BlockKills2;
    RangeArrI<bool, 0, maxBlockType, false> BlockKills3;
    RangeArrI<bool, 0, maxBlockType, false> BlockHurts;
    RangeArrI<bool, 0, maxBlockType, false> BlockPSwitch;
    RangeArrI<bool, 0, maxBlockType, false> BlockNoClipping;
    RangeArrI<bool, 0, maxBlockType, false> BlockNPCNoClipping;
    RangeArrI<bool, 0, maxBlockType, false> BlockBrick;
    RangeArrI<int, 0, maxBlockType, 0> BlockBrickEffect;
    RangeArrI<bool, 0, maxBlockType, false> BlockBouncy;
    RangeArrI<bool, 0, maxBlockType, false> BlockBouncyHorizontal;
    RangeArrI<bool, 0, maxBlockType, false> BlockDiggable;
    RangeArrI<bool, 0, maxBlockType, false> BlockHitable;
    RangeArrI<int, 0, maxBlockType, 2> BlockHitTransform;
    RangeArrI<int, 0, maxBlockType, 1> BlockFrameCount;
    RangeArrI<int, 0, maxBlockType, 8> BlockFrameSpeed;
    RangeArrI<bool, 0, maxBlockType, false> BlockConnecting;
    RangeArrI<bool, 0, maxBlockType, false> BlockExplodable;
    RangeArrI<bool, 0, maxBlockType, false> BlockHammer;
    RangeArrI<bool, 0, maxBlockType, false> BlockNoIceBrick;
};

extern BlockDefaults_t BlockDefaults;


struct TileDefaults_t
{
    RangeArrI<int, 1, maxTileType, 32> TileWidth;
    RangeArrI<int, 1, maxTileType, 32> TileHeight;
    RangeArrI<int, 1, maxTileType, 1> TileFrameCount;
    RangeArrI<int, 1, maxTileType, 14> TileFrameSpeed;
    RangeArrI<bool, 1, maxTileType, false> TileConnecting;
    RangeArrI<int, 1, maxTileType, 14> TileConnect;
};

extern TileDefaults_t TileDefaults;

struct PathDefaults_t
{
    RangeArrI<int, 1, maxPathType, 32> PathWidth;
    RangeArrI<int, 1, maxPathType, 32> PathHeight;
    RangeArrI<int, 1, maxPathType, 1> PathFrameCount;
    RangeArrI<int, 1, maxPathType, 14> PathFrameSpeed;
    RangeArrI<int, 1, maxPathType, 2> PathPlayerSpeed;
};

extern PathDefaults_t PathDefaults;

struct LevelDefaults_t
{
    RangeArrI<int, 1, maxLevelType, 32> LevelWidth;
    RangeArrI<int, 1, maxLevelType, 32> LevelHeight;
    RangeArrI<int, 1, maxLevelType, 1> LevelFrameCount;
    RangeArrI<int, 1, maxLevelType, 12> LevelFrameSpeed;
};

extern LevelDefaults_t LevelDefaults;

struct SceneDefaults_t
{
    RangeArrI<int, 1, maxSceneType, 32> SceneWidth;
    RangeArrI<int, 1, maxSceneType, 32> SceneHeight;
    RangeArrI<int, 1, maxSceneType, 32> SceneFrameCount;
    RangeArrI<int, 1, maxSceneType, 32> SceneFrameSpeed;
    RangeArrI<int, 0, maxSceneType, 0> SceneMovement;
    RangeArrI<int, 1, maxSceneType, 1> SceneMovementSpeed;
};

extern SceneDefaults_t SceneDefaults;
//Public Type Block   'Blocks
struct Block_t
{
    int Frame = 0;
    int FrameCount = 0;
//    Slippy As Boolean
    bool Slippy = false;
//    RespawnDelay As Integer
    int RespawnDelay = 0;
//    RapidHit As Integer
    int RapidHit = 0;
//    DefaultType As Integer
    int DefaultType = 0;
//    DefaultSpecial As Integer
    int DefaultSpecial = 0;
//'for event triggers
//    TriggerHit As String
    std::string TriggerHit;
//    TriggerDeath As String
    std::string TriggerDeath;
//    TriggerLast As String
    std::string TriggerLast;
//    Layer As String
    std::string Layer;
//    Hidden As Boolean
    bool Hidden = false;
//    Type As Integer 'the block's type
    int Type = 0;
//    Location As Location
    Location_t Location;
//    Special As Integer 'what is in the block?
    int Special = 0;
    int Special2 = 0;
    int Special3 = 0;
    int Special4 = 0;
    int Special5 = 0;
//'for the shake effect after hitting ablock
//    ShakeY As Integer
    int ShakeY = 0;
//    ShakeY2 As Integer
    int ShakeY2 = 0;
//    ShakeY3 As Integer
    int ShakeY3 = 0;

    int ShakeX = 0;
    int ShakeX2 = 0;
    int ShakeX3 = 0;
//    Kill As Boolean 'if true the game will destroy the block
    bool Kill = false;
//    Invis As Boolean 'for invisible blocks
    bool Invis = false;
//    NPC As Integer 'when a coin is turned into a block after the p switch is hit
    int NPC = 0;
//    IsPlayer As Integer 'for the clown car
    int IsPlayer = 0;
//    IsNPC As Integer 'the type of NPC the block is
    int IsNPC = 0;
//    standingOnPlayerY As Integer 'when standing on a player in the clown car
    int standingOnPlayerY = 0;
//    noProjClipping As Boolean
    bool noProjClipping = false;
// EXTRA: Indicate the fact that block was resized by a hit
    bool wasShrinkResized = false;
//    IsReally As Integer 'the NPC that is this block
    int IsReally = 0;
//End Type
};

extern RangeArrI<int, 0, maxWeathers, 0> WeatherWidth;
extern RangeArrI<int, 0, maxWeathers, 0> WeatherHeight;
extern RangeArrI<int, 0, maxWeathers, 0> WeatherLife;
extern RangeArrI<int, 0, maxWeathers, 0> WeatherFrameAmount;
extern RangeArrI<int, 0, maxWeathers, 0> WeatherFrameSpeed;
extern RangeArrI<int, 0, maxWeathers, 0> WeatherOpacity;

struct Weather_t
{
    Location_t Location;
    int Section = 0;
    int Type = 0;
    int Frame = 0;
    int FrameCount = 0;
    int LifeTimer = 0;
    bool Shadow = false;
};

struct WeatherDefaults_t
{
    RangeArrI<int, 0, maxWeathers, 0> WeatherWidth;
    RangeArrI<int, 0, maxWeathers, 0> WeatherHeight;
    RangeArrI<int, 0, maxWeathers, 0> WeatherLife;
    RangeArrI<int, 0, maxWeathers, 0> WeatherFrameAmount;
    RangeArrI<int, 0, maxWeathers, 0> WeatherFrameSpeed;
    RangeArrI<int, 0, maxWeathers, 0> WeatherOpacity;
};
extern WeatherDefaults_t WeatherDefaults;

//Public Type Effect  'Special effects
struct Effect_t
{
    float Red = 1.0f;
    float Green = 1.0f;
    float Blue = 1.0f;
//    Type As Integer
    int Type = 0;
//    Location As Location
    Location_t Location;
//    Frame As Integer
    int Frame = 0;
//    FrameCount As Single
    int FrameCount = 0;
//    Life As Integer 'timer before the effect disappears
    int Life = 0;
//    NewNpc As Integer 'when an effect should create and NPC, such as Yoshi
    int NewNpc = 0;
//    Shadow As Boolean 'for a black effect set to true
    bool Shadow = false;
//    Special As Double 'for special behavior
    double Special = 0;
//End Type
};

//Public Type vScreen 'Screen controls
struct vScreen_t
{
//    Left As Double
    double Left = 0.0;
//    Top As Double
    double Top = 0.0;
//    Width As Double
    double Width = 0.0;
//    Height As Double
    double Height = 0.0;
//    Visible As Boolean
    bool Visible = false;
//    tempX As Double
    double tempX = 0.0;
//    TempY As Double
    double TempY = 0.0;
//    TempDelay As Integer
    int TempDelay = 0;
//End Type
};

//Public Type WorldLevel 'the type for levels on the world map
struct WorldLevel_t
{
//    Location As Location
    Location_t Location;
//    Type As Integer
    int Type = 0;
//    FileName As String 'level's file
    std::string FileName;
//    LevelExit(1 To 4) As Integer ' For the direction each type of exit opens the path
    RangeArrI<int, 1, 4, 0> LevelExit;
//    Active As Boolean
    bool Active = false;
//    LevelName As String 'The name of the level
    std::string LevelName;
//    StartWarp As Integer 'If the level should start with a player exiting a warp
    int StartWarp = 0;
//    WarpX As Double 'for warping to another location on the world map
    double WarpX = 0.0;
//    WarpY As Double
    double WarpY = 0.0;
//    Path As Boolean 'for drawing a small path background
    bool Path = false;
//    Path2 As Boolean 'big path background
    bool Path2 = false;
//    Start As Boolean 'true if the game starts here
    bool Start = false;
//    Visible As Boolean 'true if it should be shown on the map
    bool Visible = false;
    std::string Layer;
    bool Hidden = false;
//End Type
};

//Public Type Warp 'warps such as pipes and doors
struct Warp_t
{
//    Locked As Boolean 'requires a key NPC
    bool Locked = false;
//    WarpNPC As Boolean 'allows NPC through the warp
    bool WarpNPC = false;
//    NoYoshi As Boolean 'don't allow yoshi
    bool NoYoshi = false;
//    Layer As String 'the name of the layer
    std::string Layer;
//    Hidden As Boolean 'if the layer is hidden
    bool Hidden = false;
//    PlacedEnt As Boolean 'for the editor, flags the entranced as placed
    bool PlacedEnt = false;
//    PlacedExit As Boolean
    bool PlacedExit = false;
//    Stars As Integer 'number of stars required to enter
    int Stars = 0;
//    Entrance As Location 'location of warp entrance
    Location_t Entrance;
//    Exit As Location 'location of warp exit
    Location_t Exit;
//    Effect As Integer 'style of warp. door/
    int Effect = 0;
//    level As String 'filename of the level it should warp to
    std::string level;
//    LevelWarp As Integer
    int LevelWarp = 0;
//    LevelEnt As Boolean 'this warp can't be used if set to true (this is for level entrances)
    bool LevelEnt = false;
//    Direction As Integer 'direction of the entrance for pipe style warps
    int Direction = 0;
//    Direction2 As Integer 'direction of the exit
    int Direction2 = 0;
//    MapWarp As Boolean
    bool MapWarp = false;
//    MapX As Integer
    int MapX = 0;
//    MapY As Integer
    int MapY = 0;
//    curStars As Integer
    int curStars = 0;
//    maxStars As Integer
    int maxStars = 0;
//EXTRA:
    bool noPrintStars = false;
    bool noEntranceScene = false;
    bool cannonExit = false;
    bool bombExit = false;
    double cannonExitSpeed = 10.0;
    std::string eventEnter;
    std::string StarsMsg;
//End Type
};

//Public Type Tile 'Tiles for the World
struct Tile_t
{
//    Location As Location
    Location_t Location;
//    Type As Integer
    int Type = 0;
    std::string Layer;
    bool Hidden = false;
//End Type
};

//Public Type Scene 'World Scenery
struct Scene_t
{
//    Location As Location
    Location_t Location;
//    Type As Integer
    int Type = 0;
//    Active As Boolean 'if false this won't be shown. used for paths that become available on a scene
    bool Active = false;
    std::string Layer;
    bool Hidden = false;
//End Type
};

//Public Type WorldPath 'World Paths
struct WorldPath_t
{
//    Location As Location
    Location_t Location;
//    Active As Boolean
    bool Active = false;
//    Type As Integer
    int Type = 0;
    std::string Layer;
    bool Hidden = false;

//End Type
};

//Public Type WorldMusic 'World Music
struct WorldMusic_t
{
//    Location As Location
    Location_t Location;
//    Type As Integer
    int Type = 0;
//    EXTRA: Custom Music
    std::string MusicFile;
    std::string Layer;
    bool Hidden = false;
//End Type
};

//Public Type EditorCursor 'The editor's cursor
struct EditorCursor_t
{
//    X As Single
    float X = -50.0f;
//    Y As Single
    float Y = -50.0f;
//    SelectedMode As Integer 'cursor mode. eraser/npc/block/background
    int SelectedMode = 0;
//    Selected As Integer
    int Selected = 0;
//    Location As Location
    Location_t Location;
//    Layer As String 'current layer
    std::string Layer;
//    Mode As Integer
    int Mode = 0;
//    Block As Block
    Block_t Block;
//    Water As Water
    Water_t Water;
//    Background As Background
    Background_t Background;
//    NPC As NPC
    NPC_t NPC;
//    Warp As Warp
    Warp_t Warp;
//    Tile As Tile
    Tile_t Tile;
//    Scene As Scene
    Scene_t Scene;
//    WorldLevel As WorldLevel
    WorldLevel_t WorldLevel;
//    WorldPath As WorldPath
    WorldPath_t WorldPath;
//    WorldMusic As WorldMusic
    WorldMusic_t WorldMusic;
//End Type
};

//Public Type WorldPlayer 'the players variables on the world map
struct WorldPlayer_t
{
//    Location As Location
    Location_t Location;
//    Type As Integer
    int Type = 0;
//    Frame As Integer
    int Frame = 0;
//    Frame2 As Integer
    int Frame2 = 0;
//    Move As Integer
    int Move = 0;
//    Move2 As Integer
    int Move2 = 0;
//    Move3 As Boolean
    int Move3 = 0;
    int Move4 = 2;
//    LevelName As String
    std::string LevelName;
//End Type
};

//Public Type Layer
//moved into layers.h

//Public Type CreditLine
struct CreditLine_t
{
//    Location As Location
    Location_t Location;
//    Text As String
    std::string Text;
//End Type
};

//Public ScreenShake As Integer
extern int ScreenShake;
// TODO: Make it have multiple checkpoints and assign each one with different NPCs,
// last one should resume player at given position
//Public Checkpoint As String 'the filename of the level the player has a checkpoint in
extern std::string Checkpoint;

struct Checkpoint_t
{
    int id = 0;
};
// List of taken checkpoints, spawn player at last of them
extern std::vector<Checkpoint_t> CheckpointsList;

//Public MagicHand As Boolean 'true if playing a level in the editor while not in fullscreen mode
extern bool MagicHand;
//Public testPlayer(1 To 2) As Player 'test level player settings
extern RangeArr<Player_t, 1, 2> testPlayer;
//Public ClearBuffer As Boolean 'true to black the backbuffer
extern bool ClearBuffer;
//Public numLocked As Integer
extern int numLocked;
//Public resChanged As Boolean 'true if in fullscreen mode
extern bool resChanged;
//Public inputKey As Integer 'for setting the players controls
extern int inputKey;
//Public getNewKeyboard As Boolean 'true if setting keyboard controls
extern bool getNewKeyboard;
//Public getNewJoystick As Boolean
extern bool getNewJoystick;
//Public lastJoyButton As Integer
extern KM_Key lastJoyButton;
//Public GamePaused As Boolean 'true if the game is paused
extern bool GamePaused;
//Public MessageText As String 'when talking to an npc
extern std::string MessageText;
//Public NumSelectWorld As Integer
extern int NumSelectWorld;
//Public SelectWorld(1 To 100) As SelectWorld
struct SelectWorld_t;
//extern RangeArr<SelectWorld_t, 1, maxSelectWorlds> SelectWorld;
extern std::vector<SelectWorld_t> SelectWorld;
//Public ShowFPS As Boolean
extern bool ShowFPS;
//Public PrintFPS As Double
extern double PrintFPS;
// Do ground-point by alt-run key instead of down
extern bool GameplayPoundByAltRun;
//Public vScreen(0 To 2) As vScreen 'Sets up the players screens
extern RangeArr<vScreen_t, 0, 2> vScreen;
//Public ScreenType As Integer 'The screen/view type
extern int ScreenType;
//Public DScreenType As Integer 'The dynamic screen setup
extern int DScreenType;
//Public LevelEditor As Boolean 'if true, load the editor
extern bool LevelEditor;
//Public WorldEditor As Boolean
extern bool WorldEditor;
//Public BGOffset As Float 'a background offset for wrap type 2
extern int BGOffset;
//Public Subspace As Bool 'is in subspace
extern bool Subspace;

//Public PlayerStart(1 To 2) As Location
extern RangeArr<Location_t, 1, 2> PlayerStart;

//Public blockCharacter(0 To 20) As Boolean
extern RangeArrI<bool, 0, 20, false> blockCharacter;

//Public Type SelectWorld
struct SelectWorld_t
{
//    WorldName As String
    std::string WorldName;
//    WorldPath As String
    std::string WorldPath;
//    WorldFile As String
    std::string WorldFile;
//    blockChar(1 To numCharacters) As Boolean
    RangeArrI<bool, 1, numCharacters, false> blockChar;
//End Type
};

//Public OwedMount(0 To maxPlayers) As Integer 'when a yoshi/boot is taken from the player this returns after going back to the world map
extern RangeArrI<int, 0, maxPlayers, 0> OwedMount;
//Public OwedMountType(0 To maxPlayers) As Integer
extern RangeArrI<int, 0, maxPlayers, 0> OwedMountType;
//Public AutoX(0 To maxSections) As Single 'for autoscroll
extern RangeArr<float, 0, maxSections> AutoX;
//Public AutoY(0 To maxSections) As Single 'for autoscroll
extern RangeArr<float, 0, maxSections> AutoY;
extern RangeArr<float, 0, maxSections> Section_Blink_Timer;
extern RangeArr<float, 0, maxSections> Section_Blinking;
//Public numStars As Integer 'the number of stars the player has
extern int numStars;

//Public Type Star 'keeps track of where there player got the stars from
struct Star_t
{
//    level As String
    std::string level;
//    Section As Integer
    int Section = 0;
//End Type
};

//Public nPlay As nPlay ' for online stuff
//Public Water(0 To maxWater) As Water
extern RangeArr<Water_t, 0, maxWater> Water;
//Public numWater As Integer 'number of water
extern int numWater;
//Public Star(1 To 1000) As Star
extern RangeArr<Star_t, 1, maxStarsNum> Star;
//Public GoToLevel As String
extern std::string GoToLevel;
//! EXTRA: Hide entrance screen
extern bool GoToLevelNoGameThing;
//Public StartLevel As String 'start level for an episode
extern std::string StartLevel;
//Public NoMap As Boolean 'episode has no world map
extern bool NoMap;
//Public RestartLevel As Boolean 'restart the level on death
extern bool RestartLevel;
//Public LevelChop(0 To maxSections) As Single 'for drawing backgrounds when the level has been shrunk
extern float LevelChop[maxSections + 1];
//'collision detection optimization. creates a table of contents for blocks
//Public Const FLBlocks As Long = 8000
const long FLBlocks = 10000;
//Public FirstBlock(-FLBlocks To FLBlocks) As Integer
extern RangeArr<int, -FLBlocks, FLBlocks> FirstBlock;
//Public LastBlock(-FLBlocks To FLBlocks) As Integer
extern RangeArr<int, -FLBlocks, FLBlocks> LastBlock;
//Public MidBackground As Integer 'for drawing backgrounds
extern int MidBackground;
//Public LastBackground As Integer 'last backgrounds to be drawn
extern int LastBackground;
//Public iBlocks As Integer 'blocks that are doing something. this keeps the number of interesting blocks
extern int iBlocks;
//Public iBlock(0 To maxBlocks) As Integer 'references a block #
extern RangeArrI<int, 0, maxBlocks, 0> iBlock;
//Public numTiles As Integer 'number of map tiles
extern int numTiles;
//Public numScenes As Integer 'number of scense
extern int numScenes;
//Public CustomMusic(0 To maxSections) As String 'section's custom music
extern RangeArr<std::string, 0, maxSections> CustomMusic;
//EXTRA: Max count of used sections
extern int numSections;
//Public level(0 To maxSections) As Location 'sections
extern RangeArr<Location_t, 0, maxSections> level;
//Public LevelWrap(0 To maxSections) As Boolean 'Wrap around the level
extern RangeArrI<bool, 0, maxSections, false> LevelWrap;
//Public LevelWrap2(0 To maxSections) As Boolean 'Screen wrap
extern RangeArrI<bool, 0, maxSections, false> LevelWrap2;
//EXTRA: Wrap vertically around the level
extern RangeArrI<bool, 0, maxSections, false> LevelVWrap;
//Public OffScreenExit(0 To maxSections) As Boolean 'walk offscreen to end the level
extern RangeArrI<bool, 0, maxSections, false> OffScreenExit;
//Public bgMusic(0 To maxSections) As Integer 'music
extern RangeArrI<int, 0, maxSections, 0> bgMusic;
//Public bgMusicREAL(0 To maxSections) As Integer 'default music
extern RangeArrI<int, 0, maxSections, 0> bgMusicREAL;
//Public Background2REAL(0 To maxSections) As Integer 'background
extern RangeArrI<int, 0, maxSections, 0> Background2REAL;
//Public LevelREAL(0 To maxSections) As Location 'default background
extern RangeArr<Location_t, 0, maxSections> LevelREAL;
//Public curMusic As Integer 'current music playing
extern int curMusic;
//Public bgColor(0 To maxSections) As Long 'obsolete
extern RangeArrI<long, 0, maxSections, 0> bgColor;
//Public Background2(0 To maxSections) As Integer 'level background
extern RangeArrI<int, 0, maxSections, 0> Background2;
extern RangeArrI<int, 0, maxSections, 0> SectionTimer;
extern RangeArrI<int, 0, maxSections, 0> SectionTimerTurn;
extern RangeArrI<int, 0, maxSections, 0> AceCoins;
//Public WorldPath(1 To maxWorldPaths) As WorldPath
extern RangeArr<WorldPath_t, 1, maxWorldPaths> WorldPath;
//Public numWorldPaths As Integer
extern int numWorldPaths;
//Public numWarps As Integer 'number of warps in a level
extern int numWarps;
//Public Warp(1 To maxWarps) As Warp 'define the warps
extern RangeArr<Warp_t, 1, maxWarps> Warp;
//Public Tile(1 To maxTiles) As Tile
extern RangeArr<Tile_t, 1, maxTiles> Tile;
//Public Scene(1 To maxScenes) As Scene
extern RangeArr<Scene_t, 1, maxScenes> Scene;
//Public Credit(1 To 200) As CreditLine 'for end game credits
extern RangeArr<CreditLine_t, 1, maxCreditsLines> Credit;
//Public numCredits As Integer 'number of credits
extern int numCredits;
//Public numBlock As Integer 'number of blocks
extern int numBlock;
//Public numBackground As Integer 'number of background objects
extern int numBackground;
//Public numNPCs As Integer
extern int numNPCs;
extern int numAceCoins;
//Public numEffects As Integer
extern int numEffects;
//Public numPlayers As Integer
extern int numPlayers;
//Public numWorldLevels As Integer
extern int numWorldLevels;

extern int numWeather;
//Public WorldMusic(1 To maxWorldMusic) As WorldMusic
extern RangeArr<WorldMusic_t, 1, maxWorldMusic> WorldMusic;
//Public numWorldMusic As Integer
extern int numWorldMusic;
//Public WorldLevel(1 To maxWorldLevels) As WorldLevel
extern RangeArr<WorldLevel_t, 1, maxWorldLevels> WorldLevel;
//Public Background(1 To maxBackgrounds) As Background
extern RangeArr<Background_t, 1, maxBackgrounds> Background;
//Public Effect(1 To maxEffects) As Effect
extern RangeArr<Effect_t, 1, maxEffects> Effect;
//Public NPC(-128 To maxNPCs) As NPC
extern RangeArr<NPC_t, -128, maxNPCs> NPC;

extern RangeArr<Weather_t, 0, maxWeathers> Weather;
//Public Block(0 To maxBlocks) As Block
extern RangeArr<Block_t, 0, maxBlocks> Block;
//Public Player(0 To maxPlayers) As Player
extern RangeArr<Player_t, 0, maxPlayers> Player;
//Public MarioFrameX(0 To maxPlayerFrames) As Integer 'Player frame offset X
extern RangeArrI<int, 0, maxPlayerFrames, 0> MarioFrameX;
//Public MarioFrameY(0 To maxPlayerFrames) As Integer 'Player frame offset Y
extern RangeArrI<int, 0, maxPlayerFrames, 0> MarioFrameY;
//Public LuigiFrameX(0 To maxPlayerFrames) As Integer 'Player frame offset X
extern RangeArrI<int, 0, maxPlayerFrames, 0> LuigiFrameX;
//Public LuigiFrameY(0 To maxPlayerFrames) As Integer 'Player frame offset Y
extern RangeArrI<int, 0, maxPlayerFrames, 0> LuigiFrameY;
//Public PeachFrameX(0 To maxPlayerFrames) As Integer 'Player frame offset X
extern RangeArrI<int, 0, maxPlayerFrames, 0> PeachFrameX;
//Public PeachFrameY(0 To maxPlayerFrames) As Integer 'Player frame offset Y
extern RangeArrI<int, 0, maxPlayerFrames, 0> PeachFrameY;
//Public ToadFrameX(0 To maxPlayerFrames) As Integer 'Player frame offset X
extern RangeArrI<int, 0, maxPlayerFrames, 0> ToadFrameX;
//Public ToadFrameY(0 To maxPlayerFrames) As Integer 'Player frame offset Y
extern RangeArrI<int, 0, maxPlayerFrames, 0> ToadFrameY;
//Public LinkFrameX(0 To maxPlayerFrames) As Integer 'Player frame offset X
extern RangeArrI<int, 0, maxPlayerFrames, 0> LinkFrameX;
//Public LinkFrameY(0 To maxPlayerFrames) As Integer 'Player frame offset Y
extern RangeArrI<int, 0, maxPlayerFrames, 0> LinkFrameY;
extern RangeArrI<int, 0, maxPlayerFrames, 0> WaluigiFrameX;
extern RangeArrI<int, 0, maxPlayerFrames, 0> WaluigiFrameY;
extern RangeArrI<int, 0, maxPlayerFrames, 0> YoshiFrameX;
extern RangeArrI<int, 0, maxPlayerFrames, 0> YoshiFrameY;
extern RangeArrI<int, 0, maxPlayerFrames, 0> WarioFrameX;
extern RangeArrI<int, 0, maxPlayerFrames, 0> WarioFrameY;
//Public BackgroundFence(0 To maxBackgroundType) As Boolean
extern RangeArrI<bool, 0, maxBackgroundType, false> BackgroundFence;
extern RangeArrI<bool, 0, maxBackgroundType, false> BackgroundWater;
extern RangeArrI<bool, 0, maxBackgroundType, false> BackgroundNPCFence;
extern RangeArrI<bool, 0, maxBackgroundType, false> BackgroundFreeze;
extern RangeArrI<int, 0, maxBackgroundType, 8> BackgroundDoorEffect;
//Public NPCFrameOffsetX(0 To maxNPCType) As Integer 'NPC frame offset X
extern RangeArrI<int, 0, maxNPCType, 0> NPCFrameOffsetX;
//Public NPCFrameOffsetY(0 To maxNPCType) As Integer 'NPC frame offset Y
extern RangeArrI<int, 0, maxNPCType, 0> NPCFrameOffsetY;
//Public NPCWidth(0 To maxNPCType) As Integer 'NPC width
extern RangeArrI<int, 0, maxNPCType, 0> NPCWidth;
//Public NPCHeight(0 To maxNPCType) As Integer 'NPC height
extern RangeArrI<int, 0, maxNPCType, 0> NPCHeight;
//Public NPCWidthGFX(0 To maxNPCType) As Integer 'NPC gfx width
extern RangeArrI<int, 0, maxNPCType, 0> NPCWidthGFX;
//Public NPCHeightGFX(0 To maxNPCType) As Integer 'NPC gfx height
extern RangeArrI<int, 0, maxNPCType, 0> NPCHeightGFX;
//Public NPCSpeedvar(0 To maxNPCType) As Single 'NPC Speed Change
extern RangeArr<float, 0, maxNPCType> NPCSpeedvar;
//Public NPCIsAShell(0 To maxNPCType) As Boolean 'Flags the NPC type if it is a shell
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsAShell;
//Public NPCIsABlock(0 To maxNPCType) As Boolean 'Flag NPC as a block
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsABlock;
//Public NPCIsAHit1Block(0 To maxNPCType) As Boolean 'Flag NPC as a hit1 block
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsAHit1Block;
//Public NPCIsABonus(0 To maxNPCType) As Boolean 'Flags the NPC type if it is a bonus
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsABonus;
//Public NPCIsACoin(0 To maxNPCType) As Boolean 'Flags the NPC type if it is a coin
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsACoin;
//Public NPCIsAVine(0 To maxNPCType) As Boolean 'Flags the NPC type if it is a vine
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsAVine;
//Public NPCIsAnExit(0 To maxNPCType) As Boolean 'Flags the NPC type if it is a level exit
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsAnExit;
//Public NPCIsAParaTroopa(0 To maxNPCType) As Boolean 'Flags the NPC type as a para-troopa
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsAParaTroopa;
//Public NPCIsCheep(0 To maxNPCType) As Boolean 'Flags the NPC type as a cheep cheep
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsCheep;
//Public NPCJumpHurt(0 To maxNPCType) As Boolean 'Hurts the player even if it jumps on the NPC
extern RangeArrI<bool, 0, maxNPCType, false> NPCJumpHurt;
extern RangeArrI<bool, 0, maxNPCType, true> NPCSpinJumpHurt;
extern RangeArrI<bool, 0, maxNPCType, false> NPCJumpBounce;
//Public NPCNoClipping(0 To maxNPCType) As Boolean 'NPC can go through blocks
extern RangeArrI<bool, 0, maxNPCType, false> NPCNoClipping;
//Public NPCScore(0 To maxNPCType) As Integer 'NPC score value
extern RangeArrI<int, 0, maxNPCType, 0> NPCScore;
//Public NPCCanWalkOn(0 To maxNPCType) As Boolean  'NPC can be walked on
extern RangeArrI<bool, 0, maxNPCType, false> NPCCanWalkOn;
//Public NPCGrabFromTop(0 To maxNPCType) As Boolean  'NPC can be grabbed from the top
extern RangeArrI<bool, 0, maxNPCType, false> NPCGrabFromTop;
//Public NPCTurnsAtCliffs(0 To maxNPCType) As Boolean  'NPC turns around at cliffs
extern RangeArrI<bool, 0, maxNPCType, false> NPCTurnsAtCliffs;
//Public NPCWontHurt(0 To maxNPCType) As Boolean  'NPC wont hurt the player
extern RangeArrI<bool, 0, maxNPCType, false> NPCWontHurt;
//Public NPCMovesPlayer(0 To maxNPCType) As Boolean 'Player can not walk through the NPC
extern RangeArrI<bool, 0, maxNPCType, false> NPCMovesPlayer;
//Public NPCStandsOnPlayer(0 To maxNPCType) As Boolean 'for the clown car
extern RangeArrI<bool, 0, maxNPCType, false> NPCStandsOnPlayer;
//Public NPCIsGrabbable(0 To maxNPCType) As Boolean 'Player can grab the NPC
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsGrabbable;
//Public NPCIsBoot(0 To maxNPCType) As Boolean 'npc is a kurbo's shoe
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsBoot;
//Public NPCIsYoshi(0 To maxNPCType) As Boolean 'npc is a yoshi
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsYoshi;
//Public NPCIsToad(0 To maxNPCType) As Boolean 'npc is a toad
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsToad;
//Public NPCNoYoshi(0 To maxNPCType) As Boolean 'Player can't eat the NPC
extern RangeArrI<bool, 0, maxNPCType, false> NPCNoYoshi;
//Public NPCForeground(0 To maxNPCType) As Boolean 'draw the npc in front
extern RangeArrI<bool, 0, maxNPCType, false> NPCForeground;
//Public NPCIsABot(0 To maxNPCType) As Boolean 'Zelda 2 Bot monster
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsABot;
//Public NPCDefaultMovement(0 To maxNPCType) As Boolean 'default NPC movement
extern RangeArrI<bool, 0, maxNPCType, false> NPCDefaultMovement;
//Public NPCIsVeggie(0 To maxNPCType) As Boolean 'turnips
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsVeggie;
//Public NPCNoFireBall(0 To maxNPCType) As Boolean 'not hurt by fireball
extern RangeArrI<bool, 0, maxNPCType, false> NPCNoFireBall;
extern RangeArrI<bool, 0, maxNPCType, false> NPCNoLava;
extern RangeArrI<bool, 0, maxNPCType, false> NPCIsHeavy;
//Public NPCNoIceBall(0 To maxNPCType) As Boolean 'not hurt by fireball
extern RangeArrI<bool, 0, maxNPCType, false> NPCNoIceBall;
//Public NPCNoGravity(0 To maxNPCType) As Boolean 'not affected by gravity
extern RangeArrI<bool, 0, maxNPCType, false> NPCNoGravity;
extern RangeArrI<bool, 0, maxNPCType, true> NPCDespawn;
extern RangeArrI<bool, 0, maxNPCType, false> NPCGFXDirective;
extern RangeArrI<bool, 0, maxNPCType, false> NPCInstantKill;
extern RangeArrI<bool, 0, maxNPCType, false> NPCNoHammer;

//Public NPCFrame(0 To maxNPCType) As Integer
extern RangeArrI<int, 0, maxNPCType, 0> NPCFrame;
//Public NPCFrameSpeed(0 To maxNPCType) As Integer
extern RangeArrI<int, 0, maxNPCType, 0> NPCFrameSpeed;
//Public NPCFrameStyle(0 To maxNPCType) As Integer
extern RangeArrI<int, 0, maxNPCType, 0> NPCFrameStyle;

//Public Type NPCDefaults 'Default NPC Settings
// Moved into custom.cpp as local-private

//Public BlockIsSizable(0 To maxBlockType) As Boolean 'Flags block if it is sizable
extern RangeArrI<bool, 0, maxBlockType, false> BlockIsSizable;
//Public BlockIsSizable(0 To maxBlockType) As Boolean 'Flags block if it is sizable
extern RangeArrI<bool, 0, maxBlockType, false> BlockPlayerNoClipping;
//Public BlockSlope(0 To maxBlockType) As Integer 'block is sloped on top. -1 of block has an upward slope, 1 for downward
extern RangeArrI<int, 0, maxBlockType, 0> BlockSlope;
//Public BlockSlope2(0 To maxBlockType) As Integer 'block is sloped on the bottom.
extern RangeArrI<int, 0, maxBlockType, 0> BlockSlope2;
//Public vScreenX(0 To maxPlayers) As Double  'vScreen offset
extern RangeArr<double, 0, maxPlayers> vScreenX;
//Public vScreenY(0 To maxPlayers) As Double 'vScreen offset
extern RangeArr<double, 0, maxPlayers> vScreenY;

//Public qScreenX(1 To maxPlayers) As Double  'vScreen offset adjust
extern RangeArr<double, 0, maxPlayers> qScreenX;
//Public qScreenY(1 To maxPlayers) As Double 'vScreen offset adjust
extern RangeArr<double, 0, maxPlayers> qScreenY;
//Public qScreen As Boolean 'Weather or not the screen needs adjusting
extern bool qScreen;

//Public BlockWidth(0 To maxBlockType) As Integer 'Block type width
extern RangeArrI<int, 0, maxBlockType, 32> BlockWidth;
//Public BlockHeight(0 To maxBlockType) As Integer 'Block type height
extern RangeArrI<int, 0, maxBlockType, 32> BlockHeight;
//Public BonusWidth(1 To 100) As Integer 'Bonus type width
extern RangeArrI<int, 0, maxBlockType, 0> BonusWidth;
//Public BonusHeight(1 To 100) As Integer 'Bonus type height
extern RangeArrI<int, 0, maxBlockType, 0> BonusHeight;
//Public EffectWidth(1 To maxEffectType) As Integer 'Effect width
extern RangeArrI<int, 0, maxEffectType, 0> EffectWidth;
//Public EffectHeight(1 To maxEffectType) As Integer 'Effect height
extern RangeArrI<int, 0, maxEffectType, 0> EffectHeight;
extern RangeArrI<int, 0, maxEffectType, 0> EffectFrameAmount;
extern RangeArrI<int, 0, maxEffectType, 0> EffectFrameSpeed;
extern RangeArrI<int, 0, maxEffectType, 0> EffectLifeTime;
extern RangeArrI<int, 0, maxEffectType, 0> EffectAcceleration;

//Public Type EffectDefaults
struct EffectDefaults_t
{
    RangeArrI<int, 1, maxEffectType, 0> EffectWidth;
    RangeArrI<int, 1, maxEffectType, 0> EffectHeight;
    //EXTRA: count of frames (compute from the GFX height)
    RangeArrI<int, 1, maxEffectType, 0> EffectFrames;
    RangeArrI<int, 0, maxEffectType, 0> EffectFrameAmount;
    RangeArrI<int, 0, maxEffectType, 0> EffectFrameSpeed;
    RangeArrI<int, 0, maxEffectType, 0> EffectLifeTime;
    RangeArrI<int, 0, maxEffectType, 0> EffectAcceleration;
//End Type
};

//Public EffectDefaults As EffectDefaults
extern EffectDefaults_t EffectDefaults;

//Public SceneWidth(1 To 100) As Integer 'Scene width
extern RangeArrI<int, 1, maxSceneType, 0> SceneWidth;
//Public SceneHeight(1 To 100) As Integer 'Scene height
extern RangeArrI<int, 1, maxSceneType, 0> SceneHeight;
//Public BackgroundHasNoMask(1 To maxBackgroundType) As Boolean
extern RangeArrI<bool, 1, maxBackgroundType, false> BackgroundHasNoMask;
//Public Foreground(0 To maxBackgroundType) As Boolean 'flags the background object to be drawn in front of everything else
extern RangeArrI<bool, 0, maxBackgroundType, false> Foreground;
//Public BackgroundWidth(1 To maxBackgroundType) As Integer
extern RangeArrI<int, 1, maxBackgroundType, 0> BackgroundWidth;
//Public BackgroundHeight(1 To maxBackgroundType) As Integer
extern RangeArrI<int, 1, maxBackgroundType, 0> BackgroundHeight;
//Public BackgroundFrame(1 To maxBackgroundType) As Integer
extern RangeArrI<int, 1, maxBackgroundType, 0> BackgroundFrame;
//Public BackgroundFrameCount(1 To maxBackgroundType) As Integer
extern RangeArrI<int, 1, maxBackgroundType, 0> BackgroundFrameCount;
extern RangeArrI<int, 0, maxBackgroundType, 1> BackgroundFrameAmount;
extern RangeArrI<int, 0, maxBackgroundType, 8> BackgroundFrameSpeed;

extern RangeArrI<int, 0, maxBlockType, 0> BlockFrame;
extern RangeArrI<int, 0, maxBlockType, 0> BlockFrame2;
//Public sBlockArray(1 To 1000) As Integer 'sizable block array
extern RangeArrI<int, 1, 1000, 0> sBlockArray;
//Public sBlockNum As Integer
extern int sBlockNum;
//Public SceneFrame(1 To maxSceneType) As Integer 'What frame the scene is on
extern RangeArrI<int, 1, maxSceneType, 0> SceneFrame;
//Public SceneFrame2(1 To maxSceneType) As Integer 'Counter to update the scene frames
extern RangeArrI<int, 1, maxSceneType, 0> SceneFrame2;
extern RangeArrI<int, 1, maxSceneType, 1> SceneFrameCount;
extern RangeArrI<int, 1, maxSceneType, 12> SceneFrameSpeed;
extern RangeArrI<int, 0, maxSceneType, 0> SceneMovement;
extern RangeArrI<int, 1, maxSceneType, 1> SceneMovementSpeed;
extern RangeArr<double, 0, maxSceneType> SceneSpecial;
extern RangeArr<double, 0, maxSceneType> SceneSpecial2;
//Public SpecialFrame(100) As Integer 'misc frames for things like coins and the kurbi shoe
extern RangeArrI<int, 0, 100, 0> SpecialFrame;
//Public SpecialFrameCount(100) As Single
extern RangeArr<float, 0, 100> SpecialFrameCount;
//Public TileWidth(1 To maxTileType) As Integer
extern RangeArrI<int, 1, maxTileType, 0> TileWidth;
//Public TileHeight(1 To maxTileType) As Integer
extern RangeArrI<int, 1, maxTileType, 0> TileHeight;
//Public TileFrame(1 To maxTileType) As Integer
extern RangeArrI<int, 1, maxTileType, 0> TileFrame;
//Public TileFrame2(1 To maxTileType) As Integer
extern RangeArrI<int, 1, maxTileType, 0> TileFrame2;
//Public TileFrameCount(1 To maxTileType) As Integer
extern RangeArrI<int, 1, maxTileType, 1> TileFrameCount;
//Public TileFrameSpeed(1 To maxTileType) As Integer
extern RangeArrI<int, 1, maxTileType, 14> TileFrameSpeed;
//Public TileConnecting(1 To maxTileType) As Boolean
extern RangeArrI<bool, 1, maxTileType, false> TileConnecting;
//Public TileConnect(1 To maxTileType) As Int
extern RangeArrI<int, 1, maxTileType, 14> TileConnect;


//Public PathWidth(1 To maxPathType) As Integer
extern RangeArrI<int, 1, maxPathType, 32> PathWidth;
//Public PathHeight(1 To maxPathType) As Integer
extern RangeArrI<int, 1, maxPathType, 32> PathHeight;
//Public PathFrame(1 To maxPathType) As Integer
extern RangeArrI<int, 1, maxPathType, 0> PathFrame;
//Public PathFrame2(1 To maxPathType) As Integer
extern RangeArrI<int, 1, maxPathType, 0> PathFrame2;
//Public PathFrameCount(1 To maxPathType) As Integer
extern RangeArrI<int, 1, maxPathType, 1> PathFrameCount;
//Public PathFrameSpeed(1 To maxPathType) As Integer
extern RangeArrI<int, 1, maxPathType, 14> PathFrameSpeed;
extern RangeArrI<int, 1, maxPathType, 2> PathPlayerSpeed;

//Public LevelWidth(1 To maxLevelType) As Integer
extern RangeArrI<int, 1, maxLevelType, 32> LevelWidth;
//Public LevelHeight(1 To maxLevelType) As Integer
extern RangeArrI<int, 1, maxLevelType, 32> LevelHeight;
//Public LevelFrame(1 To maxLevelType) As Integer 'What frame the scene is on
extern RangeArrI<int, 1, maxLevelType, 0> LevelFrame;
//Public LevelFrame2(1 To maxLevelType) As Integer 'Counter to update the scene frames
extern RangeArrI<int, 1, maxLevelType, 0> LevelFrame2;
//Public LevelFrameCount(1 To maxLevelType) As Integer
extern RangeArrI<int, 1, maxLevelType, 1> LevelFrameCount;
//Public levelFrameSpeed(1 To maxLevelType) As Integer
extern RangeArrI<int, 1, maxLevelType, 12> LevelFrameSpeed;


//Public BlockHasNoMask(1 To maxBlockType) As Boolean
extern RangeArrI<bool, 1, maxBlockType, false> BlockHasNoMask;
//Public LevelHasNoMask(1 To 100) As Boolean
extern RangeArrI<bool, 1, 100, false> LevelHasNoMask;
//Public BlockOnlyHitspot1(0 To maxBlockType) As Boolean
extern RangeArrI<bool, 0, maxBlockType, false> BlockOnlyHitspot1;
//Public BlockKills(0 To maxBlockType) As Boolean 'block is lava
extern RangeArrI<bool, 0, maxBlockType, false> BlockKills;
//Public BlockKills2(0 To maxBlockType) As Boolean
extern RangeArrI<bool, 0, maxBlockType, false> BlockKills2;
extern RangeArrI<bool, 0, maxBlockType, false> BlockKills3;
//Public BlockHurts(0 To maxBlockType) As Boolean 'block hurts the player
extern RangeArrI<bool, 0, maxBlockType, false> BlockHurts;
//Public BlockPSwitch(0 To maxBlockType) As Boolean 'block is affected by the p switch
extern RangeArrI<bool, 0, maxBlockType, false> BlockPSwitch;
//Public BlockNoClipping(0 To maxBlockType) As Boolean 'player/npcs can walk throught the block
extern RangeArrI<bool, 0, maxBlockType, false> BlockNoClipping;
extern RangeArrI<bool, 0, maxBlockType, false> BlockNPCNoClipping;
//Public BlockBouncy(0 To maxBlockType) As Boolean 'block is bouncy like noteblock
extern RangeArrI<bool, 0, maxBlockType, false> BlockBouncy;
//Public BlockBouncyHorizontal(0 To maxBlockType) as Boolean 'block bounces player horizontally
extern RangeArrI<bool, 0, maxBlockType, false> BlockBouncyHorizontal;
//Public BlockHitable(0 to maxBlockType) as Boolean 'block can be bumped
extern RangeArrI<bool, 0, maxBlockType, false> BlockHitable;
extern RangeArrI<int, 0, maxBlockType, 2> BlockHitTransform;
//Public BlockDiggable(0 to maxBlockType) as Boolean 'block can be dug like smb2 sand
extern RangeArrI<bool, 0, maxBlockType, false> BlockDiggable;
//Public BlockBrick(0 to maxBlockType) as Boolean 'block is smashable like a brick
extern RangeArrI<bool, 0, maxBlockType, false> BlockBrick;
extern RangeArrI<int, 0, maxBlockType, 0> BlockBrickEffect;
//Public BlockFrameCount(0 To maxBlockType) As Integer 'how many frames of animation does this block have
extern RangeArrI<int, 0, maxBlockType, 1> BlockFrameCount;
//Public BlockFrameSpeed(0 To maxBlockType) As Integer 'how many frames before the next block frane
extern RangeArrI<int, 0, maxBlockType, 8> BlockFrameSpeed;
//Public BlockConnecting(0 to maxBlockType) As Boolean 'block connects to itself like in mario maker
extern RangeArrI<bool, 0, maxBlockType, false> BlockConnecting;
//Public BlockConnecting(0 to maxBlockType) As Boolean 'block is explodable by bombs
extern RangeArrI<bool, 0, maxBlockType, false> BlockExplodable;
//Public BlockHammer(0 to maxBlockType) As Boolean 'block is destroyable with hammer or tanooki suit
extern RangeArrI<bool, 0, maxBlockType, false> BlockHammer;
extern RangeArrI<bool, 0, maxBlockType, false> BlockNoIceBrick;

//Public CoinFrame(1 To 10) As Integer 'What frame the coin is on
extern RangeArrI<int, 1, 10, 0> CoinFrame;
//Public CoinFrame2(1 To 10) As Integer 'Counter to update the coin frames
extern RangeArrI<int, 1, 10, 0> CoinFrame2;

extern RangeArrI<int, 1, 10, 0> RedRingFrame;
//Counter to update the red ring frames
extern RangeArrI<int, 1, 10, 0> RedRingFrame2;

//Public EditorCursor As EditorCursor
extern EditorCursor_t EditorCursor;
//Public EditorControls As EditorControls
extern EditorControls_t EditorControls;

//Public Sound(1 To numSounds) As Integer
extern RangeArrI<int, 1, numSounds, 0> Sound;
//Public SoundPause(1 To numSounds) As Integer
extern RangeArrI<int, 1, numSounds, 0> SoundPause;
//EXTRA: Immediately quit level because of a fatal error
extern bool ErrorQuit;
//Public EndLevel As Boolean 'End the level and move to the next
extern bool EndLevel;
//Public LevelMacro As Integer 'Shows a level outro when beat
extern int LevelMacro;
//Public LevelMacroCounter As Integer
extern int LevelMacroCounter;
//Public numJoysticks As Integer
extern int numJoysticks;
//Public FileName As String
extern std::string FileName;
//! EXTRA: A full filename (the "FileName" is now has the "base name" sense)
extern std::string FileNameFull;
//! EXTRA: Identify that episode is an intro level
extern bool IsEpisodeIntro;
//Public Coins As Integer 'number of coins
extern int Coins;
//Public Lives As Single 'number of lives
extern float Lives;
//Public EndIntro As Boolean
extern bool EndIntro;
//Public ExitMenu As Boolean
extern bool ExitMenu;
//Public LevelSelect As Boolean 'true if game should load the world map
extern bool LevelSelect;
//Public WorldPlayer(1) As WorldPlayer
extern RangeArr<WorldPlayer_t, 0, 1> WorldPlayer;
//Public LevelBeatCode As Integer ' code for the way the plauer beat the level
extern int LevelBeatCode;
//Public curWorldLevel As Integer
extern int curWorldLevel;
//Public curWorldMusic As Integer
extern int curWorldMusic;
//EXTRA: Custom world music
extern std::string curWorldMusicFile;
//Public NoTurnBack(0 To maxSections) As Boolean
extern RangeArrI<bool, 0, maxSections, false> NoTurnBack;
//Public UnderWater(0 To maxSections) As Boolean
extern RangeArrI<bool, 0, maxSections, false> UnderWater;
extern RangeArrI<int, 0, maxSections, 0> SectionWeather;
//Public TestLevel As Boolean
extern bool TestLevel;
//Public FullFileName As String
extern std::string FullFileName;
//Public FileNamePath As String
extern std::string FileNamePath;
//Public GameMenu As Boolean
extern bool GameMenu;
//Public WorldName As String
extern std::string WorldName;
//Public selWorld As Integer
extern int selWorld;
//Public selSave As Integer
extern int selSave;
//Public PSwitchTime As Integer
extern int PSwitchTime;
//Public PSwitchStop As Integer
extern int PSwitchStop;
//Public PSwitchPlayer As Integer
extern int PSwitchPlayer;
//Public SaveSlot(1 To 3) As Integer
extern RangeArrI<int, 1, maxSaveSlots, 0> SaveSlot;
//Public SaveStars(1 To 3) As Integer
extern RangeArrI<int, 1, maxSaveSlots, 0> SaveStars;
//Public BeltDirection As Integer 'direction of the converyer belt blocks
extern int BeltDirection;
//Public BeatTheGame As Boolean 'true if the game has been beaten
extern bool BeatTheGame;
// 'for frameskip
//Public cycleCount As Integer
extern int cycleCount;
//Public fpsTime As Double
extern double fpsTime;
//Public fpsCount As Double
extern double fpsCount;
//Public FrameSkip As Boolean
extern bool FrameSkip;
//Public GoalTime As Double
extern double GoalTime;
//Public overTime As Double
extern double overTime;
//'------------------
//Public worldCurs As Integer
extern int worldCurs;
//Public minShow As Integer
extern int minShow;
//Public maxShow As Integer
extern int maxShow;

//Public Type Physics
struct Physics_t
{
//    PlayerJumpHeight As Integer
    int PlayerJumpHeight = 0;
//    PlayerBlockJumpHeight As Integer
    int PlayerBlockJumpHeight = 0;
//    PlayerHeadJumpHeight As Integer
    int PlayerHeadJumpHeight = 0;
//    PlayerNPCJumpHeight As Integer
    int PlayerNPCJumpHeight = 0;
//    PlayerSpringJumpHeight As Integer
    int PlayerSpringJumpHeight = 0;
//    PlayerJumpVelocity As Single
    float PlayerJumpVelocity = 0.0f;
//    PlayerRunSpeed As Single
    float PlayerRunSpeed = 0.0f;
//    PlayerWalkSpeed As Single
    float PlayerWalkSpeed = 0.0f;
//    PlayerTerminalVelocity As Integer
    int PlayerTerminalVelocity = 0;
//    PlayerGravity As Single
    float PlayerGravity = 0.0f;
//    PlayerHeight(1 To numCharacters, 1 To numStates) As Integer
    RangeArr<RangeArrI<int, 1, numStates, 0>, 1, numCharacters> PlayerHeight;
//    PlayerDuckHeight(1 To numCharacters, 1 To numStates) As Integer
    RangeArr<RangeArrI<int, 1, numStates, 0>, 1, numCharacters> PlayerDuckHeight;
//    PlayerWidth(1 To numCharacters, 1 To numStates) As Integer
    RangeArr<RangeArrI<int, 1, numStates, 0>, 1, numCharacters> PlayerWidth;
//    PlayerGrabSpotX(1 To numCharacters, 1 To numStates) As Integer
    RangeArr<RangeArrI<int, 1, numStates, 0>, 1, numCharacters> PlayerGrabSpotX;
//    PlayerGrabSpotY(1 To numCharacters, 1 To numStates) As Integer
    RangeArr<RangeArrI<int, 1, numStates, 0>, 1, numCharacters> PlayerGrabSpotY;
//    NPCTimeOffScreen As Integer
    int NPCTimeOffScreen = 0;
//    NPCCanHurtWait As Integer
    int NPCCanHurtWait = 0;
//    NPCShellSpeed As Single
    float NPCShellSpeed = 0.0f;
//    NPCShellSpeedY As Single
    float NPCShellSpeedY = 0.0f;
//    NPCWalkingSpeed As Single
    float NPCWalkingSpeed = 0.0f;
//    NPCWalkingOnSpeed As Single
    float NPCWalkingOnSpeed = 0.0f;
//    NPCMushroomSpeed As Single
    float NPCMushroomSpeed = 0.0f;
//    NPCGravity As Single
    float NPCGravity = 0.0f;
//    NPCGravityReal As Single
    float NPCGravityReal = 0.0f;
//    NPCPSwitch As Integer
    int NPCPSwitch = 0;
//End Type
};

//Public Type Events
//moved into "layers.h"

//Public ReturnWarp As Integer 'for when the player returns from a warp
extern int ReturnWarp;
//! EXTRA: Used to be captured into game save
extern int ReturnWarpSaved;
//Public StartWarp As Integer
extern int StartWarp;
//Public Physics As Physics
extern Physics_t Physics;
//Public MenuCursor As Integer
extern int MenuCursor;
//Public MenuMode As Integer
extern int MenuMode;
extern double MenuAlpha;
//Public MenuCursorCanMove As Boolean
extern bool MenuCursorCanMove;
//Public MenuCursorCanMove2 As Boolean 'Joystick
extern bool MenuCursorCanMove2;
//Public NextFrame As Boolean
extern bool NextFrame;
//Public StopHit As Integer
extern int StopHit;
//Public MouseRelease As Boolean
extern bool MouseRelease;
//Public TestFullscreen As Boolean
extern bool TestFullscreen;
////Public keyDownAlt As Boolean 'for alt/enter fullscreen
//extern bool keyDownAlt;
////Public keyDownEnter As Boolean
//extern bool keyDownEnter;
//Public BlocksSorted As Boolean 'if using block optimization it requires the locks to be sorted
extern bool BlocksSorted;
//Public SingleCoop As Integer 'cheat code
extern int SingleCoop;
//Public CheatString As String 'logs keys for cheats
extern std::string CheatString;
//Public GameOutro As Boolean 'true if showing credits
extern bool GameOutro;
//Public CreditChop As Single
extern float CreditChop;
//Public EndCredits As Integer
extern int EndCredits;
//Public curStars As Integer 'number of stars
extern int curStars;
//Public maxStars As Integer 'max number of stars in the game
extern int maxStars;
extern int maxAceCoins;
extern int currentAceCoins;
//'cheat codes --------------
//Public ShadowMode As Boolean 'cheat code
extern bool ShadowMode;
//Public MultiHop As Boolean
extern bool MultiHop;
//Public SuperSpeed As Boolean
extern bool SuperSpeed;
//Public WalkAnywhere As Boolean
extern bool WalkAnywhere;
//Public FlyForever As Boolean
extern bool FlyForever;
//Public FreezeNPCs As Boolean
extern bool FreezeNPCs;
//Public CaptainN As Boolean
extern bool CaptainN;
//Public FlameThrower As Boolean
extern bool FlameThrower;
//Public CoinMode As Boolean 'cheat code
extern bool CoinMode;
//Public WorldUnlock As Boolean
extern bool WorldUnlock;
//Public MaxFPS As Boolean
extern bool MaxFPS;
//Public GodMode As Boolean
extern bool GodMode;
//Public GrabAll As Boolean
extern bool GrabAll;
//Public Cheater As Boolean 'if the player is a cheater
extern bool Cheater;
//EXTRA
extern Uint32 RenderMode;
//'--------------------------------
//Public WorldCredits(1 To 5) As String
extern RangeArr<std::string, 1, maxWorldCredits> WorldCredits;
//Public Score As Long 'player's score
extern int Score;
//Public Points(1 To 13) As Integer
extern RangeArrI<int, 1, 13, 0> Points;
//Public oldJumpJoy As Integer
extern KM_Key oldJumpJoy;
//Public MaxWorldStars As Integer 'maximum number of world stars
extern int MaxWorldStars;
//Public Debugger As Boolean 'if the debugger window is open
extern bool Debugger;
//Public SavedChar(0 To 10) As Player 'Saves the Player's Status
extern RangeArr<Player_t, 0, 10> SavedChar;

extern bool LoadingInProcess;
//Public LoadCoins As Integer
extern int LoadCoins;
//Public LoadCoinsT As Single
extern float LoadCoinsT;

extern int LoadCursors;
extern float LoadCursorsT;

//'Game Graphics
//Public GFXBlockCustom(1 To maxBlockType) As Boolean
extern RangeArrI<bool, 1, maxBlockType, false> GFXBlockCustom;
//Public GFXBlock(1 To maxBlockType) As Long
//extern RangeArrI<long, 1, maxBlockType, 0> GFXBlock;
#define GFXBlock GFXBlockBMP
//Public GFXBlockMask(1 To maxBlockType) As Long
extern RangeArrI<long, 1, maxBlockType, 0> GFXBlockMask;
//Public GFXBlockBMP(1 To maxBlockType) As StdPicture
extern RangeArr<StdPicture, 1, maxBlockType> GFXBlockBMP;
//Public GFXBlockMaskBMP(1 To maxBlockType) As StdPicture
extern RangeArr<StdPicture, 1, maxBlockType> GFXBlockMaskBMP;
//Public GFXBackground2Custom(1 To numBackground2) As Boolean
extern RangeArrI<bool, 1, numBackground2, false> GFXBackground2Custom;
//Public GFXBackground2(1 To numBackground2) As Long
//extern RangeArrI<long, 1, numBackground2, 0> GFXBackground2;
#define GFXBackground2 GFXBackground2BMP
//Public GFXBackground2BMP(1 To numBackground2) As StdPicture
extern RangeArr<StdPicture, 1, numBackground2> GFXBackground2BMP;
//Public GFXBackground2Height(1 To numBackground2) As Integer
extern RangeArrI<int, 1, numBackground2, 0> GFXBackground2Height;
//Public GFXBackground2Width(1 To numBackground2) As Integer
extern RangeArrI<int, 1, numBackground2, 0> GFXBackground2Width;
//Public GFXNPCCustom(1 To maxNPCType) As Boolean
extern RangeArrI<bool, 1, maxNPCType, false> GFXNPCCustom;
//Public GFXNPC(1 To maxNPCType) As Long
//extern RangeArrI<long, 1, maxNPCType, 0> GFXNPC;
//extern RangeArrI<long, 1, maxWeatherType, 0> GFXWeather;
#define GFXWeather GFXWeatherBMP
extern RangeArrI<bool, 1, maxWeatherType, false> GFXWeatherCustom;
extern RangeArrI<long, 1, maxWeatherType, 0> GFXWeatherMask;
extern RangeArr<StdPicture, 0, maxWeatherType> GFXWeatherBMP;
extern RangeArr<StdPicture, 0, maxWeatherType> GFXWeatherMaskBMP;
extern RangeArrI<int, 1, maxWeatherType, 0> GFXWeatherWidth;
extern RangeArrI<int, 1, maxWeatherType, 0> GFXWeatherHeight;
#define GFXNPC GFXNPCBMP
//Public GFXNPCMask(1 To maxNPCType) As Long
extern RangeArrI<long, 1, maxNPCType, 0> GFXNPCMask;
//Public GFXNPCBMP(1 To maxNPCType) As StdPicture
extern RangeArr<StdPicture, 0, maxNPCType> GFXNPCBMP;
//Public GFXNPCMaskBMP(1 To maxNPCType) As StdPicture
extern RangeArr<StdPicture, 0, maxNPCType> GFXNPCMaskBMP;
//Public GFXNPCHeight(1 To maxNPCType) As Integer
extern RangeArrI<int, 1, maxNPCType, 0> GFXNPCHeight;
//Public GFXNPCWidth(1 To maxNPCType) As Integer
extern RangeArrI<int, 1, maxNPCType, 0> GFXNPCWidth;
//Public GFXEffectCustom(1 To maxEffectType) As Boolean
extern RangeArrI<bool, 1, maxEffectType, false> GFXEffectCustom;
//Public GFXEffect(1 To maxEffectType) As Long
//extern RangeArrI<long, 1, maxEffectType, 0> GFXEffect;
#define GFXEffect GFXEffectBMP
//Public GFXEffectMask(1 To maxEffectType) As Long
extern RangeArrI<long, 1, maxEffectType, 0> GFXEffectMask;
//Public GFXEffectBMP(1 To maxEffectType) As StdPicture
extern RangeArr<StdPicture, 1, maxEffectType> GFXEffectBMP;
//Public GFXEffectMaskBMP(1 To maxEffectType) As StdPicture
extern RangeArr<StdPicture, 1, maxEffectType> GFXEffectMaskBMP;
//Public GFXEffectHeight(1 To maxEffectType) As Integer
extern RangeArrI<int, 1, maxEffectType, 0> GFXEffectHeight;
//Public GFXEffectWidth(1 To maxEffectType) As Integer
extern RangeArrI<int, 1, maxEffectType, 0> GFXEffectWidth;
//Public GFXBackgroundCustom(1 To maxBackgroundType) As Boolean
extern RangeArrI<bool, 1, maxBackgroundType, false> GFXBackgroundCustom;
//Public GFXBackground(1 To maxBackgroundType) As Long
//extern RangeArrI<long, 1, maxBackgroundType, 0> GFXBackground;
#define GFXBackground GFXBackgroundBMP
//Public GFXBackgroundMask(1 To maxBackgroundType) As Long
extern RangeArrI<long, 1, maxBackgroundType, 0> GFXBackgroundMask;
//Public GFXBackgroundBMP(1 To maxBackgroundType) As StdPicture
extern RangeArr<StdPicture, 1, maxBackgroundType> GFXBackgroundBMP;
//Public GFXBackgroundMaskBMP(1 To maxBackgroundType) As StdPicture
extern RangeArr<StdPicture, 1, maxBackgroundType> GFXBackgroundMaskBMP;
//Public GFXBackgroundHeight(1 To maxBackgroundType) As Integer
extern RangeArrI<int, 1, maxBackgroundType, 0> GFXBackgroundHeight;
//Public GFXBackgroundWidth(1 To maxBackgroundType) As Integer
extern RangeArrI<int, 1, maxBackgroundType, 0> GFXBackgroundWidth;
//Public GFXMarioCustom(1 To 10) As Boolean
extern RangeArrI<bool, 1, 10, false> GFXMarioCustom;
//Public GFXMario(1 To 10) As Long
//extern RangeArrI<long, 1, 10, 0> GFXMario;
#define GFXMario GFXMarioBMP
//Public GFXMarioMask(1 To 10) As Long
extern RangeArrI<long, 1, 10, 0> GFXMarioMask;
//Public GFXMarioBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, 10> GFXMarioBMP;
//Public GFXMarioMaskBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, 10> GFXMarioMaskBMP;
//Public GFXMarioHeight(1 To 10) As Integer
extern RangeArrI<int, 1, 10, 0> GFXMarioHeight;
//Public GFXMarioWidth(1 To 10) As Integer
extern RangeArrI<int, 1, 10, 0> GFXMarioWidth;
//Public GFXLuigiCustom(1 To 10) As Boolean
extern RangeArrI<bool, 1, 10, false> GFXLuigiCustom;
//Public GFXLuigi(1 To 10) As Long
//extern RangeArrI<long, 1, 10, 0> GFXLuigi;
#define GFXLuigi GFXLuigiBMP
//Public GFXLuigiMask(1 To 10) As Long
extern RangeArrI<long, 1, 10, 0> GFXLuigiMask;
//Public GFXLuigiBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, 10> GFXLuigiBMP;
//Public GFXLuigiMaskBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, 10> GFXLuigiMaskBMP;
//Public GFXLuigiHeight(1 To 10) As Integer
extern RangeArrI<int, 1, 10, 0> GFXLuigiHeight;
//Public GFXLuigiWidth(1 To 10) As Integer
extern RangeArrI<int, 1, 10, 0> GFXLuigiWidth;
//Public GFXPeachCustom(1 To 10) As Boolean
extern RangeArrI<bool, 1, 10, false> GFXPeachCustom;
//Public GFXPeach(1 To 10) As Long
//extern RangeArrI<long, 1, 10, 0> GFXPeach;
#define GFXPeach GFXPeachBMP
//Public GFXPeachMask(1 To 10) As Long
extern RangeArrI<long, 1, 10, 0> GFXPeachMask;
//Public GFXPeachBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, 10> GFXPeachBMP;
//Public GFXPeachMaskBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, 10> GFXPeachMaskBMP;
//Public GFXPeachHeight(1 To 10) As Integer
extern RangeArrI<int, 1, 10, 0> GFXPeachHeight;
//Public GFXPeachWidth(1 To 10) As Integer
extern RangeArrI<int, 1, 10, 0> GFXPeachWidth;
//Public GFXToadCustom(1 To 10) As Boolean
extern RangeArrI<bool, 1, 10, false> GFXToadCustom;
//Public GFXToad(1 To 10) As Long
//extern RangeArrI<long, 1, 10, 0> GFXToad;
#define GFXToad GFXToadBMP
//Public GFXToadMask(1 To 10) As Long
extern RangeArrI<long, 1, 10, 0> GFXToadMask;
//Public GFXToadBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, 10> GFXToadBMP;
//Public GFXToadMaskBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, 10> GFXToadMaskBMP;
//Public GFXToadHeight(1 To 10) As Integer
extern RangeArrI<int, 1, 10, 0> GFXToadHeight;
//Public GFXToadWidth(1 To 10) As Integer
extern RangeArrI<int, 1, 10, 0> GFXToadWidth;

//Public GFXLuigiCustom(1 To 10) As Boolean
extern RangeArrI<bool, 1, 10, false> GFXWaluigiCustom;
//Public GFXWaluigi(1 To 10) As Long
//extern RangeArrI<long, 1, 10, 0> GFXWaluigi;
#define GFXWaluigi GFXWaluigiBMP
//Public GFXWaluigiMask(1 To 10) As Long
extern RangeArrI<long, 1, 10, 0> GFXWaluigiMask;
//Public GFXWaluigiBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, 10> GFXWaluigiBMP;
//Public GFXWaluigiMaskBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, 10> GFXWaluigiMaskBMP;
//Public GFXWaluigiHeight(1 To 10) As Integer
extern RangeArrI<int, 1, 10, 0> GFXWaluigiHeight;
//Public GFXWaluigiWidth(1 To 10) As Integer
extern RangeArrI<int, 1, 10, 0> GFXWaluigiWidth;


#define GFXYoshi GFXYoshiBMP
extern RangeArr<StdPicture, 1, 10> GFXYoshiBMP;


extern StdPicture BMVs;
extern StdPicture BMWin;
extern RangeArr<StdPicture, 1, 4> Boot;
extern RangeArr<StdPicture, 1, 5> CharacterName;
extern StdPicture Chat;
extern RangeArr<StdPicture, 0, 2> Container;
extern RangeArr<StdPicture, 1, 4> ECursor;
extern RangeArr<StdPicture, 0, 9> Font1;
extern RangeArr<StdPicture, 1, 5> Font2;
extern StdPicture Font2S;
extern RangeArr<StdPicture, 1, 2> Heart;
extern RangeArr<StdPicture, 0, 11> Interface;
extern StdPicture LoadCoin;
extern StdPicture Loader;
extern RangeArr<StdPicture, 0, 3> MCursor;
extern RangeArr<StdPicture, 1, 5> MenuGFX;
extern RangeArr<StdPicture, 0, 4> Logo;
extern int LogoNum;
extern RangeArr<StdPicture, 2, 2> Mount;
extern RangeArr<StdPicture, 0, 7> nCursor;
extern StdPicture TextBox;
extern RangeArr<StdPicture, 1, 2> Tongue;
extern StdPicture WarpGFX;
extern StdPicture YoshiWings;

//Public GFXLinkCustom(1 To 10) As Boolean
extern RangeArrI<bool, 1, 10, false> GFXLinkCustom;
//Public GFXLink(1 To 10) As Long
//extern RangeArrI<long, 1, 10, 0> GFXLink;
#define GFXLink GFXLinkBMP
//Public GFXLinkMask(1 To 10) As Long
extern RangeArrI<long, 1, 10, 0> GFXLinkMask;
//Public GFXLinkBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, 10> GFXLinkBMP;
//Public GFXLinkMaskBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, 10> GFXLinkMaskBMP;
//Public GFXLinkHeight(1 To 10) As Integer
extern RangeArrI<int, 1, 10, 0> GFXLinkHeight;
//Public GFXLinkWidth(1 To 10) As Integer
extern RangeArrI<int, 1, 10, 0> GFXLinkWidth;

extern RangeArrI<bool, 1, 10, false> GFXWarioCustom;
#define GFXWario GFXWarioBMP
extern RangeArrI<long, 1, 10, 0> GFXWarioMask;
extern RangeArr<StdPicture, 1, 10> GFXWarioBMP;
extern RangeArr<StdPicture, 1, 10> GFXWarioMaskBMP;
extern RangeArrI<int, 1, 10, 0> GFXWarioHeight;
extern RangeArrI<int, 1, 10, 0> GFXWarioWidth;

//Public GFXYoshiBCustom(1 To 10) As Boolean
extern RangeArrI<bool, 1, maxYoshiGfx, false> GFXYoshiBCustom;
//Public GFXYoshiB(1 To 10) As Long
//extern RangeArrI<long, 1, maxYoshiGfx, 0> GFXYoshiB;
#define GFXYoshiB GFXYoshiBBMP
//Public GFXYoshiBMask(1 To 10) As Long
extern RangeArrI<long, 1, maxYoshiGfx, 0> GFXYoshiBMask;
//Public GFXYoshiBBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, maxYoshiGfx> GFXYoshiBBMP;
//Public GFXYoshiBMaskBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, maxYoshiGfx> GFXYoshiBMaskBMP;
//Public GFXYoshiTCustom(1 To 10) As Boolean
extern RangeArrI<bool, 1, maxYoshiGfx, false> GFXYoshiTCustom;
//Public GFXYoshiT(1 To 10) As Long
//extern RangeArrI<long, 1, maxYoshiGfx, 0> GFXYoshiT;
#define GFXYoshiT GFXYoshiTBMP
//Public GFXYoshiTMask(1 To 10) As Long
extern RangeArrI<long, 1, maxYoshiGfx, 0> GFXYoshiTMask;
//Public GFXYoshiTBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, maxYoshiGfx> GFXYoshiTBMP;
//Public GFXYoshiTMaskBMP(1 To 10) As StdPicture
extern RangeArr<StdPicture, 1, maxYoshiGfx> GFXYoshiTMaskBMP;
//'World Map Graphics
//Public GFXTileCustom(1 To maxTileType) As Long
extern RangeArrI<bool, 1, maxTileType, false> GFXTileCustom;
//Public GFXTile(1 To maxTileType) As Long
//extern RangeArrI<long, 1, maxTileType, 0> GFXTile;
#define GFXTile GFXTileBMP
//Public GFXTileBMP(1 To maxTileType) As StdPicture
extern RangeArr<StdPicture, 1, maxTileType> GFXTileBMP;
//Public GFXTileHeight(1 To maxTileType) As Integer
extern RangeArrI<int, 1, maxTileType, 0> GFXTileHeight;
//Public GFXTileWidth(1 To maxTileType) As Integer
extern RangeArrI<int, 1, maxTileType, 0> GFXTileWidth;
//Public GFXLevelCustom(0 To maxLevelType) As Long
extern RangeArrI<bool, 0, maxLevelType, false> GFXLevelCustom;
//Public GFXLevel(0 To maxLevelType) As Long
//extern RangeArrI<long, 0, maxLevelType, 0> GFXLevel;
#define GFXLevel GFXLevelBMP
//Public GFXLevelMask(0 To maxLevelType) As Long
extern RangeArrI<long, 0, maxLevelType, 0> GFXLevelMask;
//Public GFXLevelBMP(0 To maxLevelType) As StdPicture
extern RangeArr<StdPicture, 0, maxLevelType> GFXLevelBMP;
//Public GFXLevelMaskBMP(0 To maxLevelType) As StdPicture
extern RangeArr<StdPicture, 0, maxLevelType> GFXLevelMaskBMP;
//Public GFXLevelHeight(0 To maxLevelType) As Integer
extern RangeArrI<int, 0, maxLevelType, 0> GFXLevelHeight;
//Public GFXLevelWidth(0 To maxLevelType) As Integer
extern RangeArrI<int, 0, maxLevelType, 0> GFXLevelWidth;
//Public GFXLevelBig(0 To maxLevelType) As Boolean
extern RangeArrI<bool, 0, maxLevelType, false> GFXLevelBig;
//Public GFXSceneCustom(1 To maxSceneType) As Long
extern RangeArrI<bool, 1, maxSceneType, false> GFXSceneCustom;
//Public GFXScene(1 To maxSceneType) As Long
//extern RangeArrI<long, 1, maxSceneType, 0> GFXScene;
#define GFXScene GFXSceneBMP
//Public GFXSceneMask(1 To maxSceneType) As Long
extern RangeArrI<long, 1, maxSceneType, 0> GFXSceneMask;
//Public GFXSceneBMP(1 To maxSceneType) As StdPicture
extern RangeArr<StdPicture, 1, maxSceneType> GFXSceneBMP;
//Public GFXSceneMaskBMP(1 To maxSceneType) As StdPicture
extern RangeArr<StdPicture, 1, maxSceneType> GFXSceneMaskBMP;
//Public GFXSceneHeight(1 To maxSceneType) As Integer
extern RangeArrI<int, 1, maxSceneType, 0> GFXSceneHeight;
//Public GFXSceneWidth(1 To maxSceneType) As Integer
extern RangeArrI<int, 1, maxSceneType, 0> GFXSceneWidth;
//Public GFXPathCustom(1 To maxPathType) As Long
extern RangeArrI<bool, 1, maxPathType, false> GFXPathCustom;
//Public GFXPath(1 To maxPathType) As Long
//extern RangeArrI<long, 1, maxPathType, 0> GFXPath;
#define GFXPath GFXPathBMP
//Public GFXPathMask(1 To maxPathType) As Long
extern RangeArrI<long, 1, maxPathType, 0> GFXPathMask;
//Public GFXPathBMP(1 To maxPathType) As StdPicture
extern RangeArr<StdPicture, 1, maxPathType> GFXPathBMP;
//Public GFXPathMaskBMP(1 To maxPathType) As StdPicture
extern RangeArr<StdPicture, 1, maxPathType> GFXPathMaskBMP;
//Public GFXPathHeight(1 To maxPathType) As Integer
extern RangeArrI<int, 1, maxPathType, 0> GFXPathHeight;
//Public GFXPathWidth(1 To maxPathType) As Integer
extern RangeArrI<int, 1, maxPathType, 0> GFXPathWidth;

//Public GFXPlayerCustom(1 To numCharacters) As Long
extern RangeArrI<bool, 1, numCharacters, false> GFXPlayerCustom;
//Public GFXPlayer(1 To numCharacters) As Long
//extern RangeArrI<long, 1, numCharacters, 0> GFXPlayer;
#define GFXPlayer GFXPlayerBMP
//Public GFXPlayerMask(1 To numCharacters) As Long
extern RangeArrI<long, 1, numCharacters, 0> GFXPlayerMask;
//Public GFXPlayerBMP(1 To numCharacters) As StdPicture
extern RangeArr<StdPicture, 1, numCharacters> GFXPlayerBMP;
//Public GFXPlayerMaskBMP(1 To numCharacters) As StdPicture
extern RangeArr<StdPicture, 1, numCharacters> GFXPlayerMaskBMP;
//Public GFXPlayerHeight(1 To numCharacters) As Integer
extern RangeArrI<int, 1, numCharacters, 0> GFXPlayerHeight;
//Public GFXPlayerWidth(1 To numCharacters) As Integer
extern RangeArrI<int, 1, numCharacters, 0> GFXPlayerWidth;

//Public PlayerCharacter As Integer
extern int PlayerCharacter;
//Public PlayerCharacter2 As Integer
extern int PlayerCharacter2;
//Public MenuMouseX As Double
extern double MenuMouseX;
//Public MenuMouseY As Double
extern double MenuMouseY;
//Public MenuMouseDown As Boolean
extern bool MenuMouseDown;
//Public MenuMouseBack As Boolean
extern bool MenuMouseBack;
//Public MenuMouseRelease As Boolean
extern bool MenuMouseRelease;
//Public MenuMouseMove As Boolean
extern bool MenuMouseMove;
//Public MenuMouseClick As Boolean
extern bool MenuMouseClick;

//' event stuff
// Moved into "layers.h"

//Public ForcedControls As Boolean
extern bool ForcedControls;
//Public ForcedControl As Controls
extern Controls_t ForcedControl;
//Public SyncCount As Integer
extern int SyncCount;
//Public noUpdate As Boolean
extern bool noUpdate;
//Public gameTime As Double
extern double gameTime;
//Public noSound As Boolean
extern bool noSound;
extern bool neverPause;
//Public tempTime As Double
extern double tempTime;
//Dim ScrollDelay As Integer [in main.cpp]
//'battlemode stuff
//Public BattleMode As Boolean
extern bool BattleMode;
//Public BattleWinner As Integer
extern int BattleWinner;
//Public BattleLives(1 To maxPlayers) As Integer
extern RangeArrI<int, 1, maxPlayers, 0> BattleLives;
//Public BattleIntro As Integer
extern int BattleIntro;
//Public BattleOutro As Integer
extern int BattleOutro;
//Public LevelName As String
extern std::string LevelName;
extern std::string GameVersion;
//Public Const curRelease As Integer = 64
const int curRelease = 64;

extern bool WindowChanged;
extern int ScreenW;
extern int ScreenH;

struct LevelTimer_t
{
    bool enable = false;
    int time = 0;
    double subTimer = 0;
    int timeSpeed = 0;
    void reset();
};

extern LevelTimer_t LevelTimer;

#endif // GLOBALS_H
