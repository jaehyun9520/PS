#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
deque <int> d;
int main()
{
//freopen("input.txt", "rt", stdin);
int n,m,i,j,v,cnt=0,find,tmp,left,right,tmp1;

scanf("%d %d",&n,&m);
	
	for(i=1; i<=n; i++)
	{
		d.push_back(i);   // 덱에 순서대로 입력  
	}
	
	for(i=1; i<=m; i++)
	{
		scanf("%d",&v);   // 찾으려는 값 
		
		find=0;
		
		if(d.front()==v)    //맨앞이 찾으려는 값과 같으면 바로 POP 
			{    
		
				d.pop_front();
			     
			}
		else{
	                for(j=0; j<d.size(); j++)  // 찾으려는 값이 덱의 몇번째에 있는지  
					{
						find++;               
						 
						if(v==d[j])
						{
							break;
						}
					   }
					   tmp1=d.size();      
					   
					  
					   left=abs(1-find);   //왼쪽에서 2번 연산을 몇번해야 하는지    
					   right=abs(tmp1-find)+1;  //오른쪽에서 3번 연산을 몇번해야 하는지(  오른쪽에서 할때는 해당하는 값도 3번 연산을 통해 
					                                                             // 맨앞으로 꺼내줘야하니 +1도 해준다. 
					
					   if(left<=right)
					   {
					   	while(1)
					   	{
					   		tmp=d.front();
					   		
					   		if(tmp==v)
					   		{  
					   	
							   	   d.pop_front();
					   			break;
							   }
							   
							   else if(tmp!=v)
							   {
							   	   d.pop_front();
							   	   d.push_back(tmp);
							   	   cnt++;
							   	   
							   }
						   }
					   }
					   
					   else if(left>right)
					   {
					   	while(1)
					   	{
					   		tmp=d.back();
					   		d.pop_back();
					   	   d.push_front(tmp);
					   	   cnt++;
					   	   
					   	   if(tmp==v)
					   	   {
					   	   	   d.pop_front();
					   	   	   
					   	   	   break;
							  }		   		
					   }		      
			}	
	}
}
printf("%d",cnt);

return 0;

}
