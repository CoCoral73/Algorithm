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
#define int long long
#define pii pair<int, int>


using namespace std;

const int INF = 1e9;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    int dist[501][501];
    fill(&dist[0][0], &dist[0][0] + 501 * 501, INF);
    
    for (int i = 1; i <= N; i++) dist[i][i] = 0;
    
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }
    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (dist[i][i] < 0 && dist[1][i] != INF) {
            cout << -1;
            return 0;
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << (dist[1][i] == INF ? -1 : dist[1][i]) << '\n';
    }
}

