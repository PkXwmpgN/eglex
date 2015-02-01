//
//  elgex/error.cpp
//  core library
//
//  Created by Alexey Yegorov (yegorov.alex@gmail.com)
//

#include <eglex/error.h>

__EGL_BEGIN__

namespace error
{
	std::error_condition category::default_error_condition(int error) const
	{
		switch (error)
		{
        case EGL_SUCCESS:
            return std::error_condition(error::code::success);
		case EGL_NOT_INITIALIZED:
			return std::error_condition(error::code::not_initialized);
		case EGL_CONTEXT_LOST:
			return std::error_condition(error::code::context_lost);
		case EGL_BAD_ACCESS:
			return std::error_condition(error::code::bad_access);
		case EGL_BAD_ALLOC:
			return std::error_condition(error::code::bad_alloc);
		case EGL_BAD_ATTRIBUTE:
			return std::error_condition(error::code::bad_attribute);
		case EGL_BAD_CONFIG:
			return std::error_condition(error::code::bad_config);
		case EGL_BAD_CONTEXT:
			return std::error_condition(error::code::bad_context);
		case EGL_BAD_SURFACE:
			return std::error_condition(error::code::bad_surface);
		case EGL_BAD_CURRENT_SURFACE:
			return std::error_condition(error::code::bad_current_surface);
		case EGL_BAD_DISPLAY:
			return std::error_condition(error::code::bad_display);
		case EGL_BAD_MATCH:
			return std::error_condition(error::code::bad_match);
		case EGL_BAD_NATIVE_PIXMAP:
			return std::error_condition(error::code::bad_pixmap);
		case EGL_BAD_NATIVE_WINDOW:
			return std::error_condition(error::code::bad_window);
		case EGL_BAD_PARAMETER:
			return std::error_condition(error::code::bad_parameter);
		}
		return std::error_condition(error::code::unknown);
	}


	std::string category::message(int error) const
	{
		switch (error)
		{
		case EGL_NOT_INITIALIZED:
			return "EGL is not initialized or could not be initialized";
		case EGL_CONTEXT_LOST:
			return "A power management event has occurred, the previously current EGL context is lost";
		case EGL_BAD_ACCESS:
			return "EGL cannot access a requested resource";
		case EGL_BAD_ALLOC:
			return "EGL failed to allocate resources for the requested operation";
		case EGL_BAD_ATTRIBUTE:
			return "An unrecognized attribute or attribute value was passed in an attribute list";
		case EGL_BAD_CONTEXT:
			return "Argument does not name a valid EGLContext";
		case EGL_BAD_CONFIG:
			return "Argument does not name a valid EGLConfig";
		case EGL_BAD_CURRENT_SURFACE:
			return "The current surface of the calling thread is a window, pbuffer, or pixmap that is no longer valid";
		case EGL_BAD_DISPLAY:
			return "Argument does not name a valid EGLDisplay";
		case EGL_BAD_SURFACE:
			return "Argument does not name a valid surface (window, pbuffer, or pixmap) configured for rendering";
		case EGL_BAD_MATCH:
			return "Arguments are inconsistent";
		case EGL_BAD_PARAMETER:
			return "One or more argument values are invalid";
		case EGL_BAD_NATIVE_PIXMAP:
			return "Argument does not refer to a valid native pixmap";
		case EGL_BAD_NATIVE_WINDOW:
			return "argument does not refer to a valid native window";
		}
		return "Unknown EGL error code";
	}

}

__EGL_END__
