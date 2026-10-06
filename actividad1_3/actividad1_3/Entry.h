#pragma once
#include <string>
#include <vector>
class Entry {
private:
	double comparable;
	std::string month;
	std::string day;
	std::string time;
	std::string ip;
	std::string message;

	double create_comparable();
public:
	Entry(std::string);

	const static int month_to_int(std::string);
	const double get_comparable();
	std::string get_full_entry();
	double create_comparable(std::string);
};

std::vector<Entry*> create_vector_of_entries_from_file(std::string);
