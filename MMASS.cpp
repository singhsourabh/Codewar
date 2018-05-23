#include<bits/stdc++.h>
using namespace std;
int mass(char ch){
	return (ch == 'H')? 1 :(ch == 'C')? 12 :16;
}
int main(){
	string str;
	int s;
	cin >> str;
	stack<int> S;
	for(char x: str){
		s = 0;
		if(x == '('){
			S.push(-1);
		}
		else if(isalpha(x)){
			S.push(mass(x));
		}
		else if(x == ')'){
			while(S.top() != -1){
				s+=S.top();
				S.pop();
			}
			S.pop();
			S.push(s);
		}
		else if(isdigit(x)){
			s = S.top()*(x-'0');
			S.pop();
			S.push(s);
		}
	}
	s = 0;
	while(!S.empty()){
		s+=S.top();
		S.pop();
	}
	cout << s << endl;
}
