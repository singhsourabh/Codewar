#include<bits/stdc++.h>
#define ll long long int
#define o5 100100
using namespace std;
ll Dis[o5];

void initialize(ll N){
	for(ll i = 0; i <= N; i++){
		Dis[i] = i;
	}
}

ll root(ll x){
	while(x != Dis[x]){
		x = Dis[Dis[x]];
	}
	return x;
}

void Union(ll x, ll y){
	ll a = root(x);
	ll b = root(y);
	Dis[a] = Dis[b];
}

int main(){
	ll T, n, m, lib, road, x, y;
	cin >> T;
	while(T--){
		cin >> n >> m >> lib >> road;
		initialize(n);
		vector<ll> Count(n+1, 0);
		for(ll i = 0; i<m; i++){
			cin >> x >> y;
			Union(x,y);
		}
		
		for(ll i = 1; i<=n; i++){
			Count[root(i)]++;
		}
		ll cost = 0;
		for(ll i = 1; i<=n; i++){
			if(Count[i] != 0){
				cost += lib + (Count[i]-1)*min(road, lib);
			}
		}
		cout << cost << endl;
	}
}
