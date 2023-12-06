
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
vector<pair<int, pair<int, int >>> edges;
const int MAX = 501;
const int INF = 123456789;
long long d[MAX];	// ���� �ּҰ� ���� �س���

bool bellmanFord(int start)
{
	d[start] = 0;	// ������ �ּҰ��� �׻� 0

	// 1������ N�� ��� ����
	for (int i = 1; i <= N; i++)
	{
		// ��� ���� Ȯ��
		// vector�� ��� ��簪 Ȯ��
		for (int j = 0; j < M; j++)
		{
			int from = edges[j].first;	// ������
			int to = edges[j].second.first;	// ������
			int cost = edges[j].second.second;	// ����-�������� ����ġ

			// ����ó�� 
			// ���簣���� �ѹ��� ����� �ȵǸ�
			if (d[from] == INF)
				continue;

			// ���������� ����Ǿ� �ִ� �� ���� 
			// ��������� ������ ���� ���� ���� �� ������ ? 
			if (d[to] > d[from] + cost)
			{
				d[to] = d[from] + cost;  //d �迭�� �� ����

				// N��°���� �ִ� �Ÿ��� ���ŵǸ�?
				// ��������Ŭ�� ����
				if (i == N)
					return true;
			}

		}
	}

	// ���������� �� �߻��ϸ�
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;	// ������, ������, ����ġ

		edges.push_back({ a, {b,c} });
	}

	fill(d, d + MAX, INF);	// �ּҰ��� ���� �س��� �迭�� �ʱ�ȭ

	bool negativeCycle = bellmanFord(1);	// 1�� ���ÿ��� ����
	if (negativeCycle) // ���� ������ �����
	{
		cout << -1 << '\n';
		return 0;
	}

	// ������(1��)�� ������ 
	// �ٸ� ��� ���� ���� ���� �ִܰŸ� ���
	for (int i = 2; i <= N; i++)
	{
		if (d[i] == INF) // ������ �ȵ� ����
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << d[i] << '\n';
		}

	}


}

