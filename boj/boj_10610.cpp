
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

	//���� 14425
	string str;
	cin >> str;

	long long sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		vec.push_back(str[i] - '0');
		sum += str[i] - '0'; // �� �ڸ��� ���ϱ�
	}

	sort(vec.begin(), vec.end(), greater<>());

	if (sum % 3 == 0 && vec[vec.size() - 1] == 0) //�� �ڸ� ���� ���� 3�� ����̰� ������ ���� 0�̿��� -> 3�� ���
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i];
		}
	}
	else
		cout << -1;


}
