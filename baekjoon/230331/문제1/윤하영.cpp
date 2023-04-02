#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> egg(10);
bool visit;
int ans=0;

void dfs(int x) {  // ���� ������ ����� ���
	if (x == N) // ���� �ֱٿ� �� ����� ���� �����ʿ� ��ġ�� ����� ���
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)	{ if (egg[i].first <= 0) cnt++;	}
		ans = max(ans, cnt); // ���� ������ �ִ� ���� ����� ���� ���� ���� ���� ���� ����� ���� ����
		return;
	}

	if (egg[x].first <= 0) { dfs(x + 1); }
	else
	{
		visit = true;
		for (int i = 0; i < egg.size(); i++) // 3. ���� �ֱٿ� �� ��� ��ĭ ������ ����� ��� 2���� �ݺ��Ѵ�.
		{
			if (x != i && egg[i].first > 0) // 2. �տ� ��� �ִ� ������� ������ ���� �ٸ� ��� �� �ϳ��� ģ��.
			{
				visit = false;
				egg[x].first -= egg[i].second;
				egg[i].first -= egg[x].second;
				dfs(x + 1);
				egg[x].first += egg[i].second; // ���ϴ� ���� ã�� ������ ��� ���� ���·� ��������(��Ʈ��ŷ)
				egg[i].first += egg[x].second;
			}
		}
		if (visit) { dfs(N); } // ��� ����� �����ִٸ� �ٷ� ����(x==N�̸� �����ϹǷ�)
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int S, W;
		cin >> S >> W;
		egg[i].first = S;
		egg[i].second = W;
	}

	dfs(0);

	cout << ans;

	return 0;
}