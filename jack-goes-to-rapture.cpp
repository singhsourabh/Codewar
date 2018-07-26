#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<pair<ll,ll>> Adj[50100];

ll Dijkstra(ll N){
	vector<ll> cost(N+1, INT_MAX);
	vector<ll> visited(N+1, 0);
	priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > P;
	P.push(make_pair(0, 1));
	cost[1] = 0;
	while(!P.empty()){
		pair<ll,ll> Top = P.top();
		P.pop();
		visited[Top.second] = 1;
		for(ll i = 0; i<Adj[Top.second].size(); i++){
			if(!visited[Adj[Top.second][i].second]){
				ll newCost = Adj[Top.second][i].first - cost[Top.second];
				if(newCost<0) newCost = 0;
				if(cost[Adj[Top.second][i].second] > newCost + cost[Top.second]){
					cost[Adj[Top.second][i].second] = newCost + cost[Top.second];
					P.push(make_pair(cost[Adj[Top.second][i].second], Adj[Top.second][i].second));
				}
			}
		}
	}
	return cost[N];
}

int main(){
	ll N, E, x, y, c;
	cin >> N >> E;
	for(ll i = 0; i<E; i++){
		cin >> x >> y >> c;
		Adj[x].push_back(make_pair(c,y));
		Adj[y].push_back(make_pair(c,x));
	}
	ll cost = Dijkstra(N);
	if(cost == INT_MAX){
		cout << "NO PATH EXISTS\n";
	}
	else{
		cout << cost << endl;
	}
}
