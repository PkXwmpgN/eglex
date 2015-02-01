//
//  elgex/display.h
//  core library
//
//  Created by Alexey Yegorov (yegorov.alex@gmail.com)
//

#ifndef __EGL_DISPLAY_INCLUDED__
#define __EGL_DISPLAY_INCLUDED__

#include <eglex/traits.h>
#include <eglex/handle.h>
#include <eglex/specification.h>
#include <eglex/specification_enum.h>

__EGL_BEGIN__

using native_display = handle_owner<native_display_type_traits>;

struct current_display_construct {};
struct default_display_construct {};

const default_display_construct default_display;
const current_display_construct current_display;

class display : private handle_owner<display_type_traits>
			  , public enable_to_attribute<display>
{
public:

	using base = handle_owner<display_type_traits>;
	using handle = base::handle;
	using htraits = base::htraits;
	
	display() : base{} {}

	explicit display(default_display_construct) 
        : display{native_display()} {}

	explicit display(current_display_construct) 
        : base{details::GetCurrentDisplay()} {}

    display(const native_display & disp) 
        : base{details::GetDisplay(disp.handle_)}
	{
		details::Initialize(handle_, nullptr, nullptr);
	}
	
	display(display && rv) : base{std::move(rv)} {}
	display & operator=(display && rv)
	{
		base::operator=(std::move(rv));
		return *this;
	}

	const char * get_attribute(specs::client_attribute_code attribute) const
	{
        return details::QueryString(handle_, specs::to_integral(attribute));
	}

	const handle & get_handle() const { return handle_; }
	bool valid() const { return !(handle_ == htraits::empty()); }

    void release()
    {
        if(valid())
            details::Terminate(handle_);
    }
};

__EGL_END__

#endif // __EGL_DISPLAY_INCLUDED__