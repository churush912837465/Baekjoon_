
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

int N, M;
const int MAX = 501;
int arr[MAX][MAX];
int dp[MAX][MAX];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int dfs(int x, int y) // dp�� -1�� �ʱ�ȭ�Ǿ�����
{
	if (x == N - 1 && y == M - 1) // �������� �����ϸ� ?
	{
		return 1;
	}
	if (dp[x][y] != -1) //�湮������? 
	{
		return dp[x][y];
	}

	dp[x][y] = 0; //�湮�� �����ϱ� 0����
	for (int i = 0; i < 4; i++)
	{
		int mx = x + dx[i];
		int my = y + dy[i];

		if (mx < 0 || my <0 || mx >= N || my >M)
		{
			continue;
		}

		// ��ܼ����� �������� �Ѿ�� ������?
		if (arr[mx][my] < arr[x][y])
		{
			dp[x][y] = dp[x][y] + dfs(mx, my);
		}
	}

	// ���� ������ return?
	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//���� 1520
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	// dp[][]�� -1 : ���� �湮���� x
	// dp[][]�� 0 : 0�� 

	int answer = dfs(0, 0);
	cout << answer;
}
