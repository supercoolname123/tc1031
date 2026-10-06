#include "App.h"

void App::run()
{
    std::vector<Entry*> all_entries = create_vector_of_entries_from_file("bitacora.txt");
    Sort::merge_sort(all_entries);

    int start_date = 0;
    int end_date = 0;
    get_input_range_in_place(start_date, end_date);

    std::vector<Entry*> filtered_entries = Search::filter_by_range(all_entries, start_date, end_date);

    print_vector(filtered_entries);
    save_vector_to_file(all_entries, "bitacora_ordenada.txt");

    std::cout << "Se encontraron " << filtered_entries.size() << " resultados. \n";
    std::cout << "La lista ordenada se ha guardado en un archivo .txt \n";
}

int App::get_input_date() {
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

void App::get_input_range_in_place(int& start_date, int& end_date) {
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

void App::print_vector(std::vector<Entry*> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i]->get_full_entry() << std::endl;
    }
}

void App::save_vector_to_file(std::vector<Entry*> v, std::string file_name) {
    std::ofstream file(file_name);

    for (int i = 0; i < v.size(); i++) {
        file << v[i]->get_full_entry() << "\n";
    }

    file.close();
}

