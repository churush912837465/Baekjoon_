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

const int MAX = 1010;
const int INF = 2000000000;
int Nstart = 0;
int Nend = 0;
vector<pair<int, int>> vec[MAX];
int d[MAX];
int route[MAX];

void dijstra()
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, Nstart));
	d[Nstart] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dist > d[node])	//�̰� ��� �ð� �ʰ� ����!
			continue;

		for (int i = 0; i < vec[node].size(); i++)
		{
			int next = vec[node][i].first;
			int nextdist = vec[node][i].second;

			if (d[next] > nextdist + dist)
			{
				route[next] = node;	// next ��带 ���� ���ؼ��� node(������)�� ���ľ���
				d[next] = nextdist + dist;
				pq.push({ -d[next], next });
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

	cin >> N >> M;

	for (int i = 0; i <= N; i++)
		d[i] = INF;

	for (int i = 0; i < M; i++)
	{
		int s, e, d;
		cin >> s >> e >> d;
		vec[s].push_back({ e, d });
	}

	cin >> Nstart >> Nend;
	dijstra();


	// ��� ���� �� �ϰ� �� ��
		// ���1 : �������� �ּ� ���
	cout << d[Nend] << '\n';

	vector<int> route_vec;
	int temp = Nend;
	while (temp) // temp�� ������ ��
	{
		route_vec.push_back(temp);
		temp = route[temp];
	}
	// temp = 5 , 5�� ������ 3�� ���ľ��� 3 = temp
	// temp = 3 . 3�� ������ 1�� ���ľ��� 1 = temp
	// temp = 1 , 1�� ������ 0�� �������� -> while�� ����

	// ���2 : ���������� �ִܰ�η� ���� ��� ����
	cout << route_vec.size() << '\n';

	// ���3 : ������ ��� ���
	for (int i = route_vec.size() - 1; i >= 0; i--)
	{
		cout << route_vec[i] << " ";
	}
	cout << '\n';
}

