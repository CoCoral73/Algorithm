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

int t, h, w;
bool key[26];
vector<string> grid;
vector<vector<pii>> doors(26);
bool isVisited[100][100];
int answer;

void bfs(int y, int x);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    
    string str;
    while (t--) {
        fill(key, key + 26, false);
        grid = vector<string>();
        doors.assign(26, vector<pii>());
        fill(&isVisited[0][0], &isVisited[0][0] + 100 * 100, false);
        answer = 0;
        
        cin >> h >> w;
        for (int i = 0; i < h; i++) {
            cin >> str;
            grid.push_back(str);
            for (int j = 0; j < w; j++) {
                if (str[j] >= 'A' && str[j] <= 'Z') {
                    doors[str[j] - 'A'].push_back({i, j});
                }
            }
        }
        cin >> str;
        for (char c : str) {
            if (c == '0') break;
            key[c - 'a'] = true;
        }
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                    if (grid[i][j] == '*') continue;
                    bfs(i, j);
                }
            }
        }
        
//        for (int i = 0; i < h; i++) {
//            for (int j = 0; j < w; j++) {
//                cout << isVisited[i][j] << ' ';
//            }
//            cout << endl;
//        }
        
        cout << answer << '\n';
    }
}

void bfs(int y, int x) {
    if (grid[y][x] >= 'A' && grid[y][x] <= 'Z' && !key[grid[y][x] - 'A']) return;
    if (isVisited[y][x]) return;
    
    queue<pii> q;
    q.push({y, x});
    isVisited[y][x] = true;
    
    while (!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        
        char c = grid[y][x];
        if (c == '$') {
            answer++;
        } else if (c >= 'a' && c <= 'z') {
            key[c - 'a'] = true;
            for (auto v : doors[c - 'a']) {
                int a = v.first, b = v.second;
                for (int i = 0; i < 4; i++) {
                    int r = a + dr[i];
                    int c = b + dc[i];
                    
                    if (r < 0 || r >= h || c < 0 || c >= w) {
                        isVisited[a][b] = true;
                        q.push({a, b});
                        continue;
                    }
                    
                    if (isVisited[a][b] || !isVisited[r][c]) continue;
                    isVisited[a][b] = true;
                    q.push({a, b});
                }
            }
        }
        
        for (int i = 0; i < 4; i++) {
            int r = y + dr[i];
            int c = x + dc[i];
            
            if (r < 0 || r >= h || c < 0 || c >= w) continue;
            if (grid[r][c] == '*' || isVisited[r][c]) continue;
            if (grid[r][c] >= 'A' && grid[r][c] <= 'Z' && !key[grid[r][c] - 'A']) continue;
            isVisited[r][c] = true;
            q.push({r, c});
        }
    }
}
