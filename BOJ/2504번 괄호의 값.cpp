#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int main()
{
//freopen("input.txt", "rt", stdin);

int i,x=1,answer=0;    
char a[31];

stack <char> s;
scanf("%s",a);


for(i=0; a[i]!='\0'; i++)
{
	
	
	if(a[i]=='('||a[i]=='[')      // ( [ 괄호가 오면 스택에 넣어주고 그 괄호의 값을 하나의 변수에 계속 곱해주기        
	{
		s.push(a[i]);
		
		if(a[i]=='(')
		{
		
		  x=x*2;
	    }
		if(a[i]=='[')
		{
		
		x=x*3;
	    }
		
	}
	
	
	
	else if(a[i]==')')
	{
		if(s.empty()||s.top()=='[')
		{
			printf("0");
			exit(0);
		}
		
		else if(a[i-1]=='('&&s.top()=='(')  // 앞의 괄호가 짝이 맞는 여는 괄호라면 여태까지 곱해진 X값을 결과값result에 더해준다. 
		{
			s.pop();
			 answer=answer+x;
			 x=x/2;
		}
		
		else if(a[i-1]!='('&&s.top()=='(')  //    앞의 괄호가 닫는괄호라면 이미 스택에 있는 괄호의 값들은 곱하는걸로  쓰였으므로  
		{                                   // result에 x값을 더해주지않고 x값만 나눠준다. 
			s.pop();
			x=x/2;
		}
		
	}
	else if(a[i]==']')
	{
		if(s.empty()||s.top()=='(')
		{
			printf("0");
			exit(0);
		}
		
		else if(a[i-1]=='['&&s.top()=='[')
		{
			s.pop();
			 answer=answer+x;
			 x=x/3;
		}
		
		else if(a[i-1]!='['&&s.top()=='[')
		{
			s.pop();
			 
			 x=x/3;
		}
		
	}
		
		
		
	}
	
	if(!s.empty())   // 배열을 다 돌았는데도 스택에 괄호가 있으면?  (({{{ 이런식으로 형태니 짝이 맞지않아 0 출력 
	{
		printf("0");
		exit(0);
		
	}
	
printf("%d",answer)	;
	
	

return 0;

}
