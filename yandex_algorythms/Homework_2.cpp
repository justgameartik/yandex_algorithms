/* Task A
#include <iostream>
using namespace::std;

void Confuse(long long* arr, int arr_size)
{
	long long sum = 0;

	for (int i = 0; i < arr_size; i++)
		sum += arr[i];

	for (int i = 0; i < arr_size; i++)
		arr[i] = sum - arr[i];
}
long long Max_n_Min(long long* arr, int arr_size)
{
	long long max = arr[0];
	long long min = arr[0];
	for (int i = 1; i < arr_size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	return max - min;
}

int main()
{
	int n, k;
	cin >> n >> k;

	long long* arr = new long long[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < k; i++)
		Confuse(arr, n);

	cout << Max_n_Min(arr, n);
}
*/

/* Task B
#include <iostream>
#include <string>
using namespace::std;

int main()
{
	string x_str, y_str, z_str, temp;

	cin >> x_str >> z_str;
	
	int multiplier = 2*z_str.length() / x_str.length() + 1;

	for (int i = 0; i < multiplier; i++)
	{
		temp.append(x_str);
	}
	
	bool result = false; 
	y_str.append(z_str);
	for (int i = 0; i < z_str.length(); i++)
	{
		// mama
		// amamam
		// mamamamamamamama
		if (temp.rfind(y_str) != string::npos &&
			temp.rfind(y_str) + y_str.length() == temp.length())
		{
			result = true;
		}
		else
			y_str.erase(y_str.length() - 1);

		if (result)
			break;
	}

	for (int i = y_str.length(); i < z_str.length(); i++)
		cout << z_str[i];
}
*/