//
//  elgex/error_enum.h
//  core library
//
//  Created by Alexey Yegorov (yegorov.alex@gmail.com)
//

#ifndef __EGL_ERROR_ENUM_INCLUDED__
#define __EGL_ERROR_ENUM_INCLUDED__

#include <eglex/egl.h>

__EGL_BEGIN__

namespace error
{
	enum code
	{
        success,
		not_initialized,
		context_lost,
		bad_access,
		bad_alloc,
		bad_attribute,
		bad_config,
		bad_context,
		bad_surface,
		bad_current_surface,
		bad_display,
		bad_match,
		bad_pixmap,
		bad_window ,
		bad_parameter,
		unknown
	};
}

__EGL_END__

#endif // __EGL_ERROR_ENUM_INCLUDED__