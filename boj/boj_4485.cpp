
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
int X, Y;
const int MAX = 126;
const int INF = 12345678;

int arr[MAX][MAX];
int d[MAX][MAX];	// �ּ� �Ÿ��� ��Ƴ���

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

//bfs�� �������� �ٿ���Ʈ��
void Bfs_Dijkstra(int y, int x)
{
	// �ٿ���Ʈ�� �켱����ť
	priority_queue < pair<int, pair<int, int>>, vector < pair<int, pair<int, int>> >, greater< pair<int, pair<int, int>>> > pq;
	pq.push({ arr[y][x] , {y , x} });
	// �Ÿ� , {y��ǥ , x ��ǥ}
	d[y][x] = arr[y][x];
	// ó�� - �Ÿ�

	while (!pq.empty())
	{
		// ���� ���
		int dist = pq.top().first;	// ������� �Ÿ�
		int nowY = pq.top().second.first;	// ���� ��� Y
		int nowX = pq.top().second.second;	// ���� ��� X
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dy[i];	// ���� y��ǥ
			int nextX = nowX + dx[i];	// ���� x ��ǥ

			// ������ǥ�� �迭 �Ѿ�� �ȵ�
			if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N)
				continue;

			int nextdist = dist + arr[nextY][nextX];

			if (nextdist < d[nextY][nextX])
			{
				// �Ÿ� ����
				d[nextY][nextX] = nextdist;	//�� ª���ɷ� ����

				// �켱���� ť�� �Ÿ��� ���� ��� �ֱ�
				pq.push({ nextdist, { nextY , nextX } });
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

	int idx = 1;
	while (true)
	{
		cin >> N;

		if (N == 0)
			break;

		// �ʱ�ȭ
		fill(arr[0], arr[MAX - 1], 0);
		fill(d[0], d[MAX - 1], 0);

		//�Է�
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		// �ִ밪���� �̸� ä����
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				d[i][j] = INF;
			}
		}

		Bfs_Dijkstra(0, 0); // ������

		/*
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << d[i][j] << " ";
			}
			cout << endl;
		}
		*/
		cout << "Problem " << idx << ": " << d[N - 1][N - 1] << '\n';
		idx++;
	}

}

