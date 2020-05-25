#include <iostream>
#define MAX 100
using namespace std ; 
int arr[MAX] ;
void Swap( int &a, int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}
int Search( int arr[], int c, int d){
	int t = arr[c];
	int i = c;
	int j = t;
	while( i < j ) 
	{
		while(i < j && arr[j] > t)
		j--;
		Swap(arr[i] , arr[j]) ;
		while(i < j && arr[i] < t)
		i++;
		Swap(arr[i] , arr[j]);
	}
	return i;
}
int K( int arr[] , int f , int t , int k)
{
	int count = Search( arr , f , t);
	
	if(count > k)
	return K(arr , f , count - 1 , k);
	else
	if(count < k)
	return K(arr , count + 1 , t , k);
	else
	return arr[count];
}
	int main()
{
	int t ,n , k , a = 0;
	cin >> n >> k ;
	for( int i = 0 ; i < n ; ++i)
	cin >> arr[i];
	t = K(arr , a , n - 1 , k - 1);
	cout <<t<<endl;
 return 0 ;
}
