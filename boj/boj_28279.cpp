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


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	cin >> N;
	deque<int> de;

	for (int i = 0; i < N; i++)
	{
		cin >> M;


		if (M == 1)
		{
			cin >> R;
			de.push_front(R);
		}
		else if (M == 2)
		{
			cin >> R;
			de.push_back(R);
		}
		else if (M == 3)
		{
			if (de.empty())
				cout << "��" << -1 << '\n';
			else
			{
				int t = de.front();
				de.pop_front();
				cout << "��" << t << '\n';

			}
		}
		else if (M == 4)
		{
			if (de.empty())
				cout << "��" << -1 << '\n';
			else
			{
				int t = de.back();
				de.pop_back();
				cout << "��" << t << '\n';

			}
		}
		else if (M == 5)
		{
			cout << "��" << de.size() << '\n';
		}
		else if (M == 6)
		{
			if (de.empty())
				cout << "��" << 1 << '\n';
			else
				cout << "��" << 0 << '\n';
		}
		else if (M == 7)
		{
			if (de.empty())
				cout << "��" << -1 << '\n';
			else
				cout << "��" << de.front() << '\n';
		}
		else
		{
			if (de.empty())
				cout << "��" << -1 << '\n';
			else
				cout << "��" << de.back() << '\n';
		}
	}


}

