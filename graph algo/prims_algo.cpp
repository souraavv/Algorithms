// PRIM'S ALGORITHM

#include<bits/stdc++.h>
#define ll long long int
#define mp pair<int, int>
#define MAX 10005
using namespace std;

/*
    * prim's algorithm is greedy algorithm
    ** sort all edge values
    *** start by the lowest edge
    **** connect the smallest neighbour edge if it does not create a cycle
*/

int n, e;
bool mark[MAX];

int prim(int rt, vector<mp>vec[]){
    priority_queue<mp, vector<mp>, greater<mp>> pq;
    int mincost=0;
    pq.push({0, rt});
    while(!pq.empty()){
        mp t = pq.top();
        pq.pop();
        int v = t.second;
        if(mark[v]) continue; // avoiding a cycle
        mark[v] = true;
        mincost+= t.first;
        cout<< v+1<< " "<< t.first << endl;
        for(int i=0;i<vec[v].size();i++){
            int u = vec[v][i].second;
             if(mark[u]) continue;
            pq.push(vec[v][i]);
        }
    }
    return mincost;
}
int main(){
    int i , x,y,wt;
    cin>>n>>e;
    vector<mp>vec[n];
    for(i=0;i<e;i++){
        cin>> x>> y>>wt;
        x--;y--;
        vec[x].push_back({wt,y});
        vec[y].push_back({wt,x});
    }
    cout<<prim(0, vec)<< endl;// starting node 0

}
/*
6 8
1 2 2
1 6 6
2 3 7
3 4 9
4 5 10
3 5 14
2 5 4
6 5 2

*/
