#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<bool> isEven(n + 1, false); //标记节点是否为偶数不用0
    vector<pair<int, int>> edges(n - 1);//存储所有边  
    
    int even = 0, odd = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        edges[i] = {x, y}; 
        if (x % 2 == 0) isEven[x] = true;
        if (y % 2 == 0) isEven[y] = true;
    }
    
    //统计奇偶
    for (int i = 1; i <= n; ++i) {
        if (isEven[i]) even++;
        else odd++;
    }
    
    // 总数 偶*奇+ 二分之偶*偶-1
    long long total = even * odd + (even * (even - 1)) / 2;
    
    //算相邻的情况
    long long adj = 0;
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        if ((u % 2 == 0) || (v % 2 == 0)) {
            adj++;
        }
    }
    
    long long res = total - adj;
    
    cout << res << endl;
    return 0;
}
