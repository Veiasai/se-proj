#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

struct step
{
	vector<vector<int> > _mi;
	int _x;
	int _y;
	step(vector<vector<int> > mi, int x, int y) : _x(x), _y(y), _mi(mi) {}
};

void show_result(vector<vector<int> > mi);
bool dostep(vector<step> one);


int x, y;
int main()
{
	fstream mig("mg4.txt");
	if (mig.fail())
	{
		cout << "error filename" << endl;
		return 0;
	}
	
	mig >> x >> y;
	while (mig.get() != '\n');
	vector<vector<int> > migong;
	vector<int> te;
	for (int i = 0; i < x; i++)
	{
		te = {};
		for (int j = 0; j < y; j++)
		{
			int temp;
			mig >> temp;
			te.push_back(temp);
		}
		mig.get();
		migong.push_back(te);
	}
	vector<step> first;
	migong[0][0] = 2;
	first.push_back(step(migong, 0, 0));
	dostep(first);
}

bool dostep(vector<step> one)
{
	vector<step> next;
	for (auto c : one)
	{
		if (c._x - 1 >= 0 && c._mi[c._x - 1][c._y] == 0)
		{
			c._mi[c._x - 1][c._y] = 2;
			next.push_back(step(c._mi, c._x - 1, c._y));
			c._mi[c._x - 1][c._y] = 0;
		}
		if (c._x + 1 < x && c._mi[c._x + 1][c._y] == 0)
		{
			c._mi[c._x + 1][c._y] = 2;
			if (c._x + 1 == x-1 && c._y == y-1)
			{
				show_result(c._mi);
				return 1;
			}
			next.push_back(step(c._mi, c._x + 1, c._y));
			c._mi[c._x + 1][c._y] = 0;
		}
		if (c._y - 1 >= 0 && c._mi[c._x][c._y - 1] == 0)
		{
			c._mi[c._x][c._y - 1] = 2;
			next.push_back(step(c._mi, c._x, c._y - 1));
			c._mi[c._x][c._y - 1] = 0;
		}
		if (c._y + 1 < y && c._mi[c._x][c._y + 1] == 0)
		{
			c._mi[c._x][c._y + 1] = 2;
			if (c._x == x-1 && c._y + 1 == y-1)
			{
				show_result(c._mi);
				return 1;
			}
			next.push_back(step(c._mi, c._x, c._y + 1));
			c._mi[c._x][c._y + 1] = 0;
		}
	}
	if (next.size() > 0)
		dostep(next);
	else
	{
		cout << "no result" << endl;
		return 0;
	}
}

void show_result(vector<vector<int> > mi)
{
	for (auto a : mi)
	{
		for (auto b : a)
		{
			cout << b << " ";
		}
		cout << "\n";
	}
		
}