#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
      
        vector<int> T(N);
        map<int, int> teamCount;
        map<int, vector<int>> teamScore;
        set<int> candidates;
        
        for (int i = 0; i < N; i++) {
            cin >> T[i];
            teamCount[T[i]]++;
        }
        
        int score = 1;
        for (int t : T) {
            if (teamCount[t] < 6) continue;
            candidates.insert(t);
            teamScore[t].push_back(score);
            score++;
        }
        
        int win = -1;
        for (int x : candidates) {
            score = 0;
            for (int i = 0; i < 4; i++) {
                score += teamScore[x][i];
            }
            teamScore[x].push_back(score);
            
            if (win == -1 || teamScore[win][6] > score || (teamScore[win][6] == score && teamScore[win][4] > teamScore[x][4])) {
                win = x;
            }
        }
        cout << win << '\n';
    }
    return 0;
}