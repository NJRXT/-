#include<iostream>
using namespace std;
const int N = 20;
int w[N][N];
int c[N][N];
int main() {
	int n, m, d,k=0,s=0,t=0;
	int sum[N];
	int X[N][N];
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> w[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
	for (int i = 0; i < N; i++) {
		sum[i] = 0;
		for (int j = 0; j < N; j++)
			X[i][j] = -1;
	}
	while (k >= 0) {
		X[s][k]++;
		if(X[s][k] < m)
		t += c[k][X[s][k]];
		while (X[s][k] < m&&t > d) {
			t -= c[k][X[s][k]];
			X[s][k]++;
			if (X[s][k] < m)
				t += c[k][X[s][k]];
			else
				break;
		}
		if (X[s][k] < m&&k == n - 1) {
			s++;
			for (int i = 0; i <= k; i++)
				X[s][i] = X[s - 1][i];
			t -= c[k][X[s][k]];
		}
		if (X[s][k] < m&&k < n - 1)
			k++;
		if(X[s][k]==m)
		{
			X[s][k--] = -1;
			t -= c[k][X[s][k]];
		}
	}
	for (int i = 0; i <= s; i++)
		for (int j = 0; j < n; j++)
			sum[i] += w[j][X[i][j]];
	t = sum[0]; 
	int q = 0;
	for (int i = 0; i < s; i++)
	{
		if (sum[i] < t)
		{
			t = sum[i];
			q = i;
		}
	}
	for (int i = 0; i < n - 1; i++)
		cout << X[q][i]+1 << " ";
	cout << X[q][n - 1]+1<<endl;
	cout << t << endl;
	system("pause");
	return 0;
}
