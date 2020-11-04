#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;


int main()
{
//freopen("input.txt", "rt", stdin);	
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int H,W,i,MAX=0,idx,val,ans=0;
int arr[501]={0};
cin>>H>>W;

for(i=1; i<=W; i++)
{
	cin>>arr[i];
	 if(MAX<arr[i]) 
	 {
	 idx=i; MAX=arr[i];	
}
}

val=arr[1];

for(i=2; i<idx; i++)  //왼쪽->기준점  
{
	if(val<arr[i]) val=arr[i];
	
	else if(val>arr[i]) 
	{
	ans=ans+(val-arr[i]);

}
}



val=arr[W];
for(i=W-1; i>idx; i--) // 기준점<-오른쪽 
{
	if(val<arr[i]) val=arr[i];
	
	else if(val>arr[i]) ans+=(val-arr[i]);
}


cout<<ans;

return 0;
}
