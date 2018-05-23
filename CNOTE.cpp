#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while(T--){
		int X, Y, K, N, cond = 1;
		cin >> X >> Y >> K >> N;
		X = X - Y;
		if(X>0){
			int P, C;
			while(N--){
				cin >> P >> C;
				if(P>=X && C<=K){
					cond = 0;
				}
			}
			if(cond) cout << "UnluckyChef\n";
			else cout << "LuckyChef\n";
		}
		else{
			cout << "LuckeyChef\n";
		}
	}
	return 0;
}