#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue> 
using namespace std;
int n; // 손동작 개수 
int k; // 우승을 위해 필요한 승수  

int score[4]={0};  // 1은 지우 2는 경희 3은 민호 
int list[10][10]={0}; // 상성표  2:이김 1:비김 0:짐  
int f[4][21]={0}; //  경희(2)와 민호(3)의 20경기 낼 손동작  
int cnt[4]={0};// 지우 경희 민호의 경기 참여 횟수  
int check[10]={0};  //  손동작을 앞의 경기에서 사용했는지 확인 
                         
                         
void DFS(int player1 , int player2)   // *지우가 포함된 경우  지우는 항상 player1으로 자리에만 오도록 해놓음 
{
	cnt[player1]++;  cnt[player2]++;  //참여횟수 1씩 증가  
	
	if(player1==1) // 지우가 참여한 경기 
	{

		for(int i=1; i<=n; i++) // 사용할수있는 손동작의 개수 
		{
			//중 하나 선택 
			if(check[i]==0) //  한번도 사용한 안한 손동작  
			{
				check[i]=1; //사용  
				
			int result=list[i][f[player2][cnt[player2]]];   //2 : 이김 1: 비김  0: 짐  
				//i는 지우가선택한 손동작 
				// 뒤에는 현재 친구가 해당 경기에서 낸 손동작 
				
				if(result==2) // 이겼으면?
				{
					score[player1]++;
					
					if(score[player1]==k) // 승리횟수를 지우가 달성했다면?
					{
					cout<<"1"; 
					exit(0);
				    }
				    
					if(player2==2) 
					{	
					DFS(1,3);  
				    }
				    
				    else{
				    DFS(1,2);
				    	
					}
					score[player1]--;
					
				 }
				 
				 
				else if(result==0||result==1) // 지우가 졌거나 비긴 경우 
				{
					score[player2]++;
					
					if(score[player2]!=k) // 경희나 민호가 승수를 다 채운경우 더 들어갈 필요x 
					{
					DFS(2,3);   
				    }
					score[player2]--; 
				 } 
				 
				check[i]=0; 
			
		}
			 } 
			
			
		}
		
	


   
   
   else  //지우가 참여하지 않은 경기  
   {
   	     int result=list[f[player1][cnt[player1]]][f[player2][cnt[player2]]];
   	      
   	      
   	      if(result==2)  // 첫번째 선수가 이겼으면?
			 {
			 	score[player1]++; // 승점 1점 추가
				 
				 if(score[player1]!=k) // 승수를 다 채운경우 진행x 
			 	{
			 		DFS(1,player1);
			 		
			 		
				 }
			 	score[player1]--; 
			 	
			  }
			  
		else if(result==0) // 첫번째 선수가 졌으면?
		{
			score[player2]++; //승점 1점 추가  
			
			 if(score[player2]!=k) // 승수를 다 채운경우 진행x 
			 	{
			 		DFS(1,player2);
			 		
			 		
				 }
			 	score[player2]--; 
			
			
			   }	   
			   
			   
			else  //마지막 비긴 경우
			{
				score[max(player1,player2)]++;   // 더 큰사람이 승리  
				
			
				if(score[max(player1,player2)]!=k) // 승수를 다 채운경우 진행x  
			 	{
			 		DFS(1,max(player1,player2));
			 		
			 		
				 }
			 	score[max(player1,player2)]--; 
						   }	   			
			}   			   
	cnt[player1]--;  
	cnt[player2]--;  //참여횟수 -1  	
 } 

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,j;
cin>>n>>k;

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		cin>>list[i][j];  
	}
}
//상성표 입력 

for(i=1; i<=20; i++)
{
	cin>>f[2][i]; //경희가 낼 손동작 
}

for(i=1; i<=20; i++)
{
	cin>>f[3][i]; //민호가 낼 손동작 
}
 

DFS(1,2); // 맨 첫 경기는 무조건 지우와 경희가 하게된다  


cout<<0;
return 0;
}
