#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int n;

void func2(int x)
{
	int i;
	for(i=1; i<=x*4; i++)
	 {
	 	printf("_");
	 }
}


void func3(int x)
{
	    func2(x);
	    printf("라고 답변하였지.\n");
	    
	    if(x>0)
	    {
	    	func3(x-1);
		}
	
}

void func(int x)  
{
	int i;
	if(x>0)    // 재귀 횟수가 0보다 크면 0이될때까지  
	{
		func(x-1);
	}
	
	if(x==0) 
	     {
		 printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");  // 한번만 사용되는 맨첫줄  
	 }
	 if(x!=n) // 0부터 N-1까지 반복해서 출력  
	 {
	 
	    func2(x);  // x의 값에 따라서 앞에 _ 를 출력  
	    printf("\"재귀함수가 뭔가요?\"\n"); 
	    func2(x);
		printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
		func2(x);
		printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
		func2(x);
		printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n"); 
      }
      if(x==n)   
      {
      	func2(x);
	    printf("\"재귀함수가 뭔가요?\"\n"); 
	    func2(x);
	    printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
	    func2(x);
	    printf("라고 답변하였지.\n");
	    
	    func3(x-1);  // n-1부터 0이 될때까지 _붙여서 반복 출력  
	  }
	 
}


	


int main()
{
//freopen("input.txt", "rt", stdin);


scanf("%d",&n);  // 재귀횟수 입력  

func(n);
return 0;

}
