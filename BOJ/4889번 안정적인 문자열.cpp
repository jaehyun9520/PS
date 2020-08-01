#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;



int main()
{
//freopen("input.txt", "rt", stdin);
char a[2001];
int cnt=0,i,c;
stack <char> s;

while(1)
{
	
	c=0;   // 문자열을 안정적으로 바꾸는데 필요한 최소한의 연산자 수  
	cnt++;  // 테스트 케이스 번호  
	scanf("%s",a);
	
	if(a[0]=='-')  // - 나오면 종료  
	{
		exit(0);
	}
	
	else
	{
	   for(i=0; a[i]!='\0'; i++)
	   {
	   	    if(a[i]=='{')  
	   	    {
	   	         s.push(a[i]);	
	   	    
			   }
			   
			   else if(a[i]=='}')
			   {
			   	   if(s.size()==0)   // 스택이 비어있는데 } 나오면 바꿔주기  
			   	   {
			   	   	     c++;
			   	   	    s.push('{');
					  }
					 
					else 
					{
						s.pop();  // 스택이 비어있지 않은 상태라면 무조건 { 모양만 들어있을테니 바로 pop 
					  }  
					  
			   	
			   }
		   }
		   
		   while(!s.empty())   //  다 끝났는데도 비어있지않다면? { { { { 이런식의  형태일테니 { { { } 이렇게 한번 바꿔주고 c++ 
		   {
		   	    c++;
		   	    s.pop();
		   	    s.pop();
			   }	
		
	}
	
	printf("%d. %d\n",cnt,c);
}

return 0;

}
