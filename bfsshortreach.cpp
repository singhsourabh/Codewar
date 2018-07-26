#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> Adj[1010];
ll dist[1010];
void initialize(ll N){
	for(ll i = 0; i<=N; i++){
		dist[i] = INT_MAX;
	}
}
void bfs(ll start, ll N){
	vector<ll> visited (N+1, 0);
	queue<ll> Q;
	Q.push(start);
	dist[start] = 0;
	while(!Q.empty()){
		ll Ft = Q.front();
		Q.pop();
		visited[Ft] = 1;
		for(ll i = 0; i<Adj[Ft].size(); i++){
			if(!visited[Adj[Ft][i]]){
//				cout << dist[Adj[Ft][i]];
				if(dist[Adj[Ft][i]] > dist[Ft] + 6){
					dist[Adj[Ft][i]] = dist[Ft] + 6;
//					cout << dist[Adj[Ft][i]];
				}
				visited[Adj[Ft][i]] = 1;
				Q.push(Adj[Ft][i]);
			}
		}
	}
}

int main(){
	ll T, N, E, x, y, S;
	cin >> T;
	while(T--){
		cin >> N >> E;
		for(ll i = 0; i<E; i++){
			cin >> x >> y;
			Adj[x].push_back(y);
			Adj[y].push_back(x);
		}
		cin >> S;
		initialize(N);
		bfs(S, N);
		for(ll i = 1; i<=N; i++){
			if(dist[i] == 0){
			}
			else if(dist[i] == INT_MAX){
				cout << "-1 ";
			}
			else{
				cout << dist[i] << " ";
			}
		}
		cout << endl;
		for(ll i = 1; i<N+1; i++){
			Adj[i].clear();
		}
	}
}

