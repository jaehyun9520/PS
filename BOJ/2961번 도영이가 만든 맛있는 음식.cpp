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

void DFS(int select, int cnt, int val1, int  val2) //������ ��� ��ȣ , ��  ����, �Ÿ�, ���� 
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
	cin>>list[i].first>>list[i].second; // �Ÿ��� ����  
}


DFS(0,0,1,0);   //���� �� ����ȣ,� �������,�Ÿ��� ����   
cout<<ans;
return 0;
}
