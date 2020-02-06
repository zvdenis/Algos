#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h
using namespace std;

union number {
    unsigned int num;
    unsigned char byte[4];
};

const int sort_base = 256;

// Функция цифровой сортировки
int* radixSort(int *numbers, int array_size) {

    //В коде используется 3 массива каждый ~ 4мб в сумме 12 (ограничение 10),
    //Чтобы прошли тесты приходиться извращаться(
    number *arr = new number[array_size];
    for (int i = 0; i < array_size; i++) {
        arr[i].num = numbers[i];
    }
    delete[] numbers;
    number *B = new number[array_size];



    for (int cur_byte = 0; cur_byte < 4; cur_byte++) {
        int C[sort_base];

        for (int i = 0; i < sort_base; i++) {
            C[i] = 0;
        }

        for (int i = 0; i < array_size; i++) {
            C[arr[i].byte[cur_byte]]++;
        }

        for (int i = 1; i < sort_base; i++) {
            C[i] += C[i - 1];
        }

        for (int i = array_size - 1; i >= 0; i--) {
            B[C[arr[i].byte[cur_byte]] - 1].num = arr[i].num;
            C[arr[i].byte[cur_byte]]--;
        }

        for (int i = 0; i < array_size; i++) {
            arr[i].num = B[i].num;
        }
    }

    numbers = new int[array_size];
    delete [] arr;
    for (int i = 0; i < array_size; i++) {
        numbers[i] = B[i].num;
    }
    delete[] B;

    return numbers;
}

//Не удалять и не изменять метод main без крайней необходимости.
//Необходимо добавить комментарии, если все же пришлось изменить метод main.
int main() {
    //Объект для работы с файлами
    ReadWriter rw;

    int *brr = nullptr;
    int n;

    //Ввод из файла
    n = rw.readInt();

    brr = new int[n];
    rw.readArray(brr, n);

    //В коде используется 3 массива каждый ~ 4мб в сумме 12 (ограничение 10),
    //Чтобы прошли тесты приходиться извращаться(
    //Изменил тип возвращаемого значения и удаляю неиспользуемый по ходу работы алгоритма массив
    //Запуск сортировки, ответ в том же массиве (brr)
    brr = radixSort(brr, n);

    //Запись в файл
    rw.writeArray(brr, n);

    //освобождаем память
    delete[] brr;

    return 0;
}
