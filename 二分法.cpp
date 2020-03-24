#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

#define n 10

int erfen(int x,int a[n])
{
	int l=1,r=n;
	while(l<=r)
	{
		int m=floor((l+r)/2.0);
		if(a[m]==x)
			return m;
		else if(a[m]>x)
			r=m-1;
		else
			l=m+1;
	}
	return 0;
}
int main()
{
	int x,a[n];
	scanf("%d",&x);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	erfen(x,a);
	
	printf("%d",x);
}
