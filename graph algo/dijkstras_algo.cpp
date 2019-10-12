// DIJKSTRA'S ALGORITHM FOR SINGLE SOURCE SHORTEST PATH
/*
    * may or may not work on NEGATIVE EDGE
    ** will not work on negative edge cycle
    *** will give shortest path from a single source to all other vertex
    **** It is a GREEDY algorithm
    ***** will work on both DAG or non directed graph with non negative edges
*/

#include<bits/stdc++.h>
#define ll  long long
#define pb push_back
#define mp make_pair
#define INF 10000000
#define PAIR pair<int, int>

using namespace std;

void shortest_path(vector<PAIR>vec[], int rt, int n){
    int path[n], i;
    // initialization
    for(i=0;i<n;i++){path[i]= INF;}
    path[rt] = 0;
    // pq is the min heap of distance and source root
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
    // the 1st of the pair is just to create the min heap to pick  min distanced vertex
    /* why do we create a pair priority queue
        https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
    */
    pq.push(mp(0, rt));
    while(!pq.empty()){
        int u = pq.top().second; // greedily choose already minimum path
        pq.pop();
        for(i=0;i<vec[u].size();i++){
            int v = vec[u][i].first;
            int w = vec[u][i].second;
            if(path[v]> path[u]+ w){
                path[v] =path[u]+ w; // relaxation
                pq.push(mp(path[v], v));
            }
        }
    }
    for(i=0;i<n;i++){cout << i+1 << " " << path[i] << endl;}
}

int main(){
    int n, e;
    cin>> n >> e;
    int i ,u, v, w;
    vector<PAIR> vec[n];
    for(i=0;i<e;i++){
        cin>> u>> v>> w;
        u--,v--;
        vec[u].pb(mp(v,w));// in case of a non directed graph , we create parallel edge from v to u and u to v
        //vec[v].pb(mp(u,w)); // with same weighted edge
    }
    shortest_path(vec, 0, n);
}
/*
6 8
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
5 4 2
4 6 1
5 6 5
*/
