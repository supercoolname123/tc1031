#pragma once
#include <vector>
#include "Entry.h"

class Search
{
private:
	static std::vector<Entry*> copy_elements_from_vector(std::vector<Entry*>&, int, int);
	static bool is_in_range(int, int, int);
public:
	static int binary_search(std::vector<Entry*>&, int);
	static std::vector<Entry*> filter_by_range(std::vector<Entry*>&, int, int);
};

