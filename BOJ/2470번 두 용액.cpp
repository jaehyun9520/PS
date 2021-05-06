#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;



int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n,i,val,find,lt,rt,mid;
int ans1=0, ans2=0, min1=2100000000;
vector <int> list1;
vector <int> list2;

cin>>n;

for(i=1; i<=n; i++)
{
	cin>>val;
	list1.push_back(val);
	list2.push_back(val);
}

sort(list2.begin(),list2.end());

for(i=0; i<n; i++)
{
	val=list1[i];
	
	find=-1*val;
	lt=0; rt=n-1;
	
	while(lt<=rt)
	{
		mid=(lt+rt)/2;
		
		if(abs(val+list2[mid])<min1&&list2[mid]!=val)
		{
			min1=abs(val+list2[mid]);
			ans1=val , ans2=list2[mid];
		}
		
		
		if(find==list2[mid])
		{
			if(val<find)
			{
				cout<<val<<" "<<find;
			}
			else{
				cout<<find<<" "<<val;
			}
			
			exit(0);
		}
		
		
		else if(find<list2[mid])
		{
			rt=mid-1;
		}
		
		else{
			lt=mid+1;
		}
		
	}
}


if(ans1<ans2)
{
	cout<<ans1<<" "<<ans2;
}
else
{

cout<<ans2<<" "<<ans1;
}
return 0;
}
