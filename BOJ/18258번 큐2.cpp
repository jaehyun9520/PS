#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;

int n;
int q[2000000];
int f=0,r=0;


void push(int x)
{
	q[r++]=x;
}


void pop()
{
	if(f!=r)
	printf("%d\n",q[f++]);
	
	else
	{
		printf("-1\n");
	}
}



void size()
{
	printf("%d\n",r-f);
}


void empty()
{
	if(f!=r)
	{
		printf("0\n");
	}
	else 
	{
		printf("1\n");
	}
}


void front()
{
	if(f==r)
	{
		printf("-1\n");
	}
	
	else
	{
		printf("%d\n",q[f]);
	}
}


void back()
{
	if(f==r)
	{
		printf("-1\n");
	}
	
	else
	{
		printf("%d\n",q[r-1]);
	}
}

int main()
{
//freopen("input.txt", "rt", stdin);
 int i,val;
 char a[8];
 
 scanf("%d",&n);
 
  
  for(i=1; i<=n; i++)
  {
  	scanf("%s",a);
  	
  	if(!strcmp(a,"push"))
	      {
	      	 scanf("%d",&val);
	      	 push(val);
	      	
	      }
	      
	      
	    else if(!strcmp(a,"front"))
	      {
	      	front();
		  }
		  
		  
		else  if(!strcmp(a,"pop"))
		  {
		  	pop();
		  }
		  
		  
		 else  if(!strcmp(a,"size"))
		  {
		  	size();
		  }
		  
		else  if(!strcmp(a,"empty"))
		  {
		  	empty();
		  }
		  
		  
		  else if(!strcmp(a,"back"))
		  {
		  	back();
		  }
	      
  }
  
return 0;
}
