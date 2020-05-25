  
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
		return ac.x - bd.x;//����x��С�����˳������
	else return ac.y - bd.y;//��x��ȵ�ʱ�򣬰���y�ĴӴ�С��˳������ 
}

int cmpy(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
double mindistance(double left, double right)//���ش�С��ϵ 
{
	return left < right ? left : right;
}
double distance(int left, int right)//��������ľ���ĺ��� 
{
	return sqrt((point[left].x - point[right].x) * (point[left].x - point[right].x) + ((point[left].y - point[right].y) * (point[left].y - point[right].y)));
}
double Closest_Pair(int left, int right)
{
	double End_dis = INF;//�����ĳ�ʼֵ,����� 
	int i = 0, j = 0, k = 0;//ѭ������ 
	if (left == right)//ֻ��һ�����ʱ�򣬷�������� 
		return End_dis;
	if (right - left == 1)// �պ��������ʱ�򣬷�������ľ��뼴�� 
		return distance(left, right);
	int mid = (left + right) / 2;//���ڵ����������ʱ��
	double distanceleft = Closest_Pair(left, mid);//��ߵݹ�
	double distanceright = Closest_Pair(mid + 1, right);//�ұߵݹ�
	End_dis = mindistance(distanceleft, distanceright);//�Ƚ��������ߵĵ�Ծ��룬�ҳ���Сֵ
	int temp[N] = { 0 };//������Ϊd�ĵ� 
	for (i = left; i <= right; i++)//�ҳ�����Ҫ��ľ���mid������С�ڵ���d�ĵ� 
	{
		if (fabs(point[mid].x - point[i].x) <= End_dis)
			temp[k++] = i;//temp������ʱ�������Ҫ��ĵ����� 
	}
	for (i = 0; i <= k - 1; i++)//������Ѱ����̾��� 
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
