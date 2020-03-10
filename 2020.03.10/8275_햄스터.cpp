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


void dfs(int index) // condition의 index번째에 마리 수 저장
{
	if (index == 0 ) // 모든 칸에 햄스터 수 넣었으면 조건만족하는지 확인
	{
		for (int i = M; i > 0; i--) 
		{
			int total = 0;
			for (int s = condition[i].first.second; s >= condition[i].first.first; s--)
				total += num[s];
			if (total != condition[i].second) // 조건보다 작거나 크면 만족x 
				return;
		}
		flag = true; // 만족하는 경우 flag 설정하고 이후 계산 안하도록
		return;
	}

	for (int i = X; i >= 0; i--) // 여러개가 가능한 경우 가장 큰수 넣기 
		// -> 처음부터 크게 시작하면 가장 처음 나오는 답이 곧 결과
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
		dfs(N); // 1~N의 우리에 개수 정해주기
		// 사전순 -> 뒤가 더 커야한다 -> 마지막 index부터 가장 큰수부터 넣기

		printf("#%d ", T);
		if (flag) // 답이 있으면 답 출력
		{
			for (int i = 1; i <= N; i++)
				printf("%d ", num[i]);
			printf("\n");
		}
		else // 답이 없으면 -1 출력
			printf("-1\n");
	}

}