#pragma once
#include <iostream>

class Tree;

class Node
{
	int field;
	Node* left;
	Node* right;
	friend class Tree;
};

class Tree
{
private:
	Node* ptr; // корень дерева

	//Низкоуровневые методы класса 
	Node* addNode(int value, Node* tree);

	void deleteBranch(Node* tree);

	void printPrefix(Node* tree);
	void printPostfix(Node* tree);
	void printInfix(Node* tree);

public:
	Tree()
	{
		ptr = nullptr;
	}

	~Tree()
	{
		if(!isEmpty()) 
		{
			Clear();
		}
	}

	// Высокоуровневые методы класса
	void Add(int value) { ptr = addNode(value, ptr); }

	void Clear() { deleteBranch(ptr); ptr = nullptr; }

	void PrefixTree() { printPrefix(ptr); }
	void PostfixTree() { printPostfix(ptr); }
	void InfixTree() { printInfix(ptr); }

	bool isEmpty() { return (ptr == nullptr); }
};

