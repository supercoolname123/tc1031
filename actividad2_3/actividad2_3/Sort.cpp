#include "Sort.h"

void Sort::merge_sort(std::vector<Entry*>& v) {
    if (v.size() <= 1) {
        return;
    }
    std::vector<Entry*> resultado;
    if (v.size() > 1) {
        int middle = (int)v.size() / 2;
        std::vector<Entry*> a = copy_elements_from_vector(v, 0, middle);
        std::vector<Entry*> b = copy_elements_from_vector(v, middle, v.size());
        resultado.resize(a.size() + b.size());

        merge_sort(a);
        merge_sort(b);

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i]->get_comparable() < b[j]->get_comparable()) {
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
}

std::vector<Entry*> Sort::copy_elements_from_vector(std::vector<Entry*>& source, int start, int end) {
    std::vector<Entry*> target(end - start);
    int k = 0;
    for (int i = start; i < end; i++) {
        target[k] = source[i];
        k++;
    }
    return target;
}


