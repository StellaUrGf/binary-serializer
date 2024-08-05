#include "wmemory_t.hh"
namespace utils
{
	const wmemory_t* wmemory_t::resize(const size_t& size)
	{
		m_data->resize(size);
		return this;
	}
	const wmemory_t* wmemory_t::skip(const size_t& size)
	{
		m_data->add_len(size);
		return this;
	}
	const wmemory_t* wmemory_t::reserve(const size_t& size)
	{
		m_data->reserve(size);
		return this;
	}
	const wmemory_t* wmemory_t::reverse() noexcept(true)
	{
		m_data->reverse();
		return this;
	}
	const wmemory_t* wmemory_t::cleanup() noexcept(true)
	{
		if (!m_data)
			return this;
		m_data->cleanup();
		delete m_data;
		return this;
	}
	wmemory_t::wmemory_t(const size_t& size)
	{
		m_data = new unique_ptr(size);
	}
	wmemory_t::wmemory_t(uint8_t* blc, size_t size)
	{
		m_data = new unique_ptr(blc, size);
	}
	wmemory_t* wmemory_t::write(const std::string& value)
	{
		uintmax_t estimate = sizeof(uint16_t) + value.size();
		if (m_data->lens() + estimate > m_data->size())
			m_data->resize(m_data->size() + estimate);
		uint16_t len = static_cast<uint16_t>(value.size());
		std::memcpy(m_data->begin() + m_data->lens(), &len, sizeof(uint16_t));
		m_data->add_len(sizeof(uint16_t));
		std::memcpy(m_data->begin() + m_data->lens(), value.c_str(), len);
		m_data->add_len(len);
		return this;
	}
	wmemory_t* wmemory_t::write(const std::uint8_t& value)
	{
		uint16_t estimate = sizeof(uint8_t);
		if (m_data->lens() + estimate > m_data->size())
			m_data->resize(m_data->size() + estimate);
		std::memcpy(m_data->begin() + m_data->lens(), &value, estimate);
		m_data->add_len(estimate);
		return this;
	}
	wmemory_t* wmemory_t::write(const std::uint16_t& value)
	{
		uint16_t estimate = sizeof(uint16_t);
		if (m_data->lens() + estimate > m_data->size())
			m_data->resize(m_data->size() + estimate);
		std::memcpy(m_data->begin() + m_data->lens(), &value, estimate);
		m_data->add_len(estimate);
		return this;
	}
	wmemory_t* wmemory_t::write(const std::uint32_t& value)
	{
		uint16_t estimate = sizeof(uint32_t);
		if (m_data->lens() + estimate > m_data->size())
			m_data->resize(m_data->size() + estimate);
		std::memcpy(m_data->begin() + m_data->lens(), &value, estimate);
		m_data->add_len(estimate);
		return this;
	}
	wmemory_t* wmemory_t::write(const std::uint64_t& value)
	{
		uint16_t estimate = sizeof(uint64_t);
		if (m_data->lens() + estimate > m_data->size())
			m_data->resize(m_data->size() + estimate);
		std::memcpy(m_data->begin() + m_data->lens(), &value, estimate);
		m_data->add_len(estimate);
		return this;
	}
	wmemory_t* wmemory_t::write(const std::int8_t& value)
	{
		uint16_t estimate = sizeof(int8_t);
		if (m_data->lens() + estimate > m_data->size())
			m_data->resize(m_data->size() + estimate);
		std::memcpy(m_data->begin() + m_data->lens(), &value, estimate);
		m_data->add_len(estimate);
		return this;
	}
	wmemory_t* wmemory_t::write(const std::int16_t& value)
	{
		uint16_t estimate = sizeof(int16_t);
		if (m_data->lens() + estimate > m_data->size())
			m_data->resize(m_data->size() + estimate);
		std::memcpy(m_data->begin() + m_data->lens(), &value, estimate);
		m_data->add_len(estimate);
		return this;
	}
	wmemory_t* wmemory_t::write(const std::int32_t& value)
	{
		uint16_t estimate = sizeof(int32_t);
		if (m_data->lens() + estimate > m_data->size())
			m_data->resize(m_data->size() + estimate);
		std::memcpy(m_data->begin() + m_data->lens(), &value, estimate);
		m_data->add_len(estimate);
		return this;
	}
	wmemory_t* wmemory_t::write(const std::int64_t& value)
	{
		uint16_t estimate = sizeof(int64_t);
		if (m_data->lens() + estimate > m_data->size())
			m_data->resize(m_data->size() + estimate);
		std::memcpy(m_data->begin() + m_data->lens(), &value, estimate);
		m_data->add_len(estimate);
		return this;
	}
	wmemory_t* wmemory_t::write(const bool& value)
	{
		uint16_t estimate = sizeof(bool);
		if (m_data->lens() + estimate > m_data->size())
			m_data->resize(m_data->size() + estimate);
		std::memcpy(m_data->begin() + m_data->lens(), &value, estimate);
		m_data->add_len(estimate);
		return this;
	}
	wmemory_t* wmemory_t::write(const double& value)
	{
		uint16_t estimate = sizeof(double);
		if (m_data->lens() + estimate > m_data->size())
			m_data->resize(m_data->size() + estimate);
		std::memcpy(m_data->begin() + m_data->lens(), &value, estimate);
		m_data->add_len(estimate);
		return this;
	}
	wmemory_t* wmemory_t::write(const float& value)
	{
		uint16_t estimate = sizeof(float);
		if (m_data->lens() + estimate > m_data->size())
			m_data->resize(m_data->size() + estimate);
		std::memcpy(m_data->begin() + m_data->lens(), &value, estimate);
		m_data->add_len(estimate);
		return this;
	}
	wmemory_t* wmemory_t::write(const char* value)
	{
		uintmax_t estimate = sizeof(uint16_t) + std::strlen(value);
		if (m_data->lens() + estimate > m_data->size())
			m_data->resize(m_data->size() + estimate);
		uint16_t len = static_cast<uint16_t>(std::strlen(value));
		std::memcpy(m_data->begin() + m_data->lens(), &len, sizeof(uint16_t));
		m_data->add_len(sizeof(uint16_t));
		std::memcpy(m_data->begin() + m_data->lens(), value, len);
		m_data->add_len(len);
		return this;
		return nullptr;
	}
}