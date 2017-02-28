#include <iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	/*input format
	6
	6
	2
	0 0 0 1
	6 6 5 6
	*/
	int h,w;
	cin>>w>>h;
	bool badup[w+1][h+1];
	bool badside[w+1][h+1];
	for(int i=0;i<=w;i++){
		for(int j=0;j<=h;j++){
			badup[i][j] = badside[i][j] = 0;
		}
	}
	int n; //number of bad streets
	cin>>n;
	//cout<<n<<endl;
	// given a,b & c,d are one block away
	string s;
	getline(cin,s);
	for(int xx=0;xx<n;xx++){
		getline(cin,s);
		//cout<<"string "<<s<<","<<s.size()<<endl;
		int a[4];
		int j=0;
		a[0] = a[1] = a[2] = a[3] = 0;
		for(int i=0;i<s.size();i++){
			if(s[i]==' '){
				//cout<<j<<" -- "<<a[j]<<endl;
				j++;
			}
			else{
				a[j] = (ll)10*a[j] + (ll)(s[i] - '0');
				
			}
		}
		//cout<<a[3]<<endl;
		if(a[0]==a[2])badup[a[2]][max(a[1],a[3])] = true;
		if(a[1]==a[3])badside[max(a[0],a[2])][a[3]] = true;
	}
	ll dp[w+1][h+1];
	dp[0][0] = 1;
	
	for(int i = 1;i<=w;i++){
		if(badside[i][0]) dp[i][0] = 0;
		else dp[i][0] = dp[i-1][0];
	}
	for(int j = 1;j<=h;j++){
		if(badup[0][j]) dp[0][j] = 0;
		else dp[0][j] = dp[0][j-1];
	}
		
	for(int i = 1;i<=w;i++){
		for(int j = 1;j<=h;j++){
			if(badup[i][j] && badside[i][j]) dp[i][j] = 0;
			else if(badup[i][j]) dp[i][j] = dp[i-1][j];
			else if(badside[i][j]) dp[i][j] = dp[i][j-1];
			else dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	cout<<dp[w][h]<<endl;
	return 0;
}