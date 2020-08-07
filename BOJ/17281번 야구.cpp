#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int n,result=0,out=0;

int runner[4]={0};  //  1루 2루 3루에 주자가 나가있는지  
int t[10]={0};   // 1번~9번타자가 몇번 선수로 구성되있는지  
int check[10]={0};  // 중복순열을 방지하기 위해 이미 타자로 뽑힌 선수는 못뽑도록  
int map[51][10]={0}; // 각 선수가 각 이닝에서 얻는 결과 저장  


void play(int x)  // 야구게임 시뮬레이션   x는 몇 이닝으로 진행되는지  
{
	int i,j;
	 
	int number=1; //1번 타자부터 시작  
	int k=0;   
	int score=0;  

	for(i=1; i<=x; i++)   //1이닝부터 x이닝까지 
	{
	   out=0;   //각 이닝이 시작할때마다 out 횟수 초기화 
	   for(j=1; j<=3; j++)  // 각 이닝 시작할때마다 주자 초기화  
	   {
	   	runner[j]=0;  
	   }
	   
	    
	   while(1)   
	{

		   k=map[i][t[number]];  // 지금 나가있는 타자가 1~9번 선수 중 몇번 선수인지 그리고 지금 현재 이닝에 어떤 결과를 얻는지 저장  

		    if(k==0)  // 아웃이면  
		      {
		      	number++;   // 다음 번호의 타자  
		      	if(number>9)  // 9번 타자까지 끝나면 다시 1번타자  
		      	{
		      		number=1;
				  }
		      	out++;  // 아웃 횟수 추가  
		      	if(out==3)  // 3아웃이면 이닝 종료  
		      	break;
		    
			  }
			  
			  else if(k!=0)   // 아웃이 아니라 1루 2루 3루 홈런 이면? 
			  {
			  	number++;   
			  	if(number>9)
			  	{
			  		number=1;
				  }
			  	for(j=3; j>=1; j--)   // 3루부터 1루까지 주자가 나가있는지? 
			  	{
			  		if(runner[j]==1)
			  		{
			  			if(j+k>=4)   // 3루에 주자가 있는데   1루타를 쳤으면 3루에 있는 주자는 홈으로 오고 득점 +1        
			  			{
			  				runner[j]=0;
			  				score++;
						  }
						  
						else if(j+k<=3)  // 1루에 주자가 나가있는데 타자가 1루타를 쳤을경우   1루에 있는 주자는 2루로  타자는 1루로  
						{
							runner[j+k]=1;
							runner[j]=0;
						  }  
					  }
				  }
				if(k==4)   // 홈런일 경우  타자도 홈으로 들어가니 득점  
				{
					score++;
				  }
				else if(k<=3)  // 1루타~3루타 중 하나인 경우 타자를 옮김  
				{
					runner[k]=1;
				  }  
				    
				  
			  	
			  	
	           }   	
	}	
 } 
 
 if(result<score)
 {
 	result=score;
 }
}

void team(int number)   // 현재 타자로 뽑힌 선수 수    9명이 다 뽑히면 게임 시작  
{
	int i;
	if(number==9)  
	{
		
				for(int j=1; j<=9; j++)
		{
			printf("%d",t[j]);
		}
		
		printf("\n");
		play(n);   
	}
	
	else if(number==3)      //  4번타자는 1번 고정  
	{
		team(number+1);
	}
	
	
	else 
	{
		for(i=2; i<=9; i++)   // 선수들의 타순 정하기 (순열)  
		{
			if(check[i]==0)
			{
				check[i]=1;
				t[number+1]=i;
				
		
				
				team(number+1);
				check[i]=0;
			}
		}
		
	 } 
	
	
 } 

int main()
{
//freopen("input.txt", "rt", stdin);
int i,j;

scanf("%d",&n);

for(i=1; i<=n; i++)
{
	for(j=1; j<=9; j++)
	{
		scanf("%d",&map[i][j]);
	}
}
t[4]=1;


for(i=2; i<=9; i++)  // 2~9번 선수 타순을 순열로 짜기  
{
	check[i]=1;
	t[1]=i;
	team(1);  
	check[i]=0;
}


printf("%d",result);
return 0;

}

