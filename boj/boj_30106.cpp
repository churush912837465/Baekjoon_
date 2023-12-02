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
const int MAX = 501;
int arr[MAX][MAX];
int visit[MAX][MAX];

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
void bfs(int y, int x)
{
	queue<pair<int, int>> qu;
	qu.push({ y,x });
	visit[y][x] = true;

	while (!qu.empty())
	{
		int _y = qu.front().first;
		int _x = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int my = _y + dy[i];
			int mx = _x + dx[i];

			if (my < 0 || mx < 0 || my >= N || mx >= M)
				continue;
			if (visit[my][mx])
				continue;


			// �ڸ����� ���̰� R �̻��̸�
			if (abs(arr[_y][_x] - arr[my][mx]) > R)
				continue;

			qu.push({ my, mx });
			visit[my][mx] = true;

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

	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	int _cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visit[i][j])
			{
				bfs(i, j);
				_cnt++;
			}
		}
	}

	cout << _cnt;

}

