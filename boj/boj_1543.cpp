
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
	string a, b;
	getline(cin, a);
	getline(cin, b);

	int answer = 0;
	for (int i = 0; i < a.length(); i++)
	{
		bool check = true;

		for (int j = 0; j < b.length(); j++)
		{
			if (a[i + j] != b[j])
			{
				check = false;
				break;
			}
		}

		if (check)
		{
			answer++;
			i += b.length() - 1;
		}
	}



	cout << answer;

}
