//https://codeforces.com/problemset/problem/558/E

#include<bits/stdc++.h>
#define maxn 100005
#define inf 100000000001
#define ll long long
using namespace std;


ll n,q;
string s;

ll tree[26][4*maxn] , lazy[26][4*maxn];

void lazyu(ll l, ll r, ll rt, ll seg){
    if(lazy[seg][rt]!=-1){
        tree[seg][rt] = lazy[seg][rt] *(r-l+1);
        if(l!=r ){
            lazy[seg][rt*2] = lazy[seg][rt];
            lazy[seg][rt*2+1] = lazy[seg][rt];
        }
        lazy[seg][rt] = -1;
    }
}

void update(ll l, ll r, ll rt, ll seg, ll x, ll y, ll val){
    lazyu(l, r, rt, seg);
    if(l>r) return;
    if(y<l || r<x){ // x y l r x y
        return;
    }
    if(x<=l && r<=y){ // x l r y
        lazy[seg][rt] = val;lazyu(l, r, rt, seg);return;
    }

    ll m = (l+r)/2;
    update(l, m, rt*2, seg, x, y, val);
    update(m+1, r, rt*2+1, seg, x, y, val);
    tree[seg][rt] = tree[seg][rt*2] + tree[seg][rt*2+1];

}

ll query(ll l, ll r, ll rt, ll seg, ll x, ll y){
    lazyu(l, r, rt, seg);
    if(l>r) return 0;
    if(y<l || r<x){ // x y l r x y
        return 0;
    }
    if(x<=l && r<=y){ // x l r y
        return tree[seg][rt];
    }
    ll m = (l+r)/2;
    return query(l, m, rt*2, seg, x, y)+query(m+1, r, rt*2+1, seg, x, y);

}

int main(){
    memset(lazy, -1, sizeof(lazy));
    cin>>n>>q>>s;
    for(ll i =0;i<n;i++){
        ll val = s[i]-'a';
        update(0, n-1,1,val,i,i,1); // for val character , update frequency of val in i,i range by 1
    }
    while(q--){
        ll l,r,k;
        cin>>l>>r>>k;
        l--;r--;
        ll arr[26];
        memset(arr, 0 , sizeof(arr));
        for(ll i=0;i<26;i++){
            arr[i] = query(0, n-1,1,i,l,r);
            //cout << arr[i] << " ";
            update(0, n-1,1,i,l,r,0); // clear all the frequency by updating the range 0
        }
        if(k){ // non decreasing
            ll st = l;
            for(ll i=0;i<26;i++){
                if(arr[i]){
                update(0, n-1,1,i,st,st+arr[i]-1,1); // update (st,st+arr[i]-1) range by ith character
                st += arr[i];
                }
            }
        }
        else { // non increasing
            ll st = l;
            for(ll i=25;i>=0;i--){
                if(arr[i]){
                update(0, n-1,1,i,st,st+arr[i]-1,1);
                st += arr[i];
                }
            }
        }
    }
    string s1;
    for(ll i =0;i<n;i++){
        for(ll j = 0;j<26;j++){
            if(query(0,n-1,1,j,i,i)){ // if jth character is present in (i,i) range
                s1+= (char) (j+'a');
                break;
            }
        }
    }
    cout << s1 << endl;

}
