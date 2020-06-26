#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>



using namespace std;

int visit[100001]={0};
struct state{
	
	int dis;
	int time;
	
	state(int a, int b)
	{
		dis=a;
		time=b;
	}
};

queue <state> Q;

int main()
{
//freopen("input.txt", "rt", stdin);
int n,k,dis,time,t=0;
scanf("%d %d",&n,&k);

Q.push(state(n,0));
visit[n]=1;
while(!Q.empty())
{
	dis= Q.front().dis;
	time=Q.front().time;
	Q.pop();
	
	if(dis==k)
	{
		printf("%d",time);
		exit(0);
	}
	
	if(dis+1>=0&&dis+1<=100000&&visit[dis+1]==0)
	{
		visit[dis+1]=1;
	      Q.push(state(dis+1,time+1));
	  }
	   if(dis-1>=0&&dis-1<=100000&&visit[dis-1]==0)
	   {
	   	visit[dis-1]=1;
	   Q.push(state(dis-1,time+1));
}
	   if(dis*2>=0&&dis*2<=100000&&visit[dis*2]==0)
{
	        visit[dis*2]=1;
		   Q.push(state(2*dis,time+1));
	}
}

return 0;
}
