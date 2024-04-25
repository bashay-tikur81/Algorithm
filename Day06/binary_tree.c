#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include"../includes/binary_tree.h"

#define true 1
#define false 0

bst_node* insert(bst_node *root, int data){
    if (root == NULL){
	root = give_me_node(data);
    }
    else if (data <= root->data){
	root->left = insert(root->left, data);
    }
    else {
	root->right = insert(root->right, data);
    }
    return root;
}

int search(bst_node* root, int data){
    if (root == NULL){
	return false;
    }
    if (root->data == data){
	return true;
    }
    else if (data <= root->data){
	return search(root->left, data);
    }
    else {
	return search(root->right, data);
    }
}
bst_node* give_me_node(int value){
    bst_node* new_node = (bst_node*) malloc(sizeof(bst_node));
    if (new_node == NULL){
	printf("Can't allocate memory.\n");
	exit(1);
    }
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}



int min_l(bst_node *root){
    if (root == NULL){
	printf("No value at the tree (-_-)");
	return -1;
    }
    while(root->left != NULL){
	root = root->left;
    }
    return root->data;
}
int max_l(bst_node *root){
    if (root == NULL){
	printf("No value at the tree (-_-)");
	return -1;
    }
    while (root->right != NULL){
	root = root->right;
    }
    return root->data;
}
// finding minimum using recursive function

int min_r(bst_node * root){
    if (root == NULL){
	printf("No value at the tree.\n");
	return -1;
    }
    else if (root->left == NULL){
	return root->data;
    }
    return min_r(root->left);
}

int max_r(bst_node * root){
    if (root == NULL){
	printf("No value at the tree.\n");
	return -1;
    }
    else if (root->right == NULL){
	return root->data;
    }
    return max_r(root->right);
}

int height(bst_node* root){
    int left_height, right_height;
    if (root == NULL){
	return -1;
    }

    left_height = height(root->left);
    right_height = height(root->right);
    return maximum(left_height, right_height) + 1;

}
int maximum(int a, int b){
    return (a >= b)?a:b;
}
