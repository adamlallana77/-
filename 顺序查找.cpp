#include <stdio.h>
void main(){
	int a[100],num,i,flag=0,x;
	scanf("%d",&x)                 
	for(i=0;i<=x;i++)
	{
		scanf("%d",&a[i]);                
	}
	scanf("%d", &num);           
	for(i=0;i<=x;i++)
	{
		if(a[i]=num)
		{                     
			flag=1;
			break;
		}
	}
	}
	if(flag==1)
	{
		printf("The numbers find!\n");
	}
	else
	{
		printf("The numbers No find!\n");
	}
}
