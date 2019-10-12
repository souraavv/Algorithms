#include<bits/stdc++.h>
#define ll int
#define pr pair<ll, ll>
#define MOD 998244353
#define maxn 1000005
using namespace std;

struct data{
    ll pos,l,r,val;
};
bool comp(data a, data b){
    if(a.val== b.val) return a.l> b.l;
    else return a.val> b.val;
}
void update(ll BIT[], ll val, ll n){
    while(val<=n){
        BIT[val]++;val += val&(-val);
    }
}
ll quer(ll BIT[], ll val){
    ll ans=0;
    while(val>0){
        ans += BIT[val];val -= val&(-val);
    }
    return ans;
}
int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    scanf("%d", &n);
    //cin>> n;
    ll i , arr[n+1];
    // inputs
    for(i=1;i<=n;i++){
         scanf("%d", &arr[i]);//cin>> arr[i];
    }
    ll q;  scanf("%d", &q);//cin>>q;
    ll query[q+1][3];
    for(i=1;i<=q;i++){
         scanf("%d%d%d", &query[i][0], &query[i][1],&query[i][2]);
        //cin>> query[i][0]>> query[i][1]>> query[i][2];
    }
    // build
    data tree[n+q+1];
    for(i=1;i<=n;i++){
        tree[i].pos= 0;
        tree[i].val= arr[i];
        tree[i].l= 0;
        tree[i].r= i;
    }
    for(i=n+1;i<=n+q;i++){
        tree[i].pos= i-n;
        tree[i].val= query[i-n][2];
        tree[i].l= query[i-n][0];
        tree[i].r= query[i-n][1];
    }
    // process
    sort(tree+1, tree+n+q+1, comp);
    // calculating
    ll BIT[n+5];
    memset(BIT, 0 , sizeof(BIT));
    ll ans[q+1];
    for(i=1;i<n+q+1;i++){
        if(!tree[i].pos){// if array element then update
            update(BIT,tree[i].r, n);
        }
        else {// store query in arr[] array
            ans[tree[i].pos] = quer(BIT,tree[i].r)- quer(BIT,tree[i].l-1);
        }
    }
    // print ans
    for(i=1;i<=q;i++){
        printf("%d\n", ans[i]);//cout<< ans[i]<< endl;
    }
}
