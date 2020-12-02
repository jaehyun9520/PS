#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int check[10000]={0};
int t,i=1,ans,val,next;
string command;
queue < pair < int , string > > Q;
cin>>t;

while(i<=t)
{
	cin>>val>>ans;
	
	Q.push(make_pair(val,""));
	
	while(!Q.empty())
	{
		val=Q.front().first;
		command=Q.front().second;
		Q.pop();
		//D
		next=(val*2)%10000;
		if(next==ans) 
		{
		cout<<command<<"D\n"; break;
	    }
		else if(check[next]==0)
		{
			check[next]=1; Q.push(make_pair(next,command+"D"));
		}
		//S
		if(val==0) next=9999; else next=val-1;
		
		if(next==ans) 
		{
		cout<<command<<"S\n"; break;
	    }
		else if(check[next]==0)
		{
			check[next]=1; Q.push(make_pair(next,command+"S"));
		}
		
		//l
		next=(val*10)%10000+val/1000;
		if(next==ans) 
		{
		cout<<command<<"L\n"; break;
 	    }
		else if(check[next]==0)
		{
			check[next]=1; Q.push(make_pair(next,command+"L"));
		}
		
		//R
		
		next=val/10+(val%10*1000);
		if(next==ans) 
		{
		cout<<command<<"R\n"; break;
	    }
		else if(check[next]==0)
		{
			check[next]=1; Q.push(make_pair(next,command+"R"));
		}
	}
	
	
	while(!Q.empty()) Q.pop();
	
	
	for(int j=0; j<=9999; j++)
	{
		check[j]=0;
	}
	i++;
}
return 0;
}
