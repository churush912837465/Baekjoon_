
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


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : �Լ����� ����ϰ� �ٷγ�����
	// typeid(x).name() : �ڷ��� ���

	//���� 
	set<string> set;

	string str;
	cin >> str;

	string s = "";
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = i; j < str.length(); j++)
		{
			s += str[j];
			set.insert(s);
		}
		s = "";
	}

	cout << set.size();
}
