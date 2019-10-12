#include <bits/stdc++.h>

using namespace std;


int nodes, edges;
stack<int> s;
bool dfs(vector<int> g[], int rt , int vis[]){
    if(vis[rt]==1) return true; // back edge
    if(vis[rt]==2) return false; // cross edge
    vis[rt] = 1; // preorder
    for(int i =0;i<g[rt].size();i++){
        if(dfs(g , g[rt][i], vis))return true;
    }
    vis[rt] = 2; // postorder
    s.push(rt);
    return  false;
}

bool toposort(vector<int> g[]){
    int vis[nodes];
    bool t = false;
    memset(vis, 0 , sizeof(vis));
    for(int i=0;i<nodes;i++){
        t = dfs(g , i , vis);
        if(t) break;
    }
    return t;
}

int main(){

    cin>> nodes >> edges;
    vector<int> g[nodes];
    for(int i =0;i<edges;i++){
        int u , v;
        cin>> u>> v;
        u--;v--;
        g[u].push_back(v);
    }

    bool t = toposort(g);
    if(t) cout << " not a DAG\n";
    else {
        //cout << s.size() << " ";
        while(!s.empty()){
            cout << s.top()+1<< " ";
            s.pop();
        }
    }

}
