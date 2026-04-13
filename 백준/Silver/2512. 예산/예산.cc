#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> v(N);
    long long sum = 0;
    for (int &x : v) {
        cin >> x;
        sum += x;
    }
    
    long long M;
    cin >> M;
    
    if (sum <= M) {
        cout << *max_element(v.begin(), v.end());
        return 0;
    }
    
    long long left = 1, right = *max_element(v.begin(), v.end());
    long long answer = 0;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        
        sum = 0;
        for (int i = 0; i < N; i++) {
            sum += (v[i] > mid ? mid : v[i]);
        }
        
        if (sum <= M) {
            answer = max(answer, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << answer;
}