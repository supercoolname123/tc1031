#include "Tree.h"

void Tree::visit(int method)
{
	if (method < 1 && method > 4) {
		std::range_error("method should be between 1 and 4, available options are: \n 1. Preorder\n 1. Inorder\n 1. Postorder\n 1. Level by level");
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

	int leftResult = whatLevelAmIHelper(data, current->getLeftNode());
	if (leftResult != -1) { return leftResult + 1; }

	int rightResult = whatLevelAmIHelper(data, current->getRightNode());
	if (rightResult != -1) { return rightResult + 1; }

	return -1;
}


