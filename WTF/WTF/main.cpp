#include <iostream>
#include <vector>
using namespace std;

int noise = 0;
void merge(vector<int> &arr, int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	/* Создадим временные массивы */
	vector<int> L(n1);
	vector<int> R(n2);
	//int L[n1], R[n2];
	/* Копируем данные во временные массивы L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	/* Сливаем временные массивы обратно в arr[l..r]*/
	i = 0; // Начальный индекс первого подмассива
	j = 0; // Начальный индекс второго подмассива
	k = l; // Начальный индекс отсортированного подмассива
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
	/* Если в L есть элементы - копируем */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	/* Если в R есть элементы - копируем */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(vector<int> &arr, int l, int r)
{
	if (l < r) {
		// Тоже что и (l+r)/2, но избегает переполнения
		// для больших l и r
		int m = l + (r - l) / 2;
		// Сортируем первую и вторую половину
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
	//cout << "До сортировки" << endl;
	//printArray(arr, arr_size);
	mergeSort(arr, 0, arr_size - 1);
	//cout << "После сортировки" << endl;
	//printArray(arr, arr_size);
	cout << noise << endl;
	return 0;
}