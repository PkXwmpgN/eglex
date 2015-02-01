//
//  elgex/error.h
//  core library
//
//  Created by Alexey Yegorov (yegorov.alex@gmail.com)
//

#ifndef __EGL_ERROR_INCLUDED__
#define __EGL_ERROR_INCLUDED__

#include <eglex/egl.h>
#include <eglex/options.h>
#include <eglex/error_enum.h>
#include <system_error>

namespace std 
{
	template<> struct is_error_condition_enum<egl::error::code> : public true_type{};
}

__EGL_BEGIN__

namespace error
{
	class category : public std::error_category
	{
	public:
		const char * name() const override { return "egl"; }

		std::error_condition default_error_condition(int error) const override;
		std::string message(int error) const override;

		static const category & get()
		{
			static category error_category;
			return error_category;
		}
	};

	inline std::error_condition make_error_condition(egl::error::code error)
	{
		return std::error_condition(static_cast<int>(error), category::get());
	}

    inline std::error_code get_error()
    {
        return std::error_code{ ::eglGetError(), category::get() };
    }

	inline void check_error()
	{
        std::error_code code{get_error()};
		if (code != code::success)
            throw std::system_error{code};
	}
}

__EGL_END__


#ifdef USE_EGL_ERROR_CHECK
#define __CHECK_EGL_ERROR__() egl::error::check_error();
#else
#define __CHECK_EGL_ERROR__() do{}while(false);
#endif // USE_EGL_ERROR_CHECK

#endif // __EGL_ERROR_INCLUDED__