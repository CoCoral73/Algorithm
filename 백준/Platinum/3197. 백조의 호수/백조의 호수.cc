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

int R, C;
vector<string> grid;
queue<pii> water;
vector<pii> L;
pii parent[1500][1500];

void initParent();
void meltIce();
pii findParent(pii x);
void unionParent(pii x, pii y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        grid.push_back(str);
        for (int j = 0; j < C; j++) {
            if (str[j] == '.') {
                water.push({i, j});
            } else if (str[j] == 'L') {
                L.push_back({i, j});
                water.push({i, j});
            }
            parent[i][j] = {i, j};
        }
    }
    
    initParent();
    
    int t = 0;
    while (true) {
        pii parent1 = findParent(L[0]);
        pii parent2 = findParent(L[1]);
        
        if (parent1 == parent2) {
            cout << t;
            return 0;
        }
        
        meltIce();
        t++;
    }
    
}

void initParent() {
    bool isVisited[1500][1500];
    fill(&isVisited[0][0], &isVisited[0][0] + 1500 * 1500, 0);
    
    unsigned long size = water.size();
    for (int i = 0; i < size; i++) {
        pii front = water.front();
        water.pop();
        water.push(front);
        
        if (isVisited[front.first][front.second]) continue;
        
        queue<pii> q;
        q.push(front);
        isVisited[front.first][front.second] = true;
        
        int y, x;
        while (!q.empty()) {
            tie(y, x) = q.front();
            q.pop();
            
            unionParent({y, x}, front);
            
            for (int k = 0; k < 4; k++) {
                int r = y + dr[k];
                int c = x + dc[k];
                
                if (r < 0 || r >= R || c < 0 || c >= C) continue;
                if (grid[r][c] == 'X' || isVisited[r][c]) continue;
                isVisited[r][c] = true;
                q.push({r, c});
            }
        }
    }
}

void meltIce() {
    queue<pii> tmp;
    unsigned long size = water.size();
    
    for (int i = 0; i < size; i++) {
        int y, x;
        tie(y, x) = water.front();
        water.pop();
        
        for (int j = 0; j < 4; j++) {
            int r = y + dr[j];
            int c = x + dc[j];
            
            if (r < 0 || r >= R || c < 0 || c >= C) continue;
            if (grid[r][c] == 'X') {
                grid[r][c] = '.';
                unionParent({y, x}, {r, c});
                water.push({r, c});
                tmp.push({r, c});
            } else if (parent[y][x] != parent[r][c]) {
                unionParent({y, x}, {r, c});
            }
        }
    }
    
    while (!tmp.empty()) {
        int y, x;
        tie(y, x) = tmp.front();
        tmp.pop();
        
        for (int i = 0; i < 4; i++) {
            int r = y + dr[i];
            int c = x + dc[i];
            
            if (r < 0 || r >= R || c < 0 || c >= C) continue;
            if (grid[r][c] == 'X' || findParent({y, x}) == findParent({r, c})) continue;
            unionParent({y, x}, {r, c});
        }
    }
}

pii findParent(pii x) {
    pii p = parent[x.first][x.second];
    if (x == p)
        return x;
    parent[x.first][x.second] = findParent(p);
    return parent[x.first][x.second];
}

void unionParent(pii x, pii y) {
    pii p1 = findParent(x), p2 = findParent(y);
    
    if (p1 == p2) return;
    if (p1.first + p1.second < p2.first + p2.second) {
        parent[p2.first][p2.second] = p1;
    } else {
        parent[p1.first][p1.second] = p2;
    }
}
