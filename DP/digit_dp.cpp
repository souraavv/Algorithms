//https://www.spoj.com/problems/GONE/

#include <bits/stdc++.h>
#define ll int
#define maxn 101
using namespace std;

ll a, b, n;
ll dp[10][100][2], prime[100];
vector<ll> num;

/*
 dp[p][s][f]
    p = position
    s = sum upto p
    f = flag if the value is crossing the range or not
*/

void process(){
    for(ll i = 2; i < 100; i++){
        prime[i] = 1;
        for(ll j = 2; j <= sqrt(i); j++){
            if(i%j==0){
                prime[i] = 0;break;
            }
        }
    }
}

ll solve(ll pos, ll sum, ll f){
    if(n==pos){
        return (prime[sum]==1);
    }
    if(dp[pos][sum][f] != -1) return dp[pos][sum][f];
    ll res = 0, lmt;
    if(f==0){ // the pos can only be (0, s[pos])
        lmt = num[pos];
    }
    else { // the pos can be anything
        lmt = 9;
    }
    for(ll i = 0; i <= lmt; i++){
        ll newf = f; // newf is the flag value for next position
        if(f==0 && i<lmt) newf = 1; // if currently f =0 ie restricted and
                                 // current pos is less than the edge value
                                 //the next pos can be anything bw (0,9), hence newf is 1
        res += solve(pos+1, sum+i, newf);
    }
    return dp[pos][sum][f] = res;
}

ll s(ll x){
    num.clear();
    while(x>0){
        num.push_back(x%10); x/=10;
    }
    reverse(num.begin(), num.end());
    n = num.size();
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, 0);
}

int main(){
    process();
    ll t; cin >> t; while(t--){
        cin >> a >> b;
        a--;
        cout << s(b) - s(a) << endl;
    }
}
