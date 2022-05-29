#include <iostream>


using namespace std;


int main(int argc, const char* argv[])
{

	int arr[6][6] = {{0,1,1,0,0,0},
				     {0,0,0,1,0,0},
				     {0,0,0,0,1,0},
				     {0,0,0,0,0,1},
				     {0,0,0,0,0,0},
				     {0,0,0,0,0,0}};

	string nme[] = {"a","b","c","d","e","f"};


	stack <string> sta;

	sta.push("a");

	while(!.sta.empty())
	{

		string c = sta.top();
		cout << c << endl;
		sta.pop();


	}

	return 0;
}