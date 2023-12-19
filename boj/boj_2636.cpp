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
int arr[MAX][MAX];
bool visit[MAX][MAX];

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0 ,1, 0, -1 };

void bfs()
{
	fill(visit[0], visit[MAX - 1], false);

	queue<pair<int, int>> qu;
	qu.push({ 0,0 });
	visit[0][0] = true;

	while (!qu.empty())
	{
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (visit[ny][nx])
				continue;

			// �湮ó��
			visit[ny][nx] = true;

			// ���� 1 �̸�? -> 0���� �ٲٱ�
			if (arr[ny][nx] == 1)
			{
				arr[ny][nx] = 0;
				continue;
			}

			// ���� 0 �̸�? -> ���Ⱑ ����
			else if (arr[ny][nx] == 0)
			{
				qu.push({ ny, nx });
			}
		}
	}

}

int countCheese()
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1)
				count++;
		}
	}

	return count;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	vector<int> vec; // ġ� � ���Ҵ��� �����س��� 
	vec.push_back(0);	// ù��° �ƹ����� �־����
	int answer = 0;
	while (true)
	{
		int left = countCheese();	// ���� ġ���
		if (left == 0)
			break;

		answer++;	// ��ð� ��������
		bfs();		// bfs
		vec.push_back(left);
	}

	cout << answer << '\n';
	cout << vec[vec.size() - 1];

}

