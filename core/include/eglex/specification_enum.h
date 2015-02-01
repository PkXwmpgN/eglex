//
//  elgex/specification_enum.h
//  core library
//
//  Created by Alexey Yegorov (yegorov.alex@gmail.com)
//

#ifndef __EGL_SPECIFICATION_ENUM_INCLUDED__
#define __EGL_SPECIFICATION_ENUM_INCLUDED__

#include <eglex/egl.h>

__EGL_BEGIN__

namespace specs
{
	enum class api : int_type
	{
		opengl = EGL_OPENGL_API,
		opengl_es = EGL_OPENGL_ES_API
	};

	enum class color_buffer : int_type
	{
		dont_care = EGL_DONT_CARE,

		rgb = EGL_RGB_BUFFER,
		luminance = EGL_LUMINANCE_BUFFER
	};

	enum class renderer : int_type
	{
		dont_care = EGL_DONT_CARE,

		empty = 0,
		opengl = EGL_OPENGL_BIT,
		opengl_es = EGL_OPENGL_ES_BIT,
		opengl_es2 = EGL_OPENGL_ES2_BIT,
		all = EGL_OPENGL_BIT | EGL_OPENGL_ES_BIT | EGL_OPENGL_ES2_BIT
	};

	enum class caveat : int_type
	{
		dont_care = EGL_DONT_CARE,

		none = EGL_NONE,
		slow = EGL_SLOW_CONFIG,
		non_conformant = EGL_NON_CONFORMANT_CONFIG
	};

	enum class surface : int_type
	{
		dont_care = EGL_DONT_CARE,

		empty = 0,
		window = EGL_WINDOW_BIT,
		pixmap = EGL_PIXMAP_BIT,
		pbuffer = EGL_PBUFFER_BIT,
		multisample_resolve_box = EGL_MULTISAMPLE_RESOLVE_BOX_BIT,
		swap_behavior_preserved = EGL_SWAP_BEHAVIOR_PRESERVED_BIT,
		
		all = EGL_PIXMAP_BIT | EGL_PIXMAP_BIT | EGL_PBUFFER_BIT | 
			  EGL_MULTISAMPLE_RESOLVE_BOX_BIT | EGL_SWAP_BEHAVIOR_PRESERVED_BIT
	};

	enum class transparent : int_type
	{
		dont_care = EGL_DONT_CARE,

		none = EGL_NONE,
		rgb = EGL_TRANSPARENT_RGB
	};

	enum class render_buffer : int_type
	{
		none = EGL_NONE,
		single = EGL_SINGLE_BUFFER,
		back = EGL_BACK_BUFFER
	};

	enum class multisample : int_type
	{
		default = EGL_MULTISAMPLE_RESOLVE_DEFAULT,
		box = EGL_MULTISAMPLE_RESOLVE_BOX
	};

	enum class swap_behavior : int_type
	{
		preserved = EGL_BUFFER_PRESERVED,
		destroyed = EGL_BUFFER_DESTROYED
	};

	enum class texture_format : int_type
	{
		no = EGL_NO_TEXTURE,
		rgb = EGL_TEXTURE_RGB,
		rgba = EGL_TEXTURE_RGBA
	};

	enum class texture_target : int_type
	{
		target_no = EGL_NO_TEXTURE,
		target_2D = EGL_TEXTURE_2D
	};

	enum class client_attribute_code : int_type
	{
		CLIENT_APIS = EGL_CLIENT_APIS,
		VENDOR = EGL_VENDOR,
		VERSION = EGL_VERSION,
		EXTENSIONS = EGL_EXTENSIONS,
	};

