#include <iostream>
using namespace std;
int main(){
	int T, N, inp, cond;
	long int C;
	cin >> T;
	while(T--){
		cond = 1;
		cin >> N >> C;
		while(N--){
			cin >> inp;
			C -= inp;
			if((C == 0 || C >= 0) && N == 0){
				cout << "Yes\n";
				cond = 0;
			}
		}
		if(cond){
			cout << "No\n";
		}
	}
}