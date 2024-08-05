#ifndef __UNIQUE_PTR_HH__
#define __UNIQUE_PTR_HH__
#include <vector>
#include <memory>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
namespace utils
{
	class unique_ptr {
	public:
		explicit unique_ptr(const size_t& size);
		explicit unique_ptr(uint8_t* block, size_t);
	public:
		unique_ptr(const unique_ptr&) = delete;
		unique_ptr& operator=(unique_ptr&) = delete;
	public:
		unique_ptr* resize(const size_t& size);
		unique_ptr* reserve(const size_t& size);
	public:
		unique_ptr* add_len(const size_t& size);
		unique_ptr* rem_len(const size_t& size);
		unique_ptr* set_len(const size_t& size);
	public:
		const unique_ptr* reverse();
		const unique_ptr* cleanup();
	public:
		constexpr uint8_t* begin() {
			return m_data;
		}
		constexpr uint8_t* end() {
			return m_data + m_lens;
		}
	public:
		constexpr size_t size() { return m_size; }
		constexpr size_t lens() { return m_lens; }
	private:
		size_t m_size = NULL;
		size_t m_lens = NULL;
	private:
		uint8_t* m_data = nullptr;
	};
}
#endif // !__UNIQUE_PTR_HH__
