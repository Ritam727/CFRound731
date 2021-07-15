#include <bits/stdc++.h>
#define inf 100000000000000000
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(k);
        vector<long long> temp(k), ans(n, inf), dp1(n, inf), dp2(n, inf);
        for(int& i : a) cin >> i;
        for(long long& i : temp) cin >> i;
        for(int i = 0; i < k; i++){
            ans[a[i]-1] = temp[i];
        }
        long long m1 = inf, m2 = inf, k1 = 0, k2 = 0;
        for(int i = 0; i < n; i++){
            dp1[i] = min(ans[i], m1+k1);
            if(m1+k1 > ans[i]){
                k1 = 1;
                m1 = ans[i];
            } else{
                k1++;
            }
        }
        for(int i = n-1; i >= 0; i--){
            dp2[i] = min(ans[i], m2+k2);
            if(m2+k2 > ans[i]){
                k2 = 1;
                m2 = ans[i];
            } else{
                k2++;
            }
        }
        for(int i = 0; i < n; i++){
            ans[i] = min(dp1[i], dp2[i]);
        }
        for(long long i : ans){
            cout << i << " ";
        }
        cout << "\n";
    }
}