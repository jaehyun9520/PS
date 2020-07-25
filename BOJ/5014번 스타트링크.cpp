#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;



int main()
{
//freopen("input.txt", "rt", stdin);
int f,s,g,u,d,now,next,count;
scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
int check[f+1]={0};

queue < pair <  int , int > > Q;
check[s]=1;

Q.push(make_pair(s,0));

if(s==g)
{
	printf("0");
	exit(0);
}

while(!Q.empty())
{
	now=Q.front().first;
	count=Q.front().second;
	Q.pop();
	
	next=now+u;
	if(next==g)
	{
		printf("%d",count+1);
		exit(0);
	}
	
	else if(next>=1&&next<=f)
	{
		if(check[next]==0)
		{
			check[next]=1;
			Q.push(make_pair(next,count+1));
		}
	}
	
	
	next=now-d;
		if(next==g)
	{
		printf("%d",count+1);
		exit(0);
	}
	
	else if(next>=1&&next<=f)
	{
		if(check[next]==0)
		{
			check[next]=1;
			Q.push(make_pair(next,count+1));
		}
	}
	
	
}

printf("use the stairs");
return 0;
}
