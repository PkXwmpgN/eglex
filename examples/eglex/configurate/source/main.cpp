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
		egl::configs configs(display, RGB565_ES2);

		egl::configs::const_iterator it = std::find_if(configs.begin(), configs.end(), [](const egl::config & config)
		{
			return  config_red_size(config) == 5 &&
					config_green_size(config) == 6 &&
					config_blue_size(config) == 5 &&
					config_depth_size(config) >= 24;
		});

        if (it != configs.end())
            std::cout << config_id(*it) << std::endl;
	}
	catch (const std::system_error & ex)
	{
		std::cout << "error: " << ex.what() << std::endl;
	}
}