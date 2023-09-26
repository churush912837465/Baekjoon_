
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
const int INF = 100000000;
const int MAX = 1010;
vector<pair<int, int>> vec[MAX];
int d[MAX];
int r[MAX];

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // �Ÿ� ,  ������
	pq.push({ 0 ,start });
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first; //���� �������� �Ÿ�
		int now = pq.top().second; //���� ���
		pq.pop();

		for (int i = 0; i < vec[now].size(); i++) // ���� ���� ����� ��� Ž�� 
		{
			int next = vec[now][i].first; //�������
			int cost = dist + vec[now][i].second; //���� �������� �Ÿ� + ���� ������ ���� �Ÿ�

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

	//���� 

	cin >> N >> M >> S;
	for (int i = 0; i < M; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;

		vec[s].push_back({ e,w });
	}

	// ��� ��忡�� start�� ���� ��ΰ� 
	for (int i = 1; i <= N; i++)
	{
		fill(d, d + MAX, INF);
		dijkstra(i); // 1���� 4 ����,��� ��θ� ���ϱ�
		r[i] = d[S];
		// r�迭���� ������������ ���� �ּҺ�� ����
	}

	fill(d, d + MAX, INF);
	dijkstra(S); // ���� �뤡����� �� ��� ���� ���� ��θ� d�� ����

	for (int i = 1; i <= N; i++)
	{
		r[i] = r[i] + d[i];
	}
	sort(r + 1, r + N + 1);
	int answer = r[N];

	cout << answer;


}
