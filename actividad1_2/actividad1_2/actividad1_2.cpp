// actividad1_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Gerardo Alberto Garay - A01564643
#include <iostream>
#include <vector>
#include <string>

void printVector(std::vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ", ";
    }
    std::cout << "end\n";
}

bool isSorted(std::vector<int>& v) {
    int last = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < last) return false;
        last = v[i];
    }
    return true;
}

void assert(bool success, std::string message) {
    if (!success) {
        throw std::runtime_error(message);
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void ordenaIntercambio(std::vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i; j < v.size(); j++) {
            if (v[i] > v[j]) {
                swap(v[i], v[j]);
            }
        }
    }
}

void ordenaBurbuja(std::vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size() - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

std::vector<int> ordenaMergeNotInPlace(std::vector<int>& v, int left, int right) {
    std::vector<int> resultado;
    if (left < right) {
        int middle = (right + left) / 2;
        std::vector<int> a = ordenaMergeNotInPlace(v, left, middle);
        std::vector<int> b = ordenaMergeNotInPlace(v, middle + 1, right);

        int i = 0;
        int j = 0;
        int k = 0;
        resultado.resize(a.size() + b.size());

        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
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
        resultado[0] = v[left];
    }
    return resultado;
}

std::vector<int> copyElementsFromVector(std::vector<int>& source, int start, int end) {
    std::vector<int> target(end - start);
    int k = 0;
    for (int i = start; i < end; i++) {
        target[k] = source[i];
        k++;
    }
    return target;
}

void ordenaMerge(std::vector<int>& v) {
    std::vector<int> resultado;
    if (v.size() > 1) {
        int middle = v.size() / 2;
        std::vector<int> a = copyElementsFromVector(v, 0, middle);
        std::vector<int> b = copyElementsFromVector(v, middle, v.size());
        resultado.resize(a.size() + b.size());

        ordenaMerge(a);
        ordenaMerge(b);

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
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

int busqSecuencial(std::vector<int>& v, int target) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == target) {
            return i;
        }
    }
    return -1;
}

int busqBinaria(std::vector<int>& v, int target) {
    int center = v.size() / 2;
    int left = 0;
    int right = v.size() - 1;
    while (target != v[center] && center != left && center != right) {
        if (target > v[center]) {
            left = center;
            center = (center + right) / 2;
        }
        else {
            right = center;
            center = (center + left) / 2;
        }
    } 

    if (target == v[center]) {
        return center;
    }
    else {
        return -1;
    }
}

int main()
{
    int n;
    std::cout << "Ingrese la cantidad de numeros a ordenar: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Ingrese los " << n << " numeros:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    ordenaMerge(nums);

    int busquedas = 0;
    std::cout << "Ingrese el numero de busquedas a realizar: ";
    std::cin >> busquedas;

    int target = 0;
    for (int i = 1; i <= busquedas; i++) {
        std::cout << "\nBusqueda " << i << ": ";
        std::cin >> target;
        int binaria = busqBinaria(nums, target);
        int secuencial = busqSecuencial(nums, target);
        std::cout << "\n** RESULTADOS **\n"; 
        std::cout << "Binaria: " << binaria << "\n";
        std::cout << "Secuencial: " << secuencial << "\n";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
