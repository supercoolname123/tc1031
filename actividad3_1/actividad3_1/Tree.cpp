#include "Tree.h"
const int LEVEL_OF_ROOT = 0;

bool Tree::isEmpty(TreeNode* node)
{
	return node == nullptr;
}

void Tree::levelByLevelTraversal()
{
	std::vector<std::string> levels	= {};
	levelByLevelHelper(root, levels, LEVEL_OF_ROOT);

	for (int i = 0; i < levels.size(); i++) {
		std::cout << i << ". " << levels[i] << std::endl;
	}
}
void Tree::levelByLevelHelper(TreeNode* node, std::vector<std::string>& v, int level)
{
	if (isEmpty(node)) { return; }
	if (v.size() <= level) {
		v.push_back("");
	}

	v[level] += std::to_string(node->getData()) + " ";
	levelByLevelHelper(node->getLeftNode(), v, level + 1);
	levelByLevelHelper(node->getRightNode(), v, level + 1);
}

void Tree::visit(int method)
{
	if (method < 1 || method > 4) {
		throw std::range_error("method should be between 1 and 4, available options are: \n 1. Preorder\n 2. Inorder\n 3. Postorder\n 4. Level by level");
	} 

	switch (method) {
	case 1: preorderTraversal(); break;
	case 2: inorderTraversal(); break;
	case 3: postorderTraversal(); break;
	case 4: levelByLevelTraversal(); break;
	}
}

int Tree::height()
{
	 return heightHelper(root);
}
int Tree::heightHelper(TreeNode* node)
{
	if (isEmpty(node)) return -1;
	int leftHeight = heightHelper(node->getLeftNode());
	int rightHeight = heightHelper(node->getRightNode());
	
	int maxHeight = (leftHeight > rightHeight) ? leftHeight : rightHeight;

	return maxHeight + 1;  
}

void Tree::ancestors(int target)
{
	std::vector<int> ancestorsList = {};
	bool wasFound = ancestorsHelper(target, root, ancestorsList);

	if (!wasFound) {
		std::cout << "__Not found__";
	}
	else {
		std::cout << "_";
		for (std::size_t i = ancestorsList.size(); i > 0; i--) {
			std::cout << " -> " << ancestorsList[i - 1];
		}
	}
}
bool Tree::ancestorsHelper(int target, TreeNode* current, std::vector<int>& v)
{
	if (isEmpty(current)) { return false; }

	bool wasFound = false;
	int currentData = current->getData();
	if (target == currentData) {
		wasFound = true;
	} 
	else if (target < currentData) {
		wasFound = ancestorsHelper(target, current->getLeftNode(), v);
	}
	else {
		wasFound = ancestorsHelper(target, current->getRightNode(), v);
	}

	if (wasFound) {
		v.push_back(currentData);
	}
}

int Tree::whatLevelAmI(int data)
{
	return whatLevelAmIHelper(data, root);
}
int Tree::whatLevelAmIHelper(int data, TreeNode* current)
{
	if (isEmpty(current)) { return -1; }
	if (current->getData() == data) { return LEVEL_OF_ROOT; }

	int result = 0;
	if (data < current->getData()) {
		result = whatLevelAmIHelper(data, current->getLeftNode());
	}
	else {
		result = whatLevelAmIHelper(data, current->getRightNode());
	}

	if (result != -1) 
	{ 
		return result + 1; 
	}
	else { 
		return result; 
	}
}

void Tree::preorderTraversal()
{
	preorderHelper(root);
}
void Tree::preorderHelper(TreeNode* node)
{
	if (isEmpty(node)) {
		return;
	}

	std::cout << node->getData() << " ";
	preorderHelper(node->getLeftNode());
	preorderHelper(node->getRightNode());
}

void Tree::inorderTraversal()
{
	inorderHelper(root);
}
void Tree::inorderHelper(TreeNode* node)
{
	if (isEmpty(node)) {
		return;
	}

	inorderHelper(node->getLeftNode());
	std::cout << node->getData() << " ";
	inorderHelper(node->getRightNode());
}

void Tree::postorderTraversal()
{
	postorderHelper(root);
}
void Tree::postorderHelper(TreeNode* node)
{
	if (isEmpty(node)) {
		return;
	}

	postorderHelper(node->getLeftNode());
	postorderHelper(node->getRightNode());
	std::cout << node->getData() << " ";
}

void Tree::insertNode(int insertValue)
{
	if (isEmpty(root)) {
		root = new TreeNode(insertValue);
	}
	else
	{
		root->insert(insertValue);
	}
}
