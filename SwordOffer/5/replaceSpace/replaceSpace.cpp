#include <iostream>
#include <string>

using namespace std;

string replaceSpace(string s) 
{
    int spaceCnt = 0;
	string res = "";

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			spaceCnt++;
	}

	res.resize(s.size() + spaceCnt * 2);

	int i = s.size();
	int j = res.size();

	while (i >= 0 && j >= 0)
	{
		if (s[i] == ' ')
		{
			res[j] = '0';
			j--;
			res[j] = '2';
			j--;
			res[j] = '%';
		}
		else
		{
			res[j] = s[i];
		}
		i--;
		j--;
	}

	return res;
}

int main()
{
	string s = " das das";
	cout << replaceSpace(s) << endl;
}
