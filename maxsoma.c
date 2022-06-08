#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vet, n;
    while(1){
        printf("Insira o numero de elementos do vetor: ");
        scanf("%d", &n);
        if(n >= 3 && n <= 20){ //O laço "while" se repete até que o usuário insira um valor válido (entre 3 e 20).
            break;
        }
    }
    vet = (int *) malloc(n * sizeof(int)); //Alocando memória para o vetor.
    printf("Agora, insira os elementos do vetor:\n");
    for(int indice = 0; indice < n; indice++){
        scanf("%d", &vet[indice]);
    }
    int soma_maxima, primeiro_indice = 0, ultimo_indice = 0;
    for(int i = 0; i < n; i++){
        int soma_atual = 0;
        for(int j = i; j < n; j++){
            soma_atual += vet[j]; //Começa a somar.
            if(soma_atual > soma_maxima){ //Se a soma atual for maior que o que está armazenado em máxima, a atual se torna a máxima.
                soma_maxima = soma_atual;
                primeiro_indice = i + 1; //Salva o índice inicial do intervalo de subvetores contíguos.
                ultimo_indice = j + 1; //Salva o índice final do intervalo de subvetores contíguos.
            }
        }
    }
    printf("Soma: %d\n", soma_maxima);
    printf("Indices: %d a %d\n", primeiro_indice, ultimo_indice);
    
    free(vet);
    return 0;
}