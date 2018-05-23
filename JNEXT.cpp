#include<bits/stdc++.h>
using namespace std;
int main(){
	int T, N;
	cin >> T;
	while(T--){
		int i = 0;
		cin >> N;
		int V[N];
		while(i<N){
			cin >> V[i];
			i++;
		}
		if(next_permutation(V, V+N)){
			for(int x: V){
				cout << x;
			}
		}
		else{
			cout << "-1";
		}
		cout << endl;
	}
}
