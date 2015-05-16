#include <iostream>
#include <vector>
using namespace std;

int lookUp(vector<vector<int> > &dp, vector<vector<int> > &v, int R, int C, int row, int col)
{
	if (dp[row][col] != 0)
		return dp[row][col];
	int maxTemp = 0;
	if (row > 0 && v[row - 1][col] < v[row][col])
		maxTemp = max(maxTemp, lookUp(dp, v, R, C, row - 1, col));
	if (row < R - 1 && v[row + 1][col] < v[row][col])
		maxTemp = max(maxTemp, lookUp(dp, v, R, C, row + 1, col));
	if (col > 0 && v[row][col - 1] < v[row][col])
		maxTemp = max(maxTemp, lookUp(dp, v, R, C, row, col - 1));
	if (col < C - 1 && v[row][col + 1] < v[row][col])
		maxTemp = max(maxTemp, lookUp(dp, v, R, C, row, col + 1));
	dp[row][col] = maxTemp + 1;
	return maxTemp + 1;
}

int main()
{
	int R, C;
	cin >> R >> C;
	vector<vector<int> > v(R, vector<int>(C, 0));
	for (int i = 0; i < R; i ++)
		for (int j = 0; j < C; j ++)
			cin >> v[i][j];
	vector<vector<int> > dp(R, vector<int>(C, 0));
	int maxLen = 0;
	for (int i = 0; i < R; i ++)
		for (int j = 0; j < C; j ++)
		{
			int temp = lookUp(dp, v, R, C, i, j);
			if (temp > maxLen)
				maxLen = temp;
		}
	cout << maxLen << endl;
	return 0;
}
