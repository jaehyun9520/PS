#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;



int main()
{
//freopen("input.txt", "rt", stdin);
int i=0,total=0,flag=0;
char a[100001];
stack <char> s;


scanf("%s",a);

for(i=0; a[i]!='\0'; i++)
{

	if(a[i]=='(') 
	{
		s.push(a[i]);
		
		
	}
	
	else if(a[i]==')')    
	{
		if(a[i-1]=='(')   // 단독으로 있는 레이저인지 쇠막대기 범위 안에 있는 레이저인지 
		{
			if(s.size()>1)  // 쇠막대기 안쪽 레이저  
			{
				s.pop();        
				total=total+s.size(); // 레이저에 닿는 쇠막대기의 수 만큼 잘린 쇠막대기들이 새로 생기니 s.size()를 더해주자   
			}
			
			
			
			else if(s.size()==1) //단독으로 있으니 그냥 제거  
			s.pop();
	     }
	        if(a[i-1]==')') // 쇠막대기 
	        {
			s.pop();
			total=total+1;  // 늘어난 개수는 레이저로 다 더해줬으니 원래 쇠막대기의 개수만 더해줌  
		     }
				
						
	}		 
}
	

printf("%d",total);


return 0;

}
