
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

	// ����  
	cin >> N;


	for (int i = 0; i < N; i++)
	{
		vector<int> vec;

		cin >> M;
		for (int j = 0; j < M; j++)
		{
			int temp;
			cin >> temp;

			vec.push_back(temp);
		}

		//�ڿ��� ���� max ���� ������
		// max - �ش� �� �� answer�� ���ϰ�
		// max ���� ũ�� max ���� �ٲ۴�
		int _max = -1;
		long long answer = 0;
		for (int j = M - 1; j >= 0; j--)
		{
			// max�� vec[j]�߿� �� ū�� ��������
			//_max = max(_max, vec[j]);
			//answer += _max - vec[j];

			if (_max < vec[j])
			{
				_max = vec[j];
				continue;
			}
			else if (_max > vec[j])
				answer += _max - vec[j];
		}

		cout << answer << '\n';
	}

}
