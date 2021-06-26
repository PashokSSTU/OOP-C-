#pragma once

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

	Node* addNode(int value, Node* tree);
	void Add(int value) { ptr = addNode(value, ptr); }

	void deleteBranch(Node* tree);
	void Clear() { deleteBranch(ptr); }

	void printPrefix(Node* tree);
	void printPostfix(Node* tree);
	void printInfix(Node* tree);

	void PrefixTree() { printPrefix(ptr); }
	void PostfixTree() { printPostfix(ptr); }
	void InfixTree() { printInfix(ptr); }

	bool isEmpty() { return (ptr == nullptr); }
};

