#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		string str, op = "+-*/^";
		cin >> str;
		stack<int> O;
		string res;
		for(int i = 0; i<str.length(); i++){
			if(isalpha(str[i])){
				res.push_back(str[i]);
			}
			else if(!isalpha(str[i]) && str[i] != ')'){
				O.push(str[i]);
			}
			else{
				res.push_back(O.top());
				O.pop();
				O.pop();
			}
		}
		cout << res << endl;
	}
}
