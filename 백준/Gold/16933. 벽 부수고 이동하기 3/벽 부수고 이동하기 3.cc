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

int N, M, K;
int answer = INF;
vector<string> matrix;
int isVisited[11][1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fill(&isVisited[0][0][0], &isVisited[0][0][0] + 11 * 1000 * 1000, INF);
    
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        matrix.push_back(str);
    }
    
    queue<pair<int, pii>> q;
    q.push({0, {0, 0}});
    isVisited[0][0][0] = 1;
    //홀수: 낮, 짝수: 밤
    
    while (!q.empty()) {
        int isBroken = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();
        
        if (y == N-1 && x == M-1) {
            answer = min(answer, isVisited[isBroken][y][x]);
            continue;
        }
        
        for (int i = 0; i < 4; i++) {
            int r = y + dr[i];
            int c = x + dc[i];
            
            if (r < 0 || r >= N || c < 0 || c >= M) continue;
            if (matrix[r][c] == '0' && isVisited[isBroken][r][c] > isVisited[isBroken][y][x] + 1) {
                isVisited[isBroken][r][c] = isVisited[isBroken][y][x] + 1;
                q.push({isBroken, {r, c}});
            } else if (matrix[r][c] == '1' && isBroken + 1 <= K) {
                if (isVisited[isBroken][y][x] % 2 == 0) {
                    if (isVisited[isBroken + 1][r][c] > isVisited[isBroken][y][x] + 2) {
                        isVisited[isBroken + 1][r][c] = isVisited[isBroken][y][x] + 2;
                        q.push({isBroken + 1, {r, c}});
                    }
                    
                } else {
                    if (isVisited[isBroken + 1][r][c] > isVisited[isBroken][y][x] + 1) {
                        isVisited[isBroken + 1][r][c] = isVisited[isBroken][y][x] + 1;
                        q.push({isBroken + 1, {r, c}});
                    }
                }
                
            }
        }
    }
    
    cout << (answer == INF ? -1 : answer);
}
