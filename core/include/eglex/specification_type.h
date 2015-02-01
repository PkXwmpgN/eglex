//
//  elgex/specification_type.h
//  core library
//
//  Created by Alexey Yegorov (yegorov.alex@gmail.com)
//

#ifndef __EGL_SPECIFICATION_TYPE_INCLUDED__
#define __EGL_SPECIFICATION_TYPE_INCLUDED__

#include <eglex/egl.h>
#include <eglex/specification.h>
#include <eglex/specification_enum.h>

__EGL_BEGIN__

namespace specs
{
	// client attributes

	template<client_attribute_code code>
	using client_attribute = attribute<client_attribute_code, const char*, code>;

	// client rendering APIs are supported.
	using client_api = client_attribute<client_attribute_code::CLIENT_APIS>;

	// vendor of EGL library
	using client_vendor = client_attribute<client_attribute_code::VENDOR>;

	// version of EGL library
	using client_version = client_attribute<client_attribute_code::VERSION>;

	// EGL extensions are supported
	using client_extentions = client_attribute<client_attribute_code::EXTENSIONS>;


	// config attributes

	template<config_attribute_code code, typename _Result>
	using config_attribute = attribute<config_attribute_code, _Result, code>;

	// total color component bits in the color buffer (integer, default 0)
	using config_buffer_size = config_attribute<config_attribute_code::BUFFER_SIZE, int_type>;

	// bits of red in the color buffer (integer, default 0)
	using config_red_size = config_attribute<config_attribute_code::RED_SIZE, int_type>;

	// bits of green in the color buffer (integer, default 0)
	using config_green_size = config_attribute<config_attribute_code::GREEN_SIZE, int_type>;

	// bits of blue in the color buffer (integer, default 0)
	using config_blue_size = config_attribute<config_attribute_code::BLUE_SIZE, int_type>;

	// bits of luminance in the color buffer (integer, default 0)
	using config_luminance_size = config_attribute<config_attribute_code::LUMINANCE_SIZE, int_type>;

	// bits of Alpha in the color buffer (integer, default 0)
	using config_alpha_size = config_attribute<config_attribute_code::ALPHA_SIZE, int_type>;

	// bits of Alpha Mask in the mask buffer (integer, default 0)
	using config_alpha_mask_size = config_attribute<config_attribute_code::ALPHA_MASK_SIZE, int_type>;

	// bits of Z in the depth buffer (integer, default 0)
	using config_depth_size = config_attribute<config_attribute_code::DEPTH_SIZE, int_type>;

	// bits of stencil in the stencil buffer (integer, default 0)
	using config_stencil_size = config_attribute<config_attribute_code::STENCIL_SIZE, int_type>;

	// True if bindable to RGB textures (bool, default egl::DONT_CARE)
	using config_bind_to_texture_rgb = config_attribute<config_attribute_code::BIND_TO_TEXTURE_RGB, bool>;

	// True if bindable to RGBA textures (bool, default egl::DONT_CARE)
	using config_bind_to_rexture_rgba = config_attribute<config_attribute_code::BIND_TO_TEXTURE_RGBA, bool>;

	//  color buffer type (enum egl::specs::color_buffer, default color_buffer::rgb)
	using config_color_buffer_type = config_attribute<config_attribute_code::COLOR_BUFFER_TYPE, color_buffer>;

	// client APIs are supported (bitset egl::specs::renderer, default renderer::opengl_es)
	using config_renderable_type = config_attribute<config_attribute_code::RENDERABLE_TYPE, renderer>;

	// any caveats for the configuration (enum egl::specs::caveat, caveat::dont_care)
	using config_caveat = config_attribute<config_attribute_code::CONFIG_CAVEAT, caveat>;

	// unique EGL config identifier (integer, default 0)
	using config_id = config_attribute<config_attribute_code::CONFIG_ID, int_type>;

	// whether contexts created with this config are conformant(bitset egl::specs::renderer, default renderer::empty)
	using config_conformant = config_attribute<config_attribute_code::CONFORMANT, renderer>;

	// frame buffer level (integer, default 0)
	using config_level = config_attribute<config_attribute_code::LEVEL, int_type>;

	// maximum width of pbuffer (integer, default egl::DONT_CARE)
	using config_max_pbuffer_width = config_attribute<config_attribute_code::MAX_PBUFFER_WIDTH, int_type>;

	// maximum height of pbuffer (integer, default egl::DONT_CARE)
	using config_max_pbuffer_height = config_attribute<config_attribute_code::MAX_PBUFFER_HEIGHT, int_type>;

	// maximum size of pbuffer (integer, default egl::DONT_CARE)
	using config_max_pbuffer_pixels = config_attribute<config_attribute_code::MAX_PBUFFER_PIXELS, int_type>;

	// maximum swap interval (integer, default egl::DONT_CARE)
	using config_max_swap_interval = config_attribute<config_attribute_code::MAX_SWAP_INTERVAL, int_type>;

	// minimum swap interval (integer, default egl::DONT_CARE)
	using config_min_swap_interval = config_attribute<config_attribute_code::MIN_SWAP_INTERVAL, int_type>;

	// if native rendering APIs can render to surface (bool, default egl::DONT_CARE)
	using congig_native_randerable = config_attribute<config_attribute_code::NATIVE_RENDERABLE, bool>;

	// handle of corresponding native visual(integer)
	using config_native_visual_id = config_attribute<config_attribute_code::NATIVE_VISUAL_ID, int_type>;

	// native visual type of the associated visual (integer)
	using config_native_visual_type = config_attribute<config_attribute_code::NATIVE_VISUAL_TYPE, int_type>;

	// number of multisample buffers (integer, default 0)
	using config_sample_buffers = config_attribute<config_attribute_code::SAMPLE_BUFFERS, int_type>;

	// number of samples per pixel (integer, default 0)
	using config_samples = config_attribute<config_attribute_code::SAMPLES, int_type>;

	// types of EGL surfaces are supported (bitset egl::specs::surface, default surface::window)
	using config_surface_type = config_attribute<config_attribute_code::SURFACE_TYPE, surface>;

	// type of transparency supported (enum egl::specs::transparent, default transparent::none)
	using config_transparent_type = config_attribute<config_attribute_code::TRANSPARENT_TYPE, transparent>;

	// transparent red value (integer, default egl::DONT_CARE)
	using config_transparent_red = config_attribute<config_attribute_code::TRANSPARENT_RED_VALUE, int_type>;

	// transparent gree value (integer, default egl::DONT_CARE)
	using config_transparent_green = config_attribute<config_attribute_code::TRANSPARENT_GREEN_VALUE, int_type>;

	// transparent blue value (integer, default egl::DONT_CARE)
	using config_transparent_blue = config_attribute<config_attribute_code::TRANSPARENT_BLUE_VALUE, int_type>;
	

	// context attributtes

	template<context_attribute_code code, typename _Result>
	using context_attribute = attribute<context_attribute_code, _Result, code>;

	// unique EGL config identifier with respect to which the context was created (integer)
	using context_config_id = context_attribute<context_attribute_code::CONFIG_ID, int_type>;

	// the type of client API this context supports (enum egl::api)
	using context_type = context_attribute<context_attribute_code::CLIENT_TYPE, api>;

	// the version of the client OpenGL ES this context supports (integer) 
	using context_version = context_attribute<context_attribute_code::CLIENT_VERSION, int_type>;

	// the buffer which client API rendering via this context will use (enum egl::render_buffer)
	using context_render_buffer = context_attribute<context_attribute_code::RENDER_BUFFER, render_buffer>;

	
	// surface attributes
	
	template<surface_attribute_code code, typename _Result>
	using surface_attribute = attribute<surface_attribute_code, _Result, code>;
	
	// the pixel width and width of the rectangular pbuffer (integer)
	using surface_width = surface_attribute<surface_attribute_code::WIDTH, int_type>;

	// the pixel width and height of the rectangular pbuffer (integer)
	using surface_height = surface_attribute<surface_attribute_code::HEIGHT, int_type>;

	// the horizontal dot pitch (integer)
	using surface_horz_resolution = surface_attribute<surface_attribute_code::HORIZONTAL_RESOLUTION, int_type>;

	// the vertical dot pitch (integer)
	using surface_vert_resolution = surface_attribute<surface_attribute_code::VERTICAL_RESOLUTION, int_type>;

	// true if create largest pbuffer possible (bool)
	using surface_largest_pbuffer = surface_attribute<surface_attribute_code::LARGEST_PBUFFER, bool>;

	// true if texture has mipmaps (bool)
	using surface_mipmap_texture = surface_attribute<surface_attribute_code::MIPMAP_TEXTURE, bool>;

	// multisample resolve behavior (enum egl::specs::multisample)
	using surface_multisample_resolve = surface_attribute<surface_attribute_code::MULTISAMPLE_RESOLVE, multisample>;

	// buffer swap behavior (enum egl::specs::swap_behavior)
	using surface_swap_behavior = surface_attribute<surface_attribute_code::SWAP_BEHAVIOR, swap_behavior>;

	// format of texture (enum egl::specs::texture_format)
	using surface_texture_format = surface_attribute<surface_attribute_code::TEXTURE_FORMAT, texture_format>;

	// type of texture (egl::specs::texture_target)
	using surface_texture_target = surface_attribute<surface_attribute_code::TEXTURE_TARGET, texture_target>;


	// empty specification
	const specification empty;

	// config specification

	const specification RGB888_ES2
	{
		config_renderable_type(renderer::opengl_es2),
		config_red_size(8),
		config_green_size(8),
		config_blue_size(8),
		config_depth_size(24)
	};

	const specification ARGB4444_ES2 =
	{
		config_renderable_type(renderer::opengl_es2),
		config_red_size(4),
		config_green_size(4),
		config_blue_size(4),
		config_alpha_size(4),
		config_depth_size(24)
	};

	const specification RGB565_ES2 =
	{
		config_renderable_type(renderer::opengl_es2),
		config_red_size(5),
		config_green_size(6),
		config_blue_size(5),
		config_depth_size(24)
	};

	// context specification
	const specification ES2
	{
		context_version(2)
	};
}

__EGL_END__

#endif // __EGL_SPECIFICATION_TYPE_INCLUDED__