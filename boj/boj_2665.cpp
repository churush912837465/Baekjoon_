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

const int MAX = 51;
const int INF = 12345678;
int arr[MAX][MAX];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int dp[MAX][MAX];

void bfs_01()
{
	// ª�� �� �̸�, �켱����ť�� �μ��º��� �� ������(����ġ)�� ���� ���� �� ����
	priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
	// ����ġ (�μ��� ���� ����) , y��ǥ x ��ǥ
	pq.push({ 0 , {0,0} });
	dp[0][0] = 0;	// �� ó�� ����ġ�� 0

	while (!pq.empty())
	{

		int breakWall = pq.top().first;	// �μ� ���� ����
		int nowY = pq.top().second.first;	//���� y
		int nowX = pq.top().second.second;	// ���� x
		pq.pop();

		// �����¿� 4����
		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];

			// ���� �ۿ� ������
			if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N)
				continue;

			// dp �迭 �� ����
			// �ּڰ��� ���ϴ� �Ŵϱ� dp�� ���� �Ǿ� �ִ� �� ���� ũ�� ���� x

			// dp ���
			int nextDist = 0;
			if (arr[nextY][nextX] == 1)
				nextDist = 0;
			else if ((arr[nextY][nextX] == 0))
				nextDist = 1;

			if (dp[nextY][nextX] > dp[nowY][nowX] + nextDist)
			{
				dp[nextY][nextX] = dp[nowY][nowX] + nextDist;
				pq.push({ dp[nextY][nextX] , {nextY, nextX} });
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

	cin >> N;
	for (int i = 0; i < N; i++)
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
	cout << dp[N - 1][N - 1];
}

