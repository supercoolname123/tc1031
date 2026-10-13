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
