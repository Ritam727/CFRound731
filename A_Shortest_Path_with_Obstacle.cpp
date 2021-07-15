#include <bits/stdc++.h>
typedef long long ll;
#define vll vector<ll>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int x[3], y[3];
        for(int i = 0; i < 3; i++){
            cin >> x[i] >> y[i];
        }
        int yabs = abs(y[0]-y[1]), xabs = abs(x[0]-x[1]);
        if(x[0] == x[1]){
            if(yabs == abs(y[0]-y[2])+abs(y[2]-y[1]) && x[0] == x[2]){
                cout << yabs+2 << "\n";
            } else{
                cout << yabs << "\n";
            }
        } else if(y[0] == y[1]){
            if(xabs == abs(x[0]-x[2])+abs(x[1]-x[2]) && y[0] == y[2]){
                cout << xabs+2 << "\n";
            } else{
                cout << xabs << "\n";
            }
        } else{
            cout << xabs+yabs << "\n";
        }
    }
    return 0;
}