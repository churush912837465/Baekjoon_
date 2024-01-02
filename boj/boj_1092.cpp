
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
#include<unordered_map>

int N, M, R, C;
vector<int> crain;
vector<int> box;

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		crain.push_back(temp);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		box.push_back(temp);
	}

}

void solve()
{
	// �Ѵ� ����
	sort(crain.rbegin(), crain.rend());	// �������� ����
	sort(box.rbegin(), box.rend());

	int answer = 0;

	// �Ұ����� ���
	// ũ������ �� �� �ִ� ���Ժ��� box�� �� ũ��
	if (crain.front() < box.front())
	{
		cout << -1;
		return;
	}

	// weight���� �ش� ���ڸ� �ű�� ������ vector���� remove
	while (!box.empty())
	{
		// box�� ����������
		answer++;
		for (int i = 0; i < N; i++)
		{
			int we = crain[i];

			for (int j = 0; j < box.size(); j++)
			{
				if (we >= box[j])
				{
					// �ű�� ������ ����
					box.erase(box.begin() + j);	//box�� j ��° ��� �����
					break;
				}
			}
		}
	}
	cout << answer;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	input();
	solve();

}
