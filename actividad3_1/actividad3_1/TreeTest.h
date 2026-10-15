#pragma once
#include <iostream>
#include <random>
#include "Tree.h"

class TreeTest
{
private:
    Tree* generateRandomTree(int n) {
        Tree* tree = new Tree();
        std::srand(seed);
        int value = 0;

        for (int i = 1; i <= n; i++) {
            value = (int)(std::rand());
            tree->insertNode(value);
        }

        return tree;
    }
public:
    int numberOfNodes = 100;
    int seed = 1;

    void FullTesting() {
        std::cout << "\n======================== Test: Visit ========================\n";
        this->TestVisit();
        std::cout << "\n======================== Test: Height ========================\n";
        this->TestHeight();
        std::cout << "\n======================== Test: WhatLevelIAm ========================\n";
        this->TestWhatLevelIAm();
        std::cout << "\n======================== Test: Ancestors ========================\n";
        this->TestAncestors();
    }

	void main() {
        Tree* tree = generateRandomTree(numberOfNodes);

        // perform preorder traveral of tree
        std::cout << "\n\nPreorder traversal\n";
        tree->preorderTraversal();

        // perform inorder traveral of tree
        std::cout << "\n\nInorder traversal\n";
        tree->inorderTraversal();
           
        // perform postorder traveral of tree
        std::cout << "\n\nPostorder traversal\n";
        tree->postorderTraversal();
        std::cout << std::endl;
	}

    void TestWhatLevelIAm() {
        Tree* tree = generateRandomTree(numberOfNodes);

        std::cout << "\n\nInorder traversal";
        tree->inorderTraversal();

        std::cout << "\n\nInorder processing of WhatLevelIAm\n";
        tree->processInorder([&](int n) { std::cout << n << ", " << tree->whatLevelAmI(n) << "\n"; });
    }

    void TestHeight() {
        Tree* tree = generateRandomTree(numberOfNodes);
        int maxHeight = 0;

        std::cout << "\n\nInorder traversal \n";
        tree->inorderTraversal();
        tree->processInorder([&](int n) {
            int nodeHeight = tree->whatLevelAmI(n);
            maxHeight = (nodeHeight > maxHeight) ? nodeHeight : maxHeight;
        });

        std::cout << std::endl;
        std::cout << "tree->height(): " << tree->height() << "\n";
        std::cout << "max height found: " << maxHeight << "\n";
    }

    void TestLevelByLevel() {
        Tree* tree = generateRandomTree(numberOfNodes);

        std::cout << std::endl;
        tree->levelByLevelTraversal();

        std::cout << "\n\nInorder processing of WhatLevelIAm\n";
        tree->processInorder([&](int n) { std::cout << n << ", " << tree->whatLevelAmI(n) << "\n"; });
    }

    void TestVisit() {
        Tree* tree = generateRandomTree(numberOfNodes);

        std::cout << "\nProbando que rechaze inputs invalidos.\n";
        int invalid_inputs[5] = { -2, -1, 0, 5, 6 };
        for (int i = 0; i < 5; i++) {
            try {
                std::cout << "Prueba: " << invalid_inputs[i] << " ";
                tree->visit(invalid_inputs[i]);
                std::cout << "rechazada\n";
            }
            catch (std::range_error& e) {
                std::cout << "aprobada\n";
            }
        }

        std::cout << "\nProbando inputs validos.\n";
        std::string valid_inputs[4] = { "1. Preorder", "2. Inorder", "3. Postorder", "4. Level by level" };
        for (int i = 1; i <= 4; i++) {
            try {
                std::cout << "Prueba " << i << ":\n";
                tree->visit(i);
                std::cout << "\nFue aprobada\n\n";
            }
            catch (std::exception& e){
                std::cout << "\nFue rechazada\n";
            }
        }
    }

    void TestAncestors() {
        Tree* tree = generateRandomTree(numberOfNodes);

        int input = 0;
        while (input != -1) {
            std::cout << "\nInsert a data point you would like to know its ancestors: ";
            std::cin >> input;

            std::cout << std::endl;
            tree->ancestors(input);
            std::cout << std::endl;
        }
    }
};

