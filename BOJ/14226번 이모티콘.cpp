#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int check[1001][1001]={0};
struct state{
	int c;
	int h;
	int cnt;
	
	state(int a, int b , int d)
	{
		c=a;
		h=b;
		cnt=d;
	}
};


int main()
{
//freopen("input.txt", "rt", stdin);
int s,h,c,cc,hh,cnt;
scanf("%d",&s);

queue <state> Q;

Q.push(state(0,1,0));


while(!Q.empty())
{
	c=Q.front().c;
	h=Q.front().h;
	cnt=Q.front().cnt;
	Q.pop();
	
	
	cc=h;
	if(cc>=0&&cc<=s&&h>=0&&h<=s)
	{
		if(check[cc][h]==0)
		{
		
		check[cc][h]=1;
		Q.push(state(cc,h,cnt+1));		
	}
	}
	
	
	if(c>0)
	{
		hh=h+c;
		if(c>=0&&cc<=s&&hh>=0&&h<=s)
		{
			if(check[c][hh]==0)
{
						check[c][hh]=1;
			Q.push(state(c,hh,cnt+1));
		}
			
			if(hh==s)
			{
				printf("%d",cnt+1);
				exit(0);
			}
		}
	}
	
	if(h>0)
	{
		hh=h-1;
		if(c>=0&&c<=s&&hh>=0&&h<=s)
		{
			if(check[c][hh]==0)
			{
			
			check[c][hh]=1;
			Q.push(state(c,hh,cnt+1));
		}
			if(hh==s)
			{
				printf("%d",cnt+1);
				exit(0);
			}
		}
	}
	
	
	
	
	
	
}

return 0;
}
