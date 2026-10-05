#pragma once

class Test {
public:
    static void testCreate();
    static void testCreateNegativeIndex();
    static void testRead();
    static void testReadInvalidIndex();
    static void testUpdate();
    static void testUpdateInvalidIndex();
    static void testDelete();
    static void testDeleteLastElement();
    static void testEmptyListOperations();
};