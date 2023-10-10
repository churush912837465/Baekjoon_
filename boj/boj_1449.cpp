
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

	// ���� 1049
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		vec.push_back(temp);

	}

	// ��ġ�� ������������ ����
	sort(vec.begin(), vec.end());

	int tape = 0;
	int start = vec[0];

	for (int i = 1; i < vec.size(); i++)
	{
		//�Ÿ�
		if (vec[i] - start >= M)
		{
			start = vec[i];
			tape++;
		}
	}
	cout << tape + 1;


}
