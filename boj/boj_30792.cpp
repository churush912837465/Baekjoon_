/*
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
	// ����� �Բ��ϴ� 6ȸ �ڵ��׽�Ʈ

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	// 17��~20�����
	set<int> s;

	cin >> N;
	cin >> M;
	for (int i = 0; i < N - 1; i++)
	{
		int num;
		cin >> num;

		s.insert(num);
	}

	int idx = 0;
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
	{
		if (*iter >= M)
		{
			break;
		}
		else
		{
			idx++;
		}
	}

	cout << N - idx;


}

*/