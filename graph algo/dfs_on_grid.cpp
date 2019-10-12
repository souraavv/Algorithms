            #include<bits/stdc++.h>
            #define ll long long int
            #define maxn 505
            #define MOD 1000000007
    //https://codeforces.com/contest/327/problem/D


            using namespace std;
            int n , m, comp;
            char b = 'B', d='D', r= 'R';
            char ar[maxn][maxn];
            bool vis[maxn][maxn], vis1[maxn][maxn];
            vector<pair<char , pair<int, int> >> vec;
            int X[4]= {-1, 1, 0, 0};
            int Y[4]= {0, 0, -1, 1};
            bool valid(int a, int b){
                if(a>=0 && a<n && b>=0 && b<m ) return true;
                else return false;

            }
        void dfs(int x, int y){
            vis[x][y]= true;
            int i;
            for(i=0;i<4;i++){
                 if(valid(x+X[i], y+ Y[i])&& !vis[x+X[i]][y+ Y[i]]){

                    dfs(x+X[i], y+ Y[i]);
                    vec.push_back(make_pair(d, make_pair(x+X[i]+1, y+ Y[i]+1)));
                    vec.push_back(make_pair(r, make_pair(x+X[i]+1, y+ Y[i]+1)));

                 }
            }

        }
        /*void connectedcomp(ll x, ll y){
            vis1[x][y]= true;
            ll i;
            for(i=0;i<4;i++){
                 if(valid(x+X[i], y+ Y[i])&& !vis1[x+X[i]][y+ Y[i]]){

                    connectedcomp(x+X[i], y+ Y[i]);

                 }
            }

        }*/
            int main(){
                scanf("%d %d", &n, &m);
                int i,j,t=0;
                for(i=0;i<n;i++){
                    for(j=0;j<m;j++){
                        cin>> ar[i][j];
                        if(ar[i][j]=='.'){vec.push_back(make_pair(b, make_pair(i+1, j+1)));}
                        else vis[i][j] = true;
                    }
                }
                for(i=0;i<n;i++){
                    for(j=0;j<m;j++){
                        if(!vis[i][j]){
                            dfs(i, j);
                            comp++;
                        }
                    }
                }
                printf("%d\n", vec.size());
                for(auto x:vec){
                    printf("%c %d %d\n", x.first, x.second.first, x.second.second);
                }
                return 0;
            }
