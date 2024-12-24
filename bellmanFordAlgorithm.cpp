//Author: Abu Jafar Md Jakaria

#include<bits/stdc++.h>
using namespace std;

void bellmanFord(int source, int nodes, vector<tuple<int, int, int>>&graph, vector<int> &dist, vector<int> &parent)
{
	dist[source] = 0;
	parent[source] = -1;
	//Relaxation of edges
	for(int i = 0; i < nodes-1; i++)
	{
		for(auto &[u, v, w] : graph)
		{
			if(dist[u] != INT_MAX && dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				parent[v] = u;
			}
		}
	}
	//check for negative cycles in the graph
	for(auto &[u, v, w] : graph)
		{
			if(dist[u] != INT_MAX && dist[u] + w < dist[v])
			{
				cout << "The graph contains negative cycle!\n";
				return;
			}
		}
}
void printPath(int source, int destination, vector<int> &parent)
{
	if(parent[destination] == -1)
	{
		cout << "No path from " << source << " to " << destination << endl;
		return;
	}
	vector<int> path;
	for(int node = destination; node != -1; node = parent[node])
		path.push_back(node);

	reverse(path.begin(), path.end());
	cout << "Path from " << source << "to " << destination << ":\n";
	for(int i: path)
		cout << i << " ";
	cout << endl;
}

int main()
{
	int nodes, edges;
	//cout << "Enter nodes and edges:\n";
    cin >> nodes >> edges;
    vector<tuple<int, int, int>> graph;
    //cout << "Now enter the edges(u v w)\n";

	//adjacency list - directed graph 
    for (int i = 0; i < edges; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph.emplace_back(u, v, w);
        // graph.emplace_back(v, u, w);
    }
    int source, destination; cin >> source >> destination;
    vector<int> dist(nodes, INT_MAX); //set infinity
    vector<int> parent(nodes, -1); //initially each nodes parent are -1


    bellmanFord(source, nodes, graph, dist, parent);

    cout << "Distance of each nodes from source: " <<endl;
    for(int i = 0; i < nodes; i++)
    	cout << "Node " << i << ": " << dist[i] << endl;
    cout << "shortest path from " << source << " to " << destination << endl;
    printPath(source, destination, parent);
	return 0;
}

//Sample I/O
/*
6 7
0 1 4
0 2 3
1 3 3
1 2 1
2 3 4
3 4 2
4 5 6
0 5
*/
