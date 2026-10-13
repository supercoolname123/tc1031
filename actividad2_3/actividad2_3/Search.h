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

        int center = v.size() / 2;
        int left = 0;
        int right = v.size() - 1;

        while (target != get(v[center]) && center != left && center != right) {
            if (target > get(v[center])) {
                left = center;
                if (right - center < 2) {
                    center = right;
                }
                else {
                    center = (center + right) / 2;
                }
            }
            else {
                right = center;
                center = (center + left) / 2;
            }
        }

        return center;
    }

    template <typename T, typename BoundaryType, typename Getter>
    static std::vector<T*> filter_by_range(std::vector<T*>& v, BoundaryType start, BoundaryType end, Getter get) {
        if (v.size() <= 1) {
            return v;
        }

        int closest_to_start = Search::binary_search(v, start, get);
        int closest_to_end = Search::binary_search(v, end, get);

        if (closest_to_start == closest_to_end) {
            return {};
        }

        while (!is_in_range(get(v[closest_to_start]), start, end)) {
            closest_to_start++;
        }
        while (!is_in_range(get(v[closest_to_end]), start, end)) {
            closest_to_end--;
        }

        return copy_elements_from_vector(v, closest_to_start, closest_to_end + 1);
    }


};};