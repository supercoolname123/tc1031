// actividad1_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

#include <fstream>
#include <string>
#include "Entry.h"

std::string read_file(std::string path_file) {
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
}




int main()
{
    std::string file = read_file("bitacora.txt");
    Entry e("Oct 9 10:32:24 423.2.230.77:6166 Failed password for illegal user guest");

    std::cout << e.get_full_entry() << "\n" << e.get_comparable();
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
