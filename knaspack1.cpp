#include<bits/stdc++.h>
using namespace std;
#define int long long

int max(int a,int b){
	return a>b?a:b;}

int table[1001][1001],dp[1001][1001];


int knapsack(int i,int W)
{
		if(i<0||W==0)
		return 0;
		
		if(dp[i][W]!=-1)
		return dp[i][W];
		
		if(table[i][0]>W)
		{
				//store the result in dp and then return
				
				dp[i][W]=knapsack(i-1,W);
				return dp[i][W];
		} 
		
		dp[i][W]=max(table[i][1]+knapsack(i-1,W-table[i][0]),knapsack(i-1,W));
		
		return dp[i][W];
}

signed main(){
	
	memset(dp,-1,sizeof(dp));
	
	int n,W;
	cin>>n>>W;
	
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<2;j++)
			{cin>>table[i][j];}
	}
	
	for(int i=0;i<1000;i++)
	{
			for(int j=0;j<1000;j++)
			{dp[i][j]=-1;}
	}
	
	cout<<knapsack(n,W);
	
	return 0;}
