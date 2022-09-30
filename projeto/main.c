
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "raylib.h"
#define MAX_INPUT_CHARS     15
struct registro{
    char nome[50];
    float ponto;
};

int compara (const void * a, const void * b) {
    struct registro *p1 = (struct registro*) a;
    struct registro * p2 = (struct registro * )b;
    return (p2->ponto - p1->ponto);
     }

 int v=2,c = 0;
 float conta(float tempo)
{
    float ponto=0;

    if (tempo<=15)
    {
        ponto = ponto + 100 * (pow(2, 0.1*tempo));
    }
    else if (tempo>15 && tempo<60)
    {
        ponto = ponto + 10 * (pow(tempo, 1.1));
    }
    else
    {
        ponto = 1000;
        printf("a");
    }
    return ponto;
}

float input(int *vida,int *cont)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    int key = 0;

    char name[MAX_INPUT_CHARS + 1] = "\0";      // NOTE: One extra space required for null terminator char '\0'
    int letterCount = 0;

    Rectangle textBox = { screenWidth/2.0f - 360, 280, 225, 50 };
    Rectangle recs = {screenWidth/2.0f - 360,250, 225, 30};
    Rectangle perg = {200,90, 225, 50};
    bool mouseOnText = false;

    int framesCounter = 0;

    SetTargetFPS(20);               // Set our game to run at 10 frames-per-second
    //--------------------------------------------------------------------------------------
    char expr [50];
    int a,b,operacao;
    int contador;
    float resposta;
    float pont=0;
    int c=1;
    clock_t timer;

    timer = clock();

    Image jogo = LoadImage("Jogo.png");
    ImageResize(&jogo, 800, 550);
    Texture2D game = LoadTextureFromImage(jogo);

    // Main game loop
            operacao = rand() %4;
            switch (operacao)
            {
            case 0:
                a = rand() % 500;
                b = rand() % 500;
                sprintf(expr, "%d + %d = ", a,b);
                break;
            case 1:
                a = rand() % 500;
                b = rand() % 500;
                sprintf(expr, "%d - %d = ", a,b);
                break;

            case 2:
                a = rand() % 100;
                b = rand() % 100;
                sprintf(expr, "%d * %d = ", a,b);
                break;

            case 3:
                a = 100+ rand() % 500;
                b = 1 + rand() % 100;
                sprintf(expr, "%d / %d = ", a,b);
                break;
            }


    while (!WindowShouldClose()&&!IsKeyPressed(KEY_ENTER))    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
        else mouseOnText = false;

        if ((mouseOnText))
        {
            // Set the window's cursor to the I-Beam
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            // Get char pressed (unicode character) on the queue
            key =  GetKeyPressed();
            // Check if more characters have been pressed on the same frame
            while (key > 0)
            {
                // NOTE: Only allow keys in range [32..125]
                if ((key >= 0) && (key <= 257) && (letterCount < MAX_INPUT_CHARS))
                {
                    name[letterCount] = (char)key;
                    name[letterCount+1] = '\0'; // Add null terminator at the end of the string.
                    letterCount++;
                }

                key =  GetKeyPressed();  // Check next character in the queue

            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                name[letterCount] = '\0';
            }
        }

        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseOnText) framesCounter++;
        else framesCounter = 0;


        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        DrawTexture(game,0,0,WHITE);

        DrawRectangleRec(textBox, LIGHTGRAY);
        if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
        else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

        DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);
        DrawRectangleRec(recs, LIGHTGRAY);
        DrawText("Digite abaixo a resposta:", screenWidth/2.0f - 360, 255, 19, BLACK);
        DrawRectangleRec(perg, LIGHTGRAY);
        DrawRectangleLines((int)perg.x, (int)perg.y, (int)perg.width, (int)perg.height, BLACK);
        resposta = atof(name);




        DrawText(expr,210,100,30,WHITE);

        if (mouseOnText)
        {
            if (letterCount < MAX_INPUT_CHARS)
            {
                // Draw blinking underscore char
                if (((framesCounter/20)%2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
            }
            else DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    switch (operacao)
            {
            case 0:

                 if (resposta==a+b)
            {
             pont = pont + 1000;
                timer = (clock() - timer) / CLOCKS_PER_SEC;
                pont = pont - conta((float)(timer));
            }
            else
            {

                *vida = *vida - 1;
                printf("%d\n",*vida);
                }

                break;
            case 1:
                 if (resposta==a-b)
            {
             pont = pont + 1000;
                timer = (clock() - timer) / CLOCKS_PER_SEC;
                pont = pont - conta((float)(timer));
            }
            else
            {
                *vida = *vida - 1;
                printf("%d\n",*vida);
                }
                break;

            case 2:


                 if (resposta==a*b)
            {
             pont = pont + 1000;
                timer = (clock() - timer) / CLOCKS_PER_SEC;
                pont = pont - conta((float)(timer));
            }
             else
            {
                printf("%d\n",*vida);
                *vida = *vida - 1;
                printf("%d\n",*vida);
                }

                break;

            case 3:

                 if (resposta==a/b)
            {
             pont = pont + 1000;
                timer = (clock() - timer) / CLOCKS_PER_SEC;
                pont = pont - conta((float)(timer));
            }
            else
            {
                printf("%d\n",*vida);
                *vida = *vida - 1;
                printf("%d\n",*vida);
                }
                break;
            }
    *cont=*cont+1;
    return pont;
}
bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}

typedef enum GameScreen {TITLE, NARRATIVA, CONTROLE,GAMEPLAY, VITORIA, DERROTA, RANK, END } GameScreen;

int main()
{

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 550;
    InitWindow(screenWidth, screenHeight, "O Enigma da Esfinge");
    GameScreen currentScreen = TITLE;
    InitAudioDevice();
    Music music = LoadMusicStream("msc.mp3");
    PlayMusicStream(music);

    SetTargetFPS(20);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------// Load image data into CPU memory (RAM)
    Texture2D texture =  LoadTexture("esfingeCeu.png");
    Image image = LoadImageFromTexture(texture);
    UnloadTexture(texture);
    Image *imagem = &image;
    ImageResize(imagem,800,550);
    Texture2D texture1 = LoadTextureFromImage(*imagem);
    UnloadImage(*imagem);
    Font font = LoadFontEx("cleopatra-4.ttf",69,0,0);
    Font hist = LoadFontEx("OpenSans-Italic.ttf",24,0,0);
    Rectangle recu[2] = {{ 250, 325, 300, 30},{250,385,300,30}};
    Rectangle rec = { 100, 0, 600, 110};
    Font fonte = LoadFont("jupcrash.ttf");
    Image credito = LoadImage("pira.png");
    ImageResize(&credito, 800, 550);
    Texture2D texture2 = LoadTextureFromImage(credito);
    Image jogo = LoadImage("Jogo.png");
    ImageResize(&jogo, 800, 550);
    Texture2D game = LoadTextureFromImage(jogo);
    Image papir = LoadImage("papiro.png");
    ImageResize(&papir,400,550);
    Texture2D papiro = LoadTextureFromImage(papir);
    Image piraRank = LoadImage("piramideRank.png");
    ImageResize(&piraRank,800,550);
    Texture2D pirRank = LoadTextureFromImage(piraRank);

    FILE* rank = fopen("rank.txt", "r");

     Rectangle digNome = {180,300,400,50};
     Rectangle digNomes = {180,400,400,50};

    struct registro reg[11] = {'NONE', 0};
      int contr = 0;
    char string[10][100];
    int contador=0;
    int key =0;
    bool mouseOnText = false;
    char name[MAX_INPUT_CHARS + 1] = "\0";      // NOTE: One extra space required for null terminator char '\0'
    int letterCount = 0;
     int framesCounter = 0;
     char nome[50];


    while (fscanf(rank,"%s %f",reg[contador].nome ,&reg[contador].ponto)!=EOF){
                contador++;
            }

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        PlayMusicStream(music);
        UpdateMusicStream(music);

                BeginDrawing();
        ClearBackground(BLACK);
        switch(currentScreen)
        {
        case TITLE:
        {
            c=0;
            v=2;
            contr = 0;

            // TODO: Draw TITLE screen here!
            DrawTexture(texture1, 0,0,WHITE);
            DrawTextEx( font, "     O Enigma da Esfinge", (Vector2)
            {
                20.0f, 20.0f
            }, (float)font.baseSize, 0.0f, WHITE);
            //DrawRectangleRec(rec, BLANK);
            //DrawRectangleRec(recu[0], BLACK);
            //DrawRectangleRec(recu[1], BLACK);
            DrawText("Criadores: Joao Andrade---Lucas Nunes---Rafael Banin", 10, 500, 20, WHITE);
            DrawText("Pressione ENTER para iniciar", 250, 400, 20, WHITE);
            DrawText("Pressione C para ver os controles", 220, 440, 20, WHITE);
        }
        break;
        case NARRATIVA:
        {
            DrawTextEx(hist, "Jose Mateus, um jovem, porem, eximio explorador nascido no interior da Bahia, muito adepto aos",(Vector2)
            {
                50.0f, 20.0f
            }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "ideiais socialistas, estava trabalhando no Egito em busca de indicios para defender sua tese de que o",(Vector2)
            {
                14.5f, 45.0f
            }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "socialismo era idealizado desde os tempos antigos.",(Vector2)
            {
                14.5f, 70.0f
            }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "Infelizmente, sua exploracao nao estava o levando a lugar nenhum, entao ele decidiu 'turistar' um",(Vector2)
            {
                50.0f, 95.0f
            }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "pouco para espairecer a mente. Durante seu passeio, andando a esmo, ele ve algo brilhando perdido",(Vector2)
            {
                14.5f, 120.0f
            }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "em meio ao deserto escaldante. Ao se aproximar do estranho objeto brilhante ele se depara com",(Vector2)
            {
                14.5f, 145.0f
            }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "uma estranha bussola que nao apontava para o norte. Ele decide entao seguir o caminho indicado pela",(Vector2)
            {
                14.5f, 170.0f
            }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "bussola que o leva exatamente para o centro entre as duas patas da Esfinge de Gize.",(Vector2)
            {
                14.5f, 195.0f
            }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "La ele vislumbra um orificio com o diametro exato da bussola e em um momento de epifania, quase ",(Vector2)
            {
                50.0f, 220.0f
            }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "como se os deuses o guiassem para isso, ele decide inserir a bussola no buraco, entao, a Esfinge ",(Vector2)
            {
                14.5f, 245.0f
            }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "de forma retumbante e ecoante bradou: 'ser insignificante, eu tenho ciencia do porque voce me despertou,",(Vector2)
            {
                14.5f, 270.0f
            }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "porem eu so irei lhe dar a direcao para encontrar o que voce procura caso voce consiga responder ",(Vector2)
            {
                14.5f, 295.0f
            }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "as 10 perguntas aritmeticas que tenho preparado, caso voce erre, isso mostrara que voce nao tem ",(Vector2)
            {
                14.5f, 320.0f
            }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "determinacao o suficiente e eu terei que lhe engolir!!!'.",(Vector2)
            {
                4.5f, 345.0f
            }, (float)hist.baseSize, 0.0f, WHITE);
            DrawText("Clique S para prosseguir ao jogo", 75,400,40,WHITE);
            //sif(reg[10].ponto!=0)reg[10].ponto=0;

        }
        break;
        case CONTROLE:
        {
            DrawText("Como jogar", 10,10,30,WHITE);
            DrawText("Use as teclas numericas para responder as perguntas realizadas", 20,150,20,WHITE);
            DrawText("Use a tecla 'ENTER' para confirmar sua resposta", 20,200,20,WHITE);
            DrawText("Pressione 'V' para voltar a tela inicial", 20,400,20,WHITE);
        }
        break;

        case GAMEPLAY:
        {
            reg[10].ponto += input(&v,&c);
             if(!v){
                currentScreen = DERROTA;
            }else if(c==10){
                currentScreen = VITORIA;
            }
        }
        break;

        case DERROTA:

             DrawText("Voce nao conseguiu responder as perguntas e foi devorado pela esfinge!",20,200,20,RED);
            DrawRectangleRec(digNome, LIGHTGRAY);
            DrawRectangleLines((int)digNome.x, (int)digNome.y, (int)digNome.width, (int)digNome.height, RED);
            DrawText("Insira abaixo seu nome:",180,250,30,RED);


                    if (CheckCollisionPointRec(GetMousePosition(), digNome)) mouseOnText = true;
        else mouseOnText = false;

        if ((mouseOnText))
        {
            // Set the window's cursor to the I-Beam
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            // Get char pressed (unicode character) on the queue
            key =  GetKeyPressed();
            // Check if more characters have been pressed on the same frame
            while (key > 0)
            {
                // NOTE: Only allow keys in range [32..125]
                if ((key >= 0) && (key <= 257) && (letterCount < MAX_INPUT_CHARS))
                {
                    nome[letterCount] = (char)key;
                    nome[letterCount+1] = '\0'; // Add null terminator at the end of the string.
                    letterCount++;
                }

                key =  GetKeyPressed();  // Check next character in the queue

            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                 nome[letterCount] = '\0';
            }
        }
    else SetMouseCursor(MOUSE_CURSOR_DEFAULT);


        if (mouseOnText) framesCounter++;
        else framesCounter = 0;

          if (mouseOnText)
        {
            if (letterCount < MAX_INPUT_CHARS)
            {
                // Draw blinking underscore char
                if (((framesCounter/20)%2) == 0) DrawText("_", (int)digNome.x + 8 + MeasureText(name, 40), (int)digNome.y + 12, 40, MAROON);
            }
            else DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
        }
         DrawText(nome, (int)digNome.x + 5, (int)digNome.y + 8, 40, MAROON);
            if(IsKeyPressed(KEY_ENTER)){
                strcpy(reg[10].nome,nome);
                currentScreen = RANK;}
            break;

        case VITORIA:
             DrawText("PARABENS!!!",300,200,20,YELLOW);
            DrawText("Voce conseguiu escapar da esfinge e pode continuar sua aventura!",50,250,20,YELLOW);
             DrawRectangleRec(digNomes, LIGHTGRAY);
            DrawRectangleLines((int)digNomes.x, (int)digNomes.y, (int)digNomes.width, (int)digNomes.height, YELLOW);
            DrawText("Insira abaixo seu nome:",180,350,30,YELLOW);
                                if (CheckCollisionPointRec(GetMousePosition(), digNomes)) mouseOnText = true;
        else mouseOnText = false;

        if ((mouseOnText))
        {
            // Set the window's cursor to the I-Beam
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            // Get char pressed (unicode character) on the queue
            key =  GetKeyPressed();
            // Check if more characters have been pressed on the same frame
            while (key > 0)
            {
                // NOTE: Only allow keys in range [32..125]
                if ((key >= 0) && (key <= 257) && (letterCount < MAX_INPUT_CHARS))
                {
                    nome[letterCount] = (char)key;
                    nome[letterCount+1] = '\0'; // Add null terminator at the end of the string.
                    letterCount++;
                }

                key =  GetKeyPressed();  // Check next character in the queue

            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                 nome[letterCount] = '\0';
            }
        }

        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseOnText) framesCounter++;
        else framesCounter = 0;

          if (mouseOnText)
        {
            if (letterCount < MAX_INPUT_CHARS)
            {
                // Draw blinking underscore char
                if (((framesCounter/20)%2) == 0) DrawText("_", (int)digNomes.x + 8 + MeasureText(name, 40), (int)digNomes.y + 12, 40, MAROON);
            }
            else DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
        }
         DrawText(nome, (int)digNomes.x + 5, (int)digNomes.y + 8, 40, MAROON);
            if(IsKeyPressed(KEY_ENTER))
                strcpy(reg[10].nome,nome);
                currentScreen = RANK;

            break;
        case RANK:
        {

            //ClearBackground(GRAY);
            DrawTexture(pirRank,0,0,WHITE);
            DrawTexture(papiro,180,0,WHITE);
            DrawTextEx(font,"RANKING",(Vector2){305.0f,50.0f},70, 0.0f, BLACK);
                qsort(reg, 11, sizeof(struct registro), compara);
                if(contr<10){
                   sprintf(string[contr], "%s %6.2f", reg[contr].nome,reg[contr].ponto);
                    contr++;
                }

                rank = fopen("rank.txt", "w");

                for(int i = 0; i<10; i++){
                        for(int n = 0; n<strlen(string[i]);n++){
                            fputc(string[i][n],rank);
                        }
                        fputc('\n',rank);
                }

            DrawText(string[0],305,130,20, BLACK);
            DrawText(string[1],305,160,20, BLACK);
            DrawText(string[2],305,190,20, BLACK);
            DrawText(string[3] ,305,220,20, BLACK);
            DrawText(string[4] ,305,250,20, BLACK);
            DrawText(string[5] ,305,280,20, BLACK);
            DrawText(string[6] ,305,310,20, BLACK);
            DrawText(string[7] ,305,340,20, BLACK);
            DrawText(string[8] ,305,370,20, BLACK);
            DrawText(string[9] ,305,400,20, BLACK);
        }
        break;
        case END:
        {

            //DrawEx(&credito, "CREDITOS:", (Vector2){ 270, 160 }, (float)font.baseSize*2.3, 5, WHITE);
            DrawTexture(texture2, 0, 0, WHITE);
            DrawText( "-> Lucas Nunes - Joao Pedro Andrade - Rafael Banin",0, 190, 20, WHITE);
            DrawText( "-> Imagens usadas:",0, 220, 20, WHITE);
            DrawText( "- https://br.depositphotos.com/stock-photos/pir%C3%A2mides.html",0, 250, 20, WHITE);
            DrawText( "- https://www.freeimages.com/pt/photo/sphinx-1558589",0, 280, 20, WHITE);
            DrawText( "-https://www.dreamstime.com/great-sphinx-giza-under-stars-public-domain-image-free-95109088",0, 310, 17, WHITE);
            DrawText( "-> Musicas usadas:",0, 340, 24, WHITE);
            DrawText( "- https://pixabay.com/music/search/egypt/",0, 370, 24, WHITE);
        }
        break;
        default:
            break;
        }
        EndDrawing();
        switch(currentScreen)
        {
        case TITLE:

            if (IsKeyPressed(KEY_ENTER))
                currentScreen = NARRATIVA;
            else if(IsKeyPressed(KEY_C))
                currentScreen = CONTROLE;
            break;
        case NARRATIVA:
            if(IsKeyPressed(KEY_S))
                currentScreen = GAMEPLAY;
            break;
        case CONTROLE:
            if(IsKeyPressed(KEY_V))
                currentScreen = TITLE;
            break;

        case RANK:
            if(IsKeyPressed(KEY_ENTER))
                currentScreen = END;
            break;
        case END:
            if(IsKeyPressed(KEY_ENTER))
                currentScreen = TITLE;
            break;
        }

    }
    //----------------------------------------------------------------------------------
    UnloadMusicStream(music);

    CloseAudioDevice();
    CloseWindow();
    return 0;


}
