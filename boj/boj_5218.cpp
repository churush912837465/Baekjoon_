
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
	for (int i = 0; i < N; i++)
	{
		vector<int> vec;
		string s1, s2;
		cin >> s1 >> s2;

		for (int j = 0; j < s1.length(); j++)
		{
			char c1, c2;
			c1 = s1[j];
			c2 = s2[j];

			if (c2 >= c1)
				vec.push_back(c2 - c1);
			else
				vec.push_back((c2 + 26) - c1);
		}

		cout << "Distances: ";
		for (int j = 0; j < vec.size(); j++)
		{
			cout << vec[j] << " ";
		}
		cout << endl;
	}

}

