//
//  elgex/egl.h
//  core library
//
//  Created by Alexey Yegorov (yegorov.alex@gmail.com)
//

#ifndef __EGL_INCLUDED__
#define __EGL_INCLUDED__

#if defined(_WIN32)
	#include <EGL/egl.h>
#elif defined(__APPLE__)
	#import <OpenGLES/egl.h>
#elif defined(__ANDROID__)
	#include <EGL/egl.h>
#endif

#define __EGL_BEGIN__ namespace egl {
#define __EGL_END__ }

__EGL_BEGIN__

using int_type = EGLint;
using bool_type = EGLBoolean;

const int_type DONT_CARE = EGL_DONT_CARE;
const bool_type TRUE_VALUE = EGL_TRUE;
const bool_type FALSE_VALUE = EGL_FALSE;

namespace details
{
    const char * QueryString(::EGLDisplay, ::EGLint);
    ::EGLDisplay GetDisplay(::EGLNativeDisplayType);
    ::EGLDisplay GetCurrentDisplay();
    ::EGLBoolean Initialize(::EGLDisplay, ::EGLint *, ::EGLint *);
    ::EGLBoolean Terminate(::EGLDisplay);
    ::EGLint GetConfigAttrib(::EGLDisplay, ::EGLConfig, ::EGLint);
    ::EGLBoolean GetConfigs(::EGLDisplay, ::EGLConfig *, ::EGLint, ::EGLint *);
    ::EGLBoolean ChooseConfig(::EGLDisplay, const ::EGLint *, ::EGLConfig *, ::EGLint, ::EGLint *);
    ::EGLContext CreateContext(::EGLDisplay, ::EGLConfig, ::EGLContext, const ::EGLint *);
    ::EGLBoolean DestroyContext(::EGLDisplay, ::EGLContext);
    ::EGLBoolean MakeCurrent(::EGLDisplay, ::EGLSurface, ::EGLSurface, ::EGLContext);
    ::EGLContext GetCurrentContext();
    ::EGLint QueryContext(::EGLDisplay, ::EGLContext, ::EGLint);
    ::EGLSurface GetCurrentDrawSurface();
    ::EGLSurface GetCurrentReadSurface();
    ::EGLSurface CreateWindowSurface(::EGLDisplay, ::EGLConfig, ::EGLNativeWindowType, const ::EGLint *);
    ::EGLSurface CreatePbufferSurface(::EGLDisplay, ::EGLConfig, const ::EGLint *);
    ::EGLSurface CreatePixmapSurface(::EGLDisplay, ::EGLConfig, ::EGLNativePixmapType, const ::EGLint *);
    ::EGLBoolean DestroySurface(::EGLDisplay, ::EGLSurface);
    ::EGLint QuerySurface(::EGLDisplay, ::EGLSurface, ::EGLint);
    ::EGLBoolean SwapBuffers(::EGLDisplay, ::EGLSurface);
    ::EGLBoolean CopyBuffers(::EGLDisplay, ::EGLSurface, ::EGLNativePixmapType);
}

__EGL_END__

#endif // __EGL_INCLUDED__
