#include "Test.h"
#include <stdexcept>

void Test::is_sorted(std::vector<Entry*> v)
{
	int previous = v[0]->get_comparable();
	for (int i = 1; i < v.size(); i++) {
		if (previous > v[i]->get_comparable()) {
			throw std::runtime_error("The vector is not sorted");
		}
		else {
			previous = v[i]->get_comparable();
		}
	}
}

void Test::is_search_finding_closest_element(std::vector<Entry*> v, int start, int end, int closest_to_start, int closest_to_end) 
{
	int start_distance = abs(start - closest_to_start);
	int end_distance = abs(end - closest_to_end);
	for (int i = 0; i < v.size(); i++) {
		if (start_distance > abs(start - v[i]->get_comparable())) {
			throw std::runtime_error("Closest to start was not found ;(");
		} 
		if (end_distance > abs(end - v[i]->get_comparable())) {
			throw std::runtime_error("Closest to end was not found ;(");
		}
	}
}
