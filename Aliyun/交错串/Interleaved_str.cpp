#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Helper function to compute the prefix arrays
void compute_prefix_arrays(const string &s, vector<int> &change_to_pattern1, vector<int> &change_to_pattern2) {
    int n = s.size();
    change_to_pattern1[0] = (s[0] != '0');
    change_to_pattern2[0] = (s[0] != '1');
    for (int i = 1; i < n; ++i) {
        change_to_pattern1[i] = change_to_pattern1[i-1] + (s[i] != (i % 2 == 0 ? '0' : '1'));
        change_to_pattern2[i] = change_to_pattern2[i-1] + (s[i] != (i % 2 == 0 ? '1' : '0'));
    }
}

// Function to query the minimum changes required
int query_min_changes(const vector<int> &change_to_pattern1, const vector<int> &change_to_pattern2, int l, int r) {
    int cost1 = change_to_pattern1[r] - (l > 0 ? change_to_pattern1[l-1] : 0);
    int cost2 = change_to_pattern2[r] - (l > 0 ? change_to_pattern2[l-1] : 0);
    return min(cost1, cost2);
}

int main() {
    int n, count;
    cin >> n >> count;
    string s;
    cin >> s;
    
    vector<int> change_to_pattern1(n);
    vector<int> change_to_pattern2(n);
    
    // Compute the prefix arrays
    compute_prefix_arrays(s, change_to_pattern1, change_to_pattern2);
    
    // Process each query
    for (int i = 0; i < count; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r; // Convert to zero-indexed
        cout << query_min_changes(change_to_pattern1, change_to_pattern2, l, r) << endl;
    }
    
    return 0;
}
