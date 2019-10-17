#include<bits/stdc++.h>
#define ll long long
#define maxn 10002
using namespace std;
vector<ll> vec[maxn];
ll flg;
ll vis[maxn],dp[maxn];
ll in[maxn];// height of the node considering it as a root from its leaf descender
ll out[maxn]; // other path not considering the node and its subtree


/* recursion relation for:
    in[u]=max(in[v])+1,for every child v of u,***same as finding height***
    out[u]= max(out[par]+1, max(in[x])+2), where par is the parent of u &
                   out[par]+1 is the way considered outside par subtree
            and x is every other child of par expect u&&
                    max(in[x])+2 is the way considered inside par subtree

*/
void height(ll a){// calculation in[]
// not visited
        vis[a] = 1;
        for(ll i=0;i<vec[a].size();i++){
            if(!vis[vec[a][i]]){
                height(vec[a][i]);
                in[a] = max(in[a], in[vec[a][i]]+1);
            }
        }
}
void dfs(ll a){ // calculating out[] by in[]
// not visited
        vis[a] = 1;
        ll mx1(-1), mx2(-1);
        for(ll i=0;i<vec[a].size();i++){
            if(!vis[vec[a][i]]){//as parent node is also in the adjacency list
            if(mx1<=in[vec[a][i]]){mx2= mx1; mx1 = in[vec[a][i]];}
            else if(in[vec[a][i]]> mx2)mx2= in[vec[a][i]];// finding 2 maximum height of children of a
            }
        }
        for(ll i=0;i<vec[a].size();i++){
                ll m=0;
            if(!vis[vec[a][i]]){
                if(in[vec[a][i]]== mx1) m= mx2;// if the child itself is the max subtree, we take 2nd max
                else m = mx1;// else we take in[child] as max
                out[vec[a][i]] = max(out[a]+1, m+2);
                dfs(vec[a][i]);
            }
        }
}
int main(){
        ll n,m,x,y;
        cin>>n;
        for(ll i=0;i<n-1;i++){
            cin>> x>>y;
            x--;y--;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        height(0);
        for(ll i=0;i<n;i++){vis[i]=0;}
        dfs(0);
       // for(ll i=0;i<n;i++) cout<< in[i]<< " "<< out[i]<< endl;
        for(ll i=0;i<n;i++){
            dp[i] = max(in[i],out[i]);
            cout<< dp[i]<< " ";
        }
        //cout<< ans << endl;
}
/*
8
1 2
1 3
1 4
2 5
4 6
6 7
6 8*/
