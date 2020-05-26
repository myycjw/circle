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
int mp[maxn][maxn];
int ans = 0;
void dfs(int t) {
	if (t > n) {
		ans++;
		return;
	}
	for (int i = 1; i <= m; i++) {
		bool flag = 1;
		for (int j = 1; j <= n; j++) {
			if (mp[t][j] != -1 && i == mp[t][j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			for (int j = 1; j <= n; j++) {
				if (mp[t][j] != -1 && j != t) {
					mp[j][t] = i;
				}
			}
			dfs(t + 1);
			for (int j = 1; j <= n; j++) {
				if (mp[t][j] != -1 && j != t) {
					mp[j][t] = 0;
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &k, &m);//表示给定的图有n个顶点和k条边，m种颜色。 
	int x, y;
	memset(mp, -1, sizeof mp);
	for (i = 0; i < k; i++) {
		scanf("%d%d", &x, &y);
		mp[x][y] = 0;
		mp[y][x] = 0;
	}
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
/*
5 8 4
1 2
1 3
1 4
2 3
2 4
2 5
3 4
4 5*/
