
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
const int MAX = 10001;
vector<int> vec[MAX];
bool visit[MAX];

int ans;

void input()
{
	cin >> N;
}

void solve()
{

	// ���� �����̳� list ���
	list<char> passwd;	// list
	list<char>::iterator it; // list�� iterator
	// vector�� iterator�� ����� ����
	// vector<int>::iterator
	// ���� or ������<int>::iterator ->  Ư�� �����̳ʿ� ������ iterator ��ü ����

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;


		passwd.clear();	// �ʱ�ȭ
		it = passwd.begin();	// list���� Ư�� �ּڰ� �� Ŀ���� ��ġ


		for (int i = 0; i < str.length(); i++)
		{
			char ch = str[i];
			if (ch == '<')
			{
				// Ŀ���� �� ���̶��?
				if (it == passwd.begin())
					continue;

				// iterator�� �� ���� �ƴ� �� 
				// Ŀ�� --
				it--;
			}
			else if (ch == '>')
			{
				// Ŀ���� �� �ڰ���?
				if (it == passwd.end())
					continue;

				// iterator�� �� �ڰ� �ƴҶ�
				// Ŀ�� ++
				it++;
			}
			else if (ch == '-')
			{
				// ���� Ŀ�� �տ� �ִ� ���ڿ� ���찡
				if (it == passwd.begin())
					continue;

				it = passwd.erase(--it);
				// list.erase(iterator) -> ������ ���� ������ iterator ��ȯ
			}
			else
			{
				// �׳� ���ڿ��� �� ����
				it = passwd.insert(it, ch);
				// iter ��ġ�� ch�� ���� / ������ iterator ��ȯ
				it++;
			}

		}
		for (char ch : passwd)
			cout << ch;

		cout << endl;
	}
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
