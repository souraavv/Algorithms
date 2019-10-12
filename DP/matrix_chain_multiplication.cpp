//https://www.codechef.com/problems/MIXTURES
// bottom up approach

#include<bits/stdc++.h>
#define ll long long int
#define INF 1000000000

using namespace std;
int main(){
    ll n;
    while(scanf("%lld", &n)!= EOF){
        ll arr[n], i, j, k, l;
        ll col[n][n], smoke[n][n];
        for(i = 0; i < n; i++){
            cin >> arr[i];
            col[i][i] = arr[i];
        }
        for(i = n-1; i >= 0; i--){ // left range
            for(j = i; j < n; j++){ // right range
                smoke[i][j] = INF;
                if(i == j) smoke[i][j] = 0;
                for(k = i; k < j; k++){
                    ll temp = smoke[i][k] + smoke[k+1][j] + col[i][k]*col[k+1][j];
                    if(temp< smoke[i][j]){
                        smoke[i][j] = temp;
                        col[i][j] = (col[i][k]+col[k+1][j])%100;
                    }
                }
            }
        }
        /*
        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                cout<< col[i][j]<< " ";
            }cout<< "\n";
        }
        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                cout<< smoke[i][j]<< " ";
            }cout<< "\n";
        }
        */
        cout<< smoke[0][n-1] << endl;

    }

}
