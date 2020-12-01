#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int r,c,cnt=-1;

void func(int x, int y, int n)
{
	if(n==1)
	{	
		cnt++;
		if(x==r&&y==c) 
		{
		cout<<cnt;
		
	    }
	}
	
	
	else
	{
 
	if(r<x+n/2&&c<y+n/2) 
	func(x,y,n/2);
	
	else if(r<x+n/2&&y+n/2<=c)
	{
	  cnt=cnt+pow(n/2,2);
	func(x,y+n/2,n/2);
    }
    
    else if(x+n/2<=r&&c<y+n/2)
    {
	cnt=cnt+2*pow(n/2,2);
	func(x+n/2,y,n/2);
    }
    else{
    cnt=cnt+3*pow(n/2,2);
    func(x+n/2,y+n/2,n/2);	
	}
    
}
	
}

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int n; 

cin>>n>>r>>c;

func(0,0,pow(2,n));

}
