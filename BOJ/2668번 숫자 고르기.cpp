#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int val;
int list[100];
int check[101]={};
int map[2][101]={};
vector <int> ans;
void DFS(int x,int cnt)
{
	if(check[x]==0)
	{
		check[x]=1;
		
		    if(map[1][x]==val)
		    {
		    	
		    	for(int i=0; i<cnt; i++)
		    	{
		    		ans.push_back(list[i]);
		    	
		    		
				}
				
				    ans.push_back(x);
				    
			}
			
			else
			{    
			     list[cnt]=x;
			     DFS(map[1][x],cnt+1);	
				check[x]=0;
			}
	}
	
}


int main()
{
//freopen("input.txt", "rt", stdin);
int n,i;


scanf("%d",&n);



for(i=1; i<=n; i++)
{
	map[0][i]=i;
	
	
}





for(i=1; i<=n; i++)
{
	scanf("%d",&map[1][i]);
}
 
 
 
 
 for(i=1; i<=n; i++)
 {
 	if(check[i]==0)
 	{
 		check[i]=1;
 		
 		 
 		 if(i==map[1][i])
 		 {
 		 	ans.push_back(i);
		  }
		  
		  else{
		  	val=i;
		  	         list[0]=i;
	            DFS(map[1][i],1);
		  }
		          
		  
	 }
 }
 
 
 printf("%d\n",ans.size());
 
 sort(ans.begin(),ans.end());
 for(i=0; i<ans.size(); i++)
 {
 	printf("%d\n",ans[i]);
 	
 }
return 0;
}
