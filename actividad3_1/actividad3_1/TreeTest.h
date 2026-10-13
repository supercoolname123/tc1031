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
        Tree* tree = new Tree();
        int value = 0;

        std::cout << "Inserting the following values: ";

        // insert 10 random integers from 0-99 in tree
        for (int i = 1; i <= 10; i++) {
            value = (int)(std::rand() * 100);
            std::cout << value << " ";

            tree->insertNode(value);
        }

        // perform preorder traveral of tree
        std::cout << "\n\nPreorder traversal ";
        tree->preorderTraversal();

        // perform inorder traveral of tree
        std::cout << "\n\nInorder traversal";
        tree->inorderTraversal();
           
        // perform postorder traveral of tree
        std::cout << "\n\nPostorder traversal";
        tree->postorderTraversal();
        std::cout << std::endl;
	}

    static void whatLevelIAm() {
        Tree* tree = generateRandomTree(10);

        std::cout << "\n\nInorder traversal";
        tree->inorderTraversal();

        std::cout << "\n\nInorder processing of WhatLevelIAm\n";
        tree->processInorder([&](int n) { std::cout << n << ", " << tree->whatLevelAmI(n) << "\n"; });
    }
};

