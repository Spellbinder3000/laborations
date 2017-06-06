#pragma once


template<class KEY,class DATA>
struct NodeTree
{
	NodeTree *left, *right;
	KEY data;
	DATA valdata;
	int heightNode;
	NodeTree(KEY key,DATA val) {
		
		data = key;
		valdata = val;
		left = right = 0;
		heightNode = 1;
	}
};