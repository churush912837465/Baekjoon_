
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
map<string, int> ma;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : �Լ����� ����ϰ� �ٷγ�����

	//���� 14425
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		ma.insert({ str, 0 }); //���ڿ� , 0
	}

	int cnt = 0;
	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;

		if (ma.find(str) != ma.end()) //ã����
			cnt++;
	}

	cout << cnt;
}
