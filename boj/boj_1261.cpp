/*
#include <sstream> //split() , stringstream
#include <list>
#include <deque>
#include <map>
#include <stack>
//#include<cmath> // math.pow
using namespace std;
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm> // sort
#include <string.h> //memset
#include <string> //stoi()
#include<tuple> // turple

int N, M, R;

const int MAX = 101;
const int INF = 100000;
int arr[MAX][MAX];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int dp[MAX][MAX];

void bfs_01()
{
	// bfs�� �������� 
	queue < pair<int, int>> qu;
	qu.push({ 0,0 });	// ó���� 0
	dp[0][0] = 0;	// �� ó�� ����ġ�� 0

	while (!qu.empty())
	{
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();

		// �����¿� 4����
		for (int i = 0; i < 4; i++)
		{
			int nextY = y + dy[i];
			int nextX = x + dx[i];

			// ���� �ۿ� ������
			if (nextY < 0 || nextX < 0 || nextY >= M || nextX >= N)
				continue;

			// �� �϶�
			if (arr[nextY][nextX] == 1)
			{
				//dp �� ����
				if (dp[nextY][nextX] > dp[y][x] + 1)
				{
					dp[nextY][nextX] = dp[y][x] + 1;
					qu.push({ nextY , nextX });
				}

			}
			// ���� �ƴҶ�
			else if (arr[nextY][nextX] == 0)
			{
				//dp �� ����
				if (dp[nextY][nextX] > dp[y][x])
				{
					dp[nextY][nextX] = dp[y][x];
					qu.push({ nextY , nextX });
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			char ch = str[j];
			arr[i][j] = ch - '0';
			dp[i][j] = INF;	// �ϴ� ���� ū ������
		}
	}

	bfs_01();
	cout << dp[M - 1][N - 1];

}
*/
