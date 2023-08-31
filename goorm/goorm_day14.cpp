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
int K;
vector<int> vec[2001];
int visit[2001];

int dfs(int _n)
{
	visit[_n] = 1; //�湮�ϸ� 1

	if (vec[_n].size() == 0)  //ù��° ��� =������ �ϳ�
	{
		return _n;
	}

	//�װԾƴϸ�
	for (int next : vec[_n])
	{
		if (visit[next] == 1) // �湮������ 
		{
			continue;
		}

		//�湮��������
		return dfs(next);
	}

	return _n;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// ����ç����
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++)
	{
		int f, e;
		cin >> f >> e;

		vec[f].push_back(e);
		vec[e].push_back(f); // ���μ��� ����
	}

	//vec�� sort�ؾ��� �����������
	for (int i = 1; i <= N; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	/*
	for (int i = 1; i <= N; i++)
	{
		//cout << "i : " << i << endl;
		for (int temp : vec[i])
		{
			cout << temp << " ";
		}
		cout << endl;
	}
	*/

	int answereNode = dfs(K);
	int cnt = 0;

	for (int i = 0; i <= N; i++)
	{
		if (visit[i] == 1)
		{
			cnt++;
		}
	}

	cout << cnt << " " << answereNode;

}
