
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
int R, T; //���� , ��
const int MAX = 101;
vector<int> vec[MAX];
int visit[MAX];

queue<int> qu;

void bfs(int x)
{
	visit[x] = 1; //ó�������� 1 , 0���� �ʱ�ȭ (�湮���ϸ� 0)
	qu.push(x);

	while (!qu.empty())
	{
		int n = qu.front();
		qu.pop();

		if (n == T)
		{
			cout << visit[n] - 1;
			exit(0);
		}

		for (int next : vec[n])
		{
			if (visit[next] != 0)
				continue;
			visit[next] = visit[n] + 1;
			qu.push(next);
		}

	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//���� 
	cin >> N;
	cin >> R >> T;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		//���μ��� �����ϱ�
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	memset(visit, 0, sizeof(visit));

	bfs(R);
	cout << -1;

}
