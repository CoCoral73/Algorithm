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

int N, M;
int indegree[32001];
vector<vector<int>> graph(32001);

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        indegree[b]++;
        graph[a].push_back(b);
    }
    
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        cout << x << ' ';
        
        for (int y : graph[x]) {
            indegree[y]--;
            if (indegree[y] == 0) {
                q.push(y);
            }
        }
    }
}
