#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int map[65][65]={0};


void func(int n, int x, int y)   
{
	int val,flag=0;
	  val=map[x][y];
	if(n==1) 
         {
         	printf("%d",map[x][y]);
		 }
     
     else{
     	
     	for(int i=x; i<n+x; i++)     //  영상이 모두 같은 수로 이루어져있는지  
     	{
     		for(int j=y; j<n+y; j++)
     		{
     			if(val!=map[i][j])
     			{
     				flag=1;
     				break;
				 }
			 }
		 }
		 
		 if(flag==1)  // 아니라면 4등분 
		 {
		 	printf("(");
		 	
		 	func(n/2,x,y);  // 왼쪽 위  
		 	func(n/2,x,y+n/2);   //오른쪽 위 
		 	func(n/2,x+n/2,y);   // 왼쪽 아래  
		 	func(n/2,x+n/2,y+n/2);  // 오른쪽 아래  
		 	
		 	printf(")");
		 }
		 else if(flag==0)
		 {
		 	printf("%d",val);
		 }
	 }

   
}


int main()
{
//freopen("input.txt", "rt", stdin);
int n,i,j;
scanf("%d",&n);  
char a[65];

for(i=1; i<=n; i++)
{
	scanf("%s",a);
	for(j=1; j<=n; j++)
	{
		map[i][j]=a[j-1]-48;
		
	}
	
}

func(n,1,1); 

return 0;


}
