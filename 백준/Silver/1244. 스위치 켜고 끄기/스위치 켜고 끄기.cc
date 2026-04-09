#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int S, N;
    cin >> S;
    
    bool switches[S + 1];
    for (int i = 1; i <= S; i++)
        cin >> switches[i];
        
    cin >> N;
    while (N--) {
        int sex, n;
        cin >> sex >> n;
        
        if (sex == 1) {
            for (int i = n; i <= S; i += n)
                switches[i] = !switches[i];
        } else {
            for (int i = 0; n - i >= 1 && n + i <= S; i++) {
                if (switches[n - i] != switches[n + i]) break;
                switches[n - i] = !switches[n - i];
                if (i > 0) {
                    switches[n + i] = !switches[n + i];
                }
            }
        }
    }
    
    for (int i = 1; i <= S; i++) {
        if (i > 20 && i % 20 == 1) 
            cout << '\n';
        cout << switches[i] << ' ';
    }
}