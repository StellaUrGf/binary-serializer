#ifndef __RMEMORY_T_HH__
#define __RMEMORY_T_HH__
#include <string>
#include <stdint.h>
#include <vector>
#include <filesystem>
#include <fstream>

#include "unique.hh"

namespace utils
{
	class rmemory_t {
	public:
		explicit rmemory_t(const size_t& size);
		explicit rmemory_t(uint8_t* blc, size_t size);
		explicit rmemory_t(const std::filesystem::path&);
	public:
		const rmemory_t* reverse() noexcept;
		const rmemory_t* cleanup() noexcept;
	public:
		const rmemory_t* read(std::uint8_t& value);
		const rmemory_t* read(std::uint16_t& value);
		const rmemory_t* read(std::uint32_t& value);
		const rmemory_t* read(std::uint64_t& value);
	public:
		const rmemory_t* read(std::int8_t& value);
		const rmemory_t* read(std::int16_t& value);
		const rmemory_t* read(std::int32_t& value);
		const rmemory_t* read(std::int64_t& value);
	public:
		const rmemory_t* read(std::string& value);
	public:
		const rmemory_t* read(bool& value);
		const rmemory_t* read(double& value);
		const rmemory_t* read(float& value);
		const rmemory_t* read(const char* value);
	public:
		uint8_t* const begin() {
			return m_data->begin();
		}
		uint8_t* const end() {
			return m_data->end();
		}
	public:
		constexpr size_t lens() { return m_data->lens(); }
		constexpr size_t size() { return m_data->size(); }
	public:
		rmemory_t* reserve(const size_t& size);
		rmemory_t* skip(const size_t& size);
		rmemory_t* resize(const size_t& size);
	private:
		unique_ptr* m_data = nullptr;
	};
}
#endif // !__RMEMORY_T_HH__
