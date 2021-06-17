#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue> 
using namespace std;
string val;
bool check[100]={0};
char answer[100]={0};

void DFS(int cnt)  // 순열   cnt= 몇번째까지 만들었는지  
{
	if(cnt==val.size()) 
	{
		for(int i=0; i<val.size(); i++)
		{
			cout<<answer[i];
			
		}
		cout<<"\n";
		
	 } 

	 else
	 {
	 	int pre=-1; 

	 	for(int i=0; i<val.size(); i++)
	 	{
	 		if(check[i]==0&&pre!=val[i])   
	 		{
	 			check[i]=1;
	 			pre=val[i];
	 			
	 			answer[cnt]=val[i];
	 			DFS(cnt+1);
	 			check[i]=0;
	 			
			 }
		
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
cin>>n;
for(int i=1; i<=n; i++)
{
	cin>>val;
	sort(val.begin(),val.end()); //영단어 오름차순 정렬 	
	DFS(0); 
}


return 0;
}
