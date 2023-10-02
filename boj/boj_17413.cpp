
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

	//���� 14425
	stack<char> sta;

	string str;
	getline(cin, str);

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '<')
		{
			// �±� ������ ��
			while (!sta.empty())
			{
				cout << sta.top();
				sta.pop();
			}

			while (true)
			{
				cout << str[i];
				if (str[i] == '>')
					break;
				i++;
			}
		}

		else if (str[i] == ' ')
		{
			while (!sta.empty())
			{
				cout << sta.top();
				sta.pop();
			}
			cout << " ";
		}

		else
		{
			sta.push(str[i]);
		}
	}

	//�������� ���ÿ� ����Ǿ� �ִ°� ���
	while (!sta.empty())
	{
		cout << sta.top();
		sta.pop();
	}


}