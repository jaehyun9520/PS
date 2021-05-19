#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

vector < pair  < int , int > > node(1000001);



void post(int val)
{
	if(node[val].first!=0)
	post(node[val].first);
	
	if(node[val].second!=0)
	post(node[val].second);
	
	cout<<val<<"\n";
	
	
	
}

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int root,val,pre;
stack <int> s;
cin>>root;
s.push(root);
while(cin>>val)
{
		
	if(s.top()>val)
	{
		node[s.top()].first=val;
		s.push(val);
	}
	
	else 
	{ 
	
		    while(1)
			{	
		    pre=s.top();
		    	s.pop();
		    	
		    	if(s.size()==0||s.top()>val)
		    	{
		    		node[pre].second=val;
		    	    s.push(val);
		    	    break;
				}
		    	
			}		
	}

}

post(root);


return 0;
}
