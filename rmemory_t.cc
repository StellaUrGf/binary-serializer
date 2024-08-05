#include "rmemory_t.hh"
namespace utils
{
	rmemory_t::rmemory_t(const size_t& size)
	{
		m_data = new unique_ptr{ size };
	}
	rmemory_t::rmemory_t(uint8_t* blc, size_t size)
	{
		m_data = new unique_ptr(blc, size);
	}
	rmemory_t::rmemory_t(const std::filesystem::path& path)
	{
		if (std::filesystem::exists(path)) {
			std::ifstream file(path, std::ios::binary);
			if (file.bad())
				throw std::exception(std::string("Failed to open " + path.string()).c_str());
			else {
				file.seekg(0x0, std::ios::end);
				uintmax_t size = static_cast<uintmax_t>(file.tellg());
				file.seekg(0x0, std::ios::beg);
				uint8_t* blc = static_cast<uint8_t*>(_STD malloc(size));
				file.read(reinterpret_cast<char*>(blc), size);
				file.close();
				m_data = new unique_ptr(blc, size);
				std::free(blc);
			}
		}
	}
	const rmemory_t* rmemory_t::reverse() noexcept
	{
		m_data->reverse();
		return nullptr;
	}
	const rmemory_t* rmemory_t::cleanup() noexcept
	{
		if (!m_data)
			return nullptr;
		m_data->cleanup();
		delete m_data;
		return this;
	}
	const rmemory_t* rmemory_t::read(std::uint8_t& value)
	{
		uint8_t estimate = sizeof(uint8_t);
		if (m_data->lens() + estimate <= m_data->size()) {
			std::memcpy(&value, m_data->begin() + m_data->lens(), estimate);
			m_data->add_len(estimate);
		}
		return nullptr;
	}
	const rmemory_t* rmemory_t::read(std::uint16_t& value)
	{
		uint8_t estimate = sizeof(uint16_t);
		if (m_data->lens() + estimate <= m_data->size()) {
			std::memcpy(&value, m_data->begin() + m_data->lens(), estimate);
			m_data->add_len(estimate);
		}
		return nullptr;
	}
	const rmemory_t* rmemory_t::read(std::uint32_t& value)
	{
		uint8_t estimate = sizeof(uint32_t);
		if (m_data->lens() + estimate <= m_data->size()) {
			std::memcpy(&value, m_data->begin() + m_data->lens(), estimate);
			m_data->add_len(estimate);
		}
		return nullptr;
	}
	const rmemory_t* rmemory_t::read(std::uint64_t& value)
	{
		uint8_t estimate = sizeof(uint64_t);
		if (m_data->lens() + estimate <= m_data->size()) {
			std::memcpy(&value, m_data->begin() + m_data->lens(), estimate);
			m_data->add_len(estimate);
		}
		return nullptr;
	}
	const rmemory_t* rmemory_t::read(std::int8_t& value)
	{
		uint8_t estimate = sizeof(int8_t);
		if (m_data->lens() + estimate <= m_data->size()) {
			std::memcpy(&value, m_data->begin() + m_data->lens(), estimate);
			m_data->add_len(estimate);
		}
		return nullptr;
	}
	const rmemory_t* rmemory_t::read(std::int16_t& value)
	{
		uint8_t estimate = sizeof(int16_t);
		if (m_data->lens() + estimate <= m_data->size()) {
			std::memcpy(&value, m_data->begin() + m_data->lens(), estimate);
			m_data->add_len(estimate);
		}
		return nullptr;
	}
	const rmemory_t* rmemory_t::read(std::int32_t& value)
	{
		uint8_t estimate = sizeof(int32_t);
		if (m_data->lens() + estimate <= m_data->size()) {
			std::memcpy(&value, m_data->begin() + m_data->lens(), estimate);
			m_data->add_len(estimate);
		}
		return nullptr;
	}
	const rmemory_t* rmemory_t::read(std::int64_t& value)
	{
		uint8_t estimate = sizeof(int64_t);
		if (m_data->lens() + estimate <= m_data->size()) {
			std::memcpy(&value, m_data->begin() + m_data->lens(), estimate);
			m_data->add_len(estimate);
		}
		return nullptr;
	}
	const rmemory_t* rmemory_t::read(std::string& value)
	{
		uint16_t len = *reinterpret_cast<uint16_t*>(m_data->begin() + m_data->lens());
		m_data->add_len(sizeof(uint16_t));
		value = std::string(reinterpret_cast<char*>(m_data->begin() + m_data->lens()), len);
		m_data->add_len(len);
		return nullptr;
	}
	const rmemory_t* rmemory_t::read(bool& value)
	{
		uint8_t estimate = sizeof(bool);
		if (m_data->lens() + estimate <= m_data->size()) {
			std::memcpy(&value, m_data->begin() + m_data->lens(), estimate);
			m_data->add_len(estimate);
		}
		return nullptr;
	}
	const rmemory_t* rmemory_t::read(double& value)
	{
		uint8_t estimate = sizeof(double);
		if (m_data->lens() + estimate <= m_data->size()) {
			std::memcpy(&value, m_data->begin() + m_data->lens(), estimate);
			m_data->add_len(estimate);
		}
		return nullptr;
	}
	const rmemory_t* rmemory_t::read(float& value)
	{
		uint8_t estimate = sizeof(float);
		if (m_data->lens() + estimate <= m_data->size()) {
			std::memcpy(&value, m_data->begin() + m_data->lens(), estimate);
			m_data->add_len(estimate);
		}
		return nullptr;
	}
	const rmemory_t* rmemory_t::read(const char* value)
	{
		uint16_t len = *(uint16_t*)&m_data->begin()[m_data->lens()];
		m_data->add_len(sizeof(uint16_t));
		std::string str(reinterpret_cast<char*>(m_data->begin() + m_data->lens()), len);
		m_data->add_len(len);
		value = str.c_str();
		return nullptr;
	}
	rmemory_t* rmemory_t::reserve(const size_t& size)
	{
		m_data->reserve(size);
		return nullptr;
	}
	rmemory_t* rmemory_t::skip(const size_t& size)
	{
		m_data->add_len(size);
		return nullptr;
	}
	rmemory_t* rmemory_t::resize(const size_t& size)
	{
		m_data->resize(size);
		return nullptr;
	}
}