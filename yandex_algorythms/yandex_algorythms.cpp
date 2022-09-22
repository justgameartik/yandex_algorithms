/* H\w 1. Task A
#include <iostream>
using namespace::std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	double solution;

	if (a == 0)
		if (b == 0)
			cout << "INF";
		else cout << "NO";
	else
	{
		solution = -b / a;
		if (solution - int(solution) < 0.00001)
		{
			if (c * solution + d < 0.00001)
			{
				cout << "NO";
			}
			else
				cout << solution;
		}
		else 
			cout << "NO";
	}
}
*/

/* H\w 1. Task B
#include <iostream>
using namespace::std;

int main()
{
	int n;
	cin >> n;
	int** coordinates = new int*[n];
	for (int i = 0; i < n; i++)
	{
		coordinates[i] = new int[8];
		for (int j = 0; j < 8; j++)
			cin >> coordinates[i][j];
	}
	for (int i = 0; i < n; i++)
	{
		double max_diag=0;
		int x_first = 0, y_first = 0, x_second = 0, y_second = 0;
		for (int j = 0; j < 3; j++)
		{
			for (int k = j + 1; k < 4; k++)
			{
				double diag = pow(coordinates[i][2 * j] - coordinates[i][2 * k], 2) + pow(coordinates[i][2 * j + 1] -
					coordinates[i][2 * k + 1], 2);
				if (diag > max_diag)
				{
					max_diag = diag;
					x_first = 2 * j;
					y_first = 2 * j + 1;
					x_second = 2 * k;
					y_second = 2 * k + 1;
				}
			}
		}
		int temp_x, temp_y;
		temp_x = coordinates[i][0];
		temp_y = coordinates[i][1];
		coordinates[i][0] = coordinates[i][x_first];
		coordinates[i][1] = coordinates[i][y_first];
		coordinates[i][x_first] = temp_x;
		coordinates[i][y_first] = temp_y;

		temp_x = coordinates[i][4];
		temp_y = coordinates[i][5];
		coordinates[i][4] = coordinates[i][x_second];
		coordinates[i][5] = coordinates[i][y_second];
		coordinates[i][x_second] = temp_x;
		coordinates[i][y_second] = temp_y;

		bool parallelogramm = true;

		for (int j = 0; j < 3; j++)
		{
			for (int k =j+1; k < 4; k++)
			if (coordinates[i][2 * j] == coordinates[i][2*k] && coordinates[i][2 * j + 1] == coordinates[i][2 * k + 1])
				parallelogramm = false;
		}
		
		for (int k = 0; k < 2; k++)
		{
			double side[2];
			for (int j = 0; j < 2; j++)
			{
				side[j] = pow(coordinates[i][4 * j + 2*k] - coordinates[i][(4 * j + 2 + 2*k) %8], 2) +
					pow(coordinates[i][4 * j + 1 + 2*k] - coordinates[i][(4 * j + 3 + 2*k) % 8], 2);
			}
			if (side[0] != side[1])
				parallelogramm = false;
		}


		if (parallelogramm)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

		
	}

	for (int i = 0; i < n; i++)
		delete[] coordinates[i];
}
*/

/* H\w 1. Task C 
#include <iostream>
#include <cstdlib>
using namespace::std;

const int n = 3;

bool is_possible(int arr[n][n], const int n)
{
	bool result = true;

	int sum_chrest = 0, sum_zeros = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
				sum_chrest += 1;
			if (arr[i][j] == 4)
				sum_zeros += 1;
		}

	int chrest_count_victories = 0; int zeros_count_victories = 0;
	for (int i = 0; i < n; i++)
	{
		int sum_horisontal = 0;
		int sum_vertical = 0;
		int sum_diag_1 = 0, sum_diag_2 = 0;

		for (int j = 0; j < n; j++)
		{
			sum_horisontal += arr[i][j];
			sum_vertical += arr[j][i];
			if (i == 0)
			{
				sum_diag_1 += arr[j][j];
				sum_diag_2 += arr[n - j - 1][j];
			}
		}
		if (sum_diag_1 == 3)
			chrest_count_victories += 1;
		if (sum_diag_1 == 12)
			zeros_count_victories += 1;

		if (sum_diag_2 == 3)
			chrest_count_victories += 1;
		if (sum_diag_2 == 12)
			zeros_count_victories += 1;

		if (sum_horisontal == 3)
			chrest_count_victories += 1;
		if (sum_horisontal == 12)
			zeros_count_victories += 1;

		if (sum_vertical == 3)
			chrest_count_victories += 1;
		if (sum_vertical == 12)
			zeros_count_victories += 1;
	}
	if (chrest_count_victories + zeros_count_victories <= 2)
	{
		if (zeros_count_victories == 2)
			result = false;
		if (zeros_count_victories == 1 && chrest_count_victories == 1)
			result = false;
	}else
		result = false;

	if (sum_chrest - sum_zeros != 0 && sum_chrest - sum_zeros != 1)
		result = false;

	if (chrest_count_victories == 1 && sum_chrest - sum_zeros != 1)
		result = false;

	if (zeros_count_victories == 1 && sum_chrest != sum_zeros)
		result = false;

	return result;
}

int main()
{
	int arr[n][n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				arr[i][j] = 4;
		}

	if (is_possible(arr, n))
		cout << "YES";
	else
		cout << "NO";
	
}
*/
/*H/w 1. Task D 
#include <iostream>
#include <cstdlib>
using namespace::std;


void Swap(int* members, int change_1, int change_2, char type)
{

	int temp = members[change_1 - 1];
	members[change_1 - 1] = members[change_2 - 1];
	members[change_2 - 1] = temp;

	if (type == 'o')
		cout << change_1 << ' ' << change_2 << '\n';
}

void Find(int* members, int members_amount, int* change_members, char type, int change_amount)
{
	for (int i = 0; i < members_amount - 2; i++)
	{
		if (members[i] != i + 1)
		{
			Swap(members, i + 1, members_amount - 1, type);
			
			while (members[members[members_amount - 2] - 1] != i + 1)
			{
				Swap(members, members_amount - 1, members[members_amount - 2], type);
			}
			Swap(members, members_amount, members[members_amount - 2], type);
			Swap(members, i + 1, members_amount, type);
			Swap(members, members_amount - 1, members[members_amount - 2], type);
			
		}
	}
	if (members[members_amount - 1] != members_amount)
		Swap(members, members_amount - 1, members_amount, type);
}
bool Result(int* members, int members_amount)
{
	for (int i = 0; i < members_amount; i++)
		if (members[i] != i + 1)
			return false;
		else 
			return true;
}

int main()
{
	int members_amount, changes_amount;
	cin >> members_amount >> changes_amount;


	int* members = new int[members_amount];
	for (int i = 0; i < members_amount; i++)
		members[i] = i + 1;
	
	char type = 'i';

	int change_1, change_2;
	int* change_members = new int[changes_amount*2];
	for (int i = 0; i < changes_amount; i++)
	{
		cin >> change_1 >> change_2;
		change_members[2 * i] = change_1;
		change_members[2 * i + 1] = change_2;

		Swap(members, change_1, change_2, type);
	}
	type = 'o';
	Find(members, members_amount, change_members, type, changes_amount);

	

	delete[] members; delete[] change_members;
}
*/

/*  H\w 1.Task E
#include <iostream>
using namespace::std;

int main()
{
	long int perimetr;
	cin >> perimetr;

	int a, b, c;

	a = perimetr / 3;
	b = (perimetr - a) / 2;
	c = perimetr - a - b;

	if (a + b > c)
	{
		cout << a << ' ' << b << ' ' << c << '\n';
		if (perimetr % 2 == 1)
			cout << 1 << ' ' << perimetr / 2 << ' ' << perimetr / 2;
		else
			cout << 2 << ' ' << perimetr / 2 - 1 << ' ' << perimetr / 2 - 1;
	}
	else
		cout << -1;
}*/