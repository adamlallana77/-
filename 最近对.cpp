  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define INF 11111111111
#define N 10000
struct node {
	double x;
	double y;
}point[N];

int cmp(const void* a, const void* b) 
{
	struct node ac = *(struct node*)a;
	struct node bd = *(struct node*)b;
	if (ac.x != bd.x)
		return ac.x - bd.x;//按照x从小到大的顺序排序
	else return ac.y - bd.y;//当x相等的时候，按照y的从大到小的顺序排序 
}

int cmpy(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
double mindistance(double left, double right)//返回大小关系 
{
	return left < right ? left : right;
}
double distance(int left, int right)//计算两点的距离的函数 
{
	return sqrt((point[left].x - point[right].x) * (point[left].x - point[right].x) + ((point[left].y - point[right].y) * (point[left].y - point[right].y)));
}
double Closest_Pair(int left, int right)
{
	double End_dis = INF;//距离差的初始值,无穷大 
	int i = 0, j = 0, k = 0;//循环变量 
	if (left == right)//只有一个点的时候，返回无穷大 
		return End_dis;
	if (right - left == 1)// 刚好两个点的时候，返回两点的距离即可 
		return distance(left, right);
	int mid = (left + right) / 2;//大于等于三个点的时候
	double distanceleft = Closest_Pair(left, mid);//左边递归
	double distanceright = Closest_Pair(mid + 1, right);//右边递归
	End_dis = mindistance(distanceleft, distanceright);//比较左右两边的点对距离，找出最小值
	int temp[N] = { 0 };//储存宽度为d的点 
	for (i = left; i <= right; i++)//找出符合要求的距离mid横坐标小于等于d的点 
	{
		if (fabs(point[mid].x - point[i].x) <= End_dis)
			temp[k++] = i;//temp用于暂时储存符合要求的点的序号 
	}
	for (i = 0; i <= k - 1; i++)//纵坐标寻找最短距离 
		for (j = i + 1; j <= k - 1; j++)
			if (point[temp[j]].y - point[temp[i]].y < End_dis)
				End_dis = mindistance(End_dis, distance(temp[i], temp[j]));
	return End_dis;
}
int main()
{
	int n = 1,i;
	while (scanf_s("%d",&n)==1&&n)
	{
		for (i = 0; i < n; i++)
			scanf_s("%lf %lf", &point[i].x, &point[i].y);
		qsort(point, n, sizeof(point[0]), cmp);
		printf("%.2lf\n", Closest_Pair(0, n - 1) / 2);
	}
	return 0;
}
