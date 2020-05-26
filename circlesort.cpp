#include<map>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<string>
#include<cstdio>
#include <iomanip>
using namespace std;
//const int maxn = 3e5 + 10;
#define ll long long
int i, j, k;
int n, m;
const int inf = 0x3f3f3f;
const int mod = 1e9 + 7;
map<ll, ll> mpp[30];
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}
const int maxn = 1010;
double r[maxn], cx[maxn], a[maxn];
float minn = inf; 
double getcx(int c) {
	double len = 0, t;
	for (int i = 1; i < c; i++) {
		t = cx[i] + 2 * sqrt((r[c] * r[i]));
		if (t > len)
			len = t;
	}
	return len;
}
void cal() {//计算当前圆排列的长度 
	double L = 0, R = 0;
	for (int i = 1; i <= n; i++) {
		if (cx[i] - r[i] < L)
			L = cx[i] - r[i];
		if (cx[i] + r[i] > R)
			R = cx[i] + r[i];
	}
	if ((R - L) <= minn) {
		minn = R - L;//更新最小值
		for (i = 1; i <= n; i++)//记录最优顺序
			a[i] = r[i];
	}

}
void dfs(int c) {
	if (c == n + 1)//最后一个圆已经调整完毕
		cal();//计算当前圆排列长度 
	else {
		for (int i = c; i <= n; i++) {
			swap(r[c], r[i]);
			double x = getcx(c);//得到圆c的圆心横坐标 
			if (r[1] + x + r[c] < minn) {
				cx[c] = x;
				dfs(c + 1);
			}
			swap(r[c], r[i]);
		}
	}
}
int main() {
	cin >> n;//圆的个数
	for (i = 1; i <= n; i++)
		cin >> r[i];//每个圆的半径
	dfs(1);
	cout << "length: " << minn << endl;
	cout << "sort: ";
	for (i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	puts("");
	return 0;
}
