#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool paranthesis(const string  &s)
{
	stack <char> c1;
	cout << "\nInput: " << s << endl;
	for (char i : s)
	{
		if (i == '(' || i =='{' || i == '[')
		{
			c1.push(i);
		}

		else if (i == ')' || i == '}' || i == ']')
		{
			if (c1.empty())
			{
				return false;
			}

			if ((i == ')' && c1.top() != '(') || (i == ']' && c1.top() != '[') || (i == '}' && c1.top() != '{'))
			{
				return false;
			}
			c1.pop();
		}
		
		
	}
	return c1.empty();
}

int main()
{
	string Input1 = "{([])}([]{}())";
	string Input2 = "{()}";
	cout << (paranthesis (Input1) ? "True" : "False") << endl;
	cout << (paranthesis(Input2) ? "True" : "False") << endl;
}