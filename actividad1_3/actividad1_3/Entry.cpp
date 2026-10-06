#include "Entry.h"
#include <sstream>
#include <fstream>
#include <iostream>


const int Entry::month_to_int(std::string month) {
    if (month == "Jan") {
        return 1;
    }
    else if (month == "Feb") {
        return 2;
    }
    else if (month == "Mar") {
        return 3;
    }
    else if (month == "Apr") {
        return 4;
    }
    else if (month == "May") {
        return 5;
    }
    else if (month == "Jun") {
        return 6;
    }
    else if (month == "Jul") {
        return 7;
    }
    else if (month == "Aug") {
        return 8;
    }
    else if (month == "Sep") {
        return 9;
    }
    else if (month == "Oct") {
        return 10;
    }
    else if (month == "Nov") {
        return 11;
    }
    else if (month == "Dec") {
        return 12;
    }
    else {
        return -1;
    }
}

double Entry::create_comparable()
{
    std::istringstream _ip(ip);

    std::string temp = "";
    double temp_comparable = 0;
    int counter = 1;
    while (std::getline(_ip, temp, '.')) {
        if (counter == 1) {
            temp_comparable += std::stoi(temp) * 1000000000ll;
        }
        else if (counter == 2) {
            temp_comparable += std::stoi(temp) * 1000000ll;
        }
        else if (counter == 3) {
            temp_comparable += std::stoi(temp) * 1000ll;
        }
        else if (counter == 4) {
            std::string before_two_dots = "";
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] == ':') 
                { break; }
                before_two_dots += temp[i];

            }
            temp_comparable += std::stoi(before_two_dots);
        }
        counter++;
    }
    return temp_comparable;
}

Entry::Entry(std::string new_entry)
{
    std::istringstream stream(new_entry);

    stream >> month >> day >> time >> ip;

    stream >> message;
    std::string message_piece;
    while (stream >> message_piece) {
        message += " " + message_piece;
    }

    comparable = create_comparable();
}

const double Entry::get_comparable()
{
    return comparable;
}

std::string Entry::get_full_entry()
{
    return month + " " + day + " " + time + " " + ip + " " + message;
}

std::vector<Entry*> create_vector_of_entries_from_file(std::string file_path) {
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
