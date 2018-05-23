#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
	int N, e = -1;
	bool flag = true;
	cin >> N;
	vector<int> V;
	stack<int> S;
	while(true){
		cin >> e;
		if(e == 0){
			break;
		}
		V.push_back(e);
	}
	int rq = 1;
	for(int i = 0; i<V.size(); i++){
		while(!S.empty() && S.top() == rq){
			rq++;
			S.pop();
		}
		if(V[i] == rq){
			rq++;
		}
		else if(!S.empty() && S.top() < V[i]){
			flag = false;
			break;
		}
		else{
			S.push(V[i]);
		}
	}
	if(flag) cout << "yes\n";
	else cout << "no\n";
}
