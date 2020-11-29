#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int length[40]={0};

void func(int i, int n)
{
	
	
if(i==0)   
{

	
	if(n==1) cout<<"m";
	
	else cout<<"o";
}
	
else{

	if(n<=length[i-1])   // n이 앞쪽  s(i-1)에 속하는 경우 
	{
		func(i-1,n);
	}
	
	else if(length[i-1]<n&&n<=length[i-1]+i+3)  // n이 i+3 부분에 속하는 경우  
	{
		if(n==length[i-1]+1)
		   cout<<"m";  
		   else cout<<"o";
	}
	
	else{
		
		func(i-1,n-(length[i-1]+i+3));  // 뒤쪽 s(i-1)에 속하는 경우  
	}
}
}

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i=0,n;

cin>>n;

length[0]=3;

if(n>=4)
{

for(i=1; i<=27; i++)    
	{
	    length[i]=length[i-1]+i+3+length[i-1];  // 수열의 길이 기록  
	    
	    if(n<=length[i]) break;  //조건에 해당하면 삐져나옴 
	}
}
	func(i,n); 
												   											   
return 0;
}
