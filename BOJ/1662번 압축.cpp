#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;
int main()
{	
//freopen("input.txt", "rt", stdin);
stack <int> s;   
char a[51];
int i,cnt=0,val=0,ans=0;
scanf("%s",a);
for(i=0; a[i]!='\0'; i++)
{
	if(a[i]>='0'&&a[i]<='9')
	{
		cnt++;   // 숫자 카운트  
}
if(a[i]=='(')    
{
	if(cnt-1>0)
	{
		s.push(cnt-1);  //(바로앞의 숫자는 곱해줘야하는 수이니 -1 해서 넣어주기  
	}
	cnt=0;
	s.push(-(a[i-1]-48));  
	s.push(0);   //  '('를 0으로 취급  
		
}

if(a[i]==')')             
{
	val=cnt;
	while(1)
	{

		if(s.top()==0)  // ( 이라면 빠져나오기  
		{
			
			s.pop();
			break;
		}
		
		
			else if(s.top()>0)    // 가로안 문자열의 개수 더해주기  
			{
				
				val=s.top()+val;
				
				s.pop();
			 } 
		}
		cnt=0;
		val=val*-(s.top());  // 총합 * 곱해줘야하는 정수  
		
		s.pop();
		if(val>0) s.push(val);  //스택에 넣어주기  
		
	}
	
}

while(!s.empty()) 
{
	ans=ans+s.top();
	s.pop();
}

printf("%d",ans+cnt);  // 3(14)333   333이 카운트는 되나 스택에 안들어가고 끝나서 따로 더해주기.. 
return 0;
}
