#include<stdio.h>
#include<string.h>
char s1[100],s2[100];
int l1,l2;
int c[100][100];
lcs(int x,int y){
	int i,j;
	c[0][y]=0;
	c[x][0]=0;
	for (i=1;i<=x;i++)
	{
		for(j=1;j<=y;j++)
		{
			if(s1[i]==s2[j])
				c[i][j]=c[i-1][j-1]+1;
			else
			{
				if(c[i][j-1]>c[i-1][j])
					c[i][j]=c[i][j-1];
				else
					c[i][j]=c[i-1][j];
			}
		}
	}
	return c[x][y];
}
int main()
{
	gets(s1);
	gets(s2);
	l1=strlen(s1);
	l2=strlen(s2);
	printf("%d\n",lcs(l1,l2));
 } 
