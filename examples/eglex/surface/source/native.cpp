#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <eglex/surface.h>

void Init();
void Draw(egl::surface & surface);

LRESULT WINAPI proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
    LONG  lRet = 0;
    PAINTSTRUCT ps;

    switch(uMsg)
    {
    case WM_PAINT:
        BeginPaint(hWnd, &ps);		
        EndPaint(hWnd, &ps);
        break;
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    default:
        lRet = DefWindowProc(hWnd, uMsg, wParam, lParam);
        break;
    }

    return lRet;
}

HWND create_window()
{
   WNDCLASS wndclass = {0}; 
   DWORD    wStyle = WS_VISIBLE | WS_POPUP | WS_BORDER | WS_SYSMENU | WS_CAPTION;
   RECT     windowRect = {0, 0, 600, 800};
   HINSTANCE hInstance = GetModuleHandle(nullptr);

   wndclass.style  = CS_OWNDC;
   wndclass.lpfnWndProc = (WNDPROC)proc;
   wndclass.hInstance = hInstance; 
   wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); 
   wndclass.lpszClassName = "native_window"; 

   if (!RegisterClass(&wndclass)) 
      return nullptr; 

   AdjustWindowRect(&windowRect, wStyle, FALSE);
   HWND hWnd = CreateWindow("native_window",
                            "native_window",
                            wStyle,
                            0,
                            0,
                            windowRect.right - windowRect.left,
                            windowRect.bottom - windowRect.top,
                            NULL,
                            NULL,
                            hInstance,
                            NULL);

   ShowWindow(hWnd, TRUE);

   return hWnd;
}

int loop(egl::surface & surface)
{
    Init();

    MSG msg;
	while(true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
        { 
			if(msg.message == WM_QUIT)
				break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
		else
		{ 
            Draw(surface);
        } 
	}

	return(msg.wParam);		
}