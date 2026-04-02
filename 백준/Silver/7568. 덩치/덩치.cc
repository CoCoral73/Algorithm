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

int N;
vector<pii> v;
int answer[50];

bool compare(pii x, pii y) {
    if (x.first < y.first && x.second < y.second) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    
    for (int i = 0; i < N; i++) {
        answer[i]++;
        for (int j = i + 1; j < N; j++) {
            if (compare(v[i], v[j])) {
                answer[i]++;
            }
            if (compare(v[j], v[i])) {
                answer[j]++;
            }
        }
        cout << answer[i] << ' ';
    }
}
