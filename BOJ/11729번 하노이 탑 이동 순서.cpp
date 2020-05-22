#include<iostream>

#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;


void hanoi(int n, int a,int b, int c)
{
	if(n==1)
	printf("%d %d \n",a,c);
	
	else
	{
		hanoi(n-1,a,c,b);
		printf("%d %d \n",a,c);
		hanoi(n-1,b,a,c);
		
	}
	
	
}
	
 

	
int main()
{
//freopen("input.txt", "rt", stdin);

int n,tmp;
scanf("%d",&n);
tmp=pow(2,n)-1;
printf("%d \n",tmp);

hanoi(n,1,2,3);




return 0;
}
