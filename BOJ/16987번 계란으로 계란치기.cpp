#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,ans=0;
void DFS(int s, int d[], int w[])  // s: 현재 들고있는 계란의 번호 , 매개변수로 내구도와 무게배열을 넘겨받음  
{
	int flag=0,tmp=0,i,j,cnt=0; 
	int d1[n+1];
	int w1[n+1];
	
	for(i=1; i<=n; i++)
	{
		d1[i]=d[i];   // 복사본에 값 저장  
		w1[i]=w[i];
	
		
	}

	
	for(i=1; i<=n; i++)
	{
		
		if(i!=s&&d1[i]>=1)  // 현재들고있는 계란의 번호를 제외하고 내구도가 남아있는 계란을 선택  
		{
		   flag=1;	
		   d1[s]=d1[s]-w1[i];   // 계란으로 계란 깨기  
		   d1[i]=d1[i]-w1[s];
			
			tmp=s+1;     
			
			while(1)   
			{
				if(d1[tmp]>=1&&tmp<=n)   // 가장 마지막이 n번 계란이니 n번이하이면서 내구도가 있으면 들수있다. 
				{
					DFS(tmp,d1,w1);  // 가능한 경우를 확인  
					break;
				}
				
				else{
					
					if(tmp==n+1)   // n+1이면 오른쪽 끝까지 온거니 깨진 계란이 몇개있는지 확인 후 현재값보다 더많으면 갱신  
					{   cnt=0;
				     	for(j=1; j<=n; j++)
				     	{
				     		if(d1[j]<=0) cnt++;
						 }
						 
						 if(ans<cnt)  ans=cnt;
					   break;
				}
				
				tmp++;  
				}
	
				
			}
			 
		 d1[s]=d1[s]+w1[i];   // 다른 경우도 확인해야하니 이전상태로 되돌리기  
		   d1[i]=d1[i]+w1[s];	
		}
	}
	
	if(flag==0)   // 계란을 든 상태에서 한번도 다른 계란을 치지 못한경우 더이상 진행할수없으니 몇개가 깨져있는지 확인  
	{
		cnt=0;
				     	for(j=1; j<=n; j++)
				     	{
				     		if(d1[j]<=0) cnt++;
						 }
						 
						 if(ans<cnt)  ans=cnt;
					
		
	}
	
	
}


int main()
{
//freopen("input.txt", "rt", stdin);
int i,a,b;
scanf("%d",&n);

int d[n+1];    // 계란의 내구도를 나타내는 배열 
int w[n+1];    // 계란의 무게를 나타내는 배열  
for(i=1; i<=n; i++) 
{
	scanf("%d %d",&a,&b);
	d[i]=a;  
	w[i]=b; 
}

DFS(1,d,w);  
printf("%d",ans);
return 0;
}
