#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const string bs = "0000000000000000000000000000000";

string bin(ll n){
    string s = bs; int k = bs.length()-1;
    while(n > 0){
        s[k] = (n%2) ? '1' : '0';
        n /= 2;
        k--;
    }
    return s;
}

ll power(int n, int k){
    if(k == 0){
        return 1;
    } else{
        if(k%2 == 0){
            return power(n, k/2)*power(n, k/2);
        } else{
            return n*power(n, (k-1)/2)*power(n, (k-1)/2);
        }
    }
}

ll to_int(string s){
    int k = 0; ll num = 0;
    for(int i = bs.length()-1; i >= 0; i--){
        num = (s[i] == '1') ? num+power(2, k) : num+0;
        k++;
    }
    return num;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            ll x; cin >> x;
            a[i] = x;
        }
        vector<ll> seq(n, 0);
        for(int i = 1; i < n; i++){
            string s = bs, t = bin(a[i-1]), temp = bin(a[i]);
            for(int j = 0; j < 31; j++){
                if(temp[j] != t[j] && temp[j] == '0'){
                    s[j] = '1';
                }
            }
            seq[i] = to_int(s);
            a[i] = (a[i]^seq[i]);
        }
        for(int i = 0; i < n; i++){
            cout << seq[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}