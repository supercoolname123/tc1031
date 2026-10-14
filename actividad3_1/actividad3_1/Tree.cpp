#include "Tree.h"


void Tree::levelByLevelTraversal()
{
	const int LEVEL_OF_ROOT = 1;
	std::vector<std::string> levels	= { std::string("") };

	levelByLevelHelper(root, levels, LEVEL_OF_ROOT);

	for (int i = LEVEL_OF_ROOT; i < levels.size(); i++) {
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
	if (method < 1 && method > 4) {
		std::range_error("method should be between 1 and 4, available options are: \n 1. Preorder\n 2. Inorder\n 3. Postorder\n 4. Level by level");
	} 
}

int Tree::height()
{
	 return heightHelper(root);
}
int Tree::heightHelper(TreeNode* node)
{
	if (isEmpty(node)) return 0;
	int leftHeight = heightHelper(node->getLeftNode());
	int rightHeight = heightHelper(node->getRightNode());
	
	int maxHeight = (leftHeight > rightHeight) ? leftHeight : rightHeight;

	return maxHeight + 1;  
}

void Tree::ancestors(int)
{
}

int Tree::whatLevelAmI(int data)
{
	return whatLevelAmIHelper(data, root);
}
int Tree::whatLevelAmIHelper(int data, TreeNode* current)
{
	if (isEmpty(current)) { return -1; }
	if (current->getData() == data) { return 1; }

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


