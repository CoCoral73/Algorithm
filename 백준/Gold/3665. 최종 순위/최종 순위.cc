//
//  main.cpp
//  CppPractice
//
//  Created by 김정원 on 3/13/26.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <functional>
#define pii pair<int, int>
#define int long long

using namespace std;

const int INF = 2e9;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n;
        vector<int> v(n+1);
        bool ranking[501][501];
        fill(&ranking[0][0], &ranking[0][0] + 501 * 501, false);
        
        vector<int> indegree(n+1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            for (int j = 1; j < i; j++) {
                ranking[v[j]][v[i]] = true;
                indegree[v[i]]++;
            }
        }
        
        cin >> m;
        while (m--) {
            int a, b;
            cin >> a >> b;
            
            if (ranking[a][b]) {
                ranking[a][b] = false;
                ranking[b][a] = true;
                indegree[a]++;
                indegree[b]--;
            } else {
                ranking[a][b] = true;
                ranking[b][a] = false;
                indegree[a]--;
                indegree[b]++;
            }
        }
        
        queue<int> q;
        vector<int> answer;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        bool flag = true;
        while (!q.empty()) {
            if (q.size() >= 2) {
                cout << "?\n";
                flag = false;
                break;
            }
            
            int x = q.front();
            answer.push_back(x);
            q.pop();
            
            for (int i = 1; i <= n; i++) {
                if (ranking[x][i]) {
                    indegree[i]--;
                    if (indegree[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        
        if (flag) {
            if (answer.size() != n) {
                cout << "IMPOSSIBLE\n";
            } else {
                for (int a : answer) {
                    cout << a << ' ';
                }
                cout << '\n';
            }
        }
        
    }
}
