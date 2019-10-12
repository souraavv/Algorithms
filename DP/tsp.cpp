#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define piii pair<ll, pii>
#define MOD 1000000007
#define MAX 10005
#define INF 10000000001
#define ft first
#define sd second

using namespace std;

/*HAMILTONIAN CYCLE*/

/*TRAVELLING SALESMAN PROBLEM*/

/*
    * cycle so start and end at the same vertex
    ** hamiltonian cycle will contain every vertex once and starting vertes twice
    *** as for a complete undirected graph, HC will exist
    **** TSP is the problem about finding the minimum weighted cycle
    ***** if starting vertex is 0 then possible cycles are
                0 1 2 3 0
                0 1 3 2 0
                0 2 1 3 0
                0 2 3 1 0
                0 3 1 2 0
                0 3 2 1 0
        ie 0 - (ALL possible permutation of 1,2,3) - 0

*/

ll dp[1<<10][10];
ll n, m;
ll arr[10][10];
vector<ll> c;

ll tsp(ll mask, ll city){
    if(mask == (1<<n)-1) return arr[city][0]; // when we complete the path , we add the last
                            // vertex to the 0 vertex
    if(dp[mask][city]!=-1) return dp[mask][city]; // when the state is already calculated
    ll res = INF,i;
    for(i = 0;i<n;i++){
        if((mask&(1<<i))==0){ // when that state is not visited yet
                            // ie when that position is set to offbit 0
            ll val = arr[city][i] + tsp(mask|(1<<i),i); // we will go to all possible not visited
                                            //vertices using mask as mask|(1<<i) and new city as i
            res = min(res , val);
        }
    }
    return dp[mask][city] = res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    //while(true){
        cin>> n >>m;
        //if(n==0) break;
            // complete graph
            ll start = 0; // cycle from 0
            for(ll i=0;i<m;i++){
                ll x,y,w;
                cin>> x >> y >> w;
                x--, y--;
                arr[x][y] = arr[y][x] = w;
            }

            for(ll i=1;i<n;i++){
                c.push_back(i);
            }
            ll mn = INF;

            // N! SOLUTION
            /*
            do{
                ll res = 0;
                res += arr[0][c[0]];
                cout << "1 " ;
                for(ll i=0;i<c.size()-1;i++){
                    res += arr[c[i]][c[i+1]];
                    //cout << c[i]+1 << " " ;
                }
                //cout << c[c.size()-1]+1 << " 1 ---->" <<  res<< endl;
                res += arr[0][c[n-2]];
                mn = min(res, mn);
            }
            while(next_permutation(c.begin(), c.end()));
            cout << mn << endl;
            */

            memset(dp, -1 , sizeof(dp));
            cout << tsp(1,0) << endl; // mask -> 0001 as 1st city has been visited
                                        // 0 is the starting point
        //}
    //}
}

/*
4 6
1 2 1
1 3 2
1 4 3
2 3 4
2 4 5
3 4 6

*/
