
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
vector<int> vec[32001]; // ���� ���� 
int enterance[32001]; // ���� ����

int answer[32001];
void topologySort()
{
	queue<int> qu;

	// ������ (�ʱⰪ) �ֱ�
	// ���������� 0�� ��带 ť�� ����
	// vec�� ���� �Ǿ� �ִ°� 1 ~ N ���� ������ for������ �� �ϴµ�!
	for (int i = 1; i <= N; i++)
	{
		if (enterance[i] == 0)
			qu.push(i);
	}

	// ���� ������ �Ƿ��� N ���� ��带 �湮 �ؾ���
	for (int i = 1; i <= N; i++)
	{
		// N ���� ��带 �湮�ϱ� ���� qu�� ���?
		// = ����Ŭ�� �߻�, �������� �Ұ���
		if (qu.empty())
			return; // �Լ� ����������

		int x = qu.front();
		qu.pop();
		answer[i] = x; // ���������� ������ qu���� ���� ����, ���� ������� ���� �迭�� �־���

		// x�� ���� �Ǿ��ִ� ��� Ž��, �������� �ϳ��� ���̱� 
		// ���� ������ ������
		for (int i = 0; i < vec[x].size(); i++)
		{
			// ���� ���� ������ ���� �ߴµ�( -- ), ���������� 0�� �Ǹ�
			// ť�� �ֱ�
			if (--enterance[vec[x][i]] == 0)
				qu.push(vec[x][i]);

		}
	}

	// ���� ���� ��
	for (int i = 1; i <= N; i++)
	{
		cout << answer[i] << " ";
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
	for (int i = 0; i < M; i++)
	{
		int f, e;
		cin >> f >> e;
		vec[f].push_back(e); // 1�� 3�� ���� �Ǿ� ����
		++enterance[e];
		// �������� ���������� 0 (���������� �ƹ��͵� �ȵ��ͼ� 0)
	}

	topologySort();
}

