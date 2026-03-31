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

int N, M;
map<pii, vector<pii>> light;
bool grid[100][100];
bool isVisited[100][100];
int answer = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    int x, y, a, b;
    while (M--) {
        cin >> x >> y >> a >> b;
        light[{x-1, y-1}].push_back({a-1, b-1});
    }
    
    queue<pii> q;
    q.push({0, 0});
    grid[0][0] = true;
    isVisited[0][0] = true;
    
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        for (auto rc : light[{y, x}]) {
            tie(a, b) = rc;
            if (!grid[a][b]) {
                grid[a][b] = true;
                answer++;
            }
            
            for (int i = 0; i < 4; i++) {
                int r = a + dr[i];
                int c = b + dc[i];
                
                if (r < 0 || r >= N || c < 0 || c >= N) continue;
                if (!isVisited[r][c] || isVisited[a][b]) continue;
                isVisited[a][b] = true;
                q.push({a, b});
            }
        }
        
        for (int i = 0; i < 4; i++) {
            int r = y + dr[i];
            int c = x + dc[i];
            
            if (r < 0 || r >= N || c < 0 || c >= N) continue;
            if (!grid[r][c] || isVisited[r][c]) continue;
            isVisited[r][c] = true;
            q.push({r, c});
        }
    }
    
    cout << answer;
}
