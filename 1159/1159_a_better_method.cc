#include <iostream>
using namespace std;

#define N 5001
int M[2][N];

int main()
{
	int n;
	char s[N];
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		cin >> s[i];
		M[1][i] = 0;
	}
	for (int i = 0; i < n - 1; i ++)
	{
		if (s[i] == s[i + 1])
			M[0][i] = 0;
		else
			M[0][i] = 1;
	}
	for (int r = 3; r <= n; r ++)
	{
		for (int i = 0; i < n - r + 1; i ++)
		{
			int j = i + r - 1;
			if (s[i] == s[j])
				M[r&1][i] = M[(r - 2)&1][i + 1];
			else
				M[r&1][i] = min(M[(r - 1)&1][i+1], M[(r - 1)&1][i]) + 1;
		}
	}
	cout <<  M[n&1][0] << endl;
	return 0;
}
