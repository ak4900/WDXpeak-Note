int d = 0,num = 0, distance[MAX];

void getDepth(Node *root)
{
	if (root == NULL) return;

	d++;
	getDepth(root->lchild);
	if (root->lchild == NULL && root->rchild == NULL)
	{
		distance[num] = d;
		num++;
	}
	getDepth(root->rchild);
	d--;
}

bool isBalance(Node *root)
{
	if (root == NULL)
		return true;
	getDepth(root);
	
	int max = distance[0];
	int min = distance[0];

	for (int i = 1; i < num; ++i)
	{
		if (max < distance[i])
			max = distance[i];
		if (min > distance[i])
			min = distance[i];
	}

	return (max - min > 1)?false:true;
}