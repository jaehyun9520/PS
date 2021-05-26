#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,width,n,val,left,right,mid,flag=0;
int lego1=0,lego2=0;
vector <int> list;

while(cin>>width)
{
	flag=0;
	width=width*10000000;
	cin>>n;
	
	for(i=0; i<n; i++)
	{
	   cin>>val;
	   list.push_back(val);
	   	
	}
	sort(list.begin(),list.end());

	for(i=0; i<n&&list[i]*2<=width; i++)
	{
		val=width-list[i];  
		
		left=i+1; right=n-1;
		
		while(left<=right)
		{
			mid=(left+right)/2;	
			if(list[mid]==val)
			{
				if(flag==0)
				{
					flag=1;
					lego1=list[i]; lego2=list[mid];
				}
				
				else{
					
					if(abs(lego1-lego2)<abs(list[i]-list[mid]))
					{
						lego1=list[i];  lego2=list[mid];
					}
					
				}
				break;
			}
			
			
			else if(list[mid]<val)
			{
				left=mid+1;
			}
			
			else{
				right=mid-1;
			}
				
			
		}
		
	}

	list.clear();

	
	
	if(flag==0)
	{
		cout<<"danger\n";
	}
	
	else
	{
		cout<<"yes ";
		
		if(lego1>lego2)
		{
			cout<<lego2<<" "<<lego1<<"\n";
			
		}
		
		else
		{
		    cout<<lego1<<" "<<lego2<<"\n";
		}
	}
		
	
}

return 0;
}
