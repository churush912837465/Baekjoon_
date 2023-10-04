
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
//���ı���
bool cmp(pair<string, int>& a, pair<string, int>& b)
{
	return a.second > b.second;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : �Լ����� ����ϰ� �ٷγ�����
	// typeid(x).name() : �ڷ��� ���

	//���� 1302
	map<string, int> ma;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		ma[str] ++; //find�� �˻� ���ϰ� value�� ���� ���ѵ� �ǳ�?
	}

	int result = 0;
	for (auto i = ma.begin(); i != ma.end(); i++)
	{
		result = max(result, i->second); //���� ū value ã��
	}

	for (auto i = ma.begin(); i != ma.end(); i++)
	{
		// ���� ū value�� ���� key�� ã��
		if (result == i->second)
		{
			cout << i->first;
			break;
		}
	}
}
