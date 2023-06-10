#pragma once
#include <windows.h>


 enum class KeyCode {
    W = 'W',
    A = 'A',
    S = 'S',
    D = 'D',
    One = '1',
    Two = '2',
    SPACE = ' ',
    ENTER = '\n',
    ESC = 27
};

class GameFramework
{
public:
    GameFramework(int w, int h);
    virtual ~GameFramework();

protected:
    int screenIndex;
    HANDLE screens[2];
    int width;
    int height;

    bool currentKeyStates[256];
    bool prevKeyStates[256];


    char* screenBuffer;

    void ScreenFlipping();
    void ScreenClear();

    void UpdateInput();
    bool IsKeyDown(int keycode);

public:
    void ScreenInit();
    void ScreenRelease();

    bool GetKeyDown(KeyCode keyCode);
    bool GetKeyUp(KeyCode keyCode);
    bool GetKey(KeyCode keyCode);

    void ScreenPrint(int x, int y, const char* string);
    //void ScreenPrint(const Point& pos, const char* string);
    //void ScreenPrint(const PointF& pos, const char* string);

    void SetColor(unsigned short color);
    void Do();

    virtual void Init() = 0;
    virtual void Update(float dt) = 0;
    virtual void Draw() = 0;
    virtual void Release() = 0;
};