#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../includes/node_queue.h"

#define true 1
#define false 0

/*
  node and queue_node are structures defined in ../includes/node_queue.h
*/
node* root;
void preorder(node *);
void inorder(node *);
void postorder(node *);

node* insert(node *, int);
node* give_me_node(int);
int is_empty(queue_node *);

int main(){
    int num, i = 1, counter;
    root = NULL;
    printf("How many data to enter: ");
    scanf("%d", &counter);
    while (i <= counter){
	printf("Number %d: ", i);
	scanf("%d", &num);
	root = insert(root, num);
	++i;
    }
    printf("Pre order traversal: ");
    preorder(root);
    printf("\nIn order traversal: ");
    inorder(root);
    printf("\nPost order traversal: ");
    postorder(root);
    printf("\n");
}

node* insert(node *root, int data){
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

node* give_me_node(int value){
    node* new_node = (node*) malloc(sizeof(node));
    if (new_node == NULL){
	printf("Can't allocate memory.\n");
	exit(1);
    }
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void preorder(node *pre){
    // print root first, then left and right
    if (pre == NULL) return;
    printf("%d, ",pre->data);
    preorder(pre->left);
    preorder(pre->right);
}
void inorder(node *in){
    if (in == NULL) return ;
    inorder(in->left);
    printf("%d, ", in->data);
    inorder(in->right);
}
void postorder(node *post){
    if (post == NULL) return;
    postorder(post->left);
    postorder(post->right);
    printf("%d, ", post->data);
}
