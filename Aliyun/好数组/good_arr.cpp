#include <iostream>
#include <vector>
#include <unordered_map>
#define MOD 1000000007

using namespace std;

// 快速幂函数，用于计算 base^exp % mod
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1; // 初始结果设为1
    while (exp > 0) { // 当指数大于0时循环
        if (exp % 2 == 1) { // 如果指数是奇数
            result = (result * base) % mod; // 更新结果
        }
        base = (base * base) % mod; // 基数平方并取模
        exp /= 2; // 指数除以2
    }
    return result; // 返回最终结果
}

// 计算符合条件的子序列的数量
long long count_good_subsequences(int n, vector<int>& a) {
    unordered_map<int, int> counter; // 用于统计每个元素的出现次数
    for (int num : a) { // 遍历数组中的每个元素
        counter[num]++; // 更新每个元素的出现次数
    }
    
    long long odd_combinations = 1; // 初始奇数组合数设为1
    long long even_combinations = 1; // 初始偶数组合数设为1
    
    for (const auto& entry : counter) { // 遍历计数器中的每个元素及其出现次数
        int number = entry.first; // 当前元素
        int count = entry.second; // 当前元素的出现次数
        if (number % 2 == 1) { // 如果元素是奇数
            // 计算奇数组合数 (2^(count - 1) + 1) % MOD
            odd_combinations = (odd_combinations * (mod_pow(2, count - 1, MOD) + 1)) % MOD;
        } else { // 如果元素是偶数
            // 计算偶数组合数 (2^(count - 1)) % MOD
            even_combinations = (even_combinations * mod_pow(2, count - 1, MOD)) % MOD;
        }
    }
    
    // 计算总的组合数，减去空集
    long long result = (odd_combinations * even_combinations - 1 + MOD) % MOD;
    return result; // 返回最终结果
}

int main() {
    int n; // 数组大小
    cin >> n; // 输入数组大小
    vector<int> a(n); // 定义数组
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // 输入数组元素
    }
    
    // 调用函数计算并输出结果
    cout << count_good_subsequences(n, a) << endl;
    return 0;
}
