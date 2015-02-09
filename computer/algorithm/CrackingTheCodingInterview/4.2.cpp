int g[n][n]; // the graph
bool visited[n];
queue<int> q;

bool route(int src, int dst)
{
	if (src == dst)
		return true;

	q.push(src);
	while (!q.isEmpty())
	{
		t = q.front();
		q.pop();
		visited[t] = true;

		if (t == dst)
			return true;

		for (int i = 0; i < n; ++i)
		{
			if (visited[i] == false && g[t][i] == 1)
			{
				q.push(i);
				visited[i] = true; // don't forget!
			}
		}

	}
	return false;
}