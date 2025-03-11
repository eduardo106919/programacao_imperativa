#include <stdio.h>

int fizz(int n) { return ((n + 4) % 43) == 0; }

int buzz(int n) { return ((n - 5) % 47) == 0; }

int fizzbuzz1(int n) {
    if (fizz(n) && buzz(n))
        ;
    //   printf("FizzBuzz\n");
    else if (fizz(n))
        ;
    //   printf("Fizz\n");
    else if (buzz(n)) {
        //   printf("Buzz\n");
        return 1;
    } else
        ;
    //   printf("%d\n", n);
    return 0;
}

int fizzbuzz_range1(int from, int to) {
    int total = 0;
    for (int i = from; i < to; i++)
        total += fizzbuzz1(i);
    return total;
}

int fizzbuzz2(int n, int *dentro) {
    if (fizz(n) && buzz(n))
        ;
    // printf("FizzBuzz\n");
    else if (fizz(n)) {
        // printf("Fizz\n");
        *dentro = -1;
    } else if (buzz(n)) {
        // printf("Buzz\n");
        *dentro = 1;
    } else {
        // printf("%d\n", n);
        return 1;
    }
    return 0;
}

/**
 * Efetua o fizzbuzz, se encontrou o primeiro buzz, começa a contar, se
 * encontrar um fizz, acaba
 */
int fizzbuzz_range2(int from, int to, int *dentro) {
    int total = 0;
    int first = 0;
    for (int i = from; i < to; i++) {
        fizzbuzz2(i, dentro);

        // Garante que o programa não acaba ao encontrar um fizz sem encontrar
        // um buzz
        if (first == 0 && *dentro == -1)
            first = 0;
        if (*dentro == 1) {
            total++;
            first = 1;
        }
        if (*dentro == -1 && first == 1)
            return total;
    }
    return total;
}

int main() {
    int total1 = fizzbuzz_range1(487, 5487);
    printf("Pergunta 1: %d\n", total1);

    int dentro = 0;
    int total2 = fizzbuzz_range2(487, 5487, &dentro);
    printf("Pergunta 2: %d\n", total2 - 1);

    return 0;
}
