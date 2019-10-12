#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define piii pair<ll, pii>
#define MOD 1000000007
#define MAX 100005
#define INF 10000000001

using namespace std;
ll vis[MAX], disc[MAX], low[MAX], par[MAX], ar[MAX];
ll tim,n,m ;
void cut_vertex(ll rt, vector<ll>vec[]){
    vis[rt] = 1;
    tim++;
    disc[rt] = low[rt] = tim;
    ll ch = 0;//cout<< rt<< " ";
    for(ll i =0;i<vec[rt].size();i++){
        ll v = vec[rt][i];
        if(!vis[v]){
            ch++;
            par[v] = rt;
            cut_vertex(v, vec);
            low[rt] = min(low[rt], low[v]);
            if(par[rt]==-1&& ch>1) ar[rt] =1;
            else if(par[rt]!=-1 && low[v]>= disc[rt]) ar[rt] =1;

        }
        else if(par[rt]!=v){
            low[rt]= min(low[rt], disc[v]);
        }
    }
}

void bridge(ll rt, vector<ll>vec[]){
    vis[rt] =1;
    tim++;
    disc[rt] = low[rt] = tim;
    for(ll i =0;i<vec[rt].size();i++){
        ll v = vec[rt][i];
        if(!vis[v]){
            par[v] = rt;
            bridge(v , vec);
            low[rt] = min(low[rt] , low[v]);
            if (low[v] > disc[rt]){
                    cout << rt <<" " << v << endl;
                    }

        }
        else{
            if(par[rt]!= v){
                low[rt] = min(low[rt] , disc[v]);
            }
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
        cin>> n>>m;
        vector<ll>vec[n];
        for(ll i=0;i<m;i++){
            ll x, y;
            cin >> x>> y;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        memset(par, -1, sizeof(par));
        for(ll i= 0;i<n;i++){
            if(!vis[i])bridge(i,vec);
        }
        cout << endl;
        memset(par, -1, sizeof(par));
        memset(vis, 0, sizeof(vis));
        memset(disc, 0, sizeof(disc));
        memset(low, 0, sizeof(low));
        tim = 0;
        for(ll i= 0;i<n;i++){
            if(!vis[i])cut_vertex(i,vec);
        }
        for(ll i= 0;i<n;i++){
            if(ar[i])cout<< i << " ";
        }
}


