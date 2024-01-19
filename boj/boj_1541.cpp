
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
#include<unordered_map>

int N, M, R, C;
string str;

void input()
{
	cin >> str;
}

void solve()
{
	bool flag = false;	// -�� ���Ӵ��� �ƴ��� 
	string temp = "";
	int answer = 0;

	// -�� ������ �ڿ� �ִ� + ������ ���ش�
	for (int i = 0; i <= str.length(); i++)
	{
		char next = str[i];

		// ��ȣ�϶�
		if (next == '+' || next == '-' || i == str.size())	//���϶��� ���� 
		{
			// �տ� -�� �� ������ ��
			if (flag == false)
			{
				answer += stoi(temp);
				temp = "";
			}

			// �տ� -�� ������ ��
			else if (flag == true)
			{
				answer -= stoi(temp);
				temp = "";
			}
		}

		// ������ ��
		else
		{
			temp += next;
		}

		if (next == '-')
			flag = true;

	}

	cout << answer;
}

void print()
{

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	input();
	solve();
	print();
}
