#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;







int main()
{
//freopen("input.txt", "rt", stdin);
int k,i,j,v,e,a,b,cnt=0,nowv,set,flag;
queue < pair < int, int > > Q;
vector <int> graph[20001];
vector <int> check(20001);
scanf("%d",&k);



while(cnt!=k)
{
 cnt++;
flag=0;



scanf("%d %d",&v,&e);


	for(i=1; i<=v; i++)
	{
		while(!graph[i].empty())
		{
			graph[i].pop_back();
		}
		
		check[i]=0;
	}
      
      
      

for(i=1; i<=e; i++)
{
	scanf("%d %d",&a,&b);
	graph[a].push_back(b);
	graph[b].push_back(a);
}



for(i=1; i<=v; i++)
{
     if(check[i]==0&&flag==0)
     {
		Q.push(make_pair(i,1));
		while(!Q.empty())
		{
			nowv=Q.front().first;
			set=Q.front().second;
			Q.pop();
			if(check[nowv]==0)
			{
				check[nowv]=set;
					for(j=0; j<graph[nowv].size(); j++)
			      {
				     if(set==1)
					    {
					 	Q.push(make_pair(graph[nowv][j],2));
						 }	
						 else if(set==2)
						 {
						 	Q.push(make_pair(graph[nowv][j],1));
						 }
					}
				}
			
			
			else if(check[nowv]!=0)
			{  
				if(check[nowv]!=set)
				{
					flag=1;
					printf("NO\n");
					
					while(!Q.empty())
                      {
                    	Q.pop();
                        }
					
					
					break;
					
				}
			}
			
			
		
			}
			
		  }
		}
		if(flag==0)
			{
			
			printf("YES\n");
	}
	
	
	
}
	
	

return 0;
}
