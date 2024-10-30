//Trabalho feito por Kauã de Jesus Souza, Hendryw e Rian
#include <iostream>
using namespace std;

// Função do Bubble Sort
void bubbleSort(double arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função do Selection Sort
void selectionSort(double arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i; 
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; 
            }
        }
        double temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Função do Insertion Sort
void insertionSort(double arr[], int size) {
    for (int i = 1; i < size; ++i) {
        double key = arr[i]; 
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    double arr[100]; // Array para armazenar os números
    int size = 0; // Contador de números inseridos
    char resposta; // Resposta do usuário

    cout << "Olá, bem-vindo ao programa de organização de dados do Kaua, Andril e Little Rian!" << endl;

    // Loop para receber números do usuário
    do {
        cout << "Digite o número que deseja organizar: ";
        cin >> arr[size]; 

        // Aceita apenas números positivos
        if (arr[size] < 0) {
            cout << "Por favor, insira um número positivo." << endl;
            continue;
        }

        size++;

        cout << "Deseja inserir mais um número? (s) ou (n): ";
        cin >> resposta; // Pergunta se o usuário quer continuar

    } while (resposta == 's' && size < 100); // Continua até o usuário dizer que não

    // Exibe a lista desordenada
    cout << "Lista desordenada: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Escolhe o método de ordenação baseado na quantidade de números
    if (size <= 20) {
        cout << "Usando Insertion Sort..." << endl;
        insertionSort(arr, size); // Chama Insertion Sort
    } else if (size <= 30) {
        cout << "Usando Bubble Sort..." << endl;
        bubbleSort(arr, size); // Chama Bubble Sort
    } else {
        cout << "Usando Selection Sort..." << endl;
        selectionSort(arr, size); // Chama Selection Sort
    }

    // Exibe a lista ordenada
    cout << "Lista ordenada: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0; // Finaliza o programa
}
