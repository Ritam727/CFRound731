#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int al[26] = {0};
    for(int i = 0; i < s.length(); i++){
        al[(int)s[i]-97]++;
        if(al[(int)s[i]-97] > 1 || (int)s[i]-96 > s.length()){
            cout << "NO\n";
            return;
        }
    }
    int i = 0, j = s.length()-1, k = s.length()-1;
    while(k > 0){
        if(s[i] == (char)(k+97)){
            i++;
        } else if(s[j] == (char)(k+97)){
            j--;
        } else{
            cout << "NO\n";
            return;
        }
        k--;
    }
    cout << "YES\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}