#include<bits/stdc++.h>
using namespace std;
int board[101][6];

void initialize(){
	for(int i = 1; i<101; i++){
		for(int j = 0; j<6; j++){
			if(i+j+1 < 101)
			board[i][j] = i+j+1;
			else
			board[i][j] = -1;
		}
	}
}

int bfs(){
	int start = 1, count = 0, temp, run;
	queue<int> Q;
	vector<int> visited(101, 0);
	vector<int> dist(101, 100000);
	Q.push(start);
	visited[start] = 1;
	dist[1] = 0;
	while(!Q.empty()){
		int temp = Q.front();
		Q.pop();
		for(int i = 0; i<6; i++){
			if(board[temp][i] != -1 and !visited[board[temp][i]]){
				if(dist[board[temp][i]] > dist[temp] + 1){
					dist[board[temp][i]] = dist[temp] + 1;
				}
				visited[board[temp][i]] = 1;
				Q.push(board[temp][i]);
			}
		}
	}
	return dist[100];
}

int main(){
	int T, L, S;
	cin >> T;
	while(T--){
		cin >> L;
		vector<pair<int, int>> ladder(L);
		for(int i = 0; i<L; i++){
			cin >> ladder[i].first >> ladder[i].second;
		}
		cin >> S;
		vector<pair<int, int>> snake(S);
		for(int i = 0; i<S; i++){
			cin >> snake[i].first >> snake[i].second;
		}
		initialize();
		//ladder
		for(int i = 0; i<L; i++){
			int source = ladder[i].first;
			memset(board[source], -1, sizeof(int)*6);
			for(int j = 1; j<7 and source-j>0; j++){
				board[source-j][j-1] = ladder[i].second;
			}
		}
		//snake
		for(int i = 0; i<S; i++){
			int source = snake[i].first;
			memset(board[source], -1, sizeof(int)*6);
			for(int j = 1; j<7 and source-j>0; j++){
				board[source-j][j-1] = snake[i].second;
			}
		}
		int ans = bfs();
		if(ans != 100000)
		cout << ans << endl;
		else
		cout << "-1\n";
	}
}

/*
3
2
3 54
37 100
1
56 33
2
3 57
8 100
1
88 44
1
7 98
1
99 1
*/
