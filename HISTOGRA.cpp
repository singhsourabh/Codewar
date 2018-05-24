#include <bits/stdc++.h>

using namespace std;

long long largestRectangle(vector <long long> h) {
    long long area = 0, maxArea = 0, i = 0, tp;
    stack<long long> st;
    while(i<h.size()){
        if(st.empty() || h.at(i) >= h.at(st.top())){
            st.push(i++);
        }
        else{
            tp = st.top();
            st.pop();
            area = h.at(tp)*((st.empty()) ? i: i-1-st.top());
            if(maxArea<area) maxArea = area;
        }
    }
    while(!st.empty()){
        tp = st.top();
            st.pop();
            area = h.at(tp)*((st.empty()) ? i: i-1-st.top());
            if(maxArea<area) maxArea = area;
    }
    return maxArea;
}

int main() {
	while(true){
		long long n;
		vector<long long> h(n);
    	cin >> n;
    	if(n==0) break;
    	for(int h_i = 0; h_i<n; h_i++){
       		cin >> h[h_i];
    	}
    	long long result = largestRectangle(h);
    	cout << result << endl;
	}
    return 0;
}
