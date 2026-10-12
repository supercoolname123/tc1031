// actividad2_3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "App.h"
#include "Entry.h"
int main()
{
    App* my_app = new App();
    my_app->run();

    std::vector<Entry*> all_entries = create_vector_of_entries_from_file("bitacora.txt");
}
