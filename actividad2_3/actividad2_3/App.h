#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <fstream>

#include "Entry.h"
#include "Sort.h"
#include "Search.h"

class App
{
public:
	void run();

private:
	int get_input_date();
	void get_input_range_in_place(int&, int&);
	void print_vector(std::vector<Entry*>);
	void save_vector_to_file(std::vector<Entry*>, std::string);
};

