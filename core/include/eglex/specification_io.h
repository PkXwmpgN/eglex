//
//  elgex/specification_io.h
//  core library
//
//  Created by Alexey Yegorov (yegorov.alex@gmail.com)
//

#ifndef __EGL_SPECIFICATION_IO_INCLUDED__
#define __EGL_SPECIFICATION_IO_INCLUDED__

#include <eglex/egl.h>
#include <eglex/specification_enum.h>

__EGL_BEGIN__

template<typename _Code, typename _Value, _Code code>
struct attribute;

template<typename _Code, typename _Value, _Code code, typename _Elem, typename _Traits>
inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
	const attribute<_Code, _Value, code> & spec)
{
	out << spec.get_code() << " : " << spec.get_value();
	return out;
}

namespace specs
{
	template<typename _T, typename _Elem = char, typename _Traits = std::char_traits<_Elem>>
	class infix_ostream_iterator : public std::iterator<std::output_iterator_tag, void, void, void, void>
	{
	public:
		using ostream_type = std::basic_ostream<_Elem, _Traits>;
		using char_type = _Elem;
		using traits_type = _Traits;
		using out_type = _T;

		infix_ostream_iterator(ostream_type & ostr, const char_type * delim = nullptr)
			: stream(&ostr)
			, delimeter(delim)
			, first(true){}

		infix_ostream_iterator & operator= (const out_type & value)
		{	
			if (!first && delimeter)
				*stream << delimeter;
			*stream << value;
			first = false;
			return *this;
		}

		infix_ostream_iterator & operator* () { return *this; }
		infix_ostream_iterator & operator++ () { return *this; }
		infix_ostream_iterator & operator++ (int) { return *this; }

