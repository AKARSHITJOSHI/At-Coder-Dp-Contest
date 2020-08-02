#include<bits/stdc++.h>
using namespace std;
/*
 * Recursive approach
 * 
 * int forgJump(int arr[],int ind,int n)
 * {
 * if(ind==n-1)
 * return 0;
 * 
 * if(ind>=n)
 * return INT_MAX;
 * 
 * int left=abs(arr[i]-arr[i+1])+forgJump(arr,ind+1,n);
 * 
 * if(ind+2<n)
 * int right=abs(arr[i]-arr[i+2])+ forgJump(arr,ind+2,n);
 * 
 * return min(left,right);
 * }
 * 
 * */
 
 
 int arr[100005];
 
 
 int frogJump(int arr[],int n)
 {
		int dp[n];
		memset(dp,0,sizeof(dp));
		
		dp[0]=0;
		dp[1]=abs(arr[1]-arr[0]);
		
		for(int i=2;i<n;i++)
		{
				if(abs(arr[i]-arr[i-1])<abs(arr[i]-arr[i-2]))
				{
					dp[i]=dp[i-1]+abs(arr[i]-arr[i-1]);
					
				}
				else{
					dp[i]=dp[i-2]+abs(arr[i]-arr[i-2]);
				}
		}
		
		return dp[n-1];
}
int main(){
	
//	int arr[]={10,30,40,20};
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
			cin>>arr[i];
	}
	
	
	
	cout<<frogJump(arr,n);
	return 0;}
