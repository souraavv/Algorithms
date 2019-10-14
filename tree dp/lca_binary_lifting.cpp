#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
#define vec2d vector<vector<ll>>
using namespace std;

vector<ll> vec[maxn];
ll tim, tin[maxn], tout[maxn], len;
vector<vector<ll>> lca; // vector of vector
// lca[u][i] is the node that is the 2^i the ancestor of node u

void dfs(ll u, ll p){
    tin[u] = ++tim; // in time
    lca[u][0] = p; //  p is the 2^0 ie the 1st ancestor of node u
    for(ll i=0; i<len; i++){
        /*
                    x
                   / x is 2^ith ancestor of y
                  y                         \ then x is 2^(i+1) ancestor of u
                 / y is 2^ith ancestor of u /
                u

        */

        // x is 2^(i+1) ancestor of u
        //or 2^(i+1) ancestor of u is the 2^ith ancestor of y
        // or 2^(i+1) ancestor of u is the 2^ith ancestor of lca[u][i] as y is stored in the lca table
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
    if(u==v) return v;
    if(is_ancestor(u, v)){//if v is ancestor of u
        return v;
    }
    else if(is_ancestor(v, u)){ //if u is ancestor of v
        return u;
    }
    //if u and v are in different subtree
    // we will fix v
    // for 2^l th ancestor to 2^0 th ancestor of u , we will check if that is the common ancestor of u, v
    /*if 2^i th ancestor of u ie (lca[u][i]) is also ancestor of v (satisfies is_ancestor())
     we just decrement i , as we need the LOWEST OF COMMON ANCESTORs
     if 2^i th ancestor of u ie (lca[u][i]) is NOT an ancestor of v (!is_ancestor())
     we will raise the u node to its 2^i th ancestor and continue

    */
    for(ll i=len; i>=0; i--){
        if(!is_ancestor(v, lca[u][i])){
            u = lca[u][i];
        }
    }
    return lca[u][0];
}
int main(){
    ll n;
    cin >> n;

    for(ll i=0; i<n-1; i++){
        ll x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    len = ceil(log2(n)); // log2(n)
    tim = 0;
    memset(tin, 0, sizeof(tin));
    memset(tout, 0, sizeof(tout));
    lca.assign(n, vector<ll>(len+1));
    dfs(1, 1);
    ll q;
    cin>>q;
    while(q--){
        ll x, y;
        cin >> x >> y;
        cout << LCA(x, y) << endl;
    }
}
