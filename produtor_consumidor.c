#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define ARQUIVO "buffer.txt"

// Adiciona um valor ao final do arquivo.
void escreverNoArquivo(int valor) {
    FILE *arquivo = fopen(ARQUIVO, "a"); 
    fprintf(arquivo, "%d\n", valor); 
    fclose(arquivo); 
}

//  Le o primeiro valor do arquivo
int lerDoArquivo() {
    FILE *arquivo = fopen(ARQUIVO, "r"); 
    int valor;
    fscanf(arquivo, "%d", &valor); 
    fclose(arquivo); 
    return valor; 
}

// Remove a primeira linha do arquivo
void removerPrimeiraLinha() {
    FILE *arquivo = fopen(ARQUIVO, "r"); 
    FILE *temp = fopen("temp.txt", "w"); 

    int valor;
    fscanf(arquivo, "%d", &valor); // Lê o valor da primeira linha

    // Copia o restante do arquivo para o arquivo temporário
    while (fscanf(arquivo, "%d", &valor) != EOF) {
        fprintf(temp, "%d\n", valor);
    }
    fclose(arquivo); 
    fclose(temp); 

    remove(ARQUIVO); 
    rename("temp.txt", ARQUIVO); 
}

//  Cria um arquivo e escreve 10 valores aleatórios nele
void inicializarArquivo() {
    FILE *arquivo = fopen(ARQUIVO, "w"); 
    srand(time(NULL)); 

    // Escreve 10 valores aleatórios no arquivo
    for (int i = 0; i < 10; ++i) {
        int valorInicial = rand() % 100; // Valor aleatório entre 0 e 99
        fprintf(arquivo, "%d\n", valorInicial);
    }
    fclose(arquivo); 
}

int main() {
    srand(time(NULL)); 

    // Verifica se o arquivo existe
    FILE *verificaArquivo = fopen(ARQUIVO, "r"); 
    if (verificaArquivo == NULL) {
        fclose(verificaArquivo); 
        inicializarArquivo(); 
    } else {
        fclose(verificaArquivo); 
    }

    // Loop Infinito
    while (1) {
        int processo = fork(); 

        if (processo < 0) {
            printf("Erro ao criar processo filho");
            exit(EXIT_FAILURE); 
        } else if (processo == 0) {
            // Processo filho - Produtor
            int valorAleatorio = rand() % 100; // Valor aleatório entre 0 e 99
            printf("[Produtor] %d\n", valorAleatorio); 
            escreverNoArquivo(valorAleatorio); // Escreve o valor no arquivo

            sleep(rand() % 3 + 1); // Espera por um tempo aleatório antes de continuar
            exit(EXIT_SUCCESS); 
        } else {
            // Processo pai - Consumidor
            wait(NULL); // Espera pelo término do processo filho

            int valor = lerDoArquivo();
            printf("[Consumidor] %d\n", valor); 
            removerPrimeiraLinha(); // Remove o valor lido do arquivo

            sleep(rand() % 3 + 1); 
        }
    }

    return 0;
}
