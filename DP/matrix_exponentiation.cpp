//https://www.codechef.com/COOK50/problems/WW2

#include<bits/stdc++.h>
#define maxn 200005
#define inf 1e18L + 5
#define ll long long
#define MOD 1000000007
#define M 31
#define mat vector<vector<ll>>
using namespace std;

ll n, m;


mat mul(mat  even, mat odd){
    mat t(m, vector<ll>(m));
    for(ll i = 0; i < m; i++){
        for(ll j = 0; j < m; j++){
            for(ll k = 0; k < m; k++){
                t[i][j] += (even[i][k] * odd[k][j])%MOD;
                t[i][j] %= MOD;
            }

        }
    }
    return t;
}

mat powM(mat I, mat t, ll p){
    if(p==0) return I;
    if(p==1) return t;
    mat r = powM(I, t, p/2);
    mat res = mul(r, r);
    if(p%2==0){
        return res;
    }
    else {
        return mul(res, t);
    }
}

int main(){
    ll t; cin >> t; while(t--){
        cin >> n >> m;
        // identity matrix
        mat I(m, vector<ll>(m)), odd(m, vector<ll>(m)), even(m, vector<ll>(m));
        for(ll i = 0; i < m; i++){
            I[i][i] = 1;
            odd[i][i] = 1;
            if(i+1 <= m-1)odd[i][i+1] = even[i][i+1] = 1;
            if(i-1 >= 0)odd[i][i-1] = even[i][i-1] = 1;
        }
        mat t = mul(even, odd); // t = odd*even
        /*for(ll i = 0; i < m; i++){
            for(ll j = 0; j < m; j++){
                cout <<t[i][j] << " ";
            }cout << endl;
        }*/
        n--;
        mat ans = powM(I, t, n/2);
        if(n%2==1) ans = mul(ans, even);
        ll res = 0;
        for(ll i = 0; i < m; i++){
            for(ll j = 0; j < m; j++){
                res += ans[i][j];
                res %= MOD;
            }
        }
        cout << res << endl;
    }
}
