
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
#include <algorithm>
#include <string.h> //memset
#include <string> //stoi()
#include<tuple> // turple

int N;
int M = 3;
string str;
vector<char> vec; // �⺻ ����
vector<tuple<string, string, string>> strvec;
set<string> s;

int getIter(string abc)
{
	int position = 0;
	auto iter = s.find(abc);
	if (iter != s.end()) {
		position = distance(s.begin(), iter);
	}
	return position;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 6���� ������ ç����
	// ���̰� n���� ���ڿ��� r�� ������ ����� ����?

	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++)
	{
		vec.push_back(str[i]);
	}

	//������ ���ڿ��� ������ 3�� -> ��������

	string start = "";

	for (int i = 0; i < N; i++)
	{

		start += vec[i];

		//cout << "start : " << start;
		string mid = "";
		string end = "";

		for (int j = i + 1; j < N - 1; j++)
		{
			mid += vec[j];
			end = str.substr(j + 1);

			//cout << " mid / end : " << mid << " " << end;

			strvec.push_back(make_tuple(start, mid, end));
			s.insert(start);
			s.insert(mid);
			s.insert(end);
		}
		//cout << endl;
	}

	/*
	cout << "---�ߺ�����---" << endl; //set���� �ߺ�����
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << endl;
	}*/


	// �� ã��
	//cout << "--�� ã�� ---" << endl;
	int score = 0;
	for (int i = 0; i < strvec.size(); i++)
	{
		//a,b,cd
		//getIter ���ڿ��� set���� ���°���� ��ȯ
		int n1 = getIter(get<0>(strvec[i])) + 1;
		int n2 = getIter(get<1>(strvec[i])) + 1;
		int n3 = getIter(get<2>(strvec[i])) + 1;
		int sum = n1 + n2 + n3;

		//cout << "sum : " << sum << endl;
		score = max(score, sum);

	}
	cout << score;

}






