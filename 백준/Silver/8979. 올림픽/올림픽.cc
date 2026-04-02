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

int N, K;
pair<int, pii> v[1001];

bool compare(pair<int, pii> x, pair<int, pii> y) {
    if (x.first != y.first) {
        return x.first > y.first;
    } else if (x.second.first != y.second.first) {
        return x.second.first > y.second.first;
    } else {
        return x.second.second > y.second.second;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int n, gold, silver, bronze;
        cin >> n >> gold >> silver >> bronze;
        v[n] = {gold, {silver, bronze}};
    }
    
    pair<int, pii> k = v[K];
    
    sort(&v[1], &v[1] + N, compare);
    for (int i = 1; i <= N; i++) {
        if (k == v[i]) {
            cout << i;
            return 0;
        }
    }
}