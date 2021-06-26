#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue> 
using namespace std;
int n; // �յ��� ���� 
int k; // ����� ���� �ʿ��� �¼�  

int score[4]={0};  // 1�� ���� 2�� ���� 3�� ��ȣ 
int list[10][10]={0}; // ��ǥ  2:�̱� 1:��� 0:��  
int f[4][21]={0}; //  ����(2)�� ��ȣ(3)�� 20��� �� �յ���  
int cnt[4]={0};// ���� ���� ��ȣ�� ��� ���� Ƚ��  
int check[10]={0};  //  �յ����� ���� ��⿡�� ����ߴ��� Ȯ�� 
                         
                         
void DFS(int player1 , int player2)   // *���찡 ���Ե� ���  ����� �׻� player1���� �ڸ����� ������ �س��� 
{
	cnt[player1]++;  cnt[player2]++;  //����Ƚ�� 1�� ����  
	
	if(player1==1) // ���찡 ������ ��� 
	{

		for(int i=1; i<=n; i++) // ����Ҽ��ִ� �յ����� ���� 
		{
			//�� �ϳ� ���� 
			if(check[i]==0) //  �ѹ��� ����� ���� �յ���  
			{
				check[i]=1; //���  
				
			int result=list[i][f[player2][cnt[player2]]];   //2 : �̱� 1: ���  0: ��  
				//i�� ���찡������ �յ��� 
				// �ڿ��� ���� ģ���� �ش� ��⿡�� �� �յ��� 
				
				if(result==2) // �̰�����?
				{
					score[player1]++;
					
					if(score[player1]==k) // �¸�Ƚ���� ���찡 �޼��ߴٸ�?
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
				 
				 
				else if(result==0||result==1) // ���찡 ���ų� ��� ��� 
				{
					score[player2]++;
					
					if(score[player2]!=k) // ���� ��ȣ�� �¼��� �� ä���� �� �� �ʿ�x 
					{
					DFS(2,3);   
				    }
					score[player2]--; 
				 } 
				 
				check[i]=0; 
			
		}
			 } 
			
			
		}
		
	


   
   
   else  //���찡 �������� ���� ���  
   {
   	     int result=list[f[player1][cnt[player1]]][f[player2][cnt[player2]]];
   	      
   	      
   	      if(result==2)  // ù��° ������ �̰�����?
			 {
			 	score[player1]++; // ���� 1�� �߰�
				 
				 if(score[player1]!=k) // �¼��� �� ä���� ����x 
			 	{
			 		DFS(1,player1);
			 		
			 		
				 }
			 	score[player1]--; 
			 	
			  }
			  
		else if(result==0) // ù��° ������ ������?
		{
			score[player2]++; //���� 1�� �߰�  
			
			 if(score[player2]!=k) // �¼��� �� ä���� ����x 
			 	{
			 		DFS(1,player2);
			 		
			 		
				 }
			 	score[player2]--; 
			
			
			   }	   
			   
			   
			else  //������ ��� ���
			{
				score[max(player1,player2)]++;   // �� ū����� �¸�  
				
			
				if(score[max(player1,player2)]!=k) // �¼��� �� ä���� ����x  
			 	{
			 		DFS(1,max(player1,player2));
			 		
			 		
				 }
			 	score[max(player1,player2)]--; 
						   }	   			
			}   			   
	cnt[player1]--;  
	cnt[player2]--;  //����Ƚ�� -1  	
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
//��ǥ �Է� 

for(i=1; i<=20; i++)
{
	cin>>f[2][i]; //���� �� �յ��� 
}

for(i=1; i<=20; i++)
{
	cin>>f[3][i]; //��ȣ�� �� �յ��� 
}
 

DFS(1,2); // �� ù ���� ������ ����� ���� �ϰԵȴ�  


cout<<0;
return 0;
}
