#include "unique.hh"
namespace utils
{
	unique_ptr::unique_ptr(const size_t& size)
	{
		m_data = (uint8_t*)malloc(size);
		m_size = size, m_lens = NULL;
	}
	unique_ptr::unique_ptr(uint8_t* block, size_t size)
	{
		m_data = (uint8_t*)malloc(size);
		if (!m_data)
			throw std::exception("Failed to allocated memory");
		::std::memcpy(m_data, block, size);
		// NOTE: This pointer is allocated as a new memory but it copied the data
		// that pass through parameter, so once you cleanup by calling cleanup function
		// it only cleanup the pointer that is a class member 'uint8_t* m_data'
		// so the pointer that pass through parameter still available, you need to free the 
		// memory that pass through parameter too, if you stop using it. otherwise, it'll lead to memleak issues.
		m_size = size, m_lens = NULL;
	}
	unique_ptr* unique_ptr::resize(const size_t& size)
	{
		uint8_t* blc = (uint8_t*)_STD realloc(m_data, size);
		if (!blc)
			throw std::exception("Failed to reallocated memory during unique_ptr process.");
		else {
			m_data = blc;
			m_size = size;
		}
		return this;
	}
	unique_ptr* unique_ptr::reserve(const size_t& size)
	{
		if (m_size < size)
			this->resize(size);
		std::memset(m_data, 0, size);
		m_size = size;
		return this;
	}
	unique_ptr* unique_ptr::add_len(const size_t& size)
	{
		m_lens += size;
		return this;
	}
	unique_ptr* unique_ptr::rem_len(const size_t& size)
	{
		m_lens -= size;
		return this;
	}
	unique_ptr* unique_ptr::set_len(const size_t& size)
	{
		m_lens = size;
		return this;
	}
	const unique_ptr* unique_ptr::reverse()
	{
		std::vector<uint8_t> container(m_size);
		for (int i = 0; i < m_size; i++)
			container[i] = static_cast<uint8_t>(m_data[i]);
		std::reverse(std::begin(container), std::end(container));
		std::copy(container.begin(), container.end(), m_data);
		return this;
	}
	const unique_ptr* unique_ptr::cleanup()
	{
		std::free(m_data);
		return this;
	}
}