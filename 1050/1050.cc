#include <iostream>
#include <cstring>
using namespace std;

#define N 100
int R[N][N];
int M[N];
int maxSubArray(int a[], int n)
{
	int max = a[0];
	int b = a[0];
	for (int i = 1; i < n; i ++)
	{
		if (b < 0)
			b = a[i];
		else
			b += a[i];
		if (b > max)
			max = b;
	}
	return max;
}
int main()
{
	int n;
	cin >> n;
	int max = 0;
	for (int i = 0;i < n; i ++)	
		for (int j = 0; j < n; j ++)
			cin >> R[i][j];
	for (int i = 0; i < n; i ++) 
	{
		for (int s = 0; s < n; s++)
			M[s] = 0;
		for (int j = i; j < n; j ++) 
		{
			for (int k = 0; k < n; k ++)
				M[k] += R[j][k];
			int tempMax = maxSubArray(M, n);
			if (tempMax > max)	
				max = tempMax;
		}
	}
	cout << max << endl;
}
