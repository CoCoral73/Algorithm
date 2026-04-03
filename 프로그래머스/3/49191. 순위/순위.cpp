#include <iostream>
#include <string>
#include <vector>

const int INF = 2e9;

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool dist[101][101];
    
    fill(&dist[0][0], &dist[0][0] + 101 * 101, false);
    
    for (auto result : results) {
        int A = result[0], B = result[1];
        dist[A][B] = true;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] && dist[k][j]) {
                    dist[i][j] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] || dist[j][i])
                count++;
        }
        if (count == n-1)
            answer++;
    }
    
    return answer;
}