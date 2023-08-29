
#include <sstream> //split() , stringstream
#include <list>
#include <deque>
#include <map>
#include <stack>
#include<cmath> // math.pow
using namespace std;
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm> // sort
#include <string.h> //memset
#include <string> //stoi()
#include<tuple> // turple

#define MAX 10001
#define INF 123456789

int N;
int M;
int coin[MAX];
int dp[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// ���� 2294 ����2
	// �̰� Ǯ�� �����ϱ�!
	cin >> N >> M;

	// dp �迭�� ���� �������� ���� ����, 
	// ���������̶� �ּڰ� ����
	for (int i = 0; i < N; i++)
	{
		cin >> coin[i]; // ���� ��Ƴ��� �迭
	}

	// �ּҰ��� ���ؾ� �ϱ� ������
	for (int i = 0; i <= M; i++) {
		dp[i] = INF;
		//dp�迭�� �ִ����� ����
	}

	dp[0] = 0;
	// dp[n] = ���� n�� ���� ����
	for (int i = 0; i < N; i++) // 1 5 12
	{
		for (int j = coin[i]; j <= M; j++)
		{
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
			// 1�϶��� ó������~15
			// 5�϶��� 5~15
			// 12�϶��� 12~15
		}
	}

	if (dp[M] == INF)
	{
		cout << -1;
	}
	else
	{
		cout << dp[M];
	}

}

