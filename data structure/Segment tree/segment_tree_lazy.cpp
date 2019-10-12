#include<bits/stdc++.h>
#define ll long long
#define MAXINT 100000000
#define N 50005
using namespace std;

struct tree{
    ll val;
    ll l;
    ll r;
    ll lazy;
};

    // build segment tree
    tree arr[4*N+1];
void build(ll rt, ll left, ll right){
    if(left>right) return;
    arr[rt].val = 0, arr[rt].lazy =0;
    arr[rt].l = left;
    arr[rt].r=right;
   // cout<<left <<" " <<right<< endl;
    if(left== right) return;
    ll mid= (left+right)/2;

    build(rt*2, left, mid);
    build(rt*2+1, mid+1, right);
    return;
}

void lazy_update(ll root){
    arr[2*root].lazy+=arr[root].lazy;
    arr[2*root+1].lazy+=arr[root].lazy;
    arr[root].lazy=0;
}

void lazy_task(ll root){
    arr[root].val = min(arr[2*root].val+arr[2*root].lazy,arr[2*root+1].val+arr[2*root+1].lazy);
}

void update(ll left, ll right, ll root, ll value){
    if(left>right) return; // invalid case
    if(left>arr[root].r || right<arr[root].l) return ; //x.y l...r x.y outside the range
    else if(left<=arr[root].l && arr[root].r<= right) {arr[root].lazy+= value; return;}  // x...l..r...y // tatally inside the range
    else{// partially inside the range
        lazy_update(root);// pushing the storing value into its child
        update(left, right, root*2, value);
        update(left, right, root*2+1, value);
        lazy_task(root);
        return ;
    }
}

ll query(ll left, ll right, ll root){
    if(left>right) return MAXINT; // invalid case
       // cout<< left<< " "<<arr[root].l<<" "<< right<<" "<<arr[root].r << endl;
    if(left>arr[root].r || right<arr[root].l) return MAXINT; //x.y l...r x.y outside the range
    else if(left<=arr[root].l && arr[root].r<= right) {return arr[root].lazy+arr[root].val; }  // x...l..r...y // tatally inside the range
    else{// partially inside the range
        lazy_update(root);// pushing the storing value into its child
        ll a=query(left, right, root*2);
        ll b= query(left, right, root*2+1);
        lazy_task(root);
        return min(a,b);
    }
}
void print(ll rt, ll left, ll right){
    if(left>right) return;
   // arr[rt].val = arr[rt].lazy =0;
   // arr[rt].l = left;
   // arr[rt].r=right;
   cout<<arr[rt].val <<" " <<arr[rt].lazy<< " "<<arr[rt].l<<" "<<arr[rt].r<< endl;
    if(left== right) return;
    ll mid= (left+right)/2;

    print(rt*2, left, mid);
    print(rt*2+1, mid+1, right);
    return;
}
int main(){
    ll n,q, i, x,y;
    cin>> n;
    build(1,1,n);
    for(i=0;i<n;i++){
        cin>>x;
        update(i+1, i+1,1, x);
    }
    //print(1,1,n);
    cin>>q;
    for(i=0;i<q;i++){
        cin>>x>>y;
        cout << query(x, y, 1)<< endl;
    }
}
/*
5
1 2 3 4 5
2
1 3
1 5
*/
