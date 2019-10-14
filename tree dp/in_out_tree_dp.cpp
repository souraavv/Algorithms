#include<bits/stdc++.h>
#define ll long long
#define maxn 10002
using namespace std;
vector<ll> vec[maxn];
ll flg;
ll vis[maxn],dp[maxn];
ll in[maxn];// height of the node considering it as a root from its leaf descender
ll out[maxn]; // other path not considering the node and its subtree
/*
max path from a node can be max of
height of the node considering it as a root from its leaf descender and
other path not considering the node and its subtree

         1      the path from 7 can be 7-6-8 ie inside the children of 7 or to outside its child ie in the remaining tree
       / | \    from 7-6 is common ie in[6] or height of 7, so it is either 6-8 or 6-4-1-2-5
      2  3  4   (6-8) by h1=max(in[x])+2, where x is all other child of 6 and if we join 2 children of 6,it will cost us 2 egde , hence +2
     /      |    6-4-1-2-5 by h2 = out[6]+1, where out[6] is the out for 6 and +1 because if we connect 7 to 6 to its parent
     5      6     it will cost one edge
           / \      in[7] =0; 7
         (7)  8     out[7] = max(h1, h2) 6-4-1-2-5
         / \          dp[7] = in[]+out[] 7 + 6-4-1-2-5
        . . .
*/

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
