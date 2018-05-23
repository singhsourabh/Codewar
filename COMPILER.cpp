#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--){
		string str;
		int count = 0, final = 0;
		stack<char> st;
		cin >> str;
		for(char x: str){
			if(x == '<'){
				st.push('<');
			}
			else if(x == '>' && !st.empty() && st.top() == '<'){
				count+=2;
				st.pop();
			}
			else{
				if(x=='>' && st.empty()){
					break;
				}
			}
			if(st.empty()){
				final+=count;
				count = 0;
			}
		}
		cout << final << endl;
	}
}
