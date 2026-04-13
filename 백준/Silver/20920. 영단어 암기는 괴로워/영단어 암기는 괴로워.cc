#include <bits/stdc++.h>

using namespace std;

map<string, int> cnt;

bool compare(const string &str1, const string &str2) {
    if (cnt[str1] != cnt[str2]) {
        return cnt[str1] > cnt[str2];
    }
    if (str1.size() != str2.size()) {
        return str1.size() > str2.size();
    }
    return str1 < str2;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<string> v;
    while (N--) {
        string str;
        cin >> str;
        
        if (str.size() < M) continue;
        cnt[str]++;
        if (cnt[str] == 1) {
            v.push_back(str);
        }
    }
    
    sort(v.begin(), v.end(), compare);
    
    for (string str : v)
        cout << str << '\n';
}