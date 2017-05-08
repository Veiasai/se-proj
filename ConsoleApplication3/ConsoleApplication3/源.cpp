#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

bool cmp(string & x, string & y);
map< string, vector<string> > dictionary;

int main()
{
	fstream open_file("dictionary.txt");
	if (open_file.fail())
	{
		cout << "fail to open" << endl;
		return 0;
	}
	
	while (!open_file.eof())
	{
		string s;
		getline(open_file, s);
		for (int i = 0; i < s.size(); i++)
		{
			string temp = s.substr(s.size() - 1 - i);
			dictionary[temp].push_back(s);
		}
	}

	while (true)
	{
		cout << "input 1 or 2 to use two funcions" << endl;
		string temp;
		cin >> temp;
		if (temp == "1")
		{
			cout << "input a number" << endl;
			int num;
			cin >> num;
			cin.get();
			vector<string> suffix;
			for (auto s : dictionary)
			{
				if (s.first.size() == num)
					suffix.push_back(s.first);
			}
			sort(suffix.begin(), suffix.end(), cmp);
			for (int i = 0; i < 10; i++)
			{
				cout << suffix[i];
				cout << "  ";
				cout << dictionary[suffix[i]].size() << endl;
			}
		}
		else if (temp == "2")
		{
			cout << "input a suffix" << endl;
			string s;
			cin >> s;
			for (int i = dictionary[s].size() - 1; i >= 0; i--)
				cout << dictionary[s][i] << endl;
		}
	}
	
}

bool cmp(string & x, string & y)
{
	return (dictionary[x].size() > dictionary[y].size());
}