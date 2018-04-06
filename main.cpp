#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> intInt;
vector <pair<int, pair<int, int> > > MST;
vector<intInt> graph[100];

int primsMST(int);

int main() {
	int nodes, edges;
	int source, destination, c;
	cin >> nodes >> edges;
	for(int i = 0; i < edges; i++){
		cin >> source >> destination >> c;
		graph[source].push_back(make_pair(c, destination));
        graph[destination].push_back(make_pair(c, source));
		cout << "\n";
	}
	
	int minimumCost = primsMST(1);
	cout << "Minimum cost of the tree = " << minimumCost << endl;
	system("pause");
	return 0;
}

int primsMST(int node){
	int minimumCost = 0;
	int src = 0;
	int des = 0; 
	int cst = 0;
	bool visited[100];
	
	priority_queue <intInt, vector<intInt>, greater<intInt> > q;
	
	memset(visited, 0, sizeof visited);
	
	q.push(make_pair(0, node));
	
	while(!q.empty()){
		cst = q.top().first;
		src = q.top().second;
		q.pop();
		
		if(visited[src] == true)
			continue;
		minimumCost += cst;
		
		visited[src] = true;
		
		for(int i = 0;i < graph[src].size();++i)
        {
            des = graph[src][i].second;
            if(visited[des] == false)
                q.push(graph[src][i]);
        }
        MST.push_back(make_pair(cst, make_pair(src, des)));
	}
	return minimumCost;
}

