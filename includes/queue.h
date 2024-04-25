// In Queue

typedef struct node{
	int data;
	struct node *next;
} node;

void enqueue(int);
int dequeue();
