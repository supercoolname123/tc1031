
#include "Test.h"
#include "FLinked.h"
#include <string>

void Test::testCreate() {
    FLinked<int> list;

    list.create(0, 10);
    list.create(1, 30);
    list.create(1, 20);
    list.create(100, 40);

    if (list.read(0) != 10 ||
        list.read(1) != 20 ||
        list.read(2) != 30 ||
        list.read(3) != 40) {
        throw "Error en testCreate";
    }
}

void Test::testCreateNegativeIndex() {
    FLinked<int> list;
    list.create(0, 10);

    try {
        list.create(-1, 20);
    }
    catch (const char*) {
        return;
    }

    throw "Error en testCreateNegativeIndex";
}

void Test::testRead() {
    FLinked<int> list;
    list.create(0, 10);
    list.create(1, 20);
    list.create(2, 30);

    if (list.read(0) != 10 ||
        list.read(1) != 20 ||
        list.read(2) != 30) {
        throw "Error en testRead";
    }
}

void Test::testReadInvalidIndex() {
    FLinked<int> list;
    list.create(0, 10);
    list.create(1, 20);

    try {
        list.read(-1);
        throw "No se rechazo el indice negativo en read";
    }
    catch (const char* error) {
        if (std::string(error) ==
            "No se rechazo el indice negativo en read") {
            throw;
        }
    }

    try {
        list.read(2);
        throw "No se rechazo el indice fuera de rango en read";
    }
    catch (const char* error) {
        if (std::string(error) ==
            "No se rechazo el indice fuera de rango en read") {
            throw;
        }
    }
}

void Test::testUpdate() {
    FLinked<int> list;
    list.create(0, 10);
    list.create(1, 20);
    list.create(2, 30);

    list.update(1, 99);

    if (list.read(0) != 10 ||
        list.read(1) != 99 ||
        list.read(2) != 30) {
        throw "Error en testUpdate";
    }
}

void Test::testUpdateInvalidIndex() {
    FLinked<int> list;
    list.create(0, 10);

    try {
        list.update(1, 20);
    }
    catch (const char*) {
        return;
    }

    throw "Error en testUpdateInvalidIndex";
}

void Test::testDelete() {
    FLinked<int> list;
    list.create(0, 10);
    list.create(1, 20);
    list.create(2, 30);
    list.create(3, 40);

    list.del(0);

    if (list.read(0) != 20 ||
        list.read(1) != 30 ||
        list.read(2) != 40) {
        throw "Error al eliminar el primer elemento";
    }

    list.del(1);

    if (list.read(0) != 20 ||
        list.read(1) != 40) {
        throw "Error al eliminar un elemento intermedio";
    }

    list.del(1);

    if (list.read(0) != 20) {
        throw "Error al eliminar el ultimo elemento";
    }
}

void Test::testDeleteLastElement() {
    FLinked<int> list;
    list.create(0, 10);
    list.del(0);

    try {
        list.read(0);
    }
    catch (const char*) {
        return;
    }

    throw "Error en testDeleteLastElement";
}

void Test::testEmptyListOperations() {
    FLinked<int> list;

    try {
        list.read(0);
        throw "read permitio acceso a una lista vacia";
    }
    catch (const char* error) {
        if (std::string(error) ==
            "read permitio acceso a una lista vacia") {
            throw;
        }
    }

    try {
        list.update(0, 10);
        throw "update permitio acceso a una lista vacia";
    }
    catch (const char* error) {
        if (std::string(error) ==
            "update permitio acceso a una lista vacia") {
            throw;
        }
    }

    try {
        list.del(0);
        throw "del permitio acceso a una lista vacia";
    }
    catch (const char* error) {
        if (std::string(error) ==
            "del permitio acceso a una lista vacia") {
            throw;
        }
    }
}