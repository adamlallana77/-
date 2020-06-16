#include<stdio.h>
#include<stdlib.h> 
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int size=1000;
const int inf=2122219134;
double min_length=inf;
double center_x[size];
double radius[size];
double order[size];//最小圆排列的半径顺序
int n;

double center(int i)
{
	double bigger=0;
    int j;
	for (j=1;j<i;j++){
		double tmp=center_x[j]+2.0*sqrt(radius[i]*radius[j]);
		bigger=max(bigger,tmp);//取大
	}
	return bigger;
}

void compute()
{
	double Left_margin=inf,Right_margin=0;
    int i;
	for (i=1;i<=n;++i){
		Left_margin=min(Left_margin,center_x[i]-radius[i]);
		Right_margin=max(Right_margin,center_x[i]+radius[i]);
	}

	if (Right_margin-Left_margin<min_length)
	{
		min_length=Right_margin-Left_margin;
		for (int i=1;i<=n;i++){
			order[i]=radius[i];
		}
	}
}

void dfs(int i)//剪枝
{
	if (i==n+1){//若已排序
		compute();
	}
	else{
		for(int j=i;j<=n;j++){
			swap(radius[i],radius[j]);
			double point=center(i);//圆心位置
			if (point+radius[i]+radius[1]<min_length)
			{
				center_x[i]=point;
				dfs(i+1);
			}
			swap(radius[i],radius[j]);//交换
		}
	}
}
int main()
{
    cout << "请输入圆的个数："<<endl;
	cin>>n;
    int i;
    cout << "请分别输入圆的半径："<<endl;
	for (i=1;i<=n;i++){
		cin >> radius[i];}
	dfs(1);
	cout << "最小长度为："<<min_length<<endl;
	cout << "圆的排列顺序为："<<endl;

	for(i=1;i<=n;i++){
		cout<<order[i]<<" ";}
	return 0;
}
