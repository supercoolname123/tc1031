#pragma once
#include <vector>

class Search
{
private:
    template <typename T>
	static std::vector<T*> copy_elements_from_vector(std::vector<T*>& source, int start, int end) {
        std::vector<T*> target(end - start);
        int k = 0;
        for (int i = start; i < end; i++) {
            target[k] = source[i];
            k++;
        }
        return target;
    }

    template <typename comparable>
    static bool is_in_range(comparable value, comparable start, comparable end) {
        return value >= start && value <= end;
    }

public:
    template <typename T, typename TargetType, typename Getter>
    static int binary_search(std::vector<T*>& v, TargetType target, Getter get) {
        if (v.size() == 1) {
            return 0;
        }
        else if (v.size() == 0) { return -1; }

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

        BoundaryType a = get(v[closest_to_start]);
        while (!is_in_range(a, start, end)) {
            closest_to_start++;
        }
        BoundaryType b = get(v[closest_to_end]);
        while (!is_in_range(b, start, end)) {
            closest_to_end--;
        }

        return copy_elements_from_vector(v, closest_to_start, closest_to_end + 1);
    }


};

