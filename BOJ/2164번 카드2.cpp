#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;





int main()
{
//freopen("input.txt", "rt", stdin);
 queue <int> Q;
 int n,i;
 scanf("%d",&n);
  
  
  for(i=1; i<=n; i++)
  {
  	Q.push(i);
  }
  
  
  while(Q.size()!=1)
  {
  	Q.pop();
  	
  	Q.push(Q.front());
  	
  	Q.pop();
  	
  	
  }
  
  printf("%d",Q.front());
return 0;
}
