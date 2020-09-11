#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int s[100001]={0};
int group[100001]={0}; // 그룹에 속해있는지  
int check[100001]={0}; // 
vector <int> use; 
queue <int> Q;
int main()
{
//freopen("input.txt", "rt", stdin);
int t,n,i,j,now,cnt;
scanf("%d",&t); 
for(i=1; i<=t; i++)
{
	scanf("%d",&n);
	 
	for(j=1; j<=n; j++)
	{
	
		scanf("%d",&s[j]);   
		group[j]=0;
	
	}
	
	cnt=0;
	

	
	

	for(j=1; j<=n; j++)
	{
	   if(group[j]==0)    // 어느 팀에도 속하지 않은 경우  
		{
		   Q.push(j);
		   
		   
		   while(!Q.empty())
		   {
		   	   now=Q.front();  // 현재 학생 번호  
		   	   Q.pop();
		   	   
		   	   if(check[now]==0&&group[now]==0)  // 팀  만들기를 한적이 없는경우  
		   	   {
		   	   	    use.push_back(now);  
		   	   	   check[now]=1;     
		   	   	   
		   	   	   Q.push(s[now]);
		   	   	   
		   	   	   
				  }
				  
				  else if(check[now]==1)   // 같은 학생번호가 또 나온경우 팀이 만들어진것  
				  {
				  	while(1)
				  	{
				  		if(now==use.back())  // 중복된 학생번호가 다시 나왔으면 종료  
				  		{
				  			group[now]=1; // 1은 팀에 속한것으로 표시  
				  			check[now]=0; // 
				  			use.pop_back();
				  			break;
						  }
						  
						  else if(now!=use.back()){ // 앞의 학생들은 같은 팀 
						  	   group[use.back()]=1; // 팀에 속했다고 1 표시  
						  	   check[use.back()]=0;
						  	   use.pop_back();
						  	
						  }
					  }
				  }
		   }
		   
		   
		   while(!use.empty())  // 팀을 만들지 못한 학생들  
		   {
		   	     cnt++;// 팀을 만들지 못한 학생 수 카운트  
		   	     
		   	     group[use.back()]=-1; 
		   	     check[use.back()]=0;
		   	     use.pop_back();
		   }
		}
	
}
printf("%d\n",cnt);

}

return 0;

}
