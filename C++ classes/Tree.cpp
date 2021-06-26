#include <iostream>
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
		delete tree;
	}
}

void Tree::printPrefix(Node* tree)
{
	if (tree != nullptr)
	{
		std::cout << tree->field << " ";
		printPrefix(tree->left);
		printPrefix(tree->right);
	}
}

void Tree::printPostfix(Node* tree)
{
	if (tree != nullptr)
	{
		printPostfix(tree->left);
		printPostfix(tree->right);
		std::cout << tree->field << " ";
	}
}

void Tree::printInfix(Node* tree)
{
	if (tree != nullptr)
	{
		printInfix(tree->left);
		std::cout << tree->field << " ";
		printInfix(tree->right);
	}
}