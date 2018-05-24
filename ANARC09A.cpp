#include<bits/stdc++.h>
using namespace std;
int main(){
	while(true){
		int count = 1;
		string str;
		cin >> str;
		while(str[0] != '-'){
			int a = 0, b = 0;
			stack<char> S;
			for(int i = 0; i<str.length(); i++){
				if(str[i] == '{') S.push('{');
				
					else{
						if(!S.empty()){
							S.pop();
						}
						else{
							a++;
						}
					}
			}
			while(!S.empty()){
				b++;
				S.pop();
			}
			cout << count << ". " << a+b/2 << endl;
			count++;
			cin >> str;
		}
	}
}
