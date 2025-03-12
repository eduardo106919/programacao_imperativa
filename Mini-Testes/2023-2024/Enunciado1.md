# MINI TESTE 1

Considere as seguintes funções:

*(Consider the following functions:)*

```C
int fizz(int n) {
  return ((n + 4) % 43) == 0;
}

int buzz(int n) {
  return ((n - 5) % 47) == 0;
}

void fizzbuzz(int n) {
  if (fizz(n) && buzz(n))
      printf("FizzBuzz\n");
  else if (fizz(n))
      printf("Fizz\n");
  else if (buzz(n))
      printf("Buzz\n");
  else
      printf("%d\n", n);
}
```

Considere ainda uma função `void fizzbuzz_range(int from, int to)` que replica a funcionalidade da função `fizzbuzz` para a sequência de valores entre `from` (inclusive) e `to` (exclusive). Se esta função for invocada da seguinte forma:

*(And another function, named `void fizzbuzz_range(int from, int to)`, which, for each value in the sequence that ranges from `from` (inclusive) to `to` (exclusive), replicates the behaviour of `fizzbuzz`. Given the following function call:)*

`fizzbuzz_range(487, 5487);`

## Pergunta 1

Quantas linhas do tipo Buzz são impressas?

*(How many Buzz lines are printed?)*

## Pergunta 2

Quantos números são impressos entre a primeira linha do tipo `Buzz` e a linha do tipo `Fizz` que se lhe segue?

*(How many numbers are printed out between the first `Buzz` line and the `Fizz` line that follows it?)*

## Respostas

Pergunta 1 == **103**

Pergunta 2 == **32**
