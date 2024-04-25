/* Here the prototypes of queue of nodes */

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
} node;

typedef struct queue_node{
	struct node *nodeq;
	struct queue_node *next;
} queue_node;

extern queue_node *front;
extern queue_node *rear;

void enqueue(node *);
node* dequeue(void);

