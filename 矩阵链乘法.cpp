#include <iostream>
using namespace std;
 
int m[100][100];
int p[100];
int n;
 
void solve(){
    // 矩阵的个数
    cin >> n;
    // 连乘数如果为三个矩阵 3 x 4, 4 x 5, 5 x 6
    // p就为 3 4 5 6
    for(int i = 0; i < n + 1; ++i) cin >> p[i];
    // 初始化第单个矩阵连乘为0
    for(int i = 0; i <= n; ++i) m[i][i] = 0;
    // 矩阵规模大小
    for(int r = 2; r <= n; ++r){
         // i是左边界
        for(int i = 1; i <= n - r + 1; ++i){
            // j是右边界
            int j = r + i - 1;
            m[i][j] = m[i][i] + m[i + 1][j] + p[i - 1] * p[i] * p[j];
            for(int k = i + 1; k < j; ++k){
                int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                // 取出最小值
                if(temp < m[i][j]){
                    m[i][j] = temp;
                }
            }
        }
    }
    cout << m[1][n];
}
int main(){
    solve();
    return 0;
}
