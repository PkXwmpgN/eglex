#include <iostream>

#include <eglex/eglex.h>
#include <eglex/specification_io.h>
#include <eglex/specification_type.h>

int main()
{
	try
	{
		using namespace egl::specs;

		egl::display display(egl::default_display);
		egl::configs configs(display);

		for (auto & config : configs)
		{
			std::cout << "config id: " << config_id(config).get_value() << std::endl;
			
			std::cout << config_buffer_size(config) << std::endl;
			std::cout << config_red_size(config) << std::endl;
			std::cout << config_green_size(config) << std::endl;
			std::cout << config_blue_size(config) << std::endl;
			std::cout << config_alpha_size(config) << std::endl;
			std::cout << config_depth_size(config) << std::endl;
			std::cout << config_color_buffer_type(config) << std::endl;
			std::cout << config_renderable_type(config) << std::endl;
			std::cout << config_surface_type(config) << std::endl;
			std::cout << congig_native_randerable(config) << std::endl;
			
			std::cout << std::endl;
		};
	}
	catch (const std::system_error & ex)
	{
		std::cout << "error: " << ex.what() << std::endl;
	}
}