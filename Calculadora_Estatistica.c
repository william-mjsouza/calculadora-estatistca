#include <stdio.h>
#include <math.h>

float calcula_media(float valores[1000], int total){
    float media, soma = 0;
    int i;
    for(i=0; i<total; i++){
        soma = soma + valores[i];
    }
    media = soma / total;
    return media;   
}

void calcula_mediana(float valores[1000], int total){
    float mediana;
    if(total % 2 == 0){
        mediana = (valores[(total/2)-1] + valores[(total/2)]) / 2;
        printf("\nA mediana eh %.2f", mediana);
    }
    else{
        printf("\nA mediana eh %.2f", valores[total/2]);
    }
}

void colocando_em_rol(float valores[1000], int total){
    //Algoritmo de ordenação Bubblesort - ORDEM CRESCENTE:
    int contador, i;
    float aux;
    for(contador=1; contador<total; contador++){
        for(i=0; i<(total-1); i++){
            if(valores[i] > valores[i+1]){
                aux = valores[i];
                valores[i] = valores[i+1];
                valores[i+1] = aux;
            }
        }
    }
    printf("Colocando os valores em ROL crescente:\n");
    for(i=0; i<total; i++){
        printf("%.2f   ", valores[i]);
    }
    calcula_mediana(valores, total);
}

float calcula_variancia(float valores[1000], int total){
    float media, variancia, soma = 0;
    int i;
    media = calcula_media(valores, total);
    
    for(i=0; i<total; i++){
        soma = soma + pow((valores[i] - media), 2);
    }

    variancia = soma / total;
    return variancia;
}

int main() {
    int opcao, total, i, contador;
    float valores[1000], media, variancia, desvio_padrao;
    
    printf("=======Calculadora Estatistica=======");
    printf("\n[1] Media");
    printf("\n[2] Moda");
    printf("\n[3] Mediana");
    printf("\n[4] Variancia");
    printf("\n[5] Desvio Padrao");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);
    if(opcao == 1){
        printf("Quantos valores vc vai digitar? ");
        scanf("%d", &total);
        for(i=0; i<total; i++){
            printf("Digite o %d valor: ", i+1);
            scanf("%f", &valores[i]);
        }
        media = calcula_media(valores, total);
        printf("A media eh %.2f", media);
    }
    else if(opcao == 2){
        
    }
    else if(opcao == 3){
        printf("Quantos valores vc vai digitar? ");
        scanf("%d", &total);
        for(i=0; i<total; i++){
            printf("Digite o %d valor: ", i+1);
            scanf("%f", &valores[i]);
        }
        colocando_em_rol(valores, total);
    }
    else if(opcao == 4){
        printf("Quantos valores vc vai digitar? ");
        scanf("%d", &total);
        for(i=0; i<total; i++){
            printf("Digite o %d valor: ", i+1);
            scanf("%f", &valores[i]);
        }
        variancia = calcula_variancia(valores, total);
        printf("A variancia eh %.2f", variancia);
    }
    else if(opcao == 5){
        printf("Quantos valores vc vai digitar? ");
        scanf("%d", &total);
        for(i=0; i<total; i++){
            printf("Digite o %d valor: ", i+1);
            scanf("%f", &valores[i]);
        }
        variancia = calcula_variancia(valores, total);
        desvio_padrao = sqrt(variancia);
        printf("O desvio padrao eh %.2f", desvio_padrao);
    }
    else{
        printf("Opcao invalida!");
    }

return 0;
}