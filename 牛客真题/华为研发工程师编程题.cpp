// https://www.nowcoder.com/exam/test/72225086/submission?examPageSource=Company&pid=1088888&testCallback=https%3A%2F%2Fwww.nowcoder.com%2Fexam%2Fcompany&testclass=%E8%BD%AF%E4%BB%B6%E5%BC%80%E5%8F%91

// 1.
// 汽水瓶
// 某商店规定：三个空汽水瓶可以换一瓶汽水，允许向老板借空汽水瓶（但是必须要归还）。
// 小张手上有n个空汽水瓶，她想知道自己最多可以喝到多少瓶汽水。
// 数据范围：输入的正整数满足 
// 1
// ≤
// �
// ≤
// 100
 
// 1≤n≤100 

// 注意：本题存在多组输入。输入的 0 表示输入结束，并不用输出结果。

int solve(int n) {
    int ans = 0;
    while(n >= 3) {
        ans += n / 3;
        n = n % 3 + n / 3;
    }

    if(n == 2) ans += 1;

    return ans;
}

int main() {
    int n = 0;
    for(;;) {
        cin >> n;
        if(n == 0) break;
        cout << solve(n) << endl;
    }
}
// 64 位输出请用 printf("%lld")

// 2.
// 明明的随机数
// 明明生成了
// �
// N个1到500之间的随机整数。请你删去其中重复的数字，即相同的数字只保留一个，把其余相同的数去掉，然后再把这些数从小到大排序，按照排好的顺序输出。

// 数据范围： 
// 1
// ≤
// �
// ≤
// 1000
 
// 1≤n≤1000  ，输入的数字大小满足 
// 1
// ≤
// �
// �
// �
// ≤
// 500
 
// 1≤val≤500 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int cnt = 0;
    cin >> cnt;
    map<int, int> m;
    vector<int> ans;
    while(cnt) {
        int num;
        cin >> num;
        m[num]++;
        cnt--;
    }

    for(auto& p : m) {
        ans.push_back(p.first);
    }

    sort(ans.begin(), ans.end());

    for(auto& elem : ans) {
        cout << elem << endl;
    }
}
// 64 位输出请用 printf("%lld")

// 3.
// 进制转换
// 写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。

#include <iostream>
using namespace std;

int hexChar2Int(char c) {
    if(c >= '0' && c <= '9') return c - '0';

    if(c >= 'A' && c <= 'F') return c - 'A' + 10;

    return -1;
}

int main() {
    string sHex;

    cin >> sHex;

    int ans = 0;
    for(int i = 2; i < sHex.size(); i++) {
        ans *= 16;
        ans += hexChar2Int(sHex[i]);
    }

    cout << ans << endl;
}
// 64 位输出请用 printf("%lld")