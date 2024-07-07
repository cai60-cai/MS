#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// k进制数转十进制
long long convertToDec(const string &num, int base) {
    long long dec = 0;
    int length = num.length();
    for (int i = 0; i < length; ++i) {
        dec = dec * base + (num[i] - '0');
    }
    return dec;
}

int main() {
    int len1, k1, len2, k2;
    cin >> len1 >> k1 >> len2 >> k2;
    
    string n, m;
    cin >> n >> m;
    long long n_dec = convertToDec(n, k1);
    long long m_dec = convertToDec(m, k2);

    if (n_dec < m_dec) {
        cout << "<" << endl;
    } else if (n_dec > m_dec) {
        cout << ">" << endl;
    } else {
        cout << "=" << endl;
    }
    
    return 0;
}
