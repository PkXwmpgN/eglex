# C++ wrapper for EGL

###Basic usage

* *Initializes a display and requests an information about one*

        using namespace egl::specs;

        egl::display display(egl::default_display);
        
        std::cout << client_api(display) << std::endl;
        std::cout << client_vendor(display) << std::endl;
        std::cout << client_version(display) << std::endl;
        std::cout << client_extentions(display) << std::endl;

* *Configurates*

        using namespace egl::specs;
        
        egl::display display(egl::default_display);
        egl::configs configs(display, RGB565_es2);

        egl::configs::const_iterator it = std::find_if(configs.begin(), configs.end(), [](const egl::config & config)
        {
            return  config_red_size(config) == 5 &&
                    config_green_size(config) == 6 &&
                    config_blue_size(config) == 5 &&
                    config_depth_size(config) >= 24;
        });
        if (it != configs.end())
            std::cout << config_id(*it) << std::endl;

* *Creates a context and requests an information about one*

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

* *Creates a surface*

        egl::display display(egl::default_display);
        egl::configs configs(display, egl::specs::RGB565_ES2);
        if(!configs.empty())
        {
            egl::context context(configs.front(), egl::specs::ES2);
            egl::surface surface(configs.front(), egl::native_window(hWnd));
        
            context.make_current(surface);
        }


### Building
* *Windows*
    * Install [GLES-Emulator]. Add the directory to PATH Environment Variable **GLES_EMULATOR_DIR**
    * Install [CMake]
    * Install [Git Bash]
    * Install [Microsoft Visual Studio Express 2013 for Windows Desktop]
    * Create a project

            cd eglex
            ./project.sh

    * Open the solution file **build/eglex.sln** in Visual Studio and build
    
[GLES-Emulator]:http://malideveloper.arm.com/develop-for-mali/tools/software-tools/opengl-es-emulator/
[CMake]:http://www.cmake.org/download/
[Git Bash]:http://git-scm.com/downloads
[Microsoft Visual Studio Express 2013 for Windows Desktop]:http://www.visualstudio.com/en-us/products/visual-studio-express-vs.aspx