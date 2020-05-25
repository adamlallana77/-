#include <stdio.h>
int Bin_Search(int *num,int cnt,int target)
{
	int first = 0,last = cnt-1,mid;
	int counter = 0;
	while(first <= last)
	{
		counter ++;
		mid = (first + last) / 2;
		if(num[mid] > target)
		{
			last = mid-1;
		}
		else if(num[mid] < target)
		{
			first = mid+1;
		}	
		else
		{
			return 1;
		}
	}
	return 0;
}
int main(void)
{
	int flag = 0,target;
	int num[10] = {1,2,3,4,5,6,7,8,10};
	while(1)
	{
		scanf("%d",&target);
		flag = Bin_Search(num,10,target);
		if(flag) 
			printf("The numbers find!\n");
		else 
			printf("The numbers No find!\n");	
	}
	return 0;
}

