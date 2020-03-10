// 8275. 햄스터

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int N, X, M;
bool flag;
int num[7];

pair<pair<int, int>, int> condition[11];


void dfs(int index) // condition�� index��°�� ���� �� ����
{
	if (index == 0 ) // ��� ĭ�� �ܽ��� �� �־����� ���Ǹ����ϴ��� Ȯ��
	{
		for (int i = M; i > 0; i--) 
		{
			int total = 0;
			for (int s = condition[i].first.second; s >= condition[i].first.first; s--)
				total += num[s];
			if (total != condition[i].second) // ���Ǻ��� �۰ų� ũ�� ����x 
				return;
		}
		flag = true; // �����ϴ� ��� flag �����ϰ� ���� ��� ���ϵ���
		return;
	}

	for (int i = X; i >= 0; i--) // �������� ������ ��� ���� ū�� �ֱ� 
		// -> ó������ ũ�� �����ϸ� ���� ó�� ������ ���� �� ���
	{
		num[index] = i;
		dfs(index - 1);
		if (flag)
			return;
	}
}


int main()
{
	int Test;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &Test);
	for (int T = 1; T <= Test; T++)
	{
		flag = false;
		scanf("%d %d %d", &N, &X, &M);
		for (int i = 1; i <= M; i++)
		{
			int l, r, s;
			scanf("%d %d %d", &l, &r, &s);
			condition[i] = { {l,r},s };
		}
		dfs(N); // 1~N�� �츮�� ���� �����ֱ�
		// ������ -> �ڰ� �� Ŀ���Ѵ� -> ������ index���� ���� ū������ �ֱ�

		printf("#%d ", T);
		if (flag) // ���� ������ �� ���
		{
			for (int i = 1; i <= N; i++)
				printf("%d ", num[i]);
			printf("\n");
		}
		else // ���� ������ -1 ���
			printf("-1\n");
	}

}
