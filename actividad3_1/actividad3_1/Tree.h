#pragma once
#include <iostream>

class TreeNode
{
private:
	TreeNode* leftNode;
	int data;
	TreeNode* rightNode;

	static bool isEmpty(TreeNode* node) {
		return node == nullptr;
	}

public:
	int getData() {
		return data;
	}
	TreeNode* getLeftNode() {
		return leftNode;
	}
	TreeNode* getRightNode() {
		return rightNode;
	}

	TreeNode(int nodeData) {
		data = nodeData;
		leftNode = nullptr;
		rightNode = nullptr;
	}

	void insert(int insertValue) {
		if (insertValue < data) {
			if (isEmpty(leftNode)) {
				leftNode = new TreeNode(insertValue);
			}
			else {
				leftNode->insert(insertValue);
			}
		}
		else if (insertValue > data) {
			if (isEmpty(rightNode)) {
				rightNode = new TreeNode(insertValue);
			}
			else {
				rightNode->insert(insertValue);
			}
		}
	}
};

class Tree
{
private:
	TreeNode* root;
	
	static bool isEmpty(TreeNode* node) {
		return node == nullptr;
	}
public:
	Tree() {
		root = nullptr;
	}

	void insertNode (int insertValue) {
		if (isEmpty(root)) {
			root = new TreeNode(insertValue);
		}
		else
		{
			root->insert(insertValue);
		}
	}

	void preorderTraversal() {
		preorderHelper(root);
	}
	void preorderHelper(TreeNode* node) {
		if (isEmpty(node)) {
			return;
		}

		std::cout << node->getData() << " ";
		preorderHelper(node->getLeftNode());
		preorderHelper(node->getRightNode());
	}
	
	void inorderTraversal() {
		inorderHelper(root);
	}
	void inorderHelper(TreeNode* node) {
		if (isEmpty(node)) {
			return;
		}

		inorderHelper(node->getLeftNode());
		std::cout << node->getData() << " ";
		inorderHelper(node->getRightNode());
	}

	void postorderTraversal() {
		postorderHelper(root);
	}
	void postorderHelper(TreeNode* node) {
		if (isEmpty(node)) {
			return;
		}

		postorderHelper(node->getLeftNode());
		postorderHelper(node->getRightNode());
		std::cout << node->getData() << " ";
	}

}; 

