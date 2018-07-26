#include<bits/stdc++.h>
#define o5 100010
#define ll long long int
using namespace std;
ll Dis[o5];
ll Count[o5];

void initialize(ll L){
	for(ll i = 0; i<L; i++){
		Dis[i] = i;
		Count[i] = 0;
	}
}

ll root(ll x){
	while(x != Dis[x]){
		x = Dis[Dis[x]];
	}
	return x;
}

void Union(ll x, ll y){
	ll A = root(x);
	ll B = root(y);
	Dis[B] = A;
}

int main(){
	ll T, P, A, B;
	cin >> T >> P;
	initialize(T);
	for(ll i = 0; i<P; i++){
		cin >> A >> B;
		Union(A, B);
	}
//	for(ll i = 0; i<T; i++) cout << Dis[i] << " ";
//	cout << endl;
	for(ll i = 0; i<T; i++){
		ll ind = root(Dis[i]);
		Count[ind]++;
	}
	ll sum = 0;
	ll nxt = 0;
	for(ll i = 0; i<T; i++){
		if(Count!=0){
			nxt += sum*Count[i];
			sum += Count[i];
		}
	}
	cout << nxt << endl;
}