	enum class config_attribute_code : int_type
	{
		BUFFER_SIZE = EGL_BUFFER_SIZE,
		RED_SIZE = EGL_RED_SIZE,
		GREEN_SIZE = EGL_GREEN_SIZE,
		BLUE_SIZE = EGL_BLUE_SIZE,
		DEPTH_SIZE = EGL_DEPTH_SIZE,
		LUMINANCE_SIZE = EGL_LUMINANCE_SIZE,
		STENCIL_SIZE = EGL_STENCIL_SIZE,
		ALPHA_SIZE = EGL_ALPHA_SIZE,
		ALPHA_MASK_SIZE = EGL_ALPHA_MASK_SIZE,
		BIND_TO_TEXTURE_RGB = EGL_BIND_TO_TEXTURE_RGB,
		BIND_TO_TEXTURE_RGBA = EGL_BIND_TO_TEXTURE_RGBA,
		RENDERABLE_TYPE = EGL_RENDERABLE_TYPE,
		CONFIG_CAVEAT = EGL_CONFIG_CAVEAT,
		CONFIG_ID = EGL_CONFIG_ID,
		CONFORMANT = EGL_CONFORMANT,
		LEVEL = EGL_LEVEL,
		MAX_PBUFFER_WIDTH = EGL_MAX_PBUFFER_WIDTH,
		MAX_PBUFFER_HEIGHT = EGL_MAX_PBUFFER_HEIGHT,
		MAX_PBUFFER_PIXELS = EGL_MAX_PBUFFER_PIXELS,
		MAX_SWAP_INTERVAL = EGL_MAX_SWAP_INTERVAL,
		MIN_SWAP_INTERVAL = EGL_MIN_SWAP_INTERVAL,
		NATIVE_RENDERABLE = EGL_NATIVE_RENDERABLE,
		NATIVE_VISUAL_ID = EGL_NATIVE_VISUAL_ID,
		NATIVE_VISUAL_TYPE = EGL_NATIVE_VISUAL_TYPE,
		SAMPLE_BUFFERS = EGL_SAMPLE_BUFFERS,
		SAMPLES = EGL_SAMPLES,
		SURFACE_TYPE = EGL_SURFACE_TYPE,
		TRANSPARENT_TYPE = EGL_TRANSPARENT_TYPE,
		TRANSPARENT_RED_VALUE = EGL_TRANSPARENT_RED_VALUE,
		TRANSPARENT_GREEN_VALUE = EGL_TRANSPARENT_GREEN_VALUE,
		TRANSPARENT_BLUE_VALUE = EGL_TRANSPARENT_BLUE_VALUE,
		COLOR_BUFFER_TYPE = EGL_COLOR_BUFFER_TYPE
	};

	enum class context_attribute_code : int_type
	{
		CONFIG_ID = EGL_CONFIG_ID,
		CLIENT_TYPE = EGL_CONTEXT_CLIENT_TYPE,
		CLIENT_VERSION = EGL_CONTEXT_CLIENT_VERSION,
		RENDER_BUFFER = EGL_RENDER_BUFFER
	};

	enum class surface_attribute_code : int_type
	{
		WIDTH = EGL_WIDTH,
		HEIGHT = EGL_HEIGHT,
		HORIZONTAL_RESOLUTION = EGL_HORIZONTAL_RESOLUTION,
		VERTICAL_RESOLUTION = EGL_VERTICAL_RESOLUTION,
		LARGEST_PBUFFER = EGL_LARGEST_PBUFFER,
		MIPMAP_TEXTURE = EGL_MIPMAP_TEXTURE,
		MULTISAMPLE_RESOLVE = EGL_MULTISAMPLE_RESOLVE,
		SWAP_BEHAVIOR = EGL_SWAP_BEHAVIOR,
		TEXTURE_FORMAT = EGL_TEXTURE_FORMAT,
		TEXTURE_TARGET = EGL_TEXTURE_TARGET
	};

	template<typename _Enum>
	inline auto to_integral(_Enum en) -> typename std::underlying_type<_Enum>::type
	{
		return static_cast<typename std::underlying_type<_Enum>::type>(en);
	}

	template<typename _Enum> struct is_bitset : std::false_type {};
	template<> struct is_bitset<surface> : std::true_type{};
	template<> struct is_bitset<renderer> : std::true_type{};

	template<typename _Enum, typename = std::enable_if<is_bitset<_Enum>::value>::type>
	inline _Enum operator| (_Enum l, _Enum r)
	{
		return static_cast<_Enum>(to_integral(l) | to_integral(r));
	}

	template<typename _Enum, typename = std::enable_if<is_bitset<_Enum>::value>::type>
	inline _Enum operator& (_Enum l, _Enum r)
	{
		return static_cast<_Enum>(to_integral(l) & to_integral(r));
	}

	template<typename _Enum, typename = std::enable_if<is_bitset<_Enum>::value>::type>
	inline _Enum operator|= (_Enum & l, _Enum r)
	{
		return l = l | r;
	}

	template<typename _Enum, typename = std::enable_if<is_bitset<_Enum>::value>::type>
	inline _Enum operator&= (_Enum & l, _Enum r)
	{
		return l = l & r;
	}
}



__EGL_END__

#endif // __EGL_SPECIFICATION_ENUM_INCLUDED__