	private:
		ostream_type * stream;
		const char_type * delimeter;
		bool first;
	};
	template<typename _Elem, typename _Traits>
	inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
		const api & en)
	{
		switch (en)
		{
		case api::opengl:
			return out << "EGL_OPENGL_API";
		case api::opengl_es:
			return out << "EGL_OPENGL_ES_API";
		}
		return out;
	}

	template<typename _Elem, typename _Traits>
	inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
		const color_buffer & en)
	{
		switch (en)
		{
		case color_buffer::dont_care:
			return out << "EGL_DONT_CARE";
		case color_buffer::rgb:
			return out << "EGL_RGB_BUFFER";
		case color_buffer::luminance:
			return out << "EGL_LUMINANCE_BUFFER";
		}
		return out;
	}

	template<typename _Elem, typename _Traits>
	inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
		const renderer & en)
	{
		if (en == renderer::empty)
			return out << "EGL_NONE";
		else if (en == renderer::dont_care)
			return out << "EGL_DONT_CARE";
		
		std::vector<const char *> flags;
		if ((en & renderer::opengl) == renderer::opengl)
			flags.push_back("EGL_OPENGL_BIT");
		if ((en & renderer::opengl_es) == renderer::opengl_es)
			flags.push_back("EGL_OPENGL_ES_BIT");
		if ((en & renderer::opengl_es2) == renderer::opengl_es2)
			flags.push_back("EGL_OPENGL_ES2_BIT");

		using out_iterator = infix_ostream_iterator<const char *, _Elem, _Traits>;
		std::copy(flags.begin(), flags.end(), out_iterator(out, "|"));
		return out;
	}

	template<typename _Elem, typename _Traits>
	inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
		const caveat & en)
	{
		switch (en)
		{
		case caveat::none:
			return out << "EGL_NONE";
		case caveat::dont_care:
			return out << "EGL_DONT_CARE";
		case caveat::slow:
			return out << "EGL_SLOW_CONFIG";
		case caveat::non_conformant:
			return out << "EGL_NON_CONFORMANT_CONFIG";
		}
		return out;
	}

	template<typename _Elem, typename _Traits>
	inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
		const surface & en)
	{
		if (en == surface::empty)
			return out << "EGL_NONE";
		else if (en == surface::dont_care)
			return out << "EGL_DONT_CARE";

		std::vector<const char *> flags;
		if ((en & surface::window) == surface::window)
			flags.push_back("EGL_WINDOW_BIT");
		if ((en & surface::pixmap) == surface::pixmap)
			flags.push_back("EGL_PIXMAP_BIT");
		if ((en & surface::pbuffer) == surface::pbuffer)
			flags.push_back("EGL_PBUFFER_BIT");
		if ((en & surface::multisample_resolve_box) == surface::multisample_resolve_box)
			flags.push_back("EGL_MULTISAMPLE_RESOLVE_BOX_BIT");
		if ((en & surface::swap_behavior_preserved) == surface::swap_behavior_preserved)
			flags.push_back("EGL_SWAP_BEHAVIOR_PRESERVED_BIT");

		using out_iterator = infix_ostream_iterator<const char *, _Elem, _Traits>;
		std::copy(flags.begin(), flags.end(), out_iterator(out, "|"));
		return out;
	}

	template<typename _Elem, typename _Traits>
	inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
		const transparent & en)
	{
		switch (en)
		{
		case transparent::none:
			return out << "EGL_NONE";
		case transparent::rgb:
			return out << "EGL_TRANSPARENT_RGB";
		case transparent::dont_care:
			return out << "EGL_DONT_CARE";
		}
		return out;
	}

	template<typename _Elem, typename _Traits>
	inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
		const render_buffer & en)
	{
		switch (en)
		{
		case render_buffer::none:
			return out << "EGL_NONE";
		case render_buffer::single:
			return out << "EGL_SINGLE_BUFFER";
		case render_buffer::back:
			return out << "EGL_BACK_BUFFER";
		}
		return out;
	}

	template<typename _Elem, typename _Traits>
	inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
		const multisample & en)
	{
		switch (en)
		{
		case multisample::default:
			return out << "EGL_MULTISAMPLE_RESOLVE_DEFAULT";
		case multisample::box:
			return out << "EGL_MULTISAMPLE_RESOLVE_BOX";
		}
		return out;
	}

	template<typename _Elem, typename _Traits>
	inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
		const swap_behavior & en)
	{
		switch (en)
		{
		case swap_behavior::preserved:
			return out << "EGL_BUFFER_PRESERVED";
		case swap_behavior::destroyed:
			return out << "EGL_BUFFER_DESTROYED";
		}
		return out;
	}

	template<typename _Elem, typename _Traits>
	inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
		const texture_format & en)
	{
		switch (en)
		{
		case texture_format::no:
			return out << "EGL_NO_TEXTURE";
		case texture_format::rgb:
			return out << "EGL_TEXTURE_RGB";
		case texture_format::rgba:
			return out << "EGL_TEXTURE_RGBA";
		}
		return out;
	}

	template<typename _Elem, typename _Traits>
	inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
		const texture_target & en)
	{
		switch (en)
		{
		case texture_target::target_no:
			return out << "EGL_NO_TEXTURE";
		case texture_target::target_2D:
			return out << "EGL_TEXTURE_2D";
		}
		return out;
	}

	template<typename _Elem, typename _Traits>
	inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
		const client_attribute_code & en)
	{
		switch (en)
		{
		case client_attribute_code::CLIENT_APIS:
			return out << "EGL_CLIETN_APIS";
		case client_attribute_code::VENDOR:
			return out << "EGL_VENDOR";
		case client_attribute_code::VERSION:
			return out << "EGL_VERSION";
		case client_attribute_code::EXTENSIONS:
			return out << "EGL_EXTENSIONS";
		}
		return out;
	}

	template<typename _Elem, typename _Traits>
	inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
		const config_attribute_code & en)
	{
		switch (en)
		{
		case config_attribute_code::BUFFER_SIZE:
			return out << "EGL_BUFFER_SIZE";
		case config_attribute_code::RED_SIZE:
			return out << "EGL_RED_SIZE";
		case config_attribute_code::GREEN_SIZE:
			return out << "EGL_GREEN_SIZE";
		case config_attribute_code::BLUE_SIZE:
			return out << "EGL_BLUE_SIZE";
		case config_attribute_code::DEPTH_SIZE:
			return out << "EGL_DEPTH_SIZE";
		case config_attribute_code::LUMINANCE_SIZE:
			return out << "EGL_LUMINANCE_SIZE";
		case config_attribute_code::STENCIL_SIZE:
			return out << "EGL_STENCIL_SIZE";
		case config_attribute_code::ALPHA_SIZE:
			return out << "EGL_ALPHA_SIZE";
		case config_attribute_code::ALPHA_MASK_SIZE:
			return out << "EGL_ALPHA_MASK_SIZE";
		case config_attribute_code::BIND_TO_TEXTURE_RGB:
			return out << "EGL_BIND_TO_TEXTURE_RGB";
		case config_attribute_code::BIND_TO_TEXTURE_RGBA:
			return out << "EGL_BIND_TO_TEXTURE_RGBA";
		case config_attribute_code::RENDERABLE_TYPE:
			return out << "EGL_RENDERABLE_TYPE";
		case config_attribute_code::CONFIG_CAVEAT:
			return out << "EGL_CONFIG_CAVEAT";
		case config_attribute_code::CONFIG_ID:
			return out << "EGL_CONFIG_ID";
		case config_attribute_code::CONFORMANT:
			return out << "EGL_CONFORMANT";
		case config_attribute_code::LEVEL:
			return out << "EGL_LEVEL";
		case config_attribute_code::MAX_PBUFFER_WIDTH:
			return out << "EGL_MAX_PBUFFER_WIDTH";
		case config_attribute_code::MAX_PBUFFER_HEIGHT:
			return out << "EGL_MAX_PBUFFER_HEIGHT";
		case config_attribute_code::MAX_PBUFFER_PIXELS:
			return out << "EGL_MAX_PBUFFER_PIXELS";
		case config_attribute_code::MAX_SWAP_INTERVAL:
			return out << "EGL_MAX_SWAP_INTERVAL";
		case config_attribute_code::MIN_SWAP_INTERVAL:
			return out << "EGL_MIN_SWAP_INTERVAL";
		case config_attribute_code::NATIVE_RENDERABLE:
			return out << "EGL_NATIVE_RENDERABLE";
		case config_attribute_code::NATIVE_VISUAL_ID:
			return out << "EGL_NATIVE_VISUAL_ID";
		case config_attribute_code::NATIVE_VISUAL_TYPE:
			return out << "EGL_NATIVE_VISUAL_TYPE";
		case config_attribute_code::SAMPLE_BUFFERS:
			return out << "EGL_SAMPLE_BUFFERS";
		case config_attribute_code::SAMPLES:
			return out << "EGL_SAMPLES";
		case config_attribute_code::SURFACE_TYPE:
			return out << "EGL_SURFACE_TYPE";
		case config_attribute_code::TRANSPARENT_TYPE:
			return out << "EGL_TRANSPARENT_TYPE";
		case config_attribute_code::TRANSPARENT_RED_VALUE:
			return out << "EGL_TRANSPARENT_RED_VALUE";
		case config_attribute_code::TRANSPARENT_GREEN_VALUE:
			return out << "EGL_TRANSPARENT_GREEN_VALUE";
		case config_attribute_code::TRANSPARENT_BLUE_VALUE:
			return out << "EGL_TRANSPARENT_BLUE_VALUE";
		case config_attribute_code::COLOR_BUFFER_TYPE:
			return out << "EGL_COLOR_BUFFER_TYPE";
		}
		return out;
	}

	template<typename _Elem, typename _Traits>
	inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
		const context_attribute_code & en)
	{
		switch (en)
		{
		case context_attribute_code::CONFIG_ID:
			return out << "EGL_CONFIG_ID";
		case context_attribute_code::CLIENT_TYPE:
			return out << "EGL_CONTEXT_CLIENT_TYPE";
		case context_attribute_code::CLIENT_VERSION:
			return out << "EGL_CONTEXT_CLIENT_VERSION";
		case context_attribute_code::RENDER_BUFFER:
			return out << "EGL_RENDER_BUFFER";
		}
		return out;
	}

	template<typename _Elem, typename _Traits>
	inline std::basic_ostream<_Elem, _Traits> & operator << (std::basic_ostream<_Elem, _Traits> & out,
		const surface_attribute_code & en)
	{
		switch (en)
		{
		case surface_attribute_code::WIDTH:
			return out << "EGL_WIDTH";
		case surface_attribute_code::HEIGHT:
			return out << "EGL_HEIGHT";
		case surface_attribute_code::HORIZONTAL_RESOLUTION:
			return out << "EGL_HORIZONTAL_RESOLUTION";
		case surface_attribute_code::VERTICAL_RESOLUTION:
			return out << "EGL_VERTICAL_RESOLUTION";
		case surface_attribute_code::LARGEST_PBUFFER:
			return out << "EGL_LARGEST_PBUFFER";
		case surface_attribute_code::MIPMAP_TEXTURE:
			return out << "EGL_MIPMAP_TEXTURE";
		case surface_attribute_code::MULTISAMPLE_RESOLVE:
			return out << "EGL_MULTISAMPLE_RESOLVE";
		case surface_attribute_code::SWAP_BEHAVIOR:
			return out << "EGL_SWAP_BEHAVIOR";
		case surface_attribute_code::TEXTURE_FORMAT:
			return out << "EGL_TEXTURE_FORMAT";
		case surface_attribute_code::TEXTURE_TARGET:
			return out << "EGL_TEXTURE_TARGET";
		}
		return out;
	}
}

__EGL_END__

#endif // __EGL_SPECIFICATION_IO_INCLUDED__