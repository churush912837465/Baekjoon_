
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

int N;
int M;
int arr[2004][2004];
vector<int> vec[2004];
int visit[2004];

void bfs(int _n)
{
	queue<int> qu;
	qu.push(_n);

	visit[_n] = 1; //�湮�ϸ� 1

	while (!qu.empty())
	{
		int mx = qu.front();
		qu.pop();

		for (int next : vec[mx]) // _n�� ����Ǿ� �ִ� 
		{
			if (visit[next] == 1) //�湮������ 
			{
				continue;
			}
			visit[next] = 1; //�湮ó��
			qu.push(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// ����ç����
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		arr[a][b] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (arr[i][j] && arr[j][i]) //���� �α��� �� �����ϸ� -> ���� ����Ǿ� �մ°�
			{
				vec[i].push_back(j);
				vec[j].push_back(i);
			}

		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] != 1) // �湮 �� ������
		{
			ans++;
			bfs(i);
		}
	}

	cout << ans;
}
