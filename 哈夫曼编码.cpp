#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define maxNum     ('_' - 'A' + 1)
#define MAX        0x7F7F7F7F
struct node{
     int key;
     int pos;
};
nodeminHeap[maxNum];
int heapSize;
void minHeapify(int i)
{
     int l;
     int r;
     int min;
     node temp;
     l = i * 2;
     r = i * 2 + 1;
     min = i;
     if((l <=heapSize)&&
     (minHeap[l].key < minHeap[min].key)){
         min = l;
     }
     if((r <=heapSize)&&
     (minHeap[r].key < minHeap[min].key)){
         min = r;
     }
     if(min !=i)
     {
         temp = minHeap[min];
         minHeap[min] = minHeap[i];
         minHeap[i] = temp;
         minHeapify(min);
     }
}
void buildMinHeap()
{
     int i;
     for(i =heapSize / 2; i > 0; i--){
         minHeapify(i);
     }
}
nodeheapExtractMin()
{
     node min;
     if(heapSize< 1)
     {
         cout << "ERROR:no more" << endl;
     }
     min = minHeap[1];
     minHeap[1] = minHeap[heapSize];
     heapSize--;
     minHeapify(1);
     return min;
}
void heapIncreaseKey(int i, int key)
{
     node temp;
     if(key >minHeap[i].key)
     {
         cout << "ERROR:new key is smaller than current key" << endl;
     }
     minHeap[i].key = key;
     while(i> 1 && minHeap[i/2].key > minHeap[i].key)
     {
         temp = minHeap[i];
         minHeap[i] = minHeap[i/2];
         minHeap[i/2] = temp;
         i = i / 2;
     }
}
void minHeapInsert(node temp)
{
     heapSize++;
     minHeap[heapSize] = temp;
     minHeap[heapSize].key = MAX;
     heapIncreaseKey(heapSize, temp.key);
}
int f[maxNum + maxNum];
int huffmanLeft[maxNum + maxNum];
int huffmanRight[maxNum + maxNum];
int depth[maxNum];
int huffmanTop;
void update(int x)
{
     if(x <0)
     {
         return;
     }
     if(x <maxNum){
         depth[x]++;
         return;
     }
     update(huffmanLeft[x]);
     update(huffmanRight[x]);
}
int huffman()
{
     node x;
     node y;
     node z;
     huffmanTop = maxNum;
     while(heapSize> 1){
         x = heapExtractMin();
         y = heapExtractMin();
         z.pos = huffmanTop;
         huffmanLeft[z.pos] = x.pos;
         huffmanRight[z.pos] = y.pos;
         z.key = x.key + y.key;
         f[z.pos] = f[x.pos] + f[y.pos];
         minHeapInsert(z);
         update(x.pos);
         update(y.pos);
         huffmanTop++;
     }
     z = heapExtractMin();
     if(z.pos !=huffmanTop - 1)
     {
         int *a= (int *)0;
         *a = 0;
         printf("error\n");
     }
     returnz.pos;
}
int main()
{
     charstr[10000];
     int pos;
     int length;
     int sum;
     int i;
     int n;
     while(scanf("%s", str)){
         if(strcmp("END", str) == 0)
         {
              break;
         }
         memset(f, 0, sizeof(f));
         memset(minHeap, 0, sizeof(minHeap));
         length = strlen(str);
         n = 0;
         for(i =0; i < length; i++){
              pos = str[i] - 'A';
              if(f[pos]== 0)
              {
                   n++;
              }
              f[pos]++;
         }
         pos = 1;
         for(i =0; i < maxNum; i++){
              if(f[i]!= 0){
                   minHeap[pos].key = f[i];
                   minHeap[pos].pos = i;
                   pos++;
              }
         }
         if(n> 1){
              heapSize = n;
              buildMinHeap();
              memset(huffmanLeft, 0xff, sizeof(huffmanLeft));
              memset(huffmanRight, 0xff, sizeof(huffmanRight));
              memset(depth, 0, sizeof(depth));
              huffman();
              sum = 0;
              for(i= 0; i < maxNum; i++){
                   sum += depth[i] * f[i];
              }
         }else{
              sum = length;
         }
         length = length * 8;
         printf("%d%d %.1f\n", length, sum, (double)length/ sum);
     }
}
