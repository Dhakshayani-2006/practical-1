#include <iostream>
using namespace std;

void mergeSort(int a[], int n) {
    if (n < 2) return;
    int mid = n / 2;
    int left[mid], right[n - mid];
    for (int i = 0; i < mid; i++)
        left[i] = a[i];
    for (int i = mid; i < n; i++)
        right[i - mid] = a[i];
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid)
        a[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
    while (i < mid) a[k++] = left[i++];
    while (j < n - mid) a[k++] = right[j++];
}
int main() {
    int a[] = {5, 2, 8, 1, 3};
    int n = 5;
    mergeSort(a, n);
    for (int x : a) cout << x << " ";
}
