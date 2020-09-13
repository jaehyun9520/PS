#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
int x,y,a,b;

char map[798][398];

void func(int n)
{

	if(n==1)
	{
		
		map[x][y]='*';

	}
	
	else if(n>1) {
		
		func(n-1);

		if(n==2)  // 2일때만 나타나는 위로 2칸 올라가기  
		{
			
			for(int i=1; i<=2; i++)  
			{
				
				map[--x][y]='*';
				
			}

		}
		
		for(int i=1; i<=2; i++)   // 오른쪽 두칸 별 찍기  
		{
			map[x][++y]='*';
	
		}

		for(int i=1; i<=4*(n-1); i++)     // N의 크기에 따라 밑으로 내려가며 별 찍기  
		{
			
			map[++x][y]='*';
		
		}
	
		for(int i=1; i<=4*(n-1); i++)   // 왼쪽 이동하며 별 찍기  
		{
			map[x][--y]='*';
			
		}

		for(int i=1; i<=4*n-2; i++)  // 위로 이동하며 별 찍기  
		{
			
			map[--x][y]='*';
		}
	
		for(int i=1; i<=4*(n-1); i++)  // 오른쪽 이동하며 별 찍기  
		{
			map[x][++y]='*';
		}		
	}
}


int main()
{
//freopen("input.txt", "rt", stdin);

int n,i,j;
scanf("%d",&n);

a=4*(n-1)+3;   // N의 값에 따른 출력배열의 세로크기  
b=4*(n-1)+1;   // N의 값에 따른 출력배열의 가로크기  

for(i=1; i<=a; i++)
{
	for(j=1; j<=b; j++)
	{
		map[i][j]=' ';  // 공백으로 초기화  
	}
}

// N의 크기에 따른 시작점의 위치 계산 
x=2*n+1;    
y=2*n-1;


if(n==1)  // N이 1일때는 바로 출력  
{
	printf("*");
	
}

else
{
	
	func(n);  
	
			for(i=1; i<=a; i++)
{
	for(j=1; j<=b; j++)
	{
		if(i==2)     // 2번째 줄의 공백을 제거  
		{
			if(map[i][j]=='*')
			printf("%c",map[i][j]);
		}
		
		
		else
		printf("%c",map[i][j]);
	}

	if(i!=a&&j!=b)
	printf("\n");
}	
	
}

return 0;

}
