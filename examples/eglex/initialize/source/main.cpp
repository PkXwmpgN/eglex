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

		std::cout << client_api(display) << std::endl;
		std::cout << client_vendor(display) << std::endl;
		std::cout << client_version(display) << std::endl;
		std::cout << client_extentions(display) << std::endl;
	}
	catch (const std::system_error & ex)
	{
		std::cout << "error: " << ex.what() << std::endl;
	}
}