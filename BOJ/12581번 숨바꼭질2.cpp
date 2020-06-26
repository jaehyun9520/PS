#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>



using namespace std;

vector < pair < int, int > > visit(100001);





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

int n,k,time,dis,first=0,cnt=0,check;

scanf("%d %d",&n,&k);

Q.push(state(n,0));
visit[n].first=1;   //first가 방문 체크  second가 몇초걸렸는지 
visit[n].second=0;
if(n==k)
{
	printf("0\n");
	printf("1");
	exit(0);
}

while(!Q.empty())
{
	dis=Q.front().dis;
	time=Q.front().time;
	
	Q.pop();
	if(first==0&&dis==k)
	{
		first=time;
		printf("%d \n",time);
		cnt++;
		
	}
	
	else if(first==time&&dis==k)
	{
		cnt++;
	}
	
	
	
	else 
	{
		if(dis+1>=0&&dis+1<=100000)
		{
			if(visit[dis+1].first==0)
			{
				visit[dis+1].first=1;
				visit[dis+1].second=time+1;
				Q.push(state(dis+1,time+1));
			}
			
			else if(visit[dis+1].first==1)
			  {
			  	if(visit[dis+1].second==time+1)
			  	{
			  		Q.push(state(dis+1,time+1));
				  }
			  }
		}
		
		
		if(dis-1>=0&&dis-1<=100000)
		{
			if(visit[dis-1].first==0)
			{
				visit[dis-1].first=1;
				visit[dis-1].second=time+1;
				Q.push(state(dis-1,time+1));
			}
			else if(visit[dis-1].first==1)
			{
				if(visit[dis-1].second==time+1)
				{
					Q.push(state(dis-1,time+1));
				}
			}
			
		}
		
		if(dis*2>=0&&dis*2<=100000)
		{
			if(visit[dis*2].first==0)
			{
				visit[dis*2].first=1;
				visit[dis*2].second=time+1;
				Q.push(state(dis*2,time+1));
			}
			else if(visit[dis*2].first==1)
			{
				if(visit[dis*2].second==time+1)
				{
					Q.push(state(dis*2,time+1));
				}
			}
			
		}
		
	}
	
	
}

printf("%d",cnt);
return 0;
}
