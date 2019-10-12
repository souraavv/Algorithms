#include<bits/stdc++.h>
#define ll long long
#define maxn 10001
#define mk make_pair

using namespace std;
ll sum;
/*
https://www.geeksforgeeks.org/count-inversions-array-set-3-using-bit/
*/

/*
Inversion Count for an array indicates – how far (or close) the array is from being sorted.
 If array is already sorted then inversion count is 0.
  If array is sorted in reverse order that inversion count is the maximum.
*/

/*
APPROACH: using a binary index tree
test case: 7 6 5 4 3 2 1
*******************       *******************
NEED OF BIT:we are calculating prefix sum for a dynamic dataset where update is present
                So if we update what is at position i , we have to update all i+1 to n as
                prefix array[i] = sum(1, i); that will be of order n^2

USING BIT:
In BIT , if we want to get sum(1, i), we can just go up (reducing the value upto last on bit)---> QUERY
if we want to update , we will update for all i+1 to n,---> UPDATE
we can just go down(adding the value upto last on bit)

Let us take 6 , for query (to get sum 1 to 6):
    6 = (110)in bin = (100)2 +(10)2 --> sum from (1 to 4)+ (5,6)
    7 = 111 = 110+1= sum from (1 to 6)+7=  sum from (1 to 4)+ (5,6)+7
    In tree, we are going up by subtracting upto last on bit
    index -= index & (-index);
       -----0------
      /     |       \
      1(1)  2(1,2)  4(1,4)
            |       / \
            3       5  6(5,6)
           (3)     (5)  \
                        7(7)
Let us take 4 , for update(update 4 to rest ):
    4 = (100)in bin = 100 + 100= 8 that is 4 will be held in 8
    3 = 11 = 11+1= 100=  4 that is 3 will be held in 4
    index += index & (-index);

*/

void update(ll b[],ll n, ll pos){
    while(pos<=n){
        b[pos] += 1;
        pos += pos&(-pos);
    }
}
ll query(ll b[],ll pos){
    ll ans=0;
    while(pos>0){
        ans +=b[pos];
        pos -= pos&(-pos);
    }
    return ans;
}
int main(){
    ll t; cin>> t; while(t--){

    ll n;
    cin>> n;
    ll BIT[n+1], arr[n+1],i, x;
    memset(BIT, 0, sizeof(BIT));
    memset(arr, 0, sizeof(arr));
    vector<pair<ll,ll>> vec;
    for(i=0;i<n;i++){
        cin>> x;
        vec.push_back(mk(x, i));
    }
    sort(vec.begin(), vec.end());// in case of negative input or large input
    /*5
7 -90 100 2 1
*/
    for(i=0;i<n;i++){// convert the case into 4 1 5 3 2
        arr[vec[i].second] = i+1;
       // cout<< " "<<arr[i]<< endl;
    }
    for(i=0;i<n;i++){
        cout<< " "<<arr[i]<< endl;
    }
    for(i=n-1;i>=0;i--){ // for each position we will compute how many large number are present before it
        cout<< sum<< endl;
        sum+= query(BIT,arr[i]-1);
        update(BIT, n, arr[i]);
    }
    cout<< sum<< endl;
    sum=0;
    }
}
