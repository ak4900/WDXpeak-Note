struct Node{
    int key;
    Node *lchild, *rchild, *parent;
};
Node *p, node[maxn];

vector<list<Node*> > find_level_linklists(Node *head){
    vector<list<Node*> > res;
    int level = 0;
    list<Node*> li;
    li.push_back(head);
    res.push_back(li);
    while(!res[level].empty()){
        list<Node*> l;
        list<Node*>::iterator it;
        for(it=res[level].begin(); it!=res[level].end(); ++it){
            Node *n = *it;
            if(n->lchild) l.push_back(n->lchild);
            if(n->rchild) l.push_back(n->rchild);
        }
        ++level;
        res.push_back(l);
    }
    return res;
}