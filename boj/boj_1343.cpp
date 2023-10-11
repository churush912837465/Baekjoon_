
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
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : �Լ����� ����ϰ� �ٷγ�����
	// typeid(x).name() : �ڷ��� ���

	// ���� 1343
	string str;
	cin >> str;

	int cnt = 0;
	string answer = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'X')
			cnt++;
		if (str[i] == '.')
		{
			answer += '.';
			if (cnt % 2 != 0) //2�� �ȳ����� ���� -> AAAA�� BB�� ������
				break;
			else
				cnt = 0;
		}

		//���ڿ� �˻� -> �� ���� ���� �˻�!
		// BB������ XX�� ���� BB+BB�� �ƴ϶� AAAA ���� ���� ���� �˻��ϴµ�!
		if (cnt == 2 && str[i + 1] != 'X')
		{
			answer += "BB";
			cnt = 0;
		}
		else if (cnt == 4)
		{
			answer += "AAAA";
			cnt = 0;
		}

	}

	if (cnt % 2 != 0)
		cout << -1;
	else
		cout << answer;
}
