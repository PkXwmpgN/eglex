//
//  elgex/handle.h
//  core library
//
//  Created by Alexey Yegorov (yegorov.alex@gmail.com)
//

#ifndef __EGL_HANDLE_INCLUDED__
#define __EGL_HANDLE_INCLUDED__

#include <eglex/egl.h>

__EGL_BEGIN__

template<typename _HTraits, typename _OTraits>
class handle_base
{
public:

	using handle = typename _HTraits::handle;
	using owner = typename _OTraits::handle;
	using htraits = _HTraits;
	using otraits = _OTraits;

	
	handle_base() : handle_{htraits::empty()}, owner_{otraits::empty()} {}
	handle_base(const handle & h, const owner & own) : handle_{h}, owner_{own} {}

	handle_base(handle_base && rv) : handle_{rv.handle_}, owner_{rv.owner_}
	{
		rv.handle_ = htraits::empty();
		rv.owner_ = otraits::empty();
	}
	handle_base & operator=(handle_base && rv)
	{
		std::swap(handle_, rv.handle_);
		std::swap(owner_, rv.owner_);
		return *this;
	}

	handle_base(const handle_base &) = delete;
	handle_base & operator=(const handle_base &) = delete;

	handle handle_;
	owner owner_;
};


template<typename _HTraits>
class handle_base<_HTraits, void>
{
public:

	using handle = typename _HTraits::handle;
	using htraits = _HTraits;
	
	handle_base() : handle_{htraits::empty()} {}
	explicit handle_base(const handle & h) : handle_{h} {}

	handle_base(handle_base && rv) : handle_{rv.handle_}
	{
		rv.handle_ = htraits::empty();
	}
	handle_base & operator=(handle_base && rv)
	{
		std::swap(handle_, rv.handle_);
		return *this;
	}
	
	handle_base(const handle_base &) = delete;
	handle_base & operator=(const handle_base &) = delete;
	
	handle handle_;
};


template<typename _Htraits, typename _OTraits>
using handle_slave = handle_base<_Htraits, _OTraits>;

template<typename _Htraits>
using handle_owner = handle_base<_Htraits, void>;

__EGL_END__

#endif // __EGL_DISPLAY_INCLUDED__