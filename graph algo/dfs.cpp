#include <bits/stdc++.h>
//breadth first search

using namespace std;
int main(){
    int i,x,y,edge , node;
    cin>> edge>>node;
    vector<int> vec[node];
    for(i=0;i<edge;i++){
        cin>> x>> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for(i=0;i<node;i++){
        for(int j=0;  j<vec[i].size();j++){
        cout<< vec[i][j]<< " ";
        }
        cout<< endl;
    }
    list<int> q;
    bool arr[node];
    for(i=0;i<node;i++){arr[i]= false;}
    for(i=0;i<node;i++){
        if(arr[i]==false)q.push_back(i);
        while(!q.empty()){
            int v = q.back();

            q.pop_back();
        if(arr[v]==false){ cout<<v<<endl;arr[v]= true;}

            for(int j=0;j<vec[v].size();j++){
                if(arr[vec[v][j]]==false){
                q.push_back(vec[v][j]);}
            }
        }
    }
}
/*
5 4
0 1 0 2 1 2 1 3 2 3
6 4
0 1
0 2
1 2
2 0
2 3
3 3
*/

