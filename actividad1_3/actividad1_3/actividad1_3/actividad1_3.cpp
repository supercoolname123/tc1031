// actividad1_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include "Entry.h"
#include "Test.h"
/*std::string read_file(std::string path_file) {
    std::ifstream accessed_file(path_file);
    std::string output;

    if (!accessed_file.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
    }

    std::string line;
    while (std::getline(accessed_file, line)) {
        output += line + "\n";
    }


    accessed_file.close();
    return output;
}*/

std::vector<Entry*> create_list_of_entries_from_file(std::string file_path) {
    std::vector<Entry*> list = {};
    std::ifstream accessed_file(file_path);

    if (!accessed_file.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
    }

    std::string line;
    while (std::getline(accessed_file, line)) {
        list.push_back(new Entry(line));
    }


    accessed_file.close();
    return list;
}

std::vector<Entry*> copy_elements_from_vector(std::vector<Entry*>& source, int start, int end) {
    std::vector<Entry*> target(end - start);
    int k = 0;
    for (int i = start; i < end; i++) {
        target[k] = source[i];
        k++;
    }
    return target;
}

void merge_sort(std::vector<Entry*>& v) {
    if (v.size() <= 1) {
        return;
    }
    std::vector<Entry*> resultado;
    if (v.size() > 1) {
        int middle = (int) v.size() / 2;
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

bool is_in_range(int value, int start, int end) {
    return (value >= start) and (value <= end);
}

int binary_search(std::vector<Entry*>& v, int target) {
    if (v.size() == 1) {
        return 0;
    }
    else if (v.size() == 0) {return -1;}

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

std::vector<Entry*> filter_by_range(std::vector<Entry*>& v, int start, int end) {
    if (v.size() <= 1) {
        return v;
    }

    int closest_to_start = binary_search(v, start);
    int closest_to_end = binary_search(v, end);

    if (closest_to_start == closest_to_end) {
        return {};
    }

    while (!is_in_range(v[closest_to_start]->get_comparable(), start, end)) {
        closest_to_start++;
    }
    while (!is_in_range(v[closest_to_end]->get_comparable(), start, end)) {
        closest_to_end--;
    }

    return copy_elements_from_vector(v, closest_to_start, closest_to_end+1);
}

int get_input_date() {
    std::string month = "";
    int day = 0;
    int date = 0;
    while (month == "") {
        std::cout << "Ejemplo de formato: Aug 10\n";
        std::cout << "Ingrese el mes: ";
        std::cin >> month;

        if (Entry::month_to_int(month) == -1) {
            month = "";
            std::cout << "Intente de nuevo con el formato indicado. \n";
        }
        else {
            date += Entry::month_to_int(month) * 100000000;
        }
    }

    while (day == 0) {
        std::cout << "Ingrese el dia: ";
        std::cin >> day;

        if (day > 0 && day <= 31) {
            date += day * 1000000;
        }
        else {
            day = 0;
            std::cout << "Dia no valido, debe de estar entre el 1 y el 31. \n";
        }
    }
    return date;
}

void get_input_range_in_place(int& start_date, int& end_date) {
    bool valid_range = false;
    const int FULL_DAY_MINUS_A_SECOND = 1000000 - 1;
    while (!valid_range) {
        std::cout << "===== Fecha inicial =====\n";
        start_date = get_input_date();
        std::cout << "=====  Fecha final  =====\n";
        end_date = get_input_date() + FULL_DAY_MINUS_A_SECOND;

        if (end_date > start_date) {
            valid_range = true;
        }
        else {
            std::cout << "Rango no valido, la fecha final debe de ser posterior a la inicial. \n";
        }
    }
}

void print_vector(std::vector<Entry*> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i]->get_full_entry() << std::endl;
    }
}

void save_vector_to_file(std::vector<Entry*> v) {
    std::ofstream file("bitacora_ordenada.txt");

    for (int i = 0; i < v.size(); i++) {
        file << v[i]->get_full_entry() << "\n";
    }

    file.close();
}

int main()
{
    std::vector<Entry*> all_entries = create_list_of_entries_from_file("bitacora.txt");
    merge_sort(all_entries);
   
    int start_date = 0;
    int end_date = 0;
    get_input_range_in_place(start_date, end_date);

    std::vector<Entry*> filtered_entries = filter_by_range(all_entries, start_date, end_date);
    
    print_vector(filtered_entries);
    save_vector_to_file(all_entries);

    std::cout << "Se encontraron " << filtered_entries.size() << " resultados. \n";
    std::cout << "La lista ordenada se ha guardado en un archivo .txt \n";
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
