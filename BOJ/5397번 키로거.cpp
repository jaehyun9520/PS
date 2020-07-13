#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;



int main()
{
//freopen("input.txt", "rt", stdin);
int n,i,t=0;
char a[1000001]={0} ;
scanf("%d",&n);
list <char> L;


while(t!=n)
{
	
	t++;
	list<char>::iterator t = L.begin();

scanf(" %s",a);
for(i=0; a[i]!='\0'; i++)
{
	if(a[i]=='<'&&t!=L.begin())
	{
		
		t--;
	}
	
	if(a[i]=='>'&&t!=L.end())
	{
		t++;
	}
	
	if(a[i]=='-'&&t!=L.begin())
	{
	        t--;
	        t=L.erase(t);
	}
	
	else if(a[i]!='<'&&a[i]!='>'&&a[i]!='-') {
		  
		   
		   	   
		   
		   
		   	L.insert(t,a[i]);
		   
		   
	}
}

for(t=L.begin(); t!=L.end(); t++)
{
	printf("%c",*t);
}

printf("\n");
while(!L.empty())
{
	L.pop_back();
}
}



return 0;
}
