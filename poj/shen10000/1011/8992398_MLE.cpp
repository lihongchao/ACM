#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=70;
bool map[70];
struct str
{
int lengh;
int num;	
}str1[70];
int n,len,k,num;
//n代表木棍被截后的数量   len代表初始的长度   
//k代表有多少个不同长度的木棍的个数  num代表初始时木根的个数 

int cmp(void const *a,void const *b)
{
return (((struct str*)b)->lengh - ((struct str*)a)->lengh);	
	
}

//left代表第i根木棍还需要的长度  i代表第i根木棍   total代表已经组合的木棍的个数
bool dfs(int left, int i, int total) 
{
	if(total==num)return true;
	
	for(int j=i;i<k;j++) 
	{
		int l=str1[j].lengh;
		int &numb=str1[j].num;
		if(numb==0||l>left)continue;
		
		if(l==left)
		{	
			numb--;
			if(dfs(len,0,total+1))return true;
			numb++;return false;	
		}
		//left > l
		{
			numb--;
			if(dfs(left-l,i,total))return true;
			{
				numb++;
				if(left==len||i==k-1)return false;
			}
			
		}
		
		
		
		
		
	}
	return false;
}

int main()
{
while(scanf("%d",&n),n)	
{
	memset(map,true,sizeof(map));
	for(int i=0;i<N;i++){str1[i].lengh=0;str1[i].num=0;}
	k=0;
	int sum=0;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&len);
		sum+=len;
		if(map[len]){k++;map[len]=false;str1[len].lengh=len;}
		str1[len].num++;
	}	
	
	qsort(str1,N,sizeof(struct str),cmp);
		
	len=str1[0].lengh;
	
	for(int i=len;i<=sum;i++)
	{
		if(sum%i)continue;
		{
			num=sum/i;
			len=i;	
			if (dfs(len,0,0))
			{
				printf("%d\n",i);
				break;
			}					
		}	
	}
	
	
}
return 0;	
}
