#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue> 
#include<cmath>
using namespace std;
int n;
vector < pair < int , int > > list(11);
int ans=2147000000;

void DFS(int select, int cnt, int val1, int  val2) //선택한 재료 번호 , 총  개수, 신맛, 쓴맛 
{
	if(cnt>=1)
	{
		ans=min(ans,abs(val1-val2));
	}

	if(cnt<n)
	{
		
		for(int i=select+1; i<=n; i++)
		{
			
			DFS(i,cnt+1,val1*list[i].first,val2+list[i].second);			
		}				
}
}

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cin>>n;

for(int i=1; i<=n; i++)
{
	cin>>list[i].first>>list[i].second; // 신맛과 쓴맛  
}


DFS(0,0,1,0);   //현재 고른 재료번호,몇개 골랐는지,신맛과 쓴맛   
cout<<ans;
return 0;
}
