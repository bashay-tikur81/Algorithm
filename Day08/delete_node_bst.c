#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;
node *root;

node* insert(node *, int);
node* give_me_node(int);
void inorder(node *);
node* delete_node(node*, int);
node* find_min(node *);

int main(){
    int num, i = 1, counter;
    int deleted;
    root = NULL;
    printf("How many data to enter: ");
    scanf("%d", &counter);
    while (i <= counter){
	printf("Number %d: ", i);
	scanf("%d", &num);
	root = insert(root, num);
	++i;
    }
    printf("Node you want to delete is: ");
    scanf("%d", &deleted);
    printf("Before deleting a node: ");
    inorder(root);
    delete_node(root, deleted);
    printf("\nAfter deleting a node: ");
    inorder(root);
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
void inorder(node *in){
    if (in == NULL) return ;
    inorder(in->left);
    printf("%d ", in->data);
    inorder(in->right);
}

node* delete_node(node* del, int value){
    node *temp;
    // search the node in the tree
    // check if it has zero, one, or two children
    if (del == NULL) return del;
    else if (value < del->data)
	del->left = delete_node(del->left, value);
    else if (value > del->data)
	del->right = delete_node(del->right, value);
    else {
	// case 1: the node has no child
	if (del->left == NULL && del->right == NULL){
	    free(del);
	    del = NULL;
	    return del;
	}
	
	// case 2: the node has one child
	else if (del->left == NULL){
	    node *temp = del;
	    del = del->right;
	    free(temp);
	    
	}
	else if (del->right == NULL){
	    node *temp = del;
	    del = del->left;
	    free(temp);
	
	}

	// case 3: the node have two children
	else {
	    node *temp = find_min(del->right);
	    del->data = temp->data;
	    del->right = delete_node(del->right, temp->data);
	}
    }
    return del;
}

node* find_min(node* min){
    while (min->left != NULL)
	min = min->left;
    return min;

}
