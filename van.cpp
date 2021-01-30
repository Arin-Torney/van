#include <gdiplus.h>
#include <windows.h>
#include <objidl.h>
using namespace Gdiplus;
VOID OnPaint(HDC hdc)
{
   Graphics graphics(hdc);
   Pen pen(Color(255, 0, 0, 255));
   graphics.DrawLine(&pen, 0, 500, 500, 500);
   Pen rectPen(Color(255,0,0,0), 1);
   RectF rect(20.0f, 20.0f, 120.0f, 80.0f);
   graphics.DrawRectangle(&rectPen, rect);
   RectF myRect(30.0f, 30.0f, 25.0f, 25.0f);
   graphics.DrawRectangle(&rectPen, myRect);
   RectF yRect(105.0f, 30.0f, 25.0f, 25.0f);
   graphics.DrawRectangle(&rectPen, yRect);
   RectF midRect(68.125f, 30.0f, 25.0f, 25.0f);
   graphics.DrawRectangle(&rectPen, midRect);
   RectF vanLight(20.0f, 60.0f, 5.0f, 20.0f);
   graphics.DrawRectangle(&rectPen, vanLight);
   RectF firstWheel(30.0f, 100.0f, 25.0f, 25.0f);
   graphics.DrawEllipse(&rectPen, firstWheel);
   RectF secondWheel(105.0f, 100.0f, 25.0f, 25.0f);
   graphics.DrawEllipse(&rectPen, secondWheel);
}

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
   HWND                hWnd;
   MSG                 msg;
   WNDCLASS            wndClass;
   GdiplusStartupInput gdiplusStartupInput;
   ULONG_PTR           gdiplusToken;
   
   // Initialize GDI+.
   GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
   
   wndClass.style          = CS_HREDRAW | CS_VREDRAW;
   wndClass.lpfnWndProc    = WndProc;
   wndClass.cbClsExtra     = 0;
   wndClass.cbWndExtra     = 0;
   wndClass.hInstance      = hInstance;
   wndClass.hIcon          = LoadIcon(NULL, IDI_ASTERISK);
   wndClass.hCursor        = LoadCursor(NULL, IDC_CROSS);
   wndClass.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
   wndClass.lpszMenuName   = NULL;
   wndClass.lpszClassName  = TEXT("Van");
   
   RegisterClass(&wndClass);
   
   hWnd = CreateWindow(
      TEXT("Van"),   // window class name
      TEXT("Van"),  // window caption
      WS_OVERLAPPEDWINDOW,      // window style
      CW_USEDEFAULT,            // initial x position
      CW_USEDEFAULT,            // initial y position
      CW_USEDEFAULT,            // initial x size
      CW_USEDEFAULT,            // initial y size
      NULL,                     // parent window handle
      NULL,                     // window menu handle
      hInstance,                // program instance handle
      NULL);                    // creation parameters
      
   ShowWindow(hWnd, iCmdShow);
   UpdateWindow(hWnd);
   
   while(GetMessage(&msg, NULL, 0, 0))
   {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }
   
   GdiplusShutdown(gdiplusToken);
   return msg.wParam;
}  // WinMain

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, 
   WPARAM wParam, LPARAM lParam)
{
   HDC          hdc;
   PAINTSTRUCT  ps;
   
   switch(message)
   {
   case WM_PAINT:
      hdc = BeginPaint(hWnd, &ps);
      OnPaint(hdc);
      EndPaint(hWnd, &ps);
      return 0;
   case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
   default:
      return DefWindowProc(hWnd, message, wParam, lParam);
   }
} // WndProc
