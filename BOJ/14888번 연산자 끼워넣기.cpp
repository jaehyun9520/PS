#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
int n,min1=214700000,max1=-214700000;
vector <int> number;
vector <int> list(4);

void calculation(int val,int cnt)
{
	if(cnt==n-1)
	{
		if(min1>val)  min1=val;
		if(max1<val)  max1=val;
	}
	else
	{
		for(int i=0; i<=3; i++)
		{
			if(list[i]>0)
			{
				list[i]--;			  
				  if(i==0) 
				  {
			  	  calculation(val+number[cnt+1],cnt+1);
				  }

				  else if(i==1) 
				  {
				  	  calculation(val-number[cnt+1],cnt+1);
				  }
				  
				  else if(i==2)
				  {
				  	calculation(val*number[cnt+1],cnt+1);
				  }
				  
				  else if(i==3)
				  { 
					calculation(val/number[cnt+1],cnt+1);	
				  }
				  list[i]++;
			}
			
		}
		
	}
	
}


int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,j,val;
int count[4]={0};
cin>>n;
for(i=0; i<n; i++)
{
	cin>>val;
	number.push_back(val);
}
cin>>list[0]>>list[1]>>list[2]>>list[3];
calculation(number[0],0);

cout<<max1<<"\n"<<min1;

return 0;
}
