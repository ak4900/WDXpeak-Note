Node* minimal(Node* no){
    if(no == NULL) return NULL;
    while(no->lchild)
        no = no->lchild;
    return no;
}

Node* successor(Node* no){
    if(no == NULL) return NULL;
    if(no->rchild) return minimal(no->rchild);
    Node *y = no->parent;
    while(y && y->rchild==no){
        no = y;
        y = y->parent;
    }
    return y;
}