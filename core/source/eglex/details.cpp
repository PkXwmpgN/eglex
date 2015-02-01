//
//  elgex/details.cpp
//  core library
//
//  Created by Alexey Yegorov (yegorov.alex@gmail.com)
//

#include <eglex/egl.h>
#include <eglex/error.h>

__EGL_BEGIN__

namespace details
{
    ::EGLDisplay GetDisplay(::EGLNativeDisplayType ndpy)
    {
        ::EGLDisplay display = ::eglGetDisplay(ndpy);
        __CHECK_EGL_ERROR__();
        return display;
    }

    ::EGLDisplay GetCurrentDisplay()
    {
        ::EGLDisplay display = ::eglGetCurrentDisplay();
        __CHECK_EGL_ERROR__();
        return display;
    }

    ::EGLBoolean Initialize(::EGLDisplay dpy, ::EGLint *major, ::EGLint *minor)
    {
        ::EGLBoolean result = ::eglInitialize(dpy, major, minor);
        __CHECK_EGL_ERROR__();
        return result;
    }

    ::EGLBoolean Terminate(::EGLDisplay dpy)
    {
        EGLBoolean result = ::eglTerminate(dpy);
        __CHECK_EGL_ERROR__();
        return result;
    }

    ::EGLBoolean GetConfigs(::EGLDisplay dpy, ::EGLConfig *configs,
        ::EGLint config_size, ::EGLint *num_config)
    {
        ::EGLBoolean result = ::eglGetConfigs(dpy, configs, config_size, num_config);
        __CHECK_EGL_ERROR__();
        return result;
    }

    ::EGLBoolean ChooseConfig(::EGLDisplay dpy, const ::EGLint *attrib_list,
        ::EGLConfig *configs, ::EGLint config_size, ::EGLint *num_config)
    {
        ::EGLBoolean result = ::eglChooseConfig(dpy, attrib_list, configs, config_size, num_config);
        __CHECK_EGL_ERROR__();
        return result;
    }

    ::EGLint GetConfigAttrib(::EGLDisplay dpy, ::EGLConfig config, ::EGLint attribute)
    {
        ::EGLint result = 0;
        ::eglGetConfigAttrib(dpy, config, attribute, &result);
        __CHECK_EGL_ERROR__();
        return result;
    }

    ::EGLContext CreateContext(::EGLDisplay dpy, ::EGLConfig config,
        ::EGLContext share_context, const ::EGLint *attrib_list)
    {
        ::EGLContext context = ::eglCreateContext(dpy, config, share_context, attrib_list);
        __CHECK_EGL_ERROR__();
        return context;
    }

    ::EGLBoolean DestroyContext(::EGLDisplay dpy, ::EGLContext ctx)
    {
        ::EGLBoolean result = ::eglDestroyContext(dpy, ctx);
        __CHECK_EGL_ERROR__();
        return result;
    }

    ::EGLBoolean MakeCurrent(::EGLDisplay dpy, ::EGLSurface draw, ::EGLSurface read, ::EGLContext ctx)
    {
        ::EGLBoolean result = ::eglMakeCurrent(dpy, draw, read, ctx);
        __CHECK_EGL_ERROR__();
        return result;
    }

    ::EGLContext GetCurrentContext()
    {
        ::EGLContext context = ::eglGetCurrentContext();
        __CHECK_EGL_ERROR__();
        return context;
    }

    ::EGLint QueryContext(::EGLDisplay dpy, ::EGLContext ctx, ::EGLint attribute)
    {
        ::EGLint result = 0;
        ::eglQueryContext(dpy, ctx, attribute, &result);
        __CHECK_EGL_ERROR__();
        return result;
    }

    ::EGLSurface GetCurrentDrawSurface()
    {
        ::EGLSurface surface = ::eglGetCurrentSurface(EGL_DRAW);
        __CHECK_EGL_ERROR__();
        return surface;
    }

    ::EGLSurface GetCurrentReadSurface()
    {
        ::EGLSurface surface = ::eglGetCurrentSurface(EGL_READ);
        __CHECK_EGL_ERROR__();
        return surface;
    }

    ::EGLSurface CreateWindowSurface(::EGLDisplay dpy, ::EGLConfig config,
        ::EGLNativeWindowType win, const ::EGLint *attrib_list)
    {
        ::EGLSurface surface = ::eglCreateWindowSurface(dpy, config, win, attrib_list);
        __CHECK_EGL_ERROR__();
        return surface;
    }

    ::EGLSurface CreatePbufferSurface(::EGLDisplay dpy, ::EGLConfig config, const ::EGLint *attrib_list)
    {
        ::EGLSurface surface = ::eglCreatePbufferSurface(dpy, config, attrib_list);
        __CHECK_EGL_ERROR__();
        return surface;
    }

    ::EGLSurface CreatePixmapSurface(::EGLDisplay dpy, ::EGLConfig config,
        ::EGLNativePixmapType pixmap, const ::EGLint *attrib_list)
    {
        ::EGLSurface surface = ::eglCreatePixmapSurface(dpy, config, pixmap, attrib_list);
        __CHECK_EGL_ERROR__();
        return surface;
    }

    ::EGLBoolean DestroySurface(::EGLDisplay dpy, ::EGLSurface surface)
    {
        ::EGLBoolean result = eglDestroySurface(dpy, surface);
        __CHECK_EGL_ERROR__();
        return result;
    }

    ::EGLint QuerySurface(::EGLDisplay dpy, ::EGLSurface surface, ::EGLint attribute)
    {
        ::EGLint value = 0;
        ::eglQuerySurface(dpy, surface, attribute, &value);
        __CHECK_EGL_ERROR__();
        return value;
    }

    ::EGLBoolean SwapBuffers(::EGLDisplay dpy, ::EGLSurface surface)
    {
        ::EGLBoolean result = ::eglSwapBuffers(dpy, surface);
        __CHECK_EGL_ERROR__();
        return result;
    }

    ::EGLBoolean CopyBuffers(::EGLDisplay dpy, ::EGLSurface surface, ::EGLNativePixmapType target)
    {
        ::EGLBoolean result = ::eglCopyBuffers(dpy, surface, target);
        __CHECK_EGL_ERROR__();
        return result;
    }

    const char * QueryString(::EGLDisplay dpy, ::EGLint name)
    {
        const char * result = ::eglQueryString(dpy, name);
		__CHECK_EGL_ERROR__();
		return result;
    }
}

__EGL_END__
