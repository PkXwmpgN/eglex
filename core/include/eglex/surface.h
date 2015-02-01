//
//  elgex/surface.h
//  core library
//
//  Created by Alexey Yegorov (yegorov.alex@gmail.com)
//

#ifndef __EGL_SURFACE_INCLUDED__
#define __EGL_SURFACE_INCLUDED__

#include <eglex/traits.h>
#include <eglex/handle.h>
#include <eglex/display.h>
#include <eglex/configs.h>
#include <eglex/specification.h>
#include <eglex/specification_enum.h>

__EGL_BEGIN__

using native_window = handle_owner<native_window_type_traits>;
using native_pixmap = handle_owner<native_pixmap_type_traits>;

struct current_read_surface_construct{};
struct current_draw_surface_construct{};

const current_read_surface_construct current_read_surface;
const current_draw_surface_construct current_draw_surface;

class surface : private handle_slave<surface_type_traits, display_type_traits>
			  , public enable_to_attribute<surface>
{
public:

	using base = handle_slave<surface_type_traits, display_type_traits>;
	using handle = base::handle;
	using owner = base::owner;
	using htraits = base::htraits;
	using otraits = base::otraits;
	
	surface() : base{}{}
	surface(const config & conf, const native_window & window, const specification & spec = specification()) :
		base{create_window_surface(conf, spec, window), conf.get_owner()}{}

	surface(const config & conf, const native_pixmap & pixmap, const specification & spec = specification()) :
		base{create_pixmap_surface(conf, spec, pixmap), conf.get_owner()}{}

	surface(const config & conf, const specification & spec) :
		base{create_pbuffer_surface(conf, spec), conf.get_owner()}{}

	explicit surface(current_read_surface_construct) : 
		base{details::GetCurrentReadSurface(), display{current_display}.get_handle()} {}

	explicit surface(current_draw_surface_construct) :
        base{details::GetCurrentDrawSurface(), display{ current_display }.get_handle()} {}

    surface(surface && surf) : base(std::move(surf)) {}
    surface & operator=(surface && rv)
    {
        base::operator=(std::move(rv));
        return *this;
    }

	const handle & get_handle() const { return handle_; }
	bool valid() const { return !(handle_ == htraits::empty() && owner_ == otraits::empty()); }

	bool swap_buffers()
	{
        return details::SwapBuffers(owner_, handle_) == TRUE_VALUE;
	}

    bool copy_buffers(native_pixmap & result)
    {
        return details::CopyBuffers(owner_, handle_, result.handle_) == TRUE_VALUE;
    }

	int_type get_attribute(specs::surface_attribute_code attribute) const
	{
        return details::QuerySurface(owner_, handle_, specs::to_integral(attribute));
	}

    void release()
    {
        if (valid())
            details::DestroySurface(owner_, handle_);
    }

private:

	handle create_window_surface(const config & conf, const specification & spec, const native_window & window)
	{
		return details::CreateWindowSurface(conf.get_owner(), conf.get_handle(), window.handle_, spec.data());
	}
	handle create_pixmap_surface(const config & conf, const specification & spec, const native_pixmap & pixmap)
	{
		return details::CreatePixmapSurface(conf.get_owner(), conf.get_handle(), pixmap.handle_, spec.data());
	}
	handle create_pbuffer_surface(const config & conf, const specification & spec)
	{
		return details::CreatePbufferSurface(conf.get_owner(), conf.get_handle(), spec.data());
	}
};

inline surface make_surface(const config & conf, const native_window & window, const specification & spec = specification())
{
    return surface(conf, window, spec);
}

inline surface make_surface(const config & conf, const native_pixmap & pixmap, const specification & spec = specification())
{
    return surface(conf, pixmap, spec);
}

inline surface make_surface(const config & conf, const specification & spec)
{
    return surface(conf, spec);
}

__EGL_END__

#endif // __EGL_SURFACE_INCLUDED__