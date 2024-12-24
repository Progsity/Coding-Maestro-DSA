//Author: Abu Jafar Md Jakaria

#include<bits/stdc++.h>
using namespace std;
//calculate the distance of each node from source node
void dijkstra(int source, int nodes, vector<vector<pair<int, int>>> &graph, vector<int> &dist)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	dist[source] = 0;
	pq.push({0, source}); // source to source is zero

	 while(!pq.empty())
	 {
	 	int current_dist = pq.top().first; // current distance
	 	int current_node = pq.top().second;
	 	pq.pop();
		if(current_dist > dist[current_node]) continue;

		for(auto &i: graph[current_node])
		{
			int v = i.first; //neighbor of current node
			int wt = i.second; //weight of neighbor

			if(dist[current_node] + wt < dist[v]){
				dist[v] = dist[current_node] + wt;
				pq.push({dist[v], v});
			}
		}	 	
	 }
}
void dijkstra_shortestPath(int source, int nodes, vector<vector<pair<int, int>>> &graph, vector<int> &dist, vector<int> &parent)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	dist[source] = 0;
	parent[source] = -1; //source has no parent
	pq.push({0, source}); // source to source is zero

	 while(!pq.empty())
	 {
	 	int current_dist = pq.top().first; // current distance
	 	int current_node = pq.top().second;
	 	pq.pop();
		if(current_dist > dist[current_node]) continue;

		for(auto &i: graph[current_node])
		{
			int v = i.first; //neighbor of current node
			int wt = i.second; //weight of neighbor

			if(dist[current_node] + wt < dist[v]){
				dist[v] = dist[current_node] + wt;
				parent[v] = current_node;
				pq.push({dist[v], v});
			}
		}	 	
	 }
}
void printPath(int source, int destination, vector<int> &parent)
{
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
    cin >> nodes >> edges;
    vector<vector<pair<int, int>>>graph(nodes);

	//adjacency list - undirected graph 
    for (int i = 0; i < edges; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); 
    }
    int source, destination; cin >> source >> destination;
    vector<int> dist(nodes, INT_MAX);
    vector<int> parent(nodes, -1); //initially each nodes parent are -1


    dijkstra_shortestPath(source, nodes, graph, dist, parent);

    cout << "Distance of each nodes from source: " <<endl;
    for(int i = 0; i < nodes; i++)
    	cout << "Node " << i << ": " << dist[i] << endl;
    cout << "shortest path from " << source << " to " << destination << endl;
    printPath(source, destination, parent);
	return 0;
}

/* Sample Input
5 5
0 1 5
1 2 1
1 3 2
2 4 1
4 3 -1
0 4
*/
