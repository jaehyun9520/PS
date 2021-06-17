#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue> 
using namespace std;
int array1[101][101]={0};
int tmp[101][101]={0};
int n,m; // 행 열 
int cnt;  // 명령 횟수  


void tmpcopy()
{
	
		 for(int i=1; i<=n; i++)
     {
     	for(int j=1; j<=m; j++)
     	{
     		array1[i][j]=tmp[i][j];
		 }
	 }
}


void process1()  //상하 반전  
{
     for(int i=1; i<=n; i++)
     {
     	for(int j=1; j<=m; j++)
     	{
     		tmp[n+1-i][j]=array1[i][j];
		 }
	 }
	
	tmpcopy();

	
}


void process2()   //좌우 반전  
{
	
	 for(int i=1; i<=n; i++)
     {
     	for(int j=1; j<=m; j++)
     	{
     		tmp[i][m+1-j]=array1[i][j];
		 }
	 }
	
	tmpcopy();
	
}


void process3()   //오른쪽 90도 회전  
{
	
	 for(int i=1; i<=n; i++)
     {
     	for(int j=1; j<=m; j++)
     	{
     		tmp[j][n+1-i]=array1[i][j];
		 }
	 }
	
	int tmp=n;
	n=m;
	m=tmp;
	
	tmpcopy();
	
	
	
	
	
}





void process4()  //왼쪽 90도  
{
	
	 for(int i=1; i<=n; i++)
     {
     	for(int j=1; j<=m; j++)
     	{
     		tmp[m+1-j][i]=array1[i][j];
		 }
	 }
	
	
		int tmp=n;
	n=m;
	m=tmp;
	
	tmpcopy();
	
	
}



void process5()
{
	for(int i=1; i<=n/2; i++)  //1번 그룹 -> 2번 그룹  
	{
		for(int j=1; j<=m/2; j++)
		{
			tmp[i][j+m/2]=array1[i][j];
			
		}
	}
	
	
	for(int i=1; i<=n/2; i++)  //2번 그룹 -> 3번 그룹  
	{
		for(int j=m/2+1; j<=m; j++)
		{
			tmp[i+n/2][j]=array1[i][j];
			
		}
	}
	
	
	for(int i=n/2+1; i<=n; i++)  //3번 그룹 -> 4번 그룹  
	{
		for(int j=m/2+1; j<=m; j++)
		{
			tmp[i][j-m/2]=array1[i][j];
			
		}
	}
	
	
	for(int i=n/2+1; i<=n; i++)  //4번 그룹 -> 1번 그룹  
	{
		for(int j=1; j<=m/2; j++)
		{
			tmp[i-n/2][j]=array1[i][j];
			
		}
	}
	
	
		tmpcopy();
	
	
}



void process6()
{
	for(int i=1; i<=n/2; i++)  //1번 그룹 -> 4번 그룹  
	{
		for(int j=1; j<=m/2; j++)
		{
			tmp[i+n/2][j]=array1[i][j];
			
		}
	}
	
	
	for(int i=1; i<=n/2; i++)  //2번 그룹 -> 1번 그룹  
	{
		for(int j=m/2+1; j<=m; j++)
		{
			tmp[i][j-m/2]=array1[i][j];
			
		}
	}
	
	
	for(int i=n/2+1; i<=n; i++)  //3번 그룹-> 2번 그룹  
	{
		for(int j=m/2+1; j<=m; j++)
		{
			tmp[i-n/2][j]=array1[i][j];
			
		}
	}
	
	
	for(int i=n/2+1; i<=n; i++)  //4번 -> 3번 그룹  
	{
		for(int j=1; j<=m/2; j++)
		{
			tmp[i][j+m/2]=array1[i][j];
			
		}
	}
	
	
		tmpcopy();
	
	
}



int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,j;
cin>>n>>m>>cnt;


for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	{
		cin>>array1[i][j];
	}
}


for(i=1; i<=cnt; i++)
{
	int number;
	
	cin>>number;
	
	if(number==1)
	{
		process1();
	}
	else if(number==2)
	{
		process2();
	}
	
	else if(number==3)
	{
		process3();
	}
	
	else if(number==4)
	{
		process4();
	}
	
	else if(number==5)
	{
		process5();
	}
	
	else if(number==6)
	{
		process6();
	}
	
	
}



for(int i=1; i<=n; i++)
{
	for(int j=1; j<=m; j++)
	{
		cout<<array1[i][j]<<" ";
	}
	cout<<"\n";
}


return 0;
}
