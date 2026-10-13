#include "App.h"

void App::run()
{
    std::vector<Entry*> all_entries = create_vector_of_entries_from_file("bitacora.txt");
    
    Sort::merge_sort(all_entries, [](Entry* e) {return e->get_comparable();});
    print_vector(all_entries);

    IP start_ip =  IP();
    IP end_ip =  IP();
    get_input_ip_range_in_place(start_ip, end_ip);

    std::vector<Entry*> filtered_entries = Search::filter_by_range(all_entries, start_ip, end_ip, [](Entry* e) { return e->get_comparable(); });

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

IP App::get_input_ip()
{
    std::string input_ip = "";

    while (input_ip == "") {
        std::cout << "Ejemplo de formato: 17.205.2.34\n";
        std::cout << "Ingrese la IP (XXX.XXX.XXX.XXX): ";
        std::getline(std::cin, input_ip);

        try {
            return IP(input_ip);
        }
        catch (const std::exception& e) {
            input_ip = "";
            std::cout << "Intente de nuevo. " << e.what() << "\n";
        }
    }
}

void App::get_input_ip_range_in_place(IP& start, IP& end)
{
    bool valid_range = false;
    while (!valid_range) {
        std::cout << "===== IP inicial =====\n";
        start = get_input_ip();
        std::cout << "=====  IP final  =====\n";
        end = get_input_ip();

        if (end >= start) {
            valid_range = true;
        }
        else {
            std::cout << "Rango no valido, la IP final debe de ser posterior o igual a la inicial. \n";
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

