#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;


int main()
{
//freopen("input.txt", "rt", stdin);	
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int N,L,H,i,left,right,ans=0,end=0,start=1000,MAX=0,val=0,idx;
int array[1001]={0};
cin>>N;

for(i=1; i<=N; i++)
{
	cin>>L>>H;
	array[L]=H; 
	if(H>MAX) 
	{
	MAX=H; idx=L;
    }
	if(start>L) start=L; 
	if(L>end) end=L;  
}  
 
 val=0;  

for(i=start; i<=idx; i++)  //기준 -> 왼쪽  
{
	if(val<array[i])  
	{
		val=array[i];
	}
	
	ans+=val;
	
}

val=0;
for(i=end; i>idx; i--)  //기준 <-오른쪽 
{
	if(val<array[i])   
   {
   	    val=array[i];
   }
   ans+=val;
}

cout<<ans;

return 0;
}
