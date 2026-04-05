#include <iostream>
using namespace std;

const int MAX = 50;

//  Прототипи 
void inputMatrix(int a[MAX][MAX], int &m, int &n);
void printMatrix(int a[MAX][MAX], int m, int n);

void task1();
void task2();

//  Ввід матриці з перевіркою 
void inputMatrix(int a[MAX][MAX], int &m, int &n) {
    do {
        cout << "Введіть кількість рядків (2..50): ";
        cin >> m;
    } while (m < 2 || m > 50);

    do {
        cout << "Введіть кількість стовпців (2..50): ";
        cin >> n;
    } while (n < 2 || n > 50);

    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

//  Вивід матриці 
void printMatrix(int a[MAX][MAX], int m, int n) {
    cout << "Матриця:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

//  TASK 1 
void task1() {
    int a[MAX][MAX], m, n;
    inputMatrix(a, m, n);

    for (int i = 0; i < m; i++) {
        int pos = 0, neg = 0;

        for (int j = 0; j < n; j++) {
            if (a[i][j] > 0) pos++;
            else if (a[i][j] < 0) neg++;
        }

        if (pos == neg && pos != 0) {
            cout << "Номер рядка: " << i + 1 << endl;
            return;
        }
    }

    cout << "0\n";
}

//  TASK 2 
void task2() {
    int a[MAX][MAX], m, n;
    inputMatrix(a, m, n);

    for (int j = 0; j < n; ) {
        bool allPositive = true;

        for (int i = 0; i < m; i++) {
            if (a[i][j] <= 0) {
                allPositive = false;
                break;
            }
        }

        if (allPositive) {
            // Видаляємо стовпець (зсув вліво)
            for (int k = j; k < n - 1; k++) {
                for (int i = 0; i < m; i++) {
                    a[i][k] = a[i][k + 1];
                }
            }
            n--; // зменшуємо кількість стовпців
        } else {
            j++;
        }
    }

    printMatrix(a, m, n);
}

//  MAIN 
int main() {
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1 - Завдання 1\n";
        cout << "2 - Завдання 2\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 0: cout << "Вихід...\n"; break;
            default: cout << "Невірний вибір!\n";
        }

    } while (choice != 0);

    return 0;
}