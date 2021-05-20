#include<iostream>
#include<algorithm>
#include<vector>
#include<queue> 
using namespace std;

unsigned long long dy[1000001]={0};
int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int T,n;
cin>>T;


dy[1]=1; dy[2]=2; dy[3]=4; dy[4]=7;


for(int i=5; i<=1000000; i++)
{
	dy[i]=(dy[i-1]+dy[i-2]+dy[i-3])%1000000009;
	
	
}

for(int i=1; i<=T; i++)
{
	cin>>n;
	cout<<dy[n]<<"\n";
}

return 0;
}
