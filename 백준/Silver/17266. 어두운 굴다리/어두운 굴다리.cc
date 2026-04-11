#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> location(M);
    for (int &x : location) {
        cin >> x;
    }
    
    int answer = 0;
    if (location.front() != 0) {
        answer = max(answer, location.front());
    }
    if (location.back() != N) {
        answer = max(answer, N - location.back());
    }
    
    for (int i = 0; i < M - 1; i++) {
        int x = (double)(location[i + 1] - location[i]) / 2 + 0.5;
        answer = max(answer, x);
    }
    
    cout << answer;
    
    return 0;
}