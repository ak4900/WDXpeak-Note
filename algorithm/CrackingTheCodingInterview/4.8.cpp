bool match(Node* r1, Node* r2){
    if(r1 == NULL && r2 == NULL) return true;
    else if(r1 == NULL || r2 == NULL) return false;
    else if(r1->key != r2->key) return false;
    else return match(r1->lchild, r2->lchild) && match(r1->rchild, r2->rchild);
}
bool subtree(Node* r1, Node* r2){
    if(r1 == NULL) return false;
    else if(r1->key == r2->key){
        if(match(r1, r2)) return true;
    }
    else return subtree(r1->lchild, r2) || subtree(r1->rchild, r2);
}
bool contain_tree(Node* r1, Node* r2){
    if(r2 == NULL) return true;
    else return subtree(r1, r2);
}