#pragma once

int main() {
    try {
        Test::testCreate();
        Test::testCreateNegativeIndex();
        Test::testRead();
        Test::testReadInvalidIndex();
        Test::testUpdate();
        Test::testUpdateInvalidIndex();
        Test::testDelete();
        Test::testDeleteLastElement();
        Test::testEmptyListOperations();


        std::cout << "Todos los test pasaron\n";
    }
    catch (const char* error) {
        std::cout << "Un test tuvo un error: " << error << '\n';
    }
}
