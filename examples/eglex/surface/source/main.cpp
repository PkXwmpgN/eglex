#include <iostream>

#include <eglex/eglex.h>
#include <eglex/specification_type.h>

HWND create_window();
int loop(egl::surface & surface);

int start()
{
    egl::surface surface(egl::current_draw_surface);
    return loop(surface);
}

int main()
{
    try
    {
        HWND hWnd = create_window();


        egl::display display(egl::default_display);
        egl::configs configs(display, egl::specs::RGB565_ES2);
        if (!configs.empty())
        {
            egl::context context(configs.front(), egl::specs::ES2);
            egl::surface surface(configs.front(), egl::native_window(hWnd));

            context.make_current(surface);

            return start();
        }
    }
    catch (const std::system_error & ex)
    {
        std::cout << "error: " << ex.what() << std::endl;
    }
}