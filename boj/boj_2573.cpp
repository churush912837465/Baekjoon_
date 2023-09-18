
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
const int MAX = 301;
int arr[MAX][MAX];
int visit[MAX][MAX];
int temp[MAX][MAX];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

bool visist[MAX][MAX];

void check(int y, int x)
{
	queue<pair<int, int >> qu;
	visit[y][x] = true;
	qu.push(make_pair(y, x));

	while (!qu.empty())
	{
		int _y = qu.front().first;
		int _x = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int my = _y + dy[i];
			int mx = _x + dx[i];

			if (mx < 0 || my < 0 || mx >= M || my >= N)
				continue;
			if (arr[my][mx] == 0) //�ٴٸ� �н� (������ ������ check)
				continue;
			if (visit[my][mx])
				continue;

			qu.push({ my, mx });
			visit[my][mx] = true;
		}
	}
}

void meltIce()
{
	memset(temp, 0, sizeof(temp));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0) //���̸� �н�
				continue;

			int cnt = 0;
			for (int p = 0; p < 4; p++)
			{
				int my = i + dy[p];
				int mx = j + dx[p];

				if (mx < 0 || my < 0 || mx >= M || my >= N)
					continue;

				if (arr[my][mx] == 0)
					cnt++;
			}

			int val = arr[i][j] - cnt; //���ǰ��� ����
			if (val > 0)
				temp[i][j] = val;
		}
	}

	//���� ���� �Ѵ��� arr�� ��������
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = temp[i][j];
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : �Լ����� ����ϰ� �ٷγ�����

	//���� 2573
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	int year = 0;
	while (true)
	{
		memset(visit, false, sizeof(visit)); //�˻��ϱ����� visit�ʱ�ȸ (bfs�� �˻�����)
		int len = 0; // bfs�� �˻��� ����
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!visit[i][j] && arr[i][j] != 0)
				{
					check(i, j); // bfs�� ���� ���ϱ�
					len++;
				}
			}
		}
		if (len == 0)
		{
			cout << 0;
			break;
		}
		if (len >= 2)
		{
			cout << year;
			break;
		}

		//�װ� �ƴϸ� 
		year++;
		//���ϳ��̱�
		meltIce();
	}
}
