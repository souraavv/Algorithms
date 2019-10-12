#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define MAX 10005
using namespace std;

pair<int , pair<int , int>> p[MAX];
int n, e;

int root(int a, int id[]){
    while(a!= id[a]){
        id[a] =id[id[a]];
        a= id[a];
    }
    return a;
}

void unionk(int a, int b , int id[]){
    int x = root(a , id);
    int y = root(b , id);
    id[x]= id[y];
}
int kruskal(int id[]){
    int i, res=0;
    for(i =0;i<e;i++){
        int x,y,wt;
        x= p[i].second.first;
        y=p[i].second.second;
        wt =p[i].first;
        if(root(x, id)!= root(y , id)){
            res+= wt;
            unionk(x,y, id);
        }
    }
    return res;
}
int main(){
    int i , x,y,wt;
    cin>>n>>e;
    int id[n];
    for(i=0;i<n;i++){
        id[i]= i; // initialize
    }
    for(i=0;i<e;i++){
        cin>> x>> y>>wt;
        x--;y--;
        p[i]= mp(wt, mp(x,y));
    }
    sort(p, p+e);
    cout<<kruskal(id)<< endl;

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
