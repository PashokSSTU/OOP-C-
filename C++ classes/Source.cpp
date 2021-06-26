#include <iostream>

struct node
{
	int field;
	node* left;
	node* right;
};

void printPrefix(node* tree);
void printPostfix(node* tree);
void printInfix(node* tree);

void deletePart(node* tree);

node* addNode(int value, node* tree);

int main()
{
	node *root = nullptr; // ”казатель на корень дерева
	
	root = addNode(50, root);

	root = addNode(20, root);
	root = addNode(25, root);
	root = addNode(15, root);
	root = addNode(23, root);
	root = addNode(27, root);

	root = addNode(51, root);
	root = addNode(63, root);
	root = addNode(61, root);
	root = addNode(59, root);
	root = addNode(90, root);

	printPostfix(root);

	std::cout << std::endl;

	node* temp = root;

	deletePart(root);

	root = addNode(50, root);

	root = addNode(20, root);

	root = addNode(0, root);

	printInfix(root);

	return 0;
}

void printPrefix(node* tree)
{
	if (tree != nullptr)
	{
		std::cout << tree->field << " ";
		printPrefix(tree->left);
		printPrefix(tree->right);
	}
}

void printPostfix(node* tree)
{
	if (tree != nullptr)
	{
		printPostfix(tree->left);
		printPostfix(tree->right);
		std::cout << tree->field << " ";
	}
}

void printInfix(node* tree)
{
	if (tree != nullptr)
	{
		printInfix(tree->left);
		std::cout << tree->field << " ";
		printInfix(tree->right);
	}
}

node* addNode(int value, node* tree)
{
	if (tree == nullptr)
	{
		tree = new node;
		tree->left = nullptr;
		tree->right = nullptr;
		tree->field = value;
	}
	else if (value < tree->field)
	{
		tree->left = addNode(value, tree->left);
	}
	else
	{
		tree->right = addNode(value, tree->right);
	}
	return tree;
}

void deletePart(node* tree)
{
	if (tree != nullptr)
	{
		deletePart(tree->left);
		deletePart(tree->right);
		delete tree;
	}
}