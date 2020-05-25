#include <iostream>
#include <math.h>
using namespace std;
const int X = 5;
const int Y = 6;
int plmax(int a[X][Y],int b[X][Y],int x,int y)//X为投资金额，Y为数量 
{
	for (int i=1;i<=y;i++)
	{
		for (int j=0;j<=x;j++)
		{
			a[i][j]=0;
			for (int k=0;k<=j;k++)
			{
				if (a[i][j]<b[i][k]+a[i-1][j-k])
					a[i][j]=b[i][k]+a[i-1][j-k];
			}
		}
	}
	return a[y][x];
}

int main()
{
	int a[X][Y]={0};
	int b[X][Y] = {0,0,0,0,0,0,
				   0,11,12,13,14,15,
				   0,0,5,10,15,20,
				   0,2,10,30,32,40,
				   0,20,21,22,23,24};
	cout << plmax(a,b,5,4) << endl;
	return 0;
}
