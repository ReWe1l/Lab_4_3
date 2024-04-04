#include <iostream>
using namespace std;

int maxdig(int N) {
    if (N < 10) {                                      // Базовый случай: если число состоит из одной цифры
        return N;
    }
    else {
        int last_digit = N % 10;                       // Находим последнюю цифру числа
        int max_in_rest = maxdig(N / 10);              // Находим наибольшую цифру в оставшейся части числа
        return max(last_digit, max_in_rest);           // Возвращаем наибольшую из двух цифр
    }
}

int main() {

    locale::global(locale("Russian_Russia.1251"));

    int N;

    while (true) {
        cout << "Введите положительное десятичное целое число N: ";
        cin >> N;

        if (cin.fail() || N < 0) {
            cout << "Пожалуйста, введите положительное десятичное целое число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка ввода
        }
        else {
            break;
        }
    }


    cout << "Наибольшая цифра в десятичной записи целого числа " << N << " - цифра " << maxdig(N);
    return 0;
}