#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int val=5000;
int front=val;
int rear=val;

int deque[100001];



void push_front(int x)
{
	deque[--front]=x;
	
}

void push_back(int x)
{
	deque[rear++]=x;
}

void pop_front()
{
	if((rear-front)>=1)
	{
	
	printf("%d\n",deque[front++]);
	
}
else if((rear-front)==0)
{
	printf("-1\n");
}

}


void pop_back()
{
	if((rear-front)>=1)
	{
	
	printf("%d\n",deque[--rear]);
}

else if((rear-front)==0)
{
	printf("-1\n");
}


}


void size()
{
	printf("%d\n",rear-front);
}

void empty()
{
	if((rear-front)>=1)
	{
	
	printf("0\n");
}

else if((rear-front)==0)
{
	printf("1\n");
}
}


void front1()
{
		if((rear-front)>=1)
	{
	
              printf("%d\n",deque[front]);
}

else {
	printf("-1\n");
}
}



void back()
{
		if((rear-front)>=1)
	{
	
	printf("%d\n",deque[rear-1]);
}

else{
	printf("-1\n");
}
}



int main()
{
//freopen("input.txt", "rt", stdin);
int n,i,v;
char a[10];
scanf("%d",&n);
	
	for(i=1; i<=n; i++)
	{
		scanf("%s",a);
		
		if(!strcmp(a,"push_back"))
		{
			scanf("%d",&v);
			push_back(v);
		}
		
		else if(!strcmp(a,"push_front"))
		{
			scanf("%d",&v);
			push_front(v);
		}
		
		
		else if(!strcmp(a,"pop_front"))
		{
			pop_front();
		}
		
		else if(!strcmp(a,"pop_back"))
		{
			pop_back();
		}
		
		else if(!strcmp(a,"size"))
		{
			size();
		}
		
		else if(!strcmp(a,"empty"))
		{
			empty();
		}
		
		else if(!strcmp(a,"front"))
		{
			front1();
		}
		
		else if(!strcmp(a,"back"))
		{
			back();
		}
	}

}
