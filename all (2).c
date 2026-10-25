#include <stdio.h>
#include <locale.h>

int task1(int years);
double task2(double x);
int task3(int d, int m, int y);
double dz(double z, double k); 

int main() {
    setlocale(LC_ALL, "Russian");

    
    printf("Задание 1\n\n");
    int years;
    printf("Впишите год: ");
    if (scanf("%d", &years) == 1) {
        if (task1(years) == 1) {
            printf("Год %d високосный\n", years);
        } else {
            printf("Год %d не високосный\n", years);
        }
    } else {
        printf("Ошибка ввода года!\n");
    }

   
    printf("\nЗадание 2\n\n");
    double x;
    printf("Введите x: ");
    if (scanf("%lf", &x) == 1) {
        double y = task2(x);
        printf("f(%.2f) = %.2f\n", x, y);
    } else {
        printf("Ошибка ввода x!\n");
    }

   
    printf("\nЗадание 3\n\n");
    int d, m, y;
    printf("Введите дату в формате дд.мм.гггг: ");
    if (scanf("%d.%d.%d", &d, &m, &y) == 3) {
        task3(d, m, y);
    } else {
        printf("Ошибка!\n");
    }

   
    printf("\nДомашнее задание\n\n");
    double z, k;
    printf("Введите координаты z и k через пробел: ");
   
    if (scanf("%lf %lf", &z, &k) == 2) {
        dz(z, k);
    } else {
        printf("Ошибка ввода координат!\n");
    }

    return 0;
}

int task1(int years) {
    if ((years % 4 == 0 && years % 100 != 0) || (years % 400 == 0)) {
        return 1;
    }
    return 0; 
}

double task2(double x) {
    double y;
    if (x <= 1) {
        y = 0;
    } else {
        y = 1.0 / (x + 6);
    }
    return y;
}

int task3(int d, int m, int y) {
    if (y < 1 || m < 1 || m > 12) {
        printf("Ошибка: Дата %02d.%02d.%04d не существует.\n", d, m, y);
        return 0;
    }

    int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (task1(y) == 1) {
        daysInMonths[2] = 29;
    }

    if (d < 1 || d > daysInMonths[m]) {
        printf("Ошибка: В этом месяце всего %d дней.\n", daysInMonths[m]);
        return 0;
    }

    int c;
    printf("\nЧто вы хотите вычислить?\n");
    printf("1 - Сколько дней осталось до конца месяца\n");
    printf("2 - Сколько дней осталось до конца года\n");
    printf("Ваш выбор (1 или 2): ");
    
    if (scanf("%d", &c) != 1) {
        printf("Ошибка!\n");
        return 0;
    }

    if (c == 1) {
        int daysToMonthEnd = daysInMonths[m] - d;
        printf("До конца месяца осталось дней: %d\n", daysToMonthEnd);
    } 
    else if (c == 2) {
        int daysToYearEnd = daysInMonths[m] - d;
        for (int nextMonth = m + 1; nextMonth <= 12; nextMonth++) {
            daysToYearEnd += daysInMonths[nextMonth];
        }
        printf("До конца года осталось дней: %d\n", daysToYearEnd);
    } 
    else {
        printf("Неверный выбор! Пожалуйста, введите цифру 1 или 2.\n");
    }

    return 0;
}


double dz(double z, double k) {
   
    if ((z * z + k * k <= 36) && (z <= 0 || k <= 0)) {
        printf("Результат: Точка (%.2lf, %.2lf) ПОПАДАЕТ в заштрихованную область.\n", z, k);
    } else {
        printf("Результат: Точка (%.2lf, %.2lf) НЕ попадает в заштрихованную область.\n", z, k);
    }
    return 0.0;
}
