#define _CRT_SECURE_NO_WARNINGS
#include "memory_t.hh"
namespace utils
{
	namespace io
	{
		void deserialize(rmemory_t& blc, std::filesystem::path path)
		{
			blc = rmemory_t(path);
		}
		void deserialize(wmemory_t& blc, std::filesystem::path path)
		{
			if (std::filesystem::exists(path)) {
				std::fstream file;
				file.open(path, std::ios::in | std::ios::binary);
				if (file.bad())
					return;
				file.seekg(0x0, std::fstream::end);
				uintmax_t size = static_cast<uintmax_t>(file.tellg());
				file.seekg(0x0, std::fstream::beg);
				uint8_t* ptr = static_cast<uint8_t*>(_STD malloc(size));
				if (not file.read(reinterpret_cast<char*>(ptr), size)) {
					std::string error("Failed to read " + path.string());
					std::free(ptr);
					throw std::exception(error.c_str());
				} else {
					blc = wmemory_t(ptr, size);
					std::free(ptr);
				}
				file.close();
			}
		}
		void serialize(rmemory_t& blc, std::filesystem::path path)
		{
			std::ofstream file(path, std::ios::binary);
			if (!file)
				return;
			file.write(reinterpret_cast<char*>(blc.begin()), blc.lens());
			file.close();
		}
		void serialize(wmemory_t& blc, std::filesystem::path path)
		{
			std::ofstream file(path, std::ios::binary);
			if (!file)
				return;
			file.write(reinterpret_cast<char*>(blc.begin()), blc.lens());
			file.close();
		}
	}
}