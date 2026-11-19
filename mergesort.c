#include <stdio.h>

void merge(int v[], int inicio, int meio, int fim) {
    int i = inicio, m = meio + 1, k = 0; // k = numerados do vetor temporario
    int temp[fim - inicio + 1];

    // ordenando
    while (i <= meio && m <= fim) { // enquanto tiver elementos. Ele compara o primeiro com o ultimo elemento
        if (v[i] < v[m]){           // e qual for escolhido anda pra frente. 

            temp[k] = v[i]; // inserção na array temp é v[i]
            i++;
        }
        else{
            temp[k] = v[m]; // se não é v[m]
            m++;
        }
        k++; // 'k' é o motor
    }

    // completa o temp com os numeros que sobraram
    while (i <= meio){   // insere o resto no inicio
        temp[k] = v[i];
        i++;
        k++;
    }

    while (m <= fim){    // insere no fim
        temp[k] = v[m];
        m++;
        k++;
    }

    // remontando v -- inserindo a array temp
    for (i = inicio, k = 0; i <= fim; i++, k++) //insere elementos de volta no vetor
        v[i] = temp[k];
}

void msort(int v[], int inicio, int fim) {
    if (inicio < fim) { // base. se nao tem um par de elementos, retorna.

        int meio = (inicio + fim) / 2;

        // divide o vetor em duas partes
        msort(v, inicio, meio);  // parte 1
        msort(v, meio + 1, fim); // parte 2


        merge(v, inicio, meio, fim); // como é uma função recursiva ela se monta de cima pra baixo, as ultimas chamadas são as primeiras.
    }   
}

void ler(int v[], int n){ // lê arrau

    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);

}

int main() {
    int v[] = {8, 3, 5, 9, 2, 7};
    int n = sizeof(v) / sizeof(v[0]); // quantidade de elementos  || ((total de bytes) / (bytes p elemento)) = total de elementos

    ler(v,n);

    msort(v, 0, n - 1); // vetores já são ponteiros, de certa forma. por isso nao tem & e mesmo assim ele é modificado 

    printf("lista organizada: ");
    ler(v,n);

    return 0;
}