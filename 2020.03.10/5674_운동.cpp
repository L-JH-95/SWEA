// 5674. �
/*
union find�� ������� �ƴ϶� �ȵǴµ� (bfs : priority queue)
-> dfs���
�ܹ��� �׷����̱� ������ i=1~N ���� �����ϸ� ��� Ȯ��
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int N, M;
int Min;
vector <pair<int, int>> v[401]; // v[������].push_back({����, ������ ����})
int visit[401];

void dfs(int index, int sum)
{
	if (Min < sum) // �ּҰ����� ���� ���� ũ�� �� �ʿ� x -> �����ָ� �ð��ְ�
		return;
	for (int i = 0; i < v[index].size(); i++) // �ܹ������� ����� ��常 Ȯ��
	{
		pair <int, int> p = v[index][i];
		if (visit[p.first] == 0) // ó�� �湮
		{
			visit[p.first] = 1;
			dfs(p.first, sum + p.second);
			visit[p.first] = 0;
		}
		else // �̹� �湮 -> cycle �ϼ�
		{
			if (Min > sum + p.second)
				Min = sum + p.second;
			return;
		}
	}
}


int main()
{
	int Test;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &Test);
	for (int T = 1; T <= Test; T++)
	{
		Min = 987654321;
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++)
			v[i].clear();
		for (int i = 0; i < M; i++)
		{
			int s, e, c;
			scanf("%d %d %d", &s, &e, &c);
			v[s].push_back({ e,c });
		}

		for (int i = 1; i <= N; i++) // �ܹ����̹Ƿ� ��� ��忡�� ó�� ����
		{
			visit[i] = 1;
			dfs(i, 0);
			visit[i] = 0;
		}
		if (Min == 987654321) // cycle������ -1���
			Min = -1;
		printf("#%d %d\n", T, Min);
	}
}