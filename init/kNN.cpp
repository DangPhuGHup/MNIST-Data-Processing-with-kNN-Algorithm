#include "kNN.hpp"

/* TODO: You can implement methods, functions that support your data structures here.
 * */
void train_test_split(Dataset &X, Dataset &Y, double test_size,
                      Dataset &X_train, Dataset &X_test, Dataset &Y_train, Dataset &Y_test)
{
    // if (test_size >= 1 || test_size <= 0)
    // {
    //     return;
    // }
    // //* phân chia phần train
    // int nRows, nCols;
    // X.getShape(nRows, nCols);

    // X_train = X.extract(0, (1 - test_size) * nRows - 1, 0, -1);

    // Y_train = Y.extract(0, (1 - test_size) * nRows - 1, 0, 0);

    // //* phân chia phần test

    // X_test = X.extract((1 - test_size) * nRows, nRows, 0, -1);

    // Y_test = Y.extract((1 - test_size) * nRows, nRows, 0, 0); // moi sua lai tu lms dau tien


    if (X.getData()->length() != Y.getData()->length() || test_size >= 1 || test_size <= 0)
        return;

    double minDouble = 1.0e-15;
    int nRow = X.getData()->length();
    double rowSplit = nRow * (1 - test_size);

    if (abs(round(rowSplit) - rowSplit) < minDouble * nRow)
        rowSplit = round(rowSplit);

    X_train = X.extract(0, rowSplit - 1, 0, -1);
    Y_train = Y.extract(0, rowSplit - 1, 0, -1);

    X_test = X.extract(rowSplit, -1, 0, -1);
    Y_test = Y.extract(rowSplit, -1, 0, -1);
}


void merge(pair<double, int>* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cấp phát động cho các mảng tạm thời
    pair<double, int>* L = new pair<double, int>[n1];
    pair<double, int>* R = new pair<double, int>[n2];

    // Copy dữ liệu sang các mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge các mảng tạm lại vào arr
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Giải phóng bộ nhớ đã cấp phát
    delete[] L;
    delete[] R;
}


void mergeSort(pair<double, int> arr[], int l, int r) {
    if (l >= r) {
        return; // Trường hợp cơ bản
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
