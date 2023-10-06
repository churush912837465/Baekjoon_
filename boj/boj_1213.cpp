
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
int arr[26];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : �Լ����� ����ϰ� �ٷγ�����
	// typeid(x).name() : �ڷ��� ���

	//���� 1213 c++
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		arr[str[i] - 'A'] += 1;
	}

	//�˻�
	int cnt = 0;

	for (int i = 0; i < 27; i++)
	{
		if (arr[i] % 2 == 1) //���ĺ��� ������ Ȧ����
		{
			cnt++;
		}

	}

	string ans = "";
	//���ĸ��� ������ Ȧ���ΰ� �ΰ� �̻� �����Ѵٸ�
	if (cnt >= 2)
	{
		cout << "I'm Sorry Hansoo";
	}
	else  //�縰��� ���ϱ�
	{
		// ���� ���� ���� ���ĺ��� ����/2�� ����
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < arr[i] / 2; j++)
			{
				ans += i + 'A';
			}
		}
		for (int i = 0; i < 26; i++)
		{
			if (arr[i] % 2)
				ans += i + 'A';
		}

		for (int i = 26; i >= 0; i--)
		{
			for (int j = 0; j < arr[i] / 2; j++)
			{
				ans += i + 'A';
			}
		}
	}
	cout << ans;

}
