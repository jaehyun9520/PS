#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int record[7][4]={0};  // [A B C D E F][승 무 패] 
                       // [1 2 3 4 5 6][1  2  3]
                       
int check[7][7]={0};  // [뽑는국가][뽑히는국가]
 
int flag=0; // 가능한 경우라면 1로 변환  

void DFS(int now,int cnt)  //now 뽑는나라  cnt 뽑아야할 횟수  
{

	if(now==5&&cnt==0)  // E가 F와 경기를 했다면? 가능한 결과  
	{
		flag=1;
	}
	
	
else if(cnt>0)
	{
	
	for(int i=1; i<=3; i++)  // 1:승  2:무 3:패  
	{
		if(record[now][i]>0)  
		{
			int x=0;        // 승(1)이라면 뽑는국가의 패(3)가 있는지 확인  
			if(i==1) x=3;
			else if(i==2) x=2;
			else if(i==3)  x=1;
			
		       for(int j=now+1; j<=6; j++) //자신보다 앞의 나라들하고는 이미 경기함 
			    {                      
			   	     if(check[now][j]==0&&record[j][x]>0&&flag==0)
			   	     {
			   	           check[now][j]=1;
						   record[j][x]--;
					       record[now][i]--;  
						   
						   DFS(now,cnt-1);
						   check[now][j]=0;
						   record[j][x]++;
						   record[now][i]++;	   	
			   	     	
					 }
			   	
			    }	
			break;
		 } 
		
		
	}
}

else if(cnt==0)
{
	DFS(now+1,6-(now+1));  //1(A)번 국가가 5개의 국가를 다 뽑았으면  
}                          //2(B)번 국가가 4개의 국가를 뽑아야함  
		                                    
}

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,j;

for(i=1; i<=4; i++)
{
	int total=0; flag=0;
	for(j=1; j<=6; j++)
	{
		cin>>record[j][1]>>record[j][2]>>record[j][3];
		total=total+record[j][1]+record[j][2]+record[j][3];
	} 
	if(total==30)
{
	  
     DFS(1,5);   

 }
 	if(flag==0) 
 	{
 		cout<<"0 "; 
	 }
	else{
		cout<<"1 ";   
	} 
	
	
	
}


return 0;
}
