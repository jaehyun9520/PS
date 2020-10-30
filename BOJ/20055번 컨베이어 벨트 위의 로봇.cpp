#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,k,val,sp=0,ep=0,cnt=0,ans=0,i;   
vector <pair <int , int > > conveyer; // first는 내구도 second는 로봇유무  
queue <int> reuse;
queue <int> robot;
void p1()
{
	sp--; ep--; // 시작점과 끝지점을 한칸씩 뒤로  
	

	if(sp<0)  sp=2*n-1;
	if(ep<0)  ep=2*n-1;

}

void p2()
{
	int x,tmp;
	while(!robot.empty())  // 로봇의 위치를 뒤쪽부터 꺼내줌  
	{
		x=robot.front();
		robot.pop();

		if(x==ep) conveyer[x].second=0; // 만약 p1로 인해 끝지점에 도착했다면 그대로 내려주기  
		
		else {
		   tmp=x+1;	  if(tmp>2*n-1) tmp=0;  // 다음칸 tmp 
		   
		   if(conveyer[tmp].first>0&&tmp==ep)   //다음칸이 끝지점이고 내구도가 있으면 바로 내려주기  
		   {
		   	conveyer[tmp].first--;  if(conveyer[tmp].first==0) cnt++;
		   	conveyer[x].second=0;
		   	
		   }
		   
		   else if(conveyer[tmp].first>0&&conveyer[tmp].second==0) // 다음칸이 내구도가 있고 로봇이 없으면  
		   {
		   	conveyer[tmp].first--;  if(conveyer[tmp].first==0) cnt++;
		   	conveyer[tmp].second=1;  conveyer[x].second=0;
		   	reuse.push(tmp);
		   }
		   
		   
		   else {  // 앞으로 못가면 다시 넣어주기  
		   	reuse.push(x);
		   }
		}
	}
	
	while(!reuse.empty())
	{
		robot.push(reuse.front());  
		reuse.pop();
	}
	 
	
}
void p3()
{

	if(conveyer[sp].first>0&&conveyer[sp].second==0)
	{
		
		conveyer[sp].first--;
		if(conveyer[sp].first==0) {
		cnt++;}
		
		robot.push(sp);
		conveyer[sp].second=1;
	
		
			}
}


int main()
{	
//freopen("input.txt", "rt", stdin);



scanf("%d %d",&n,&k);
ep=n-1;

for(i=1; i<=2*n; i++)
{
	scanf("%d",&val);
	conveyer.push_back(make_pair(val,0));
 }
while(cnt<k)
{
	
	ans++;
	p1();
	p2();
	p3();
	
	
}
  printf("%d",ans);
return 0;
}
