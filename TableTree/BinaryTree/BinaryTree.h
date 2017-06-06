#pragma once
#include "NodeTree.h"
#include <iostream>
#include <vector>
#include <string>

template <class KEY,class DATA>
class BinaryTree
{
	NodeTree<KEY,DATA> *root;
	std::vector<std::string> str;
	NodeTree<KEY, DATA>* insert(NodeTree<KEY, DATA>* node, KEY elem, DATA val);
	NodeTree<KEY, DATA>* remove(NodeTree<KEY, DATA>* node, KEY elem);
	void showNode(NodeTree<KEY, DATA>* node);


	NodeTree<KEY, DATA>* findmin(NodeTree<KEY, DATA>* p)
	{
		return p->left ? findmin(p->left) : p;
	}

	NodeTree<KEY, DATA>* removemin(NodeTree<KEY, DATA>* p)
	{
		if (p->left == 0)
			return p->right;
		p->left = removemin(p->left);
		return balance(p);
	}
	unsigned char height(NodeTree<KEY, DATA>* p)
	{
		return p!= nullptr ? p->heightNode : 0;
	}

	int bfactor(NodeTree<KEY, DATA>*& p)
	{
		return height(p->right) - height(p->left);
	}

	void fixHeight(NodeTree<KEY, DATA>*& p)
	{
		unsigned char hl = height(p->left);
		unsigned char hr = height(p->right);
		p->heightNode = (hl > hr ? hl : hr) + 1;
	}

	NodeTree<KEY, DATA>* rotateRight(NodeTree<KEY, DATA>*& p)
	{
		NodeTree<KEY, DATA>* q = p->left;
		p->left = q->right;
		q->right = p;
		fixHeight(p);
		fixHeight(q);
		return q;
	}
	NodeTree<KEY, DATA>* rotateLeft(NodeTree<KEY, DATA>*& q)
	{
		NodeTree<KEY, DATA>* p = q->right;
		q->right = p->left;
		p->left = q;
		fixHeight(q);
		fixHeight(p);
		return p;
	}
	NodeTree<KEY, DATA>* balance(NodeTree<KEY, DATA>* p)
	{
		fixHeight(p);
		if (bfactor(p) == 2)
		{
			if (bfactor(p->right) < 0)
				p->right = rotateRight(p->right);
			return rotateLeft(p);
		}
		if(bfactor(p) == -1)
		{
			if (bfactor(p->left) > 0)
				p->left = rotateLeft(p->left);
			return rotateRight(p);
		}
		return p;
	}
	DATA getMaxValue(NodeTree<KEY, DATA>*p)
	{
		if (p->right != nullptr)
			return getMaxValue(p->right);
		return p->valdata;
	}
	
public:
	DATA getMaxValue()
	{
		return getMaxValue(root);
	}
	BinaryTree();
	~BinaryTree();

	void add(KEY elem,DATA val);
	void remove(KEY elem);
	void show();

	unsigned char height()
	{
		return height(root);
	}

};

template<class KEY,class DATA>
NodeTree<KEY, DATA> * BinaryTree<KEY, DATA>::insert(NodeTree<KEY, DATA>* node, KEY elem, DATA val)
{
	if (elem == 3746)
		elem = elem;
	if (node == nullptr)
	    return new NodeTree<KEY, DATA>(elem,val);
	 
	if (elem <= node->data)
        node->left = insert(node->left, elem,val);
	else
	    node->right = insert(node->right, elem,val);
	return balance(node);

}

template<class KEY,class DATA>
inline NodeTree<KEY, DATA>* BinaryTree<KEY, DATA>::remove(NodeTree<KEY, DATA>* node, KEY elem)
{
	if (node == nullptr)
		return nullptr;
	if (elem < node->data)
		node->left = remove( node->left, elem);
	else if(elem > node->data)
		node->right = remove( node->right, elem);
	else
	{
		NodeTree<KEY, DATA>* q = node->left;
		NodeTree<KEY, DATA>* r = node->right;
		delete node;
		if (!r) return q;
		NodeTree<KEY, DATA>* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}

	return balance(node);
}

 template<class KEY,class DATA>
void BinaryTree<KEY, DATA>::showNode(NodeTree<KEY, DATA>* node)
 {
	
	 if (node != nullptr)
	 {
		 showNode(node->left);
		 std::cout <<"("<< node->data<<"," <<node->valdata << ") < ";
		 showNode(node->right);
	 }
 }

template<class KEY, class DATA>
BinaryTree<KEY, DATA>::BinaryTree()
{
	root = nullptr;
}

template<class KEY, class DATA>
BinaryTree<KEY, DATA>::~BinaryTree()
{
}

template<class KEY,class DATA>
void BinaryTree<KEY, DATA>::add(KEY elem, DATA val)
{
	root = insert( root, elem,val);
}
template<class KEY, class DATA>
void BinaryTree<KEY, DATA>::remove(KEY elem)
{
	root = remove(root, elem );
}

template<class KEY, class DATA>
void BinaryTree<KEY, DATA>::show()
{
	showNode(root);
	}
