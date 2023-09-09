
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

	//���� 2164
	queue<int> qu;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		qu.push(i); // 1���� N���� �ֱ�
	}

	while (qu.size() > 1)
	{
		qu.pop(); // 1������
		int f = qu.front();
		qu.push(f); // 2�ֱ�
		qu.pop();

	}

	cout << qu.front();
}
