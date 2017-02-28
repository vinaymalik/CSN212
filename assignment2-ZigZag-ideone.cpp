#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//Assignment2-DP
//ZigZag

/*input format
50
374 40 854 203 203 156 362 279 812 955 600 947 978 46 100 953 670 862 568 188 67 669 810 704 52 861 49 640 370 908 477 245 413 109 659 401 483 308 609 120 249 22 176 279 23 22 617 462 459 244
*/

int main() {
	int n;
	cin>>n;
	if(n<1){
		cout<<0<<endl;
		return 0;
	}
	int A[n];
	for(int i=0;i<n;i++)cin>>A[i];
	int DpNeg[n]; //longest sequence eding at i with last diff negative
	int DpPos[n]; //longest sequence ending at i with last diff positive
	DpNeg[0] = 1;
	DpPos[0] = 1;
	int ans = 1;
	for(int i=1;i<n;i++){
		DpNeg[i] = DpPos[i] = 1;
		for(int j=i-1;j>=0;j--){
			if(A[i]>A[j]){
				DpPos[i] = max(DpPos[i], DpNeg[j]+1);
			}
			
			if(A[i]<A[j]){
				DpNeg[i] = max(DpNeg[i], DpPos[j]+1);
			}
		}
		ans = max(ans, max(DpPos[i], DpNeg[i]));
	}
	cout<<ans<<endl;
	return 0;
}