//
//  elgex/configs.h
//  core library
//
//  Created by Alexey Yegorov (yegorov.alex@gmail.com)
//

#ifndef __EGL_CONFIGS_INCLUDED__
#define __EGL_CONFIGS_INCLUDED__

#include <eglex/traits.h>
#include <eglex/handle.h>
#include <eglex/display.h>
#include <eglex/specification.h>
#include <eglex/specification_enum.h>

#include <vector>

__EGL_BEGIN__

class config : private handle_slave<config_type_traits, display_type_traits>
			 , public enable_to_attribute<config>
{
public:

	using base = handle_slave<config_type_traits, display_type_traits>;
	using handle = base::handle;
	using owner = base::owner;
	using htraits = base::htraits;
	using otraits = base::otraits;

	config() : base{} {}
	config(const handle &h, const owner & own) : base{h, own} {}
	config(config && conf) : base{std::move(conf)} {}
	config & operator=(config && rv)
	{
		base::operator=(std::move(rv));
		return *this;
	}

	const handle & get_handle() const { return handle_; }
	const owner & get_owner() const { return owner_; }
	bool valid() const { return !(handle_ == htraits::empty() && owner_ == otraits::empty()); }

	int_type get_attribute(specs::config_attribute_code attribute) const
	{
        return details::GetConfigAttrib(owner_, handle_, specs::to_integral(attribute));
	}
};

class configs
{
public:

    using container_native_type = std::vector<config::handle>;
	using container_type = std::vector<config>;
	using const_iterator = container_type::const_iterator;
	using const_reverse_iterator = container_type::const_reverse_iterator;
	using const_reference = container_type::const_reference;

	explicit configs(const display & disp)
	{
        query_configs(disp);
	}

	configs(const display & disp, const specification & specs)
	{
        query_configs(disp, specs);
	}

	bool empty() const { return configs_.empty(); }

	const_iterator begin() const { return configs_.begin(); }
	const_iterator end() const { return configs_.end(); }

	const_reverse_iterator rbegin() const { return configs_.rbegin(); }
	const_reverse_iterator rend() const { return configs_.rend(); }

	const_reference front() const { return configs_.front(); }
	const_reference back() const { return configs_.back(); }

private:

	void query_configs(const display & disp)
	{
		int_type count = 0;
		details::GetConfigs(disp.get_handle(), nullptr, 0, &count);

        container_native_type raw_configs(count);
        details::GetConfigs(disp.get_handle(), raw_configs.data(), raw_configs.size(), &count);

        configurate(disp, raw_configs);
	}

	void query_configs(const display & disp, const specification & specs)
	{
		int_type count = 0;
		details::ChooseConfig(disp.get_handle(), specs.data(), nullptr, 0, &count);

        container_native_type raw_configs(count);
		details::ChooseConfig(disp.get_handle(), specs.data(), raw_configs.data(), raw_configs.size(), &count);

        configurate(disp, raw_configs);
	}

    void configurate(const display & disp, container_native_type & raw_configs)
	{
		for(auto & raw : raw_configs)
			configs_.emplace_back(raw, disp.get_handle());
	}

private:

	container_type configs_;
};

__EGL_END__

#endif // __EGL_CONFIGS_INCLUDED__