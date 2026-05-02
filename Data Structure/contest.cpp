#include<iostream>
using namespace std;

int main() {
	int n;
	int x;
	cin >> n >> x;
	bool flag=false;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] + a[j] == x)
			{
				flag = true;
			}
		}
	}

	if (flag)
		cout << "YES";
	else
		cout << "NO";
	
}