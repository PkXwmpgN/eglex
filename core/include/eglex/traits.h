//
//  elgex/traits.h
//  core library
//
//  Created by Alexey Yegorov (yegorov.alex@gmail.com)
//

#ifndef __EGL_TRAITS_INCLUDED__
#define __EGL_TRAITS_INCLUDED__

#include <eglex/egl.h>

__EGL_BEGIN__

struct native_display_type_traits
{
	using handle = ::EGLNativeDisplayType;
	static handle empty() { return EGL_DEFAULT_DISPLAY; }
};

struct display_type_traits
{
	using handle = ::EGLDisplay;
	static handle empty() { return EGL_NO_DISPLAY; }
};

struct config_type_traits
{
	using handle = ::EGLConfig;
	static handle empty() { return nullptr; }
};

struct context_type_traits
{
	using handle = ::EGLContext;
	static handle empty() { return EGL_NO_CONTEXT; }
};

struct native_window_type_traits
{
	using handle = ::EGLNativeWindowType;
	static handle empty() { return nullptr; }
};

struct native_pixmap_type_traits
{
	using handle = ::EGLNativePixmapType;
	static handle empty() { return nullptr; }
};

struct surface_type_traits
{
	using handle = ::EGLSurface;
	static handle empty() { return EGL_NO_SURFACE; }
};

__EGL_END__

#endif // __EGL_TRAITS_INCLUDED__