#pragma once
#include <vector>


class Sort
{
public:
    template <typename T, typename Getter>
	static void merge_sort(std::vector<T*>& v, Getter get) {
        if (v.size() <= 1) {
            return;
        }

        std::vector<T*> resultado;
        if (v.size() > 1) {
            int middle = (int)v.size() / 2;
            std::vector<T*> a = copy_elements_from_vector(v, 0, middle);
            std::vector<T*> b = copy_elements_from_vector(v, middle, v.size());
            resultado.resize(a.size() + b.size());

            merge_sort(a, get);
            merge_sort(b, get);

            int i = 0;
            int j = 0;
            int k = 0;

            while (i < a.size() && j < b.size()) {
                auto x = get(a[i]);
                auto y = get(b[j]);
                if (x < y) {
                    resultado[k] = a[i];
                    i++;
                }
                else {
                    resultado[k] = b[j];
                    j++;
                }
                k++;
            }

            while (i < a.size()) {
                resultado[k] = a[i];
                i++;
                k++;
            }

            while (j < b.size()) {
                resultado[k] = b[j];
                j++;
                k++;
            }

        }
        else {
            resultado.resize(1);
            resultado[0] = v[0];
        }
        v = resultado;
    };

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
};