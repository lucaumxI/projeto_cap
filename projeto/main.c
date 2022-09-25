#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float conta(float tempo){
    float ponto=1000;

    if (tempo<=5){
        ponto = ponto - 100 * (pow(2, 0.1*tempo));
    }
    if (tempo >5 && tempo<60){
        ponto = ponto - 10 * (pow(tempo, 1.1));
    }
    else{
        ponto = 1000;
    }
    return ponto;
}

struct registro{
    char nome[50];
    float ponto;
};

int compara(struct registro *a, struct registro *b){
    if (a->ponto == b->ponto)
        return 0;
    else if (a->ponto > b->ponto)
        return -1;
    else
        return 1;
}

float facil(){
    int a, b, vida=2;
    int operacao, cont = 0;
    float pont = 0;
    float resposta;
    clock_t timer;

    while (cont<10 && vida!=0){
        srand(time(NULL));
        operacao = rand() % 2;
        timer = clock();

        switch (operacao){
            case 0:
                a = rand() % 100;
                b = rand() % 100;
                printf ("%d + %d = ", a, b);
                scanf("%f", &resposta);
                if (resposta==a+b){
                    pont = pont + 1000;
                }
                else{
                    vida--;
                }
                break;
            case 1:
                a = rand() % 100;
                b = rand() % 100;
                printf ("%d - %d = ", a, b);
                scanf("%f", &resposta);
                if (resposta==a-b){
                    pont = pont + 1000;
                }
                else{
                    vida--;
                }
                break;
        }
        timer = (clock() - timer) / CLOCKS_PER_SEC;
        pont = pont - conta(timer);

        cont++;
    }
    return pont;
}

float medio(){
    int a, b, vida = 2;
    int operacao, cont = 0, pont = 0;
    float resposta;
    clock_t timer;

    while (cont<10 && vida!=0){
        srand(time(NULL));
        operacao = rand() % 4;
         timer = clock();


        switch (operacao){
            case 0:
                a = 100 + rand() % 1000;
                b = 100 + rand() % 1000;
                printf ("%d + %d = ", a, b);
                scanf("%f", &resposta);
                if (resposta==a+b){
                    pont = pont + 1000;
                }
                else{
                    vida--;
                }
                break;
            case 1:
                a = 100 + rand() % 1000;
                b = 100 + rand() % 1000;
                printf ("%d - %d = ", a, b);
                scanf("%f", &resposta);
                if (resposta==a-b){
                    pont = pont + 1000;
                }
                else{
                    vida--;
                }
                break;
            case 2:
                a = 10 + rand() % 25;
                b = 10 + rand() % 25;
                printf ("%d x %d = ", a, b);
                scanf("%f", &resposta);
                if (resposta==a*b){
                    pont = pont + 1000;
                }
                else{
                    vida--;
                }
                break;
            case 3:
                a = 50 + rand() % 500;
                b = 5 + rand() % 10;
                printf ("%d / %d = ", a, b);
                scanf("%f", &resposta);
                if (resposta==a/b){
                    pont = pont + 1000;
                }
                else{
                    vida--;
                }
                break;
        }
        timer = (clock() - timer) / CLOCKS_PER_SEC;
        pont = pont - conta(timer);

        cont++;
    }
    return pont;
}

float dificil(){
    int a, b, vida = 1;
    int operacao, cont = 0, pont = 0;
    float resposta;
    clock_t timer;

    while (cont<10 && vida!=0){
        srand(time(NULL));
        operacao = rand() % 4;
         timer = clock();

        switch (operacao){
            case 0:
                a = 1000 + rand() % 10000;
                b = 1000 + rand() % 10000;
                printf ("%d + %d = ", a, b);
                scanf("%f", &resposta);
                if (resposta==a+b){
                    pont = pont + 1000;
                }
                else{
                    vida--;
                }
                break;
            case 1:
                a = 1000 + rand() % 10000;
                b = 1000 + rand() % 10000;
                printf ("%d - %d = ", a, b);
                scanf("%f", &resposta);
                if (resposta==a-b){
                    pont = pont + 1000;
                }
                else{
                    vida--;
                }
                break;
            case 2:
                a = 100 + rand() % 1000;
                b = 100 + rand() % 1000;
                printf ("%d x %d = ", a, b);
                scanf("%f", &resposta);
                if (resposta==a*b){
                    pont = pont + 1000;
                }
                else{
                    vida--;
                }
                break;
            case 3:
                a = 100 + rand() % 5000;
                b = 50 + rand() % 100;
                printf ("%d / %d = ", a, b);
                scanf("%f", &resposta);
                if (resposta==a/b){
                    pont = pont + 1000;
                }
                else{
                    vida--;
                }
                break;
        }
        timer = (clock() - timer) / CLOCKS_PER_SEC;
        pont = pont - conta(timer);

        cont++;
    }
    return pont;
}

int main()
{
    int escolha;
    FILE* rank = fopen("rank.txt", "r");
    struct registro reg[11] = {'NULL', 0};
    int cont=0;

    scanf("%d", &escolha);
    scanf("%s", &reg[cont].nome);
     switch(escolha){
        case 1:
            rank = fopen("rankf.txt", "r");
            reg[cont].ponto = facil();
            break;
        case 2:
            rank = fopen("rankm.txt", "r");
            reg[cont].ponto = medio();
            break;
        case 3:
            rank = fopen("rankd.txt", "r");
            reg[cont].ponto = dificil();
            break;
    }



    while (!feof(rank)){
        fscanf(rank,"%s %f", reg[cont].nome, &reg[cont].ponto);
        cont++;
    }
    fclose(rank);

    switch(escolha){
        case 1:
            rank = fopen("rankf.txt", "w");
            break;
        case 2:
            rank = fopen("rankm.txt", "w");
            break;
        case 3:
            rank = fopen("rankd.txt", "w");
            break;
    }

    printf ("%f", reg[cont].ponto);

    qsort(reg, cont+1, sizeof(struct registro), compara);
    fclose(rank);

    return 0;
}
