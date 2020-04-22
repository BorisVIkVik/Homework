#include <iostream>
#include <vector>
using namespace std;

int noise = 0;
void merge(vector<int> &arr, int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	/* �������� ��������� ������� */
	vector<int> L(n1);
	vector<int> R(n2);
	//int L[n1], R[n2];
	/* �������� ������ �� ��������� ������� L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	/* ������� ��������� ������� ������� � arr[l..r]*/
	i = 0; // ��������� ������ ������� ����������
	j = 0; // ��������� ������ ������� ����������
	k = l; // ��������� ������ ���������������� ����������
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
			noise += n1-i;
		}
		k++;
	}
	/* ���� � L ���� �������� - �������� */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	/* ���� � R ���� �������� - �������� */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(vector<int> &arr, int l, int r)
{
	if (l < r) {
		// ���� ��� � (l+r)/2, �� �������� ������������
		// ��� ������� l � r
		int m = l + (r - l) / 2;
		// ��������� ������ � ������ ��������
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void printArray(vector<int> &A, int size) {
	int i;
	for (i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}

int main() {
	
	//int arr[] = { 38, 27, 43, 3, 9, 82, 10 };
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int arr_size = arr.size();
	//cout << "�� ����������" << endl;
	//printArray(arr, arr_size);
	mergeSort(arr, 0, arr_size - 1);
	//cout << "����� ����������" << endl;
	//printArray(arr, arr_size);
	cout << noise << endl;
	return 0;
}