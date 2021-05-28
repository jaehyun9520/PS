#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n,w,l,i,weight=0,ans=0;
int truck[1001]={0};

int list[101]={0};

cin>>n>>w>>l; 

for(i=1; i<=n; i++)
{
	cin>>truck[i];
}

for(i=1; i<=n; i++)
{
	if(weight+truck[i]<=l) 
	{
	
		ans++;
		weight+=truck[i];
		
			if(list[w]!=0) 
			{
				weight-=list[w];
				list[w]=0;
			 } 
		
		
		
		for(int j=w; j>=2; j--)
		{
		      list[j]=list[j-1];
		      list[j-1]=0;
			 
			 }
			 
			 list[1]=truck[i];
			
		}
		
		else{
			
			int cnt=1; 
			int sum=0;
			for(int j=w; j>=1; j--)
			{
				
			 if(list[j]!=0)
			 {
			 	sum+=list[j];
			 	list[j]=0;
				 
				if(weight-sum+truck[i]<=l)
				{
					cnt=cnt+w-j;
					weight-=sum;
					   
					   for(int k=j-1; k>=1; k--)
					   {
					   	 if(list[k]!=0)
					   	 {
					   	 	list[k+cnt]=list[k];
					   	 	list[k]=0;
							}
					   }
					   break;
				}
			}
				
			 } 
			 
			 weight+=truck[i];
			 list[1]=truck[i];
			 ans+=cnt;
			

}
}
for(i=1; i<=w; i++)
{
	if(list[i]!=0)
	{
	
		ans=ans+w-i+1;
		break;
	}
}


cout<<ans;
return 0;
}
