#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pairInt;
vector<vector<pairInt>> graph;

void addedge(int x, int y, int cost)
{
	graph[x].push_back(make_pair(cost, y));
	graph[y].push_back(make_pair(cost, x));
}

int heuristic(int from, int to) {
	return abs(from - to);
}

void astar_search(int actual_Src, int target, int n)
{
	vector<bool> visited(n, false);
	priority_queue<pairInt, vector<pairInt>, greater<pairInt>> pq;
	pq.push(make_pair(0, actual_Src));
	int s = actual_Src;
	visited[s] = true;
	while (!pq.empty())
	{
		int x = pq.top().second;
		cout << x << " ";
		pq.pop();
		if (x == target)
			break;

		for (int i = 0; i < graph[x].size(); i++)
		{
			if (!visited[graph[x][i].second])
			{
				visited[graph[x][i].second] = true;
				pq.push(make_pair(graph[x][i].first + heuristic(graph[x][i].second, target), graph[x][i].second));
			}
		}
	}
}

int main()
{
	int v = 14;
	graph.resize(v);

	addedge(0, 1, 3);
	addedge(0, 2, 6);
	addedge(0, 3, 5);
	addedge(1, 4, 9);
	addedge(1, 5, 8);
	addedge(2, 6, 12);
	addedge(2, 7, 14);
	addedge(3, 8, 7);
	addedge(8, 9, 5);
	addedge(8, 10, 6);
	addedge(9, 11, 1);
	addedge(9, 12, 10);
	addedge(9, 13, 2);
	
	int source = 0;
	int target = 9;
	astar_search(source, target, v);
	return 0;
}
