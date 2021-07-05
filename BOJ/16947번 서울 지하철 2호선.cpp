#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue> 
using namespace std;
int n;
bool flag=0;
vector <int> node[3001];
int check[3001]={0};
int check1[3001]={0};

void BFS(int s)
{
	check[s]=1;   //��ȯ�� �� �ϳ�  
	
	queue <int> Q;
	
	Q.push(s);
	
	
	while(!Q.empty())
	{
		int now=Q.front();
		Q.pop();
		
		for(int i=0; i<node[now].size(); i++)
		{
			if(check[node[now][i]]==0)  
			{
				check[node[now][i]]=1; 
				if(check1[node[now][i]]!=-1) // �������� �湮�� ���� ��ȯ���� �ƴѰ�� 
				{
				   if(check1[now]==-1)  //���� ���� ��ȯ���� ���  
				   {
				   	check1[node[now][i]]=1;  //  �Ÿ��� 1��  
				   }
				   
				   else if(check1[now]>0) {  // ���翪�� ��ȯ���� �ƴ� ���  
				   	
				   	check1[node[now][i]]=check1[now]+1;  // ���翪�� �Ÿ� +1  
				   	
				   }
				}
				
				Q.push(node[now][i]);
			}
			
			
			
		}
		
		
		
	}
	
	
	
	
}




void DFS(int number)
{	

	if(flag==0)
	{
	for(int i=0; i<node[number].size(); i++)
	{
		if(check[node[number][i]]==0) //�湮���� ������  
		{	  
			check[node[number][i]]=check[number]+1;  //���� ���� �湮�� +1 
			DFS(node[number][i]);
		    check[node[number][i]]=0;	
		 } 
		 
		else if(abs(check[number]-check[node[number][i]])>=2)  // �湮�ƴ� ���� �ٽ� �湮�Ϸ��� �õ� 
		{                                                      // +  �湮���� ���� 2�̻��̸� ��ȯ�� 
			
		
			flag=1;
		       
			for(int j=1; j<=n; j++)  
			{
				if(check[j]>=check[node[number][i]]&&check[j]<=check[number]) // ��ȯ�� ��ó�� �湮��~ �� ������ �湮��  
				{
				
				check1[j]=-1;  // �� ���� ���ϸ� ��ȯ������ ǥ��  
			    }
			}
		}
		
	}
}

	
}


int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,a,b;

cin>>n;

for(i=1; i<=n; i++)
{
	cin>>a>>b;
	node[a].push_back(b);
	node[b].push_back(a);
}

   check[1]=1;
	DFS(1);    // ��ȯ���� ���ϴ� ������ ã�� ���� üũ 
	check[1]=0;


	
for(i=1; i<=n; i++)
{
 if(check1[i]==-1)	
	{
	
	BFS(i);  // BFS�� ���� �� ���� ��ȯ�� ������ �Ÿ��� Ȯ��   
	break;
     }
}
	
for(int i=1; i<=n; i++)
{
	if(check1[i]==-1) cout<<"0 ";
	
	else
	cout<<check1[i]<<" "; 
}

return 0;
}
