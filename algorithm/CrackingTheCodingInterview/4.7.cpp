// without limitations
Node* first_ancestor(Node* n1, Node* n2){
    if(n1 == NULL || n2 == NULL) return NULL;
    map<Node*, bool> m;
    while(n1){
        m[n1] = true;
        n1 = n1->parent;
    }
    while(n2 && !m[n2]){
        n2 = n2->parent;
    }
    return n2;
}

// no extra space
bool father(Node* n1, Node* n2){
    if(n1 == NULL) return false;
    else if(n1 == n2) return true;
    else return father(n1->lchild, n2) || father(n1->rchild, n2);
}
Node* first_ancestor1(Node* n1, Node* n2){
    if(n1 == NULL || n2 == NULL) return NULL;
    while(n1){
        if(father(n1, n2)) return n1;
        n1 = n1->parent;
    }
    return NULL;
}

// no pointer to parent Node
void first_ancestor2(Node* head, Node* n1, Node* n2, Node* &ans){
    if(head==NULL || n1==NULL || n2==NULL) return;
    if(head && father(head, n1) && father(head, n2)){
        ans = head;
        first_ancestor2(head->lchild, n1, n2, ans);
        first_ancestor2(head->rchild, n1, n2, ans);
    }
}

//这里用到了递归，ans最终保存的是这两个结点从根结点算起最后找到的那个祖先。 因为从根结点开始，每次找到满足要求的结点，ans都会被更新。