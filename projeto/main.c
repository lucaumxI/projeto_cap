#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

float conta(float tempo){
    float ponto=0;

    if (tempo<=5){
        ponto = ponto + 100 * (pow(2, 0.1*tempo));
    } else if (tempo>5 && tempo<60){
                ponto = ponto + 10 * (pow(tempo, 1.1));
            }
            else{
                ponto = 1000;
                printf("a");
            }
    return ponto;
}

struct registro{
    char nome[50];
    float ponto;
};

int compara (const void * a, const void * b) {
    struct registro *p1 = (struct registro*) a;
    struct registro * p2 = (struct registro * )b;
    return (p2->ponto - p1->ponto);
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
                    timer = (clock() - timer) / CLOCKS_PER_SEC;
                    pont = pont - conta((float)(timer));
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
                    timer = (clock() - timer) / CLOCKS_PER_SEC;
                    pont = pont - conta((float)(timer));
                }
                else{
                    vida--;
                }
                break;
        }

        printf("%f\n", pont);

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
                    timer = (clock() - timer) / CLOCKS_PER_SEC;
                    pont = pont - conta((float)(timer));
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
                    timer = (clock() - timer) / CLOCKS_PER_SEC;
                    pont = pont - conta((float)(timer));
                }
                else{
                    vida--;
                }
                break;
            case 2:
                a = 5 + rand() % 20;
                b = 5 + rand() % 20;
                printf ("%d x %d = ", a, b);
                scanf("%f", &resposta);
                if (resposta==a*b){
                    pont = pont + 1000;
                    timer = (clock() - timer) / CLOCKS_PER_SEC;
                    pont = pont - conta((float)(timer));
                }
                else{
                    vida--;
                }
                break;
            case 3:
                a = 50 + rand() % 450;
                b = 5 + rand() % 10;
                printf ("%d / %d = ", a, b);
                scanf("%f", &resposta);
                if (resposta==a/b){
                    pont = pont + 1000;
                    timer = (clock() - timer) / CLOCKS_PER_SEC;
                    pont = pont - conta((float)(timer));
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
                    timer = (clock() - timer) / CLOCKS_PER_SEC;
                    pont = pont - conta((float)(timer));
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
                    timer = (clock() - timer) / CLOCKS_PER_SEC;
                    pont = pont - conta((float)(timer));
                }
                else{
                    vida--;
                }
                break;
            case 2:
                a = 100 + rand() % 400;
                b = 100 + rand() % 400;
                printf ("%d x %d = ", a, b);
                scanf("%f", &resposta);
                if (resposta==a*b){
                    pont = pont + 1000;
                    timer = (clock() - timer) / CLOCKS_PER_SEC;
                    pont = pont - conta((float)(timer));
                }
                else{
                    vida--;
                }
                break;
            case 3:
                a = 100 + rand() % 5000;
                b = 10 + rand() % 90;
                printf ("%d / %d = ", a, b);
                scanf("%f", &resposta);
                if (resposta==a/b){
                    pont = pont + 1000;
                    timer = (clock() - timer) / CLOCKS_PER_SEC;
                    pont = pont - conta((float)(timer));
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
     switch(escolha){
        case 1:
            rank = fopen("rankf.txt", "r");
            while (fscanf(rank,"%s %f",reg[cont].nome ,&reg[cont].ponto)!=EOF){
                cont++;
            }
            reg[cont].ponto = facil();
            break;
        case 2:
            rank = fopen("rankm.txt", "r");
            while (fscanf(rank,"%s %f",reg[cont].nome ,&reg[cont].ponto)!=EOF){
                cont++;
            }
            reg[cont].ponto = medio();
            break;
        case 3:
            rank = fopen("rankd.txt", "r");
            while (fscanf(rank,"%s %f",reg[cont].nome ,&reg[cont].ponto)!=EOF){
                cont++;
            }
            reg[cont].ponto = dificil();
            break;
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
    scanf("%s", reg[cont].nome);
    qsort(reg, cont+1, sizeof(struct registro), compara);
    for(int i = 0; i<cont+1; i++){
        for(int n = 0; n<strlen(reg[i].nome);n++){
        fputc(reg[i].nome[n],rank);
        }
        fprintf(rank," %f\n", reg[i].ponto);

    }


    fclose(rank);

    return 0;
}
