#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int i = 0;
typedef struct node 
{
	int next[10];
	int end;
}node;

node T[100000];

void init(int num)
{
	for (i = 0; i < 10; i ++)
		T[num].next[i] = 0;
	T[num].end = 0;
}

int isConsist(int num)
{
	int ret = 1;
	int len = 1;
	char str[11];
	int length = 0;
	int p = 0;
	while (num --)
	{
		//string str;
		//cin >> str;
		scanf("%s", str);
		if (!ret)
			continue;
		length = strlen(str);
		p = 0;
		for (i = 0; i < length; i ++)
		{
			if (i == length - 1 && T[p].next[str[i] - '0'] != 0)
				ret = 0;
			if (T[p].next[str[i] - '0'] == 0)
			{
//				init(len);
				T[p].next[str[i] - '0'] = len ++;
			}

			p = T[p].next[str[i] - '0'];
			if (T[p].end == 1)
				ret = 0;

			if (i == length - 1)
				T[p].end = 1;
			if (!ret)
				break;
		}
	}	
	return ret;
}

int main()
{
	int num;
	int n;
	//cin >> num;
	scanf("%d", &num);
	while (num --)
	{
		//cin >> n;
		scanf("%d", &n);
		memset(T, 0, sizeof(node) * 100000);
		if (isConsist(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
