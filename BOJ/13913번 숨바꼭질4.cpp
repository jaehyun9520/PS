#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>



using namespace std;
int time1[100001];
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
int n,k,dis,time,t=0,tmp,i;
scanf("%d %d",&n,&k);
std::fill_n(time1, 100001, -1);
Q.push(state(n,0));
visit[n]=1;
time1[n]=0;
while(!Q.empty())
{
	dis= Q.front().dis;
	time=Q.front().time;
	Q.pop();
	
	
	if(dis==k)
	{
		printf("%d \n",time);
		break;
	}
	
	if(dis+1>=0&&dis+1<=100000&&visit[dis+1]==0)
	{
		visit[dis+1]=1;
		time1[dis+1]=time+1;
	      Q.push(state(dis+1,time+1));
	  }
	   if(dis-1>=0&&dis-1<=100000&&visit[dis-1]==0)
	   {
	   	visit[dis-1]=1;
	   	time1[dis-1]=time+1;
	   Q.push(state(dis-1,time+1));
}
	   if(dis*2>=0&&dis*2<=100000&&visit[dis*2]==0)
{
	        visit[dis*2]=1;
	        time1[dis*2]=time+1;
		   Q.push(state(2*dis,time+1));
	}
}

tmp=time;
vector <int> result(time+1);
result[time]=k;

if(time==1)
{

printf("%d %d",n,k);
exit(0);
}

while(k!=n)
{
	
	if(k%2==0&&time1[k/2]==time-1)
	{
		time=time-1;
		result[time]=k/2;
		k=k/2;
	
	
	
	}
    else if(time1[k-1]==time-1)
	{
		
		time=time-1;
		result[time]=k-1;
		k=k-1;
	
	
	
		
	}
	 else if(time1[k+1]==time-1)
	{
			 
		time=time-1;
		result[time]=k+1;
		k=k+1;
	
 } 
}

for(i=0; i<=tmp; i++)
{
	printf("%d ",result[i]);
 } 


return 0;
}
