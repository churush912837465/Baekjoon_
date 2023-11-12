
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

int N, M, R;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	string str;
	while (cin >> str)
	{
		// ���� ����
		if (str == "end")
			break;

		bool answer = true;
		bool flag = false;
		int con = 0; // ���� ������ ����
		int vow = 0; // ���� ������ ����
		for (int i = 0; i < str.length(); i++)
		{

			char ch = str[i];

			// �����̸�? 
			bool is = false;
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			{
				is = true;

			}

			if (is)
			{
				// �����̸�
				flag = true;
				con = 0;
				vow++;
			}
			else //�����̸� 
			{
				con++;
				vow = 0;
			}

			// 3���� ���ӵǸ�? (����2)
			if (con == 3 || vow == 3)
			{
				answer = false;
				break;
			}
			// ���� �ΰ� ���ڰ� ����? (����3)
			if (i > 0 && str[i - 1] == str[i] && !(ch == 'e' || ch == 'o'))
			{
				answer = false;
				break;
			}
		}

		if (!flag)
			answer = false;

		if (answer)
			cout << "<" << str << "> is acceptable.\n";
		else
			cout << "<" << str << "> is not acceptable.\n";
	}


}

