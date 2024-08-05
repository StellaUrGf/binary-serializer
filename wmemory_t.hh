#ifndef __WMEMORY_T_HH__
#define __WMEMORY_T_HH__
#include <string>
#include <stdint.h>

#include "unique.hh"

namespace utils
{
	class wmemory_t {
	public:
		const wmemory_t* resize(const size_t& size);
		const wmemory_t* skip(const size_t& size);
		const wmemory_t* reserve(const size_t& size);
	public:
		const wmemory_t* reverse() noexcept(true);
		const wmemory_t* cleanup() noexcept(true);
	public:
		explicit wmemory_t(const size_t& size = 5 * 1024 * 1024);
		explicit wmemory_t(uint8_t* blc, size_t size);
	public:
		wmemory_t* write(const std::string& value);
	public:
		wmemory_t* write(const std::uint8_t& value);
		wmemory_t* write(const std::uint16_t& value);
		wmemory_t* write(const std::uint32_t& value);
		wmemory_t* write(const std::uint64_t& value);
	public:
		wmemory_t* write(const std::int8_t& value);
		wmemory_t* write(const std::int16_t& value);
		wmemory_t* write(const std::int32_t& value);
		wmemory_t* write(const std::int64_t& value);
	public:
		wmemory_t* write(const bool& value);
		wmemory_t* write(const double& value);
		wmemory_t* write(const float& value);
		wmemory_t* write(const char* value);
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
	private:
		unique_ptr* m_data = nullptr;
	};
}
#endif // !__WMEMORY_T_HH__
