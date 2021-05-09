#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
int n,m;
vector <int > list;
 
 int check(int x)
 {
 	int sum=0;
 	
 	for(int i=0; i<n; i++)
 	{
 		if(list[i]>x)
 		{
 			sum+=x;
		 }
		 
		 else
		 {
		 	sum+=list[i];
		 }
		 
		 if(sum>m) //예산초과 
		 {
		 	return sum;
		 }
 		
	 }
	 
	 return sum;
 }
 
 
int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cin>>n;
int i,val,low,high,mid,ans=0;

for(i=1; i<=n; i++)
{
	cin>>val;
	
	list.push_back(val);
}

sort(list.begin(),list.end());

cin>>m;

low=1 ;high=list[n-1];


while(low<=high)
{
	mid=(low+high)/2;
	
	if(check(mid)<=m)
	{
		ans=mid;
		low=mid+1;
	}
	else{
		high=mid-1;
	}
	
	
	
}
cout<<ans;
return 0;
}
