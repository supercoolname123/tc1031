#pragma once
#include <iostream>
#include <vector>
#include <string>

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
	
	static bool isEmpty(TreeNode*);

	int heightHelper(TreeNode*);
	int whatLevelAmIHelper(int, TreeNode*);
	bool ancestorsHelper(int, TreeNode*, std::vector<int>&);

	void preorderHelper(TreeNode*);
	void inorderHelper(TreeNode*);
	void postorderHelper(TreeNode*);
	void levelByLevelHelper(TreeNode*, std::vector<std::string>&, int);
	
	template <typename process>
	void processInorderHelper(TreeNode* node, process run) {
		if (node == nullptr) {
			return;
		}

		processInorderHelper(node->getLeftNode(), run);
		run(node->getData());
		processInorderHelper(node->getRightNode(), run);
	}
public:
	Tree() {
		root = nullptr;
	}

	void insertNode(int insertValue);

	void preorderTraversal();
	void inorderTraversal();
	void postorderTraversal();
	void levelByLevelTraversal();

	void visit(int);
	int height();
	void ancestors(int);
	int whatLevelAmI(int);

	template <typename process>
	void processInorder(process run) {
		processInorderHelper(root, run);
	}
}; 

