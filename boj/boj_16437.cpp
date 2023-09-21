
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
int animal[123457];
vector<long long> vec[123457];

bool visit[123457];

long long dfs(int node)
{
	//��������̸�?
	if (vec[node].size() == 0) //������ �ܹ�������
	{
		if (animal[node] > 0)
			return animal[node];
		else if (animal[node] < 0)
			return 0;
	}

	long long rst = 0;
	for (int next : vec[node])
	{
		rst += dfs(next);
	}

	rst += animal[node];
	if (rst < 0)
		return 0;
	else
		return rst;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : �Լ����� ����ϰ� �ٷγ�����

	//���� 16437
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		char ch;
		int many, node;
		cin >> ch >> many >> node;

		// i�� node�� ���� �Ǿ�����
		vec[node].push_back(i);

		if (ch == 'S') //���̸� ���
			animal[i] = many;
		else if (ch == 'W') //����� ����
			animal[i] = many * (-1);
	}

	long long n = dfs(1);
	cout << n;
}
