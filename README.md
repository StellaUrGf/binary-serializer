## Binary-Serializer:
This is a simple C++ project. It use to write data into memory and read back from memory. You are able to ``Serialize`` and ``Deserialize`` easily. The code is so easy to understand and maintain. However i didn't comment anything inside the code because it's bother my Code-Aesthetic and look pretty ugly to me. i don't know if anyone like me but whatever. It's has flexibility to extend block of memory whenever you writing your data exceed the amount of you allocated. But i recommand to allocate the right amount that you want to write.

## Feature:
- [x] Clean and Readable: The codebase prioritizes clarity and readablity.
- [x] Easy to Maintain and Understandable.
- [ ] Avoid Code comment usage due to my Aesthetic preference.
- [x] Automatically extend memory blocks when needed.
- [x] Fast Serialization - Deserialization.
- [x] Memory Reversal Support.
- [x] Well-structured and Reliable code.
- [ ] Excludes standard container due to Code-Aesthetic
- [ ] manually clean-up block of memory by calling cleanup function.
- [x] Optimized for speed and space.

## How to use:
- Serialize:
```cpp
namespace
{
	static class {
	public:
		std::string m_name = "StellaUrGf";
		std::string m_nums = "12345678";
	public:
		uint16_t m_grade = 99;
		uint16_t m_age = 21;
	} client;
}

int main(int argc, char* argv[])
{
	using namespace utils;
	
	size_t size = sizeof(uint16_t) * 0x4;
	size += client.m_name.size();
	size += client.m_nums.size();

	wmemory_t mem = wmemory_t(size);
	mem.write(client.m_name);
	mem.write(client.m_nums);

	mem.write(client.m_grade);
	mem.write(client.m_age);

	utils::io::serialize(mem, "client.dat");

	mem.cleanup();

	return EXIT_SUCCESS;
}
```
- Deserialize:
```cpp
int main(int argc, char* argv[])
{
	using namespace utils;

	try {

		rmemory_t* blc = nullptr;
		utils::io::deserialize(&blc, "client.dat");
		blc->read(client.m_name);
		blc->read(client.m_nums);
		blc->read(client.m_grade);
		blc->read(client.m_age);

		blc->cleanup();
		delete blc;

	} catch (_STD exception& error) {
		std::println(std::cout, "exception: {}", error.what());
	}

	return EXIT_SUCCESS;
}
```

## Supported Data-Type:

|   signed   |   unsigned    |   float-point    |    single-value    |    container    |
| ---------- | ------------- | ---------------  | ------------------ | --------------- |
| uint8_t    | int8_t        | float            | atomic_bool        | string          |
| uint16_t   | int16_t       | double           | bool               | string_view     |
| uint32_t   | int32_t       |                  | char               |                 |
| uint64_t   | int64_t       |                  |                    |                 |

## Installation:
1. Clone repository or Download File.
2. Add it to your directory.
3. Open up your project in Visual Studio.
4. And include ``memory_t.hh``.
5. Done.

## Credit:
You could give me a start if you found it useful, I appreciate your star. Thanks you.
- [StellaUrGf](https://github.com/StellaUrGf)
