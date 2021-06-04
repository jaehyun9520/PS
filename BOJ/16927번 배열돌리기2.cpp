#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int map[301][301]={0};
int ans[301][301]={0};
vector <pair <int ,int > > tmp;
int cx,cy;
void function1(int minx,int maxx,int miny,int maxy)
{
 int i;
	for(i=minx; i<=maxx; i++)
	{
		tmp.push_back({i,miny}); 
	
	}
	
	for(i=miny+1; i<=maxy; i++)
	{  
		tmp.push_back({maxx,i});
	
	}
	
	for(i=maxx-1; i>=minx; i--)
	{       
		tmp.push_back({i,maxy});
		
	}
	
	for(i=maxy-1; i>=miny+1; i--)
	{
	
		tmp.push_back({minx,i});
	
	}


	
}
void move1(int maxx,int minx,int maxy,int miny,int cnt)
{
	while(cnt) 
	{
	
	cnt--;
	if(minx<=cx&&cx<maxx&&cy==miny)   
	{ 
	    cx++;	
	}
	else if(cx==maxx&&miny<=cy&&cy<maxy)
	{
		cy++;
	}
	else if(cy==maxy&&cx<=maxx&&cx>minx)
	{
		cx--;
	}
	else if(cx==minx&&cy<=maxy&&cy>miny)
	{
		cy--;
	}
	
}
	
	
	
	
}


int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int n,m,r,i,j,state;
int a;
cin>>n>>m>>r;

for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	{
		cin>>map[i][j];
	}
}

a=min(n,m);
 

for(int i=0; i<(a/2); i++) 
{
	int minx=1+i;     int miny=1+i;
   int maxx=n-i;      int maxy=m-i;
	 function1(minx,maxx,miny,maxy);

for(int j=0; j<tmp.size(); j++)

{

   int px=tmp[j].first;    
   int py=tmp[j].second;

      state=2*(n-1-(2*i))+2*(m-1-(2*i));  
      
     int cnt=r%state;   
	 
	 if(cnt==0)  
	 {

	 ans[px][py]=map[px][py];
}
	 else 
	 {
	 	cx=px; cy=py;
	 	move1(maxx,minx,maxy,miny,cnt);

	ans[cx][cy]=map[px][py];

}
		
}
tmp.clear();

}
 
 for(int i=1; i<=n; i++)
 {
 	for(int j=1; j<=m; j++)
 	{
 		cout<<ans[i][j]<<" ";
 		
	 }
	 cout<<"\n";
 }
 
 
return 0;
}
