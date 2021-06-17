#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue> 
using namespace std;
int array1[101][101]={0};
int tmp[101][101]={0};
int n,m; // �� �� 
int cnt;  // ��� Ƚ��  


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


void process1()  //���� ����  
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


void process2()   //�¿� ����  
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


void process3()   //������ 90�� ȸ��  
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





void process4()  //���� 90��  
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
	for(int i=1; i<=n/2; i++)  //1�� �׷� -> 2�� �׷�  
	{
		for(int j=1; j<=m/2; j++)
		{
			tmp[i][j+m/2]=array1[i][j];
			
		}
	}
	
	
	for(int i=1; i<=n/2; i++)  //2�� �׷� -> 3�� �׷�  
	{
		for(int j=m/2+1; j<=m; j++)
		{
			tmp[i+n/2][j]=array1[i][j];
			
		}
	}
	
	
	for(int i=n/2+1; i<=n; i++)  //3�� �׷� -> 4�� �׷�  
	{
		for(int j=m/2+1; j<=m; j++)
		{
			tmp[i][j-m/2]=array1[i][j];
			
		}
	}
	
	
	for(int i=n/2+1; i<=n; i++)  //4�� �׷� -> 1�� �׷�  
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
	for(int i=1; i<=n/2; i++)  //1�� �׷� -> 4�� �׷�  
	{
		for(int j=1; j<=m/2; j++)
		{
			tmp[i+n/2][j]=array1[i][j];
			
		}
	}
	
	
	for(int i=1; i<=n/2; i++)  //2�� �׷� -> 1�� �׷�  
	{
		for(int j=m/2+1; j<=m; j++)
		{
			tmp[i][j-m/2]=array1[i][j];
			
		}
	}
	
	
	for(int i=n/2+1; i<=n; i++)  //3�� �׷�-> 2�� �׷�  
	{
		for(int j=m/2+1; j<=m; j++)
		{
			tmp[i-n/2][j]=array1[i][j];
			
		}
	}
	
	
	for(int i=n/2+1; i<=n; i++)  //4�� -> 3�� �׷�  
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
