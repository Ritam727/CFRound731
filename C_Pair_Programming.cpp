#include <bits/stdc++.h>
using namespace std;

void solve(){
    int k, n, m; cin >> k >> n >> m;
    int a[n], b[m], ans[n+m];
    for(int& i : a) cin >> i;
    for(int& i : b) cin >> i;
    int i = 0, j = 0, ind = 0;
    while(ind < n+m){
        int temp = ind;
        if(i < n){
            if(a[i] == 0){
                ans[ind] = 0;
                i++; k++; ind++;
            } else{
                if(a[i] <= k){
                    ans[ind] = a[i];
                    i++; ind++;
                } else{
                    ans[ind] = -1;
                }
            }
        }
        if(j < m){
            if(b[j] == 0){
                ans[ind] = 0;
                j++; k++; ind++;
            } else{
                if(b[j] <= k){
                    ans[ind] = b[j];
                    j++; ind++;
                } else{
                    ans[ind] = -1;
                }
            }
        }
        if(temp == ind){
            cout << "-1\n";
            return;
        }
    }
    for(int i = 0; i < n+m; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}