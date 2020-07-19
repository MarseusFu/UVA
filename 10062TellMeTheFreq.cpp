#include<stdio.h>
#include<stdlib.h>
void sort(int check[],char dic[])
{
	int i,j;
	for(i=1; i<=128;i++)
	{
		int flag=1;
		for(j=0; j<128-i; j++)
		{
			if(check[j]>check[j+1])
			{
				int temp = check[j];
				check[j]=check[j+1];
				check[j+1]=temp;
				
				char tmpc = dic[j];
				dic[j]=dic[j+1];
				dic[j+1]=tmpc;
				
				flag=0;
			}
			if(check[j]==check[j+1])
			{
				if(dic[j]<dic[j+1])
				{
					char tmpc=dic[j];
					dic[j]=dic[j+1];
					dic[j+1]=tmpc;
					flag=0;
				}
			}
		}
		if(flag)
			break;
	}
}
int main()
{
	char input[1003],dic[128];
	int freq[128],i,j;
	int num=0;
	int blank=0;
	while(fgets(input,1003,stdin))
	{
		num=0;
		for(i=0; i<128; i++)
		{
			freq[i]=9999;
			dic[i]=0;
		}
		
		if(!blank)
			blank=1;
		else
			printf("\n");
			
	
		
		for(i=0; ;i++)
		{
			if(input[i]=='\0'||input[i]=='\n')
				break;
				
			int flag=0;
			for(j=0; j<=num; j++)
			{
				if(input[i]==dic[j])
				{
					freq[j]++;
					flag=1;
				}
			}
			if(!flag)
			{
				dic[num]=input[i];
				freq[num]=1;
				num++;
			}
		}
		sort(freq,dic);
		for(i=0; i<128; i++)
		{
			if(freq[i]!=9999)
				printf( "%d %d\n", dic[i], freq[i] );
			else
				break;
		}
	}
	return 0;
}
