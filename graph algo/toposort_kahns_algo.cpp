#include <bits/stdc++.h>
//http://www.spoj.com/problems/TOPOSORT/
using namespace std;
vector<int> topo;
void kahns_toposort(vector<int>g[],int nodes,int in_degree[]){
    priority_queue <int, vector<int>, greater<int> > pq; // min heap
    for( int  i =0;i<nodes; i++){
        if(in_degree[i]==0) pq.push(i);
    }
    int cnt =0;
    while(!pq.empty()){
        int t = pq.top(); //cout<< t+1<< " ";
        pq.pop();
        topo.push_back(t);cnt++;
        for( int  i =0;i<g[t].size(); i++){
            in_degree[g[t][i]]--;// cout << g[t][i]<<" "<<in_degree[g[t][i]] << endl;
            if(in_degree[g[t][i]]==0) pq.push(g[t][i]);
        }
    }
    if(cnt!= nodes) cout << "Sandro fails.\n";
    else {
       for(int i =0; i<topo.size();i++){
        cout<< topo[i]+1<< " ";
        }
    }
}

int main(){
    int nodes, edges;
    cin>> nodes >> edges;
    vector<int> g[nodes];
    int in_degree[nodes];
    memset(in_degree, 0 , sizeof(in_degree));
    for(int i =0;i<edges;i++){
        int u , v;
        cin>> u>> v;
        u--;v--;
        g[u].push_back(v);
        in_degree[v]++;
    }
  //  for(int i =0;i<nodes;i++) cout<<in_degree[i] << " ";
    kahns_toposort(g, nodes, in_degree);

    /* for(int i =0; i<s.size();i++){
        cout<< s[i]+1<< " ";
    }*/
}
