
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


int N;
long long M;
vector<tuple<long long, long long, long long>> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// ����ç����
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		long long p, c;
		cin >> p >> c;

		vec.push_back(make_tuple(c / p, c, p)); //������ ������ ,  ������ , ����
	}

	sort(vec.begin(), vec.end(), greater<>()); // ������ ������ ������ ��������

	/*
	for (int i = 0; i < vec.size(); i++)
	{
		cout << get<0>(vec[i]) << " " << get<1>(vec[i]) << " " << get<2>(vec[i]) << endl;
	}
	*/

	long long myC = 0; //������
	long long myP = 0; //����

	for (int i = 0; i < N; i++)
	{
		long long divC = get<0>(vec[i]); //������ ������
		long long c = get<1>(vec[i]); // ������
		long long p = get<2>(vec[i]); // ����

		if (myP + p <= M) //������ ������
		{
			myC += c;
			myP += p;
			continue;
		}
		else
		{
			while (myP < M)
			{
				myP += 1;
				myC += divC;
			}
			break;
		}

	}

	cout << myC;

}
