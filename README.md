# Programa de Ordenação em C++

Este programa em C++ implementa três algoritmos de ordenação: **Insertion Sort**, **Bubble Sort** e **Selection Sort**. O usuário pode inserir até 100 números positivos, e o programa seleciona automaticamente o algoritmo de ordenação apropriado com base na quantidade de números inseridos.

## Estrutura do Programa

### Variáveis Utilizadas

- `double arr[100]`: Array para armazenar até 100 valores.
- `int size`: Controla o número de elementos inseridos pelo usuário.
- `char resposta`: Recebe a resposta do usuário sobre a continuação da inserção de números.

### Funcionamento do Programa

1. **Coleta de Números**: O programa solicita ao usuário que insira números positivos.
   - A inserção continua até que o usuário decida parar ou atinja o limite de 100 números.
   - Se o usuário tentar inserir um número negativo, uma mensagem de erro é exibida.

2. **Exibição da Lista Desorganizada**: Após a coleta, a lista desordenada é exibida.

3. **Escolha do Algoritmo de Ordenação**:
   - Se o número de elementos (`size`) for menor ou igual a 20, o programa utiliza **Insertion Sort**.
   - Se `size` estiver entre 21 e 30, o programa utiliza **Bubble Sort**.
   - Se `size` for maior que 30, o programa utiliza **Selection Sort**.

4. **Exibição da Lista Ordenada**: O programa exibe a lista ordenada e informa qual método de ordenação foi utilizado.

## Código Fonte

```cpp
#include <iostream>
using namespace std;

// Função para Insertion Sort
void insertionSort(double arr[], int size) {

    for (int i = 1; i < size; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função para Bubble Sort
void bubbleSort(double arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Função para Selection Sort
void selectionSort(double arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Função principal
int main() {
    double arr[100];
    int size = 0;
    char resposta;

    // Coleta de números
    do {
        double num;
        cout << "Insira um número positivo: ";
        cin >> num;

        if (num >= 0) {
            arr[size++] = num;
        } else {
            cout << "Por favor, insira um número positivo." << endl;
        }

        if (size >= 100) {
            cout << "Limite de 100 números alcançado." << endl;
            break;
        }

        cout << "Deseja inserir mais números? (s/n): ";
        cin >> resposta;

    } while (resposta == 's' || resposta == 'S');

    // Exibe a lista desorganizada
    cout << "Lista desorganizada: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Ordenação
    if (size <= 20) {
        insertionSort(arr, size);
        cout << "Método de ordenação: Insertion Sort" << endl;
    } else if (size <= 30) {
        bubbleSort(arr, size);
        cout << "Método de ordenação: Bubble Sort" << endl;
    } else {
        selectionSort(arr, size);
        cout << "Método de ordenação: Selection Sort" << endl;
    }

    // Exibe a lista ordenada
    cout << "Lista ordenada: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
