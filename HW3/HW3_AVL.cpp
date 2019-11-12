#include "HW3_AVL.h"

AVL::AVL() {
	// TODO : Implement a constructor of AVL
	BST();
}


void AVL::insert(const int& key, const double& data) {
	// TODO : Implement an insert function of AVL Tree using private insert function
	insert(root, key, data);
}

void AVL::remove(const int& key) {
	// TODO : Implement a remove function of AVL Tree using private remove function
	remove(root, key);
}

int AVL::BF(TreeNode* curr_node) {
	// TODO : Return the balance factor of curr_node
	// BF = The height of left child node of curr_node - The height of right child node of curr_node
	if (curr_node == nullptr) {
		return 0;
	}
	return getLevelFromLeaf(curr_node->left) - getLevelFromLeaf(curr_node->right);
}

void AVL::insert(TreeNode*& curr_node, const int& key, const double& data) {
	// TODO : Insert new node in AVL tree
	if (curr_node == nullptr) {
		// TODO : Create a new node
		TreeNode* newNode = new TreeNode(key, data);
		curr_node = newNode;
	}
	else if (key < curr_node->key) {
		insert(curr_node->left, key, data);
		// TODO : Insert the node in left sub-tree with rotation process
	}
	else if (key > curr_node->key) {
		insert(curr_node->right, key, data);
		// TODO : Insert the node in right sub-tree with rotation process
	}
	else if (key == curr_node->key) {
		// TODO : Update when a node which has same key exists
		curr_node->data = data;
	}
	if (BF(curr_node) == -2) {
		if (BF(curr_node->right) != -1)
			rotateLeft(curr_node->right);
		rotateSingle(curr_node);
	}else if (BF(curr_node) == 2) {
		if (BF(curr_node->left) != 1)
			rotateSingle(curr_node->left);
		rotateLeft(curr_node);
	}
	return;
}

void AVL::rotateSingle(TreeNode*& curr_node) {
	TreeNode* nextHead = curr_node->right;
	TreeNode* temp = curr_node;

	curr_node = nextHead;
	temp->right = nextHead->left;
	nextHead->left = temp;
	// TODO : Implement a rotateSingle function
}

void AVL::rotateLeft(TreeNode*& curr_node) {
	TreeNode* nextHead = curr_node->left;
	TreeNode* temp = curr_node;

	curr_node = nextHead;
	temp->left = nextHead->right;
	nextHead->right = temp;
	// TODO : Implement a rotateSingle function
}


void AVL::rotateDouble(TreeNode*& curr_node) {
	// TODO : Implement a rotateDouble function
	TreeNode* nextHead = curr_node->right;
	TreeNode* nextRoot = curr_node->right->left;
	TreeNode* temp = curr_node;
	
	curr_node = nextRoot;
	temp->right = nextRoot->left;
	nextHead->left = nextRoot->right;
	nextRoot->right = nextHead;
	nextRoot->left = temp;
}

void AVL::remove(TreeNode*& curr_node, const int& key) {
	// TODO : Implement a remove function with propagated rotation process
	if (curr_node != nullptr) {
		if (key == curr_node->key) doRemoval(curr_node);
		else if (key < curr_node->key) remove(curr_node->left, key);
		else remove(curr_node->right, key);
	}
	if (BF(curr_node) == -2) {
		if (BF(curr_node->right) == 1)
			rotateLeft(curr_node->right);
		rotateSingle(curr_node);
	}
	else if (BF(curr_node) == 2) {
		if (BF(curr_node->left) == -1)
			rotateSingle(curr_node->left);
		rotateLeft(curr_node);
	}
}