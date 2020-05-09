#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
vector <int> list;
int ans[9];
int check[9];
int n,m;
		
	void DFS(int cnt)
	{int i;
		if(cnt==m)
		{
			for(i=1; i<=m; i++)
			{
				printf("%d ",ans[i]);
				
		    }
		printf("\n");
		}
		
		else
		{
			for(i=0; i<n; i++)
			{ 
			if(check[i]==0)
			{
                    check[i]=1;			  
					ans[++cnt]=list[i];	
					DFS(cnt);
					check[i]=0;	
					cnt--;
				}
				}
			}
		}
		
	
		
int main()
{
//freopen("input.txt", "rt", stdin);
int i,a;
scanf("%d %d",&n,&m);

 
 for(i=1; i<=n; i++)
 {
 	scanf("%d",&a);
 	list.push_back(a);
 }
 
 sort(list.begin(),list.end());


DFS(0);
return 0;
}
