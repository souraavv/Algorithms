//https://codeforces.com/contest/1187/problem/E

#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define piii pair<ll, pii>
#define MOD 1000000007
#define M 200005
using namespace std;

ll ans1[M], ans2[M], ans,n;
void dfs1(ll u,ll vis[],ll ch[], vector<ll> vec[]){
    vis[u] =1;
    for(ll i=0;i<vec[u].size();i++){
        ll v = vec[u][i];
        if(!vis[v]) {
            dfs1(v,vis,ch, vec);
            ans1[u]+= ans1[v];
            ch[u] += ch[v];
        }
    }
    ch[u]++;
    //cout <<res+ch[u] << " ";
    ans1[u] +=ch[u];
}

void dfs2(ll u, ll p, ll ch[], vector<ll>vec[]){
    if(p==0) ans2[u] = ans1[u];
    else ans2[u] = ans2[p] - ch[u] - ans1[u]+n;
    for(ll i =0;i<vec[u].size();i++){
        ll v = vec[u][i];
        if(v!=p && p!=0){
            ans2[u] += ans1[v];
        }
    }
    ans = max(ans, ans2[u]);
    for(ll i =0;i<vec[u].size();i++){
        ll v = vec[u][i];
        if(v!=p ){
            dfs2(v, u, ch, vec);
        }
    }
}

int main(){
    //ll t; cin>> t; while(t--){

        cin>> n;
        vector<ll>vec[n+1];
        for(ll i =0;i<n-1;i++) {
            ll x, y;
            cin>> x>>y;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }

        ll vis[n+1], ch[n+1];
        memset(vis, 0, sizeof(vis));
        memset(ch, 0, sizeof(ch));
        dfs1(1, vis, ch, vec);
        dfs2(1, 0, ch,vec);
        //for(ll i =1;i<=n;i++) cout << ans2[i]<< " ";
       cout << ans<< endl;
}
