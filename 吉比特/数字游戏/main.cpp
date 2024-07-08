#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    stack<int> Stack;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (Stack.empty() || sum >= Stack.top()) {
            Stack.push(sum);
            sum = 0;
        }
    }
    
    cout << Stack.size();
    return 0;
}
