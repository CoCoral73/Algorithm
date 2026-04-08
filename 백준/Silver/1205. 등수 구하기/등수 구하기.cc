#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long long N, taesu, P;
    cin >> N >> taesu >> P;
    
    vector<long long> ranking;
    for (int i = 0; i < N; i++) {
        long long score;
        cin >> score;
        ranking.push_back(score);
    }
    
    sort(ranking.begin(), ranking.end(), greater<>());
    
    if (N == 0) {
        cout << 1;
        return 0;
    }
    
    if ((N == P && ranking[N-1] >= taesu)) {
        cout << -1;
        return 0;
    }
    
    int answer = 1;
    for (int r : ranking) {
        if (taesu >= r) break;
        answer++;
    }
    
    cout << answer;
}