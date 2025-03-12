// https://acm.timus.ru/problem.aspx?space=1&num=1057

#include <iostream>
#include <algorithm>

// Функция для вычисления биномиального коэффициента C(n, k)
int C(int n, int k) {
    if (k > n) return 0; // Если k > n, то C(n, k) = 0
    long long c = 1;
    for (int i = 0; i < k; i++) {
        c = c * (n - i) / (i + 1);
    }
    return c;
}

// Функция для подсчета чисел, содержащих ровно K единиц в своей B-ичной записи, не превышающих N
int F(int N, int K, int B) {
    if (N < B) { // Базовый случай для однозначного числа
        return (K <= 1 && N > 0) || (N == 0 && K == 0);
    }

    long long p = 1;
    int k = 0;
    // Находим максимальную степень B, меньшую или равную N
    while (p * B <= N) {
        p *= B;
        k++;
    }

    int firstDigit = N / p; // Первая цифра числа N в B-ичной системе

    if (firstDigit >= 2) {
        // Если первая цифра >= 2, то все числа с первой цифрой 0 или 1 подходят
        return C(k, K - 1) + (K ? C(k, K) : 0);
    } else if (firstDigit == 1) {
        // Если первая цифра == 1, то рекурсивно считаем для оставшейся части числа
        return C(k, K) + (K ? F(N - p, K - 1, B) : 0);
    } else {
        // Если первая цифра == 0, то рекурсивно считаем для оставшейся части числа
        return F(N % p, K, B);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int X, Y, K, B;
    std::cin >> X >> Y >> K >> B;

    // Вычисляем F(Y, K, B) - F(X-1, K, B)
    std::cout << F(Y, K, B) - F(X - 1, K, B) << std::endl;

    return 0;
}
