#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;			
int k,n,ans=0;
char word[51][16];
int word2[51]={0};

void combination(int cnt,int now,int val)
{
	int i,count1;

	if(cnt==k-5)
	{
		count1=0;
			for(i=1; i<=n; i++)
			{
	
					if(!(word2[i]&~val)) 
					{
		
					count1++;
		               }
			}
			
			if(ans<count1)
			{

			  ans=count1;
		}

	}
	
	else if(cnt<k-5)
	{
		for(i=now; i<=26; i++)
		{
		
			
		        if((val&1<<(i-1))==0)
		        {
        	
		        	combination(cnt+1,i+1,val|(1<<(i-1)));
		        
		        }	
		}
	}
	
}

int main()
{
//freopen("input.txt", "rt", stdin);
int i,j,t;


scanf("%d %d",&n,&k);

for(i=1; i<=n; i++)
{
	scanf("%s",word[i]); 
	t=0;
	for(j=0; j<strlen(word[i]); j++)
	{
		t=t|1<<(word[i][j]-97);
	}
	word2[i]=t;
	 
}
i=0;
i=i|1<<0;
i=i|1<<2;
i=i|1<<8;
i=i|1<<13;
i=i|1<<19;   



combination(0,1,i);

printf("%d",ans);
return 0;
}
