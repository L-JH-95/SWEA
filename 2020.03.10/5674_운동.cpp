// 5674. 운동
/*
union find는 양방향이 아니라 안되는듯 (bfs : priority queue)
-> dfs사용
단방향 그래프이기 때문에 i=1~N 까지 시작하며 모두 확인
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int N, M;
int Min;
vector <pair<int, int>> v[401]; // v[시작점].push_back({끝점, 도로의 길이})
int visit[401];

void dfs(int index, int sum)
{
	if (Min < sum) // 최소값보다 현재 합이 크면 볼 필요 x -> 안해주면 시간최과
		return;
	for (int i = 0; i < v[index].size(); i++) // 단방향으로 연결된 노드만 확인
	{
		pair <int, int> p = v[index][i];
		if (visit[p.first] == 0) // 처음 방문
		{
			visit[p.first] = 1;
			dfs(p.first, sum + p.second);
			visit[p.first] = 0;
		}
		else // 이미 방문 -> cycle 완성
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

		for (int i = 1; i <= N; i++) // 단방향이므로 모든 노드에서 처음 시작
		{
			visit[i] = 1;
			dfs(i, 0);
			visit[i] = 0;
		}
		if (Min == 987654321) // cycle없으면 -1출력
			Min = -1;
		printf("#%d %d\n", T, Min);
	}
}