#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

long long sum=0;
int i,n,val,s,e,ans=21470000,size=2;


cin>>n>>val;

vector <int> a(n);
for(i=0; i<n; i++)
{
	cin>>a[i];
}



s=0; e=1;
sum=a[s]+a[e];

while(s<=e&&e<n)    
{

   if(sum>=val)
   {
   	     if(ans>size)
			{
			  ans=size;
   	 }
   	     
   	      size--;
			sum-=a[s];
			s++;              
	   }
	   
	 else{  
	 	
	 	size++;
	 	e++;
	 	
	 	if(e<a.size()) 
		 {
		 sum+=a[e];
	 }
	 }  	

	
}
	
	
	if(ans!=21470000)
	{
		cout<<ans;
	}
	
	else cout<<0;



return 0;
}
