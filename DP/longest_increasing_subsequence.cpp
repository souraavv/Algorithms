#include<bits/stdc++.h>

using namespace std;

int main(){
    int n , i , j;
    cin >> n;
    int arr[n] ,lis[n];
    for(i=0;i<n;i++){
        cin>> arr[i];
        lis[i] = 1;
    }
    // n2 approach
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(arr[i]> arr[j])
                lis[i] = max(lis[i], lis[j]+1);
        }
    }
    // nlog(n) approach
    for(i=0;i<n;i++){
        lis[i] =  0;
    }
    int len = 0;
    lis[len++] = arr[0];
    for(i=1;i<n;i++){
        int l = 0 , r = len-1;
        while(r>=l){
            int m = (l+r)/2;
            if(arr[i]> lis[m]) l =  m+1;
            else r = m-1;
            //cout << l << "\n";
        }
        if(l == len) lis[len++] = arr[i];
        else lis[l] = arr[i];

    }
    cout << len << endl;
}
/*
9
10 22 9 33 21 50 41 60 80

*/
