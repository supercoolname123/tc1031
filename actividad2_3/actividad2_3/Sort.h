#pragma once
#include <vector>
#include "Entry.h"
class Sort
{
public:
	static void merge_sort(std::vector<Entry*>&);

private:
	static std::vector<Entry*> copy_elements_from_vector(std::vector<Entry*>&, int, int);
};

