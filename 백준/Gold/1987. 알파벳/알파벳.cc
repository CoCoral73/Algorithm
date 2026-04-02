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

using namespace std;

const int INF = 2e9;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int R, C;
vector<string> grid;
bool isVisited[26];
int answer = 0;

void dfs(int depth, int r, int c) {
    answer = max(answer, depth);
    
    for (int i = 0; i < 4; i++) {
        int y = r + dr[i];
        int x = c + dc[i];
        
        if (y < 0 || y >= R || x < 0 || x >= C) continue;
        
        int index = grid[y][x] - 'A';
        if (isVisited[index]) continue;
        isVisited[index] = true;
        dfs(depth + 1, y, x);
        isVisited[index] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        grid.push_back(str);
    }
    
    int index = grid[0][0] - 'A';
    isVisited[index] = true;
    dfs(1, 0, 0);
    
    cout << answer;
}
