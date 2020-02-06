#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

void sort(int *numbers, int left, int right) {
    if (right - left < 1)
        return;
    //int x = numbers[(left + right) / 2];
    int x = numbers[right];
    int l = left, r = right;
    while (l <= r) {
        while (numbers[l] < x)
            l++;
        while (numbers[r] > x)
            r--;
        if (l <= r) {
            swap(numbers[l], numbers[r]);
            r--;
            l++;
        }
    }
    sort(numbers, left, r);
    sort(numbers, l, right);
}

void quickSort(int *numbers, int array_size) {
    sort(numbers, 0, array_size - 1);
}

int main() {
    int *brr;
    int n;

    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open()) {
        fin >> n;
        brr = new int[n];
        for (int i = 0; i < n; i++)
            fin >> brr[i];

        fin.close();
    }
    quickSort(brr, n);
//    for(int i1 = 1; i1 < 6;i1++)
//        for(int i2 = 1; i2 < 6;i2++)
//            for(int i3 = 1; i3 < 6;i3++)
//                for(int i4 = 1; i4 < 6;i4++)
//                    for(int i5 = 1; i5 < 6;i5++){
//                        brr[0] = i1;
//                        brr[1] = i2;
//                        brr[2] = i3;
//                        brr[3] = i4;
//                        brr[4] = i5;
//                        quickSort(brr, n);
//                        for(int i = 1;i < n;i++){
//                            if(brr[i] > brr[i - 1])
//                                cout << i1 << i2 << i3 << i4 << i5;
//                        }
//                    }
    fstream fout;
    fout.open("output.txt", ios::out);
    for (int i = 0; i < n; i++)
        fout << brr[i] << " ";

    fout.close();
    delete[] brr;
    return 0;
}