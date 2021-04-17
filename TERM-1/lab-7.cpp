#include <iostream>

using namespace std;

struct info
{
	char country[50];
	char team[50];
	char name[50];
	int number;
	int age;
	int height;
	int weight;
};

int main()
{
	int n;
	cout << "Number of players: ";
		cin >> n;
	
	info* player = new info[n];
	for (int i = 0; i < n; i++)
	{
		cout << endl << "---PLAYER:" << i+1 << "---" << endl;
		cout << "Country: ";
			cin >> player[i].country;
		cout << "Team: ";
			cin >> player[i].team;
		cout << "Name: ";
			cin >> player[i].name;
		cout << "Number: ";
			cin >> player[i].number;
		cout << "Age: ";
			cin >> player[i].age;
		cout << "Height: ";
			cin >> player[i].height;
		cout << "Weight: ";
			cin >> player[i].weight;
	}

	int k = 0;
	for (int i = 0; i < n; i++)
		if (player[k].age > player[i].age) k = i;

	cout << endl << "--THE YOUNGEST TEAM:" << player[k].team << "--" << endl;
	cout << "Country: " << player[k].country << endl;
	cout << "Player name: " << player[k].name << endl;
	cout << "Number: " << player[k].number << endl;
	cout << "Age: " << player[k].age << endl;
	cout << "Height: " << player[k].height << endl;
	cout << "Weight: " << player[k].weight << endl;

	return 0;
}