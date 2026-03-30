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
#define pii pair<int, int>

using namespace std;

const int INF = 2e9;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int N, M, P;
int S[10], castle[10];
vector<string> grid;
vector<queue<pair<pii, int>>> Q(10);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> P;
    for (int i = 1; i <= P; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        grid.push_back(str);
        for (int j = 0; j < M; j++) {
            if (str[j] >= '1' && str[j] <= '9') {
                int p = str[j] - '0';
                castle[p]++;
                Q[p].push({{i, j}, 0});
            }
        }
    }
    
    int player = 0;
    bool flag = false;
    while (true) {
        player = player % P + 1;
        if (player == 1) flag = false;
        
        queue<pair<pii, int>> tmp;
        while (!Q[player].empty()) {
            int y = Q[player].front().first.first;
            int x = Q[player].front().first.second;
            int s = Q[player].front().second;
            Q[player].pop();
            
            if (s == S[player]) {
                tmp.push({{y, x}, 0});
            }
            
            for (int i = 0; i < 4; i++) {
                int r = y + dr[i];
                int c = x + dc[i];
                
                if (r < 0 || r >= N || c < 0 || c >= M) continue;
                if (grid[r][c] != '.') continue;
                if (s + 1 > S[player]) continue;
                grid[r][c] = grid[y][x];
                castle[player]++;
                flag = true;
                Q[player].push({{r, c}, s + 1});
            }
        }
        
        Q[player] = tmp;
        
        if (player == P && !flag) break;
    }
    
    for (int i = 1; i <= P; i++) {
        cout << castle[i] << ' ';
    }
}
