#include <iostream>

using namespace std;

void heapify(int *arr, int array_size, int cur) {
    int left, right, max = cur;
    for (;;) {
        left = cur * 2 + 1;
        right = cur * 2 + 2;
        max = cur;

        if (left < array_size && arr[left] > arr[cur]) {
            max = left;
        }

        if (right < array_size && arr[right] > arr[max]) {
            max = right;
        }

        if (max == cur) {
            return;
        }

        swap(arr[cur], arr[max]);
        cur = max;
    }
}

void makeHeap(int *arr, int array_size) {
    for (int i = array_size / 2; i >= 0; i--) {
        heapify(arr, array_size, i);
    }
}

int pop(int *arr, int array_size) {
    swap(arr[0], arr[array_size - 1]);
    heapify(arr, array_size - 1, 0);
    return arr[array_size - 1];
}

void heapSort(int *numbers, int array_size) {

    makeHeap(numbers, array_size);
    for (int i = array_size; i > 0; i--) {
        pop(numbers, i);
    }
}


int main() {

#ifndef NDEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int *X = new int[n];
    int *Y = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
    }

    heapSort(X, n);
    heapSort(Y, n);

    int k, x;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> x;
        int x_ans, y_ans;

        int l = -1, r = n, mid;
        while (r - l > 1) {
            mid = (r + l) / 2;
            if (X[mid] <= x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        x_ans = l;


        l = -1, r = n;
        while (r - l > 1) {
            mid = (r + l) / 2;
            if (Y[mid] < x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        y_ans = l;

        cout << x_ans - y_ans << endl;
    }


    return 0;
}