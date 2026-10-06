#include "Search.h"

std::vector<Entry*> Search::copy_elements_from_vector(std::vector<Entry*>& source, int start, int end) {
    std::vector<Entry*> target(end - start);
    int k = 0;
    for (int i = start; i < end; i++) {
        target[k] = source[i];
        k++;
    }
    return target;
}

bool Search::is_in_range(int value, int start, int end) {
    return (value >= start) and (value <= end);
}

int Search::binary_search(std::vector<Entry*>& v, int target) {
    if (v.size() == 1) {
        return 0;
    }
    else if (v.size() == 0) { return -1; }

    int center = v.size() / 2;
    int left = 0;
    int right = v.size() - 1;
    while (target != v[center]->get_comparable() && center != left && center != right) {
        if (target > v[center]->get_comparable()) {
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

std::vector<Entry*> Search::filter_by_range(std::vector<Entry*>& v, int start, int end) {
    if (v.size() <= 1) {
        return v;
    }

    int closest_to_start = Search::binary_search(v, start);
    int closest_to_end = Search::binary_search(v, end);

    if (closest_to_start == closest_to_end) {
        return {};
    }

    while (!is_in_range(v[closest_to_start]->get_comparable(), start, end)) {
        closest_to_start++;
    }
    while (!is_in_range(v[closest_to_end]->get_comparable(), start, end)) {
        closest_to_end--;
    }

    return copy_elements_from_vector(v, closest_to_start, closest_to_end + 1);
}



