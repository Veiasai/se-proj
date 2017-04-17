#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
double read_time(ifstream &);
void read_(ifstream &);
string read_name(ifstream &);

int main()
{
	ifstream s("123.txt");
	ofstream result("result.txt");
	char r;
	double time;
	string name;
	while (!s.eof())
	{
		try {
			time = read_time(s);
			read_(s);
			name = read_name(s);
			result << name << " : " << fixed << setprecision(3) << time << "s" << endl;
		}
		catch (const char * err)
		{
			result << err << endl;
			continue;
		}
	}
	return 0;
}

double read_time(ifstream & s)
{
	double time, timeall = 0;
	if (!(s >> time))
	{
		s.clear();
		while (s.get() != '\n')
			continue;
		throw "invalid input";
	}
	while (true)
	{
		switch (s.get())
		{
		case 'h': timeall = timeall + time * 3600; break;
		case 'm':
			if (s.get() == 'i')
			{
				timeall = timeall + time * 60;
				s.get();
			}
			else timeall = timeall + time * 0.001;
		case 's': timeall = timeall + time; break;
		}
		char r;
		s >> r;
		if (isdigit(r))
			s.putback(r);
		else
		{
			s.putback(r);
			break;
		}
		s >> time;
	}
	return timeall;
}

void read_(ifstream & s)
{
	char r;
	s >> r;
	if (r != '|')
	{
		while (s.get() != '\n')
			continue;
		throw "invalid input";
	}
	else
		s.get();
}

string read_name(ifstream & s)
{
	string name;
	getline(s, name);
	for (int i = 0; i < name.size(); i++)
		if (name[i] != ' ')
			return name;
	throw "invalid input";
}