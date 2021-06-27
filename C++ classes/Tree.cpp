#include "Tree.h"

Node* Tree::addNode(int value, Node* tree)
{
	if (tree == nullptr)
	{
		tree = new Node;
		tree->field = value;
		tree->left = nullptr;
		tree->right = nullptr;
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

void Tree::deleteBranch(Node* tree)
{
	if (tree != nullptr)
	{
		deleteBranch(tree->left);
		deleteBranch(tree->right);
		
		//Зануление КОПИИ(!!!) корня. Корень зануляется в Clear()!!!
		delete tree;
		tree = nullptr;
	}
}

void Tree::printPrefix(Node* tree)
{
	if (!isEmpty())
	{
		if (tree != nullptr)
		{
			std::cout << tree->field << " ";
			printPrefix(tree->left);
			printPrefix(tree->right);
		}
	}
	else
	{
		std::cout << std::endl << "Error! Tree is empty!" << std::endl;
	}
}

void Tree::printPostfix(Node* tree)
{
	if (!isEmpty())
	{
		if (tree != nullptr)
		{
			printPrefix(tree->left);
			printPrefix(tree->right);
			std::cout << tree->field << " ";
		}
	}
	else
	{
		std::cout << std::endl << "Error! Tree is empty!" << std::endl;
	}
}

void Tree::printInfix(Node* tree)
{
	if (!isEmpty())
	{
		if (tree != nullptr)
		{
			printPrefix(tree->left);
			std::cout << tree->field << " ";
			printPrefix(tree->right);
		}
	}
	else
	{
		std::cout << std::endl << "Error! Tree is empty!" << std::endl;
	}
}