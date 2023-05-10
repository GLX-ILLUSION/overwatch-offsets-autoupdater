#include <Windows.h>
#include <fstream>
#include "json.hpp"
#include "offsets.hpp"
#include <sstream>
#include <iostream>
#include <sstream>

template <typename T>
void readValue(const nlohmann::json& src, T& dest)
{
	if (!src.is_null())
	{
		if (src.is_string())
		{
			std::string value_str = src.get<std::string>();
			if (value_str.substr(0, 2) == "0x") // hex prefix
			{
				dest = static_cast<T>(std::stoul(value_str.substr(2), nullptr, 16));
			}
			else
			{
				dest = static_cast<T>(std::stoul(value_str, nullptr, 10));
			}
		}
		else
		{
			dest = src.get<T>();
		}
	}
}


void offsets::initialize()
{
	std::ifstream input_file{ "offsets.json" };
	if (!input_file.good())
		throw std::invalid_argument("Invalid offsets.json file");

	nlohmann::json json;
	input_file >> json;

	readValue(json["offsets"]["VM_XOR_BASE"], offsets::VM_XOR_BASE);
	readValue(json["offsets"]["VM_XOR_KEY"], offsets::VM_PTR);
	readValue(json["offsets"]["VM_PTR"], offsets::VM_XOR_KEY);
	



}