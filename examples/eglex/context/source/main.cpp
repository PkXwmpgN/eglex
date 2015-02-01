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

		if (!configs.empty())
		{
			egl::context context(configs.front());

            std::cout << context_type(context) << std::endl;
            std::cout << context_version(context) << std::endl;
            std::cout << context_config_id(context) << std::endl;
            std::cout << context_render_buffer(context) << std::endl;
		}	
	}
	catch (const std::system_error & ex)
	{
        std::cout << "error: " << ex.what() << std::endl;
	}
}