/*	works correctly*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int  mod =1e9+7;
char grid[10000][10000];
int r,c;
int dp[1000][1000];	
	
	//using memoization
	int path(int x,int y)
	{
			if(x>=r||y>=c)
			return 0;
			
			if(grid[x][y]=='#')
			return 0;
			
			if(x==r-1&&y==c-1)
			return 1;
			
			if(dp[x][y]!=-1)
			return dp[x][y];
			
			return  dp[x][y]= (path(x+1,y)+path(x,y+1))%mod;
			 
			
	}
	
	
	int pathTabulation(int x,int y)
	{
			memset(dp,-1,sizeof(dp));
			
			//initialize dp with first row and column
			for(int j=0;j<c;j++)
			{
					(grid[0][j]=='.')?dp[0][j]=1:dp[0][j]=0;
			}
			
			for(int i=0;i<r;i++)
			{
					(grid[i][0]=='.')?dp[i][0]=1:dp[i][0]=0;
			}
			
			//now process our dp table
			for(int i=1;i<r;i++)
			{
					for(int j=1;j<c;j++)
					{
							if(grid[i][j]=='#')continue;
							else{
								dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
								}
					}
			}
			
			return dp[r-1][c-1];
	} 

signed main(){
	
	cin>>r>>c;
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cin>>grid[i][j];
	}
	
	memset(dp,-1,sizeof(dp));
	
	//cout<<pathTabulation(0,0);
	cout<<path(0,0);
	
	return 0;}

