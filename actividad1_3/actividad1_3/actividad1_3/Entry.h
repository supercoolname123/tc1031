#pragma once
#include <string>
class Entry {
private:
	int comparable;
	std::string month;
	std::string day;
	std::string time;
	std::string ip;
	std::string message;

	int create_comparable();
public:
	Entry(std::string);

	int get_comparable();
	std::string get_full_entry();
};