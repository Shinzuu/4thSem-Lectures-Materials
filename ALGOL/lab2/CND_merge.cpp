#include <iostream>
#include <climits>

using namespace std;

int cnt = 0;
int divi = 0;

void Merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[q + j + 1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void MergeSort(int A[], int p, int r) {
    if (p < r) {
        divi++;
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

int main() {
    int Array[] = {10, 80, 30, 90, 40, 50, 70, 20};
    int r = sizeof(Array) / sizeof(Array[0]);
    MergeSort(Array, 0, r - 1);
    cout << "The sorted array is:" << endl;
    for (int i = 0; i < r; i++) {
        cout << Array[i] << " ";
    }
    cout << endl << "Total number of times the flag was triggered: " << cnt << endl;
    cout << "Total number of divisions: " << divi << endl;
    return 0;
}
