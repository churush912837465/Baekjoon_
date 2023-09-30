
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

int N, M, S;
const int MAX = 5001;
const int INF = 100000000;
vector<pair<int, int>> vec[MAX]; // a�� ����� ��� b,  ����ġ c
int d[MAX];
bool visit[MAX];

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //������ �ּҰŸ� ,  ���� ���
	pq.push({ 0 , start }); // ù��° ���� �������� �ּҰŸ��� 0
	d[start] = 0;
	visit[start] = true; //�湮ó��

	while (!pq.empty())
	{
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		visit[now] = true;

		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i].first;
			int cost = vec[now][i].second + dist; // next ��� ������ �Ÿ�

			if (!visit[next])
			{
				if (cost < d[next])
				{
					d[next] = cost;
					pq.push({ cost, next });
				}
			}

		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : �Լ����� ����ϰ� �ٷγ�����

	//���� 
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vec[a].push_back({ b,c }); //����� ����
		vec[b].push_back({ a,c });

	}
	int s, t;
	cin >> s >> t;

	fill(d, d + MAX, INF);
	dijkstra(s);
	cout << d[t];

}
