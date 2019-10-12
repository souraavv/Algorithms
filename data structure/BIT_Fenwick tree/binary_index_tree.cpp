// sum of range
#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int n;
int BIT[MAX], arr[MAX];
void update(int a, int b){
    for(int i=a;i<=n;i+= (i &-i)){
        BIT[i]+= b;
    }
}
int query(int x){
    int sum=0;
    for(int i=x;i>0;i-=(i &-i)){
        sum+= BIT[i];
    }
    return sum;
}
int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>> arr[i];
        update(i+1, arr[i]); // 0 is a dummy node
    }
    int q;
    cin>> q;
    while(q--){
        char a;
        cin>>a;

        if(a=='Q'){ // query
            int l,r;
            cin>>l>>r;// return sum of (l,r)  l,r>0
            cout<<query(r)- query(l-1)<< endl;
        }
        else{
            int newV, pos;
            cin>>pos>>newV; // pos>0 as the qn is 1 based array
            update(pos, newV-arr[pos-1]);// updated the difference throughout the range
        }
    }

}
