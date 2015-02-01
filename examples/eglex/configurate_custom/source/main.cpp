#include <iostream>
#include <algorithm>

#include <eglex/eglex.h>
#include <eglex/specification_io.h>
#include <eglex/specification_type.h>

int main()
{
    try
    {
        using namespace egl::specs;

        egl::display display(egl::default_display);

        egl::specification my_spec
        {
            config_red_size(4),
            config_green_size(4),
            config_blue_size(4),
            config_alpha_size(4)
        };

        egl::configs configs(display, my_spec);
        if (!configs.empty())
            std::cout << config_id(configs.front()) << std::endl;
    }
    catch (const std::system_error & ex)
    {
        std::cout << "error: " << ex.what() << std::endl;
    }
}