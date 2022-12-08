#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <dwmapi.h>
#pragma comment (lib, "dwmapi.lib")
#pragma comment (lib, "user32.lib")
#pragma comment (lib, "gdi32.lib")

extern "C" void *GetWindowHandle(void);

void ApplyTransparency()
{
    HWND window = (HWND)GetWindowHandle();
    // Enable window transparency
    {
        SetLayeredWindowAttributes(window, 0, 255, LWA_ALPHA);
        DWM_BLURBEHIND bb = {0};
        HRGN hRgn = CreateRectRgn(0, 0, -1, -1);
        bb.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION;
        bb.hRgnBlur = hRgn;
        bb.fEnable = TRUE;
        DwmEnableBlurBehindWindow(window, &bb);
    }
}