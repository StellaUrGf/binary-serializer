#ifndef __MEMORY_T_HH__
#define __MEMORY_T_HH__
#include "rmemory_t.hh"
#include "wmemory_t.hh"
namespace utils
{
	namespace io
	{
		void deserialize(rmemory_t& blc, std::filesystem::path path);
		void deserialize(wmemory_t& blc, std::filesystem::path path);

		void serialize(rmemory_t& blc, std::filesystem::path path);
		void serialize(wmemory_t& blc, std::filesystem::path path);
	}
}
#endif // !__MEMORY_T_HH__
