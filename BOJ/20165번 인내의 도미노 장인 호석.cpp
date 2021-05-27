#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dirx[4]={0,0,1,-1};  
int diry[4]={1,-1,0,0}; 
int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n,m,R,i,j,ans=0;  
int map[101][101]={0}; 
char check[101][101]={0}; 



int ax,ay,dx,dy;
char dir;

cin>>n>>m>>R;

for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	{
		cin>>map[i][j];
		check[i][j]='S';
	}
}

for(i=1; i<=R; i++)
{
	cin>>ax>>ay>>dir;
	
	if(check[ax][ay]=='S') //�Ѿ����� �ʾҴٸ�?
	{   
	    
		int cnt=1, k=map[ax][ay]-1;  // cnt�� �Ѿ�߸� ���� (�⺻ 1�� ) 
		int nowdir=0;
		
		check[ax][ay]='F';
		
		if(dir=='E') nowdir=0;  //���⿡ ���� ����  
		else if(dir=='W') nowdir=1;
		else if(dir=='S') nowdir=2;
		else  nowdir=3; 
		
	    while(k)
	    {
	    	k--;
	        ax=ax+dirx[nowdir];  //���� ���⸸ŭ ��ĭ  
			ay=ay+diry[nowdir];	
	    
	    if(ax<1||ax>n||ay<1||ay>m) break; //�迭 ������ ����� �ߴ�  
	    
	    if(check[ax][ay]=='S') //���� ���̳밡 �Ѿ����� �ʾҴٸ�  
		{
			check[ax][ay]='F';
			
			if(k<map[ax][ay]-1) //���� �����ִ� ���� Ƚ������ �Ѿ�߸� ���̳��� ����-1�� ũ�ٸ� 
			{                 
			
                 k=map[ax][ay]-1;  
             }
				 cnt++;			
		 } 
		    	
		}		
		   ans+=cnt;		
	 } 
		
	cin>>dx>>dy;
	
	check[dx][dy]='S';
	
}

cout<<ans<<"\n";


for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	{
		cout<<check[i][j]<<" ";
	}
	cout<<"\n";
}
return 0;
}
