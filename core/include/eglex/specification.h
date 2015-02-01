//
//  elgex/specification.h
//  core library
//
//  Created by Alexey Yegorov (yegorov.alex@gmail.com)
//

#ifndef __EGL_SPECIFICATION_INCLUDED__
#define __EGL_SPECIFICATION_INCLUDED__

#include <eglex/egl.h>
#include <vector>

__EGL_BEGIN__

template<typename _Translator>
struct enable_to_attribute
{
	template<typename _Result, typename _Code>
	_Result get_attribute(_Code attribute) const
	{
		return static_cast<_Result>(static_cast<const _Translator*>(this)->get_attribute(attribute));
	}
};

template<typename _Code, typename _Value, _Code code>
struct attribute
{
	using code_type = _Code;
	using value_type = _Value;

	explicit attribute(value_type v) : value{v} {}
	
	template<typename _Translator>
	explicit attribute(const enable_to_attribute<_Translator> & t) : value{ t.get_attribute<value_type>(code) }{}

	operator value_type() { return value; }

	code_type get_code() const { return code; }
	value_type get_value() const { return value; }

private:
	value_type value;
};


class specification
{
	using specifications_t = std::vector<int_type>;

public:

	template<typename ..._Specs>
	specification(_Specs && ...specs)
	{
		generate_(std::forward<_Specs>(specs)...);
	}

	specifications_t::const_pointer data() const { return specs_.data(); }

private:

	template<typename _Code, typename _Value, _Code code, typename ..._Tail>
	void generate_(attribute<_Code, _Value, code> && attrib, _Tail && ...tail)
	{
		using attribute_type = attribute<_Code, _Value, code>;
		add_spec(std::forward<attribute_type>(attrib));
		generate_(std::forward<_Tail>(tail)...);
	}

	void generate_()
	{
		add_spec(attribute<int_type, int_type, EGL_NONE>(EGL_NONE));
	}

	template<typename _Code, typename _Value, _Code code>
	void add_spec(attribute<_Code, _Value, code> && attribute)
	{
		specs_.push_back(static_cast<int_type>(attribute.get_code()));
		specs_.push_back(static_cast<int_type>(attribute.get_value()));
	}

private:
	specifications_t specs_;
};


__EGL_END__

#endif // __EGL_SPECIFICATION_INCLUDED__