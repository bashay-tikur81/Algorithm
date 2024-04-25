typedef struct bst_node{
    int data;
    struct bst_node *left;
    struct bst_node *right;
}bst_node;

typedef struct node{
    int data;
    struct node  *next;
}node;


// In binary search tree
bst_node* give_me_node(int);
bst_node* insert(bst_node *, int);
int search(bst_node*, int);

int max_r(bst_node*);
int max_l(bst_node*);
int min_r(bst_node*);
int min_l(bst_node*);
int maximum(int, int);
int height(bst_node*);
