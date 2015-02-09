typedef struct node{
	int data;
	node *left;
	node *right;
	node *parent;
}Node;


void create_minimal_tree(Node* &head, Node *parent, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end) / 2;
        node[cnt].data = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        create_minimal_tree(head->lchild, head, a, start, mid-1);
        create_minimal_tree(head->rchild, head, a, mid+1, end);
    }
}
