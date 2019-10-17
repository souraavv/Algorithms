// https://www.spoj.com/problems/LCA/

#include <bits/stdc++.h>
#define ll long long
#define maxn 1005
#define vec2d vector<vector<ll>>
using namespace std;

vector<ll> vec[maxn];
ll tim, tin[maxn], tout[maxn], len;
ll lca[maxn][51];
// lca[u][i] is the node that is the 2^i the ancestor of node u

void dfs(ll u, ll p){
    tin[u] = ++tim; // in time
    lca[u][0] = p; //  p is the 2^0 ie the 1st ancestor of node u
    for(ll i=0; i<len; i++){
        lca[u][i+1] = lca[lca[u][i]][i];
    }
    for(ll i=0; i<vec[u].size(); i++){
        ll v = vec[u][i];
        if(v!=p){
            dfs(v, u);
        }
    }
    tout[u] = ++tim; // out time

}

bool is_ancestor(ll ch, ll par){ // if v is ancestor of u ,ie u is in the subtree rooted at v
    if(tin[par]<tin[ch] && tout[ch]<tout[par]){
        return true;
    }
    else return false;
}

ll LCA(ll u, ll v){
    if(u == v) return u;
    if(is_ancestor(u, v)){//if v is ancestor of u
        return v;
    }
    else if(is_ancestor(v, u)){ //if u is ancestor of v
        return u;
    }
    for(ll i=len; i>=0; i--){
        if(!is_ancestor(v, lca[u][i])){
            u = lca[u][i];
        }
    }
    return lca[u][0];
}
int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);
    ll t; cin>>t;
    for(ll tc = 0;tc<t; tc++){
        ll n;
        cin >> n;
        // clear
        len = ceil(log2(n)); // log2(n)
        memset(lca, 0, sizeof(lca));
        for(ll i=0; i<=n; i++){
            vec[i].clear();
        }
        tim = 0;
        memset(tin, 0, sizeof(tin));
        memset(tout, 0, sizeof(tout));
        for(ll i=1; i<=n; i++){
            ll m;
            cin >> m;
            while(m--){
            ll x; cin >> x;
            vec[x].push_back(i);
            vec[i].push_back(x);
            }
        }
        dfs(1, 1);
        ll q;
        cin>>q;
        cout << "Case " << tc+1 << ":\n";
        while(q--){
            ll x, y;
            cin >> x >> y;
            cout << LCA(x, y) << endl;
        }
    }
}

