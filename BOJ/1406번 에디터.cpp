#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;



int main()
{
//freopen("input.txt", "rt", stdin);
list <char> L;
char a[100001];
int i,n;
char m,val;
scanf("%s",a);
 list<char>::iterator tmp ;
for(i=0; a[i]!='\0'; i++)
{
	L.push_back(a[i]);
}




list<char>::iterator t = L.end();

scanf("%d",&n);
for(i=1; i<=n; i++)
{
	scanf(" %c",&m);
	
	if(m=='L'&&t!=L.begin())
	{
		
		  
		
		t--;
	
	}
	
	if(m=='D'&&t!=L.end())
	{
		t++;
	}
	
	
	if(m=='B'&&t!=L.begin())
	{
		tmp=t;
		L.erase(--tmp);
        
	}
	
	
	if(m=='P')
	{
		scanf(" %c",&val);
		L.insert(t,val);
	
	}
}



 
  for(t = L.begin(); t != L.end(); t++)
    {
    	printf("%c",*t);
	}
return 0;
}
