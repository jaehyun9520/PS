#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
int n,m,ans=0;

int dx[5]={0,-1,1,0,0};
int dy[5]={0,0,0,-1,1};
int map[50][50]={0}; 

queue <int> Q; 

int process(int command)  
{
	queue < pair < int , int > > save; 
	int movex[4]={0,1,0,-1};  
	int movey[4]={-1,0,1,0}; 
	int x=(n+1)/2, y=(n+1)/2;
	int l=1  , cnt=0   ,dir=0;  
	int flag=0;                             
	                            
	                            
	                            

	 int color=0, count1=0;
	                            
	while(y!=0) 
	{
		 
		for(int i=1; i<=l; i++)  
		{
			x+=movex[dir];  y+=movey[dir];
			
			if(command==1&&1<=x&&x<=n&&1<=y&&y<=n)  
			{
		
			if(map[x][y]==0) 
			{
				save.push(make_pair(x,y));  
			 } 
			 
			 else if(map[x][y]!=0&&!save.empty()) 
			                                   
			  {
			  	map[save.front().first][save.front().second]=map[x][y];
			  	map[x][y]=0;
			  	save.pop();
			  	save.push(make_pair(x,y));
			  	
												}   
												
											}

            else if(command==2)
	{
		if(color==map[x][y])  
				       save.push(make_pair(x,y)); 
				       
				else{
					  if(save.size()>=4)   
					  {
					  	flag=1;
					  	ans=ans+color*save.size(); 
					  	
					  	 while(!save.empty())  
					  	 {
					  	 	map[save.front().first][save.front().second]=0;
					  	 	save.pop();
						   }
						   
						   
					  }
					  
					  else{   
					  	while(!save.empty()) 
						  {
						  save.pop();    
					}
						  
					  	
					  }
					  color=map[x][y];
						  save.push(make_pair(x,y)); 
					  if(map[x][y]==0) break;   
				}      
		
		
		
		}	
		




			 else if(command==3) 
			 {
			 	
				 	if(color==map[x][y])  
					 count1++;  
				 	
				 	
				 	else if(color!=map[x][y]) 
					 
					 {   
				      if(color!=0)
				      {
					  
				 		Q.push(count1);  
				 		Q.push(color);
				 	   }
				 	
				 		color=map[x][y];   
				 		count1=1;
				 		
				 		
					 }
				 
											 }	
     else if(command==4)
     {
	     if(!Q.empty())
	     {
		
            map[x][y]=Q.front();											 							
           Q.pop(); 
       }
       
       else{
       	map[x][y]=0;
	   }
		}

		}
		
		if(command==2&&map[x][y]==0) break;
		
		cnt++;
		dir++;
		if(dir>3) dir=0;
		if(cnt==2) {
			cnt=0; l++;
			
		
		}
		
		
	}
	
	return flag;
	
 } 



int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,j,d,s,x,y,nx,ny;
cin>>n>>m;

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		cin>>map[i][j];
	}
}

x=(n+1)/2 ,y=(n+1)/2 ;  

for(i=1; i<=m; i++)
{
	cin>>d>>s;
	
	nx=x; ny=y;
	  for(j=1; j<=s; j++)
	  {
	  	 nx+=dx[d];
	  	 ny+=dy[d];
	  	 
	  	 map[nx][ny]=0;
	  	  
	   }
	  
   
	   process(1); 
	 
	   
	   while(process(2))  
	   {
	   	 process(1);
	   	
	   }
	   
	  
	   process(3); 
	  
	   process(4); 
	  
	   
	   while(!Q.empty()) 
	   {
		 Q.pop();
	}
}

cout<<ans;
return 0;
}
