#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,j,k,z,num,dir,left,right,ln,rn,tmp,ans=0,a,b;
int check[5]={0};
int array[5][9]={0};
string val;

for(i=1; i<=4; i++)
{
	cin>>val;
	
	for(j=0; j<val.size(); j++)
	{
		array[i][j+1]=val[j]-48;
		
	}
	
}
cin>>k;

for(i=1; i<=k; i++)
{
	for(j=1; j<=4; j++)
	{
		check[j]=0;
	}

	cin>>num>>dir;
	
	check[num]=dir;
	
	ln=num;       rn=num;
	left=num-1;  right=num+1;
	
	while(left>0)
	{
		if(array[ln][7]!=array[left][3])   
		{
			if(check[ln]==-1)  check[left]=1;
			
			else check[left]=-1;
		}
		if(check[left]==0) break;
		left--;
		ln--;
	
	}
	
	
	while(right<5)
	{
	
		if(array[rn][3]!=array[right][7])
		{
			if(check[rn]==-1) check[right]=1;
			
			else check[right]=-1;
		}
		
		if(check[right]==0) break;
		right++;
		rn++;
		
	}
	for(j=1; j<=4; j++)
	{
		if(check[j]==1)  //시계방향 일경우    
		{
			tmp=array[j][8];
			
			for(z=8; z>=2; z--)
			{
				array[j][z]=array[j][z-1];
				
			}
			array[j][1]=tmp;
			
		}
		
		
		else if(check[j]==-1)
		{
			
			tmp=array[j][1];
			
			for(z=1; z<=7; z++)
			{
				array[j][z]=array[j][z+1];
			}
			array[j][8]=tmp;
		}
		}
	 } 
if(array[1][1]==1)  ans+=1;	
if(array[2][1]==1)	ans+=2;
if(array[3][1]==1)  ans+=4;
if(array[4][1]==1)  ans+=8;
cout<<ans;
return 0;
}
