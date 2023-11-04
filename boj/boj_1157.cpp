
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

int N, M;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : �Լ����� ����ϰ� �ٷγ�����
	// typeid(x).name() : �ڷ��� ���

	string str;
	cin >> str;

	int arr[27];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < str.length(); i++)
	{
		// �빮�ڸ�?
		if (str[i] - 96 <= 0)
		{
			arr[str[i] - 'A'] += 1;
		}
		//�ҹ��ڸ�
		else
		{
			arr[(str[i] - 32) - 'A'] += 1;
		}
	}

	int max = 0; //���� Ƚ�� ����
	char answer;
	for (int i = 0; i < 27; i++)
	{
		//���� ���� ��
		if (arr[i] != 0)
		{
			if (arr[i] > max)
			{
				max = arr[i];
				answer = i + 'A';
			}

			else if (arr[i] == max)
				answer = '?';

		}
	}

	cout << answer;
}

