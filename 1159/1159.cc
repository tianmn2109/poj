#include <iostream>
using namespace std;

#define N 5001
short int M[N][N];

int main()
{
	int n;
	char s[N];
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		cin >> s[i];
		M[i][i] = 0;
	}
	for (int i = 0; i < n - 1; i ++)
	{
		if (s[i] == s[i + 1])
			M[i][i + 1] = 0;
		else
			M[i][i + 1] = 1;
	}
	for (int r = 3; r <= n; r ++)
	{
		for (int i = 0; i < n - r + 1; i ++)
		{
			int j = i + r - 1;
			if (s[i] == s[j])
				M[i][j] = M[i + 1][j - 1];
			else
				M[i][j] = min(M[i + 1][j], M[i][j -1]) + 1;
		}
	}
	cout <<  M[0][n - 1] << endl;
	return 0;
}
