using namespace std;
#include<iostream>

void Merge(int num[], int temp[], int left, int mid, int right)
{
	int i, num_elem;
	int left_end = mid - 1,tmp_pos = left;
	num_elem = right - left + 1;
	while ((left <= left_end) && (mid <= right))
	{
		if (num[left] <= num[mid])
		{
			temp[tmp_pos] = num[left];
			tmp_pos = tmp_pos + 1;
			left = left + 1;
		}
		else
		{
			temp[tmp_pos] = num[mid];
			tmp_pos = tmp_pos + 1;
			mid = mid + 1;
		}
	}
	while (left <= left_end)
	{
		temp[tmp_pos] = num[left];
		left = left + 1;
		tmp_pos = tmp_pos + 1;
	}
	while (mid <= right)
	{
		temp[tmp_pos] = num[mid];
		mid = mid + 1;
		tmp_pos = tmp_pos + 1;
	}
	for (i = 0; i < num_elem; i++)
	{
		num[right] = temp[right];
		right = right - 1;
	}
}

void M_Sort(int num[], int temp[], int left, int right)
{
	int  mid;
	if (right > left)
	{
		mid = (right + left) / 2;
		M_Sort(num, temp, left, mid);
		M_Sort(num, temp, mid + 1, right);
		Merge(num, temp, left, mid + 1, right);
	}
}
int main()
{
	int i, n;
	int num[50], temp[50];
	cout << "Enter Size of Array : ";  cin >> n;
	cout << "Enter the elem : " << endl;
	for (i = 0; i < n; i++)
		cin >> num[i];
	cout << "The elements after sorting" << endl;
	M_Sort(num, temp, 0, n - 1);
	for (i = 0; i < n; i++)
		cout << num[i] << endl;
	return 0;
}