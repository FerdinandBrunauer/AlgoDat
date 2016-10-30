#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> // memcpy

//				  +-------+
//				  |		  |
//				  |		  |
//				  +-------+
//					/	\
//				   /	 \
//				  /		  \
//		+-------+			+-------+
//		|		|			|		|
//		|		|			|		|
//		+-------+			+-------+
//
//		SMALLER 			  GREATER
//	<-------------		  ------------->
//

// When adding a datatype, extend the compare method
typedef enum TreeDataType {
	INT,
	CHAR
} TreeDataType;

typedef struct BinaryTreeNode {
	void *data;
	struct BinaryTreeNode *right;
	struct BinaryTreeNode *left;
} BinaryTreeNode;

typedef struct BinaryTree {
	unsigned int elements;
	TreeDataType dataType;
	struct BinaryTreeNode *rootElement;
} BinaryTree;

BinaryTree* CreateIntTree();
BinaryTree* CreateCharTree();
BinaryTreeNode* CreateTreeNode();
BinaryTreeNode* CreateTreeNodeWithData(void *data, size_t size);
// Dispose
// ChangeType -> (Remove all Items -> change type)

bool IsTreeEmpty(BinaryTree *tree);
unsigned int GetTreeElementCount(BinaryTree *tree);
/*
* \return <0 = SMALLER, 0 = EQUAL, >0 = GREATER
*/
int CompareTreeNode(TreeDataType type, BinaryTreeNode *node1, BinaryTreeNode *node2);
int CompareTreeNodeData(TreeDataType type, void *data1, void *data2);

void AddTreeNodeWithData(BinaryTree *tree, void *data, size_t size);
void AddTreeNode(BinaryTree *tree, BinaryTreeNode *node);

bool ContainsTreeNodeWithData(BinaryTree *tree, void *data);
bool CheckTreeNode(TreeDataType type, BinaryTreeNode *node, void *data);
bool ContainsTreeNode(BinaryTree *tree, BinaryTreeNode *node);

void* RemoveTreeNode(BinaryTree *tree, void *data);
void AddRemovedTreeNode(BinaryTree *tree, BinaryTreeNode *node);