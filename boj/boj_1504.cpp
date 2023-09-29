
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
const int MAX = 801;
const int INF = 100000000;
vector<pair<int, int>> vec[MAX]; // ���۳�� -> ����� ,  ���
int d[MAX];
bool visit[MAX];
int v1, v2;

void dijkstra(int start)
{
	// d �ʱ�ȭ
	fill(d, d + MAX, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// ����, ���۳��
	pq.push({ 0,start });
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first; //���
		int now = pq.top().second; //���� ���
		pq.pop();

		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i].first; //next ���
			int cost = dist + vec[now][i].second; //next������ ���� ���

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

	//���� 1504 ���� ��ǰ!

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}

	cin >> v1 >> v2; // �ݵ�� ������ �ϴ� �ΰ��� ���


	// 1 -> A -> B -> N
	// 1 -> B -> A -> N

	int sToV1, sToV2, V1ToV2, V1ToN, V2ToN;
	dijkstra(1);
	sToV1 = d[v1];
	sToV2 = d[v2];

	dijkstra(v1);
	V1ToV2 = d[v2];
	V1ToN = d[N];

	dijkstra(v2);
	V2ToN = d[N];

	int res = INF;
	res = min(res, sToV1 + V1ToV2 + V2ToN);
	res = min(res, sToV2 + V1ToV2 + V1ToN);
	if (V1ToV2 == INF || res == INF) cout << -1;
	else cout << res;
}
