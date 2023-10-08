
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

bool comp(pair<string, int>& a, pair<string, int>& b) //pair�� vector �� (���� �ܿﶧ�� �Ǿ���!
{
	if (a.second == b.second)
	{
		if (a.first.length() == b.first.length())
			return a.first < b.first; //������ 
		return a.first.length() > b.first.length(); //���ڿ� ���� �� 
	}
	return a.second > b.second; // ���� Ƚ����
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : �Լ����� ����ϰ� �ٷγ�����
	// typeid(x).name() : �ڷ��� ���

	//���� 
	cin >> N >> M;

	map<string, int> m;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		if (str.length() >= M) //���ǿ� ������
			m[str]++; //map�� key�� �´� value�� ����
	}

	// map�� ���� �ؾ��� ��! -> ���� vector�� �ű�� , �����ϴµ�?
	vector<pair<string, int>> vec(m.begin(), m.end());
	// -> map�� begin���� end���� ���� vector�� '����'��
	sort(vec.begin(), vec.end(), comp);

	for (auto p : vec)
		cout << p.first << '\n';

}
