#include <iostream>
#include<bits/stdc++.h>
using namespace std;


#define INF (1<<30)
typedef pair<int, int> iPair; 
 
int LIS(int x,int n, int a[])
{
	int b[n+1];
    b[0] = -INF;
    for(int i=1; i<=n; i++){
        b[i] = INF;
    }
    int res=0;
 
    for(int i=x;i<x+n;i++)
    {
        int low = 0, high = res, mid;
 
        while(low<=high){
            mid = (low+high)/2;
            if(b[mid]<a[i]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
 
        b[low] = a[i];
 
        if(res<low){
            res = low;
        }
    }
 
    return res;
 
}
 
 
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[2*n];
        for(int i=0;i< n;i++)
        {
            cin>>a[i];
            a[i+n]=a[i];
        }
        vector<iPair> myvec;
        for(int i=0; i<n;i++)
            myvec.push_back( make_pair(a[i],i) );
        sort(myvec.begin(), myvec.end());
 
        int x = 1;
        for(int i=0;i<myvec.size();i++){
            x = max(x, LIS(myvec[i].second,n,a));
        }
 
        cout<<x<<endl;
    }
    return 0;
}