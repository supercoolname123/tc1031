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

Entry::Entry(std::string new_entry)
{
    full_entry = new_entry;
    std::istringstream stream(new_entry);

    std::string unparsed_ip;
    stream >> month >> day >> time >> unparsed_ip;
    ip = new IP(unparsed_ip);

    stream >> message;
    std::string message_piece;
    while (stream >> message_piece) {
        message += " " + message_piece;
    }
}

std::string Entry::get_full_entry()
{
    return full_entry;
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

bool IP::is_octeto_valid(int octeto)
{
    return octeto >= 0 && octeto <= 999;
}

IP::IP()
{
    octeto1 = 0;
    octeto2 = 0;
    octeto3 = 0;
    octeto4 = 0;
}

IP::IP(std::string unparsed)
{
    std::istringstream stream(unparsed);

    try {
        std::string octeto;
        std::getline(stream, octeto, '.');
        octeto1 = std::stoi(octeto);
        std::getline(stream, octeto, '.');
        octeto2 = std::stoi(octeto);
        std::getline(stream, octeto, '.');
        octeto3 = std::stoi(octeto);
        std::getline(stream, octeto, '.');
        octeto4 = std::stoi(octeto);
    }
    catch (const std::exception& e){
        throw std::invalid_argument("Favor de seguir el formato");
    }
    is_ip_valid(this);
}

bool IP::is_ip_valid(IP* ip)
{
    bool all_octetos_valid = is_octeto_valid(ip->octeto1) && is_octeto_valid(ip->octeto2) && is_octeto_valid(ip->octeto3) && is_octeto_valid(ip->octeto4);
    if (!all_octetos_valid) {
        throw std::range_error("IP " + ip->getFullIP() + " is not valid, all octects must be whithin 0 and 999");
    }
    return true;
}

const std::string IP::getFullIP()
{
    return std::to_string(octeto1) + "." + std::to_string(octeto2) + "." + std::to_string(octeto3) + "." + std::to_string(octeto4);
}

bool IP::operator<(const IP& o) const
{
    if (octeto1 < o.octeto1) return true;
    else if (octeto2 < o.octeto2 && octeto1 == o.octeto1) return true;
    else if (octeto3 < o.octeto3 && octeto2 == o.octeto2 && octeto1 == o.octeto1) return true;
    else if (octeto4 < o.octeto4 && octeto3 == o.octeto3 && octeto2 == o.octeto2 && octeto1 == o.octeto1) return true;
    else {
        return false;
    }
}

bool IP::operator>(const IP& o) const
{
    return  o < *this;
}

bool IP::operator==(const IP& o) const
{
    return octeto1 == o.octeto1 && octeto2 == o.octeto2 && octeto3 == o.octeto3 && octeto4 == o.octeto4;
}

bool IP::operator>=(const IP& o) const
{
    return !(*this < o);
}

bool IP::operator<=(const IP& o) const
{
    return !(*this > o);
}

bool IP::operator!=(const IP& o) const
{
    return !(*this == o);
}