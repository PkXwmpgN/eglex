//
//  elgex/context.h
//  core library
//
//  Created by Alexey Yegorov (yegorov.alex@gmail.com)
//

#ifndef __EGL_CONTEXT_INCLUDED__
#define __EGL_CONTEXT_INCLUDED__

#include <eglex/traits.h>
#include <eglex/handle.h>
#include <eglex/configs.h>
#include <eglex/surface.h>
#include <eglex/specification_enum.h>

__EGL_BEGIN__

struct current_context_construct{};
const current_context_construct current_context;

class context : private handle_slave<context_type_traits, display_type_traits>
			  , public enable_to_attribute<context>
{

public:

	using base = handle_slave<context_type_traits, display_type_traits>;
	using handle = base::handle;
	using owner = base::owner;
	using htraits = base::htraits;
	using otraits = base::otraits;

	context() : base{} {}

	explicit context(current_context_construct) : 
        base{details::GetCurrentContext(), display{current_display}.get_handle()} {}

	explicit context(const config & conf, const specification & spec = specification()) :
        base{initialize(context{}, conf, spec), conf.get_owner() } {}

	context(const context & shared, const config & conf, const specification & spec = specification()) :
        base(initialize(shared, conf, spec), conf.get_owner()) {}

	context(context && c) : base(std::move(c)) {}
	context & operator=(context && rv)
	{
		base::operator=(std::move(rv));
		return *this;
	}
	 
	bool make_current(const surface & draw, const surface & read)
	{
        details::MakeCurrent(owner_, draw.get_handle(), read.get_handle(), handle_) == TRUE_VALUE;
	}
	bool make_current(const surface & surf)
	{
        details::MakeCurrent(owner_, surf.get_handle(), surf.get_handle(), handle_) == TRUE_VALUE;
	}
	bool make_current()
	{
		details::MakeCurrent(owner_, htraits::empty(), htraits::empty(), handle_) == TRUE_VALUE;
	}

	int_type get_attribute(specs::context_attribute_code attribute) const
	{
        return details::QueryContext(owner_, handle_, specs::to_integral(attribute));
	}

	const handle & get_handle() const { return handle_; }
	bool valid() const { return !(handle_ == htraits::empty() && owner_ == otraits::empty()); }

    void release()
    {
        if (valid())
            details::DestroyContext(owner_, handle_);
    }

private:

	handle initialize(const context & shared, const config & conf, const specification & spec)
	{
		return  details::CreateContext(conf.get_owner(), conf.get_handle(), shared.get_handle(), spec.data());
	}
};

inline context make_context(const config & conf, const specification & spec = specification())
{
    return context(conf, spec);
}
inline context make_context(const context & shared, const config & conf, const specification & spec = specification())
{
    return context(shared, conf, spec);
}

__EGL_END__

#endif // __EGL_CONTEXT_INCLUDED__