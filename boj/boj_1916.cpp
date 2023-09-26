
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

int N, M, R;
int sNode, eNode;
const int MAX = 1001;
const int INF = 100000000;
vector<pair<int, int>> vec[MAX]; // vec[N]{} : N�� ����� ��� , ����ġ
int d[MAX];

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// �Ÿ�, �ش� ���

	pq.push({ 0,start }); // ���� - ���� �Ÿ��� 0
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist)
			continue;

		for (int i = 0; i < vec[now].size(); i++) //���� ���� ����Ǿ� �ִ� ��� Ž��
		{
			int next = vec[now][i].first;
			int cost = dist + vec[now][i].second;

			// ���� + ����->���� ��� ���� �Ÿ� vs d[next]�� ����Ǿ� �ִ� �ּҰŸ�
			if (cost < d[next])
			{
				d[next] = cost;
				pq.push({ cost, next });
			}
		}

	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : �Լ����� ����ϰ� �ٷγ�����

	//���� 1916
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;

		vec[s].push_back({ e , w });
	}
	cin >> sNode >> eNode; //���۳�� , ���� ���

	fill(d, d + MAX, INF); //�ִ밪���� äv���ֱ�
	dijkstra(sNode);

	// ����� �ּ� ��� ���
	cout << d[eNode];

}
