#include "BinaryTree.h"

BinaryTree* CreateIntTree()
{
	BinaryTree *tree = (BinaryTree*)malloc(sizeof(BinaryTree));
	tree->elements = 0;
	tree->rootElement = NULL;
	tree->dataType = INT;

	return tree;
}

BinaryTree * CreateCharTree()
{
	BinaryTree *tree = (BinaryTree*)malloc(sizeof(BinaryTree));
	tree->elements = 0;
	tree->rootElement = NULL;
	tree->dataType = CHAR;

	return tree;
}

BinaryTreeNode* CreateTreeNode()
{
	BinaryTreeNode *node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	node->data = NULL;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BinaryTreeNode* CreateTreeNodeWithData(void *data, size_t size)
{
	BinaryTreeNode *node = CreateTreeNode();
	node->data = memcpy(malloc(size), data, size);

	return node;
}

bool IsTreeEmpty(BinaryTree *tree)
{
	return tree->elements == 0;
}

unsigned int GetTreeElementCount(BinaryTree *tree)
{
	return tree->elements;
}

int CompareTreeNode(TreeDataType type, BinaryTreeNode *node1, BinaryTreeNode *node2)
{
	return CompareTreeNodeData(type, node1->data, node2->data);
}

int CompareTreeNodeData(TreeDataType type, void *data1, void *data2)
{
	if (type == INT || type == CHAR)
	{
		int value1 = *(int*)data1;
		int value2 = *(int*)data2;

		if (value1 < value2)
		{
			return -1;
		}
		else if (value1 > value2)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	// Default is equal -> not inserted for example
	printf("Invalid TreeDataType");
	return 0;
}

void AddTreeNodeWithData(BinaryTree *tree, void *data, size_t size)
{
	AddTreeNode(tree, CreateTreeNodeWithData(data, size));
}

void AddTreeNode(BinaryTree *tree, BinaryTreeNode *node)
{
	// Special case, if the tree is empty
	if (tree->rootElement == NULL && tree->elements == 0)
	{
		tree->rootElement = node;
		++tree->elements;
		return;
	}

	BinaryTreeNode *treeNode = tree->rootElement;
	int compareResult;
	while (true)
	{
		compareResult = CompareTreeNode(tree->dataType, treeNode, node);
		if (compareResult < 0)
		{
			// Smaller = LEFT
			if (treeNode->left == NULL)
			{
				treeNode->left = node;
				break;
			}
			else
			{
				treeNode = treeNode->left;
			}
		}
		else if (compareResult > 0)
		{
			// Larger = RIGHT
			if (treeNode->right == NULL)
			{
				treeNode->right = node;
				break;
			}
			else
			{
				treeNode = treeNode->right;
			}
		}
		else
		{
			// Ignore element, because this element already exists ...
			return;
		}
	}

	++tree->elements;
}

bool ContainsTreeNodeWithData(BinaryTree *tree, void *data)
{
	if (tree->rootElement == NULL)
	{
		return false;
	}

	return CheckTreeNode(tree->dataType, tree->rootElement, data);
}

bool CheckTreeNode(TreeDataType type, BinaryTreeNode *node, void *data)
{
	if (node == NULL)
	{
		return false;
	}

	if (CompareTreeNodeData(type, node->data, data) == 0)
	{
		return true;
	}

	if (node->right != NULL)
	{
		if (CheckTreeNode(type, node->right, data))
		{
			return true;
		}
	}

	if (node->left != NULL)
	{
		if (CheckTreeNode(type, node->left, data))
		{
			return true;
		}
	}

	return false;
}

bool ContainsTreeNode(BinaryTree *tree, BinaryTreeNode *node)
{
	return ContainsTreeNodeWithData(tree, node->data);
}

BinaryTreeNode* FindNode(TreeDataType type, BinaryTreeNode *node, void *data)
{
	if (CompareTreeNodeData(type, node->data, data))
	{
		return node;
	}

	if (node->right != NULL)
	{
		BinaryTreeNode *foundNode = FindNode(type, node->right, data);
		if (foundNode != NULL)
		{
			return foundNode;
		}
	}

	if (node->left != NULL)
	{
		BinaryTreeNode* foundNode = FindNode(type, node->left, data);
		if (foundNode != NULL)
		{
			return foundNode;
		}
	}

	return NULL;
}

void* RemoveTreeNode(BinaryTree *tree, void *data)
{
	// It does not contain the element ...
	// if (!ContainsTreeNodeWithData(tree, data))
	// {
	// 	return NULL;
	// }

	BinaryTreeNode* node = FindNode(tree->dataType, tree->rootElement, data);
	if (node != NULL)
	{
		AddRemovedTreeNode(tree, node);
	}

	return NULL;
}

void AddRemovedTreeNode(BinaryTree *tree, BinaryTreeNode *node)
{
	// TODO
}
