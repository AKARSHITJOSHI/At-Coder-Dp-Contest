#include<bits/stdc++.h>
using namespace std;

int arr[10005],dp[1000005];
int n,k;
int func(int ind)
{
	if(ind==n)
	return 0;
	
	if(dp[ind]!=-1)
	return dp[ind];
	
	
	int minimum=1e10;
	
	//from index+1 to k check all combinations
	for(int i=ind+1;i<=min(n,ind+k);i++)
	{
	minimum=min(minimum,abs(arr[i]-arr[ind])+func(i));	
	}
	
	return dp[ind]=minimum;	
}

int main(){

	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	
	memset(dp,-1,sizeof(dp));

		cout<<func(1);
	
	}
