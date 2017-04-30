#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <string>

using namespace std;

void print_vector(vector<vector<int>> arr, string a, string b)
{
	cout << "    ";
	for (int k = 0; k < arr[0].size(); k++)
	{
		cout << a[k] << " ";
	}
	cout << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		if (i == 0)
			cout << "  ";
		else
			cout << b[i - 1] << " ";
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	string a;
	string b;
	int i;
	cout << "Please enter two strings" << endl;
	//a = readline();
	//cin >> b;

	cin >> a;
	cin >> b;
	//a = "aqmrpqiwpfoiqiwef";
	//b = "afqefpqwiiasdfewf";

	int n = a.length();
	int m = b.length();

	vector<int> temp;
	temp.resize(n + 1);
	vector<vector<int>> arr;
	arr.resize(m + 1);

	for (int j = 0; j < n + 1; j++)
		temp[j] = 0;

	for (int i = 0; i < m + 1; i++)
		arr[i] = temp;

	print_vector(arr, a, b);

	cout << endl;

	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (a[j - 1] == b[i - 1])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = (arr[i - 1][j] > arr[i][j - 1]) ? arr[i - 1][j] : arr[i][j - 1];
		}
	}

	print_vector(arr, a, b);

	i = m;
	int j = n;
	int temp2 = arr[i][j];
	string LCS = "";

	stack<char> letters;

	while (i >= 1 && j >= 1)
	{
		if (arr[i][j] == arr[i - 1][j] || arr[i][j] == arr[i][j - 1]) //the entry is different than those above or to the left
		{
			if (arr[i - 1][j] > arr[i][j - 1]) //the one above is greater than to the left
				i -= 1;//move up
			else
				j -= 1;//move to the left
		}
		else if (arr[i][j] == arr[i - 1][j - 1] + 1) //so this one is different than the two above and to the left, and it's also
													 //different than the one diagonal from it, so it's what we want
		{
			cout << "Gotta push " << a[j - 1] << " at arr[" << i << "][" << j << "]" << endl;
			letters.push(a[j - 1]);
			i -= 1;
			j -= 1;
		}
		else
		{
			if (arr[i - 1][j] > arr[i][j - 1])
				i -= 1;
			else
				j -= 1;
		}
	}

	while (!letters.empty())
	{
		char temp = letters.top();
		LCS += temp;
		letters.pop();
	}
	cout << "The LCS of " << a << " and " << b << " is " << LCS << endl;

	cin >> i;
	//system("pause");
	return 0;
}