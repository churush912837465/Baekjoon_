
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

int N, M, R;
int arr[101];
string str;

bool alpha[27];
int cnt = 0;

void check(string s)
{
	//ù��°�� �湮ó��
	alpha[s[0] - 'a'] = true;
	for (int i = 1; i < s.length(); i++)
	{
		//�� ���ڶ� ������ -> ���� ���ڴ� �Ѿ��
		if (s[i] == s[i - 1])
			continue;

		//���� x , �湮 0
		else if (s[i] != s[i - 1] && alpha[s[i] - 'a'])
		{
			cnt++;
			break;
		}

		//���� x , �湮 x
		else
			alpha[s[i] - 'a'] = true;
	}

}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : �Լ����� ����ϰ� �ٷγ�����

	//����  1136
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		memset(alpha, false, sizeof(alpha));
		check(str);
	}

	cout << N - cnt;
	// cnt�� �׷�ܾ� x


}
