#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
int map[128][128]={0};
int ans[2]={0};
void recur(int n, int x , int y)
{

	int color=-1; int flag=0;
	
	for(int i=x; i<n+x; i++)
	{
		for(int j=y; j<n+y; j++)
		{
			if(color==-1) color=map[i][j];
			
			else if(color!=map[i][j]){
				flag=1;
				break;
			}
			
		}
	}
	
	if(flag==0) {
	
		  ans[color]++;
	}
	
	
	else{
		
		recur(n/2,x,y);
		recur(n/2,x,y+n/2);
		recur(n/2,x+n/2,y);
		recur(n/2,x+n/2,y+n/2);
		
		
	}
	
	
}

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n;
cin>>n;


for(int i=0; i<n; i++)
{
	for(int j=0; j<n; j++)
	{
		cin>>map[i][j];
	}
}

recur(n,0,0);

for(int i=0; i<=1; i++)
{
	cout<<ans[i]<<"\n";
}
return 0;
}
