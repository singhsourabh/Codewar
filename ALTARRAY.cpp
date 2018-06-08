#include < bits / stdc++.h >
  using namespace std;
void seriesprint(long int x) {
  while (x > 0) {
    cout << x << " ";
    x--;
  }
}
int main() {
  int T, N;
  cin >> T;
  while (T--) {
    cin >> N;
    vector < int > inp(N);
    vector < int > ans;
    for (int i = 0; i < N; i++) {
      float s;
      cin >> s;
      if (s > 0) inp[i] = 1;
      else inp[i] = -1;
    }
    long int sum = 0;
    int L = 1;
    for (int i = 0; i < N - 1; i++) {
      if (inp[i] * inp[i + 1] > 0 && L > 1) {
        ans.push_back(L);
        sum += L;
        L = 1;
      } else if (inp[i] * inp[i + 1] > 0 && L == 1) {
        ans.push_back(1);
        sum += 1;
      } else {
        L += 1;
      }
    }
    
    if (L != 1) {
      ans.push_back(L);
      sum += L;
    }
    if (sum < N) {
      ans.push_back(1);
    }

    for (int x: ans) {
      if (x == 1) {
        cout << "1 ";
      } else {
        seriesprint(x);
      }
    }
    cout << endl;
  }
}