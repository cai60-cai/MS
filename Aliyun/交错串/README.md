定义一个01串为“交错串”，当且仅当任意两个相邻的字符都是不同的。例如，"10101"是交错串. 现在小红拿到了一个01串，她有若干次询问，每次询问一个区间，你需要回答将该区间代表的连续子串修改为“交错串”的最小修改次数。每次修改可以修改任意一个字符。
```
输入描述

第一行输入两个正整数n,q，代表字符串长度和询问次数。
第二行输入一个长度为n的、仅由'0'和'1'组成的字符串。
接下来的q行，每行输入两个正整数l,r，代表询问的是第l个字符到第r个字符组成的子串,
1≤n,q≤1e5
1<=l,r<=n
输出描述

输出q行，每行输出一个整数代表询问的答案。
示例1

输入：
6 3
101101
1 3
3 5
1 6
输出：
0
1
3
```