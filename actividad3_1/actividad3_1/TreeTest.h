#pragma once
#include <iostream>
#include <random>
#include "Tree.h"

class TreeTest
{
private:
    static Tree* generateRandomTree(int n) {
        Tree* tree = new Tree();
        int value = 0;

        std::cout << "Inserting the following values: ";

        for (int i = 1; i <= n; i++) {
            value = (int)(std::rand() * 100);
            std::cout << value << " ";

            tree->insertNode(value);
        }

        return tree;
    }
public:
	static void main() {
        Tree* tree = generateRandomTree(10);

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

    static void TestWhatLevelIAm() {
        Tree* tree = generateRandomTree(50);

        std::cout << "\n\nInorder traversal";
        tree->inorderTraversal();

        std::cout << "\n\nInorder processing of WhatLevelIAm\n";
        tree->processInorder([&](int n) { std::cout << n << ", " << tree->whatLevelAmI(n) << "\n"; });
    }

    static void TestHeight() {
        Tree* tree = generateRandomTree(1);
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

    static void TestLevelByLevel() {
        Tree* tree = generateRandomTree(100);

        tree->levelByLevelTraversal();

        std::cout << "\n\nInorder processing of WhatLevelIAm\n";
        tree->processInorder([&](int n) { std::cout << n << ", " << tree->whatLevelAmI(n) << "\n"; });
    }
};

