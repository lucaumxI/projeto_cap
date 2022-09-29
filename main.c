#include "raylib.h"
typedef enum GameScreen {TITLE, NARRATIVA, CONTROLE, GAMEPLAY, RANK, END } GameScreen;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 550;
    int i;
    InitWindow(screenWidth, screenHeight, "O Enigma da Esfinge");
    GameScreen currentScreen = TITLE;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
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
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
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
        case GAMEPLAY:
            if(IsKeyPressed(KEY_ENTER))
                currentScreen = RANK;
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

        BeginDrawing();
        ClearBackground(BLACK);
        switch(currentScreen)
        {
        case TITLE:
        {
            // TODO: Draw TITLE screen here!
            DrawTexture(texture1, 0,0,WHITE);
            DrawTextEx( font, "     O Enigma da Esfinge", (Vector2){ 20.0f, 20.0f }, (float)font.baseSize, 0.0f, WHITE);
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
            DrawTextEx(hist, "Jose Mateus, um jovem, porem, eximio explorador nascido no interior da Bahia, muito adepto aos",(Vector2){ 50.0f, 20.0f }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "ideiais socialistas, estava trabalhando no Egito em busca de indicios para defender sua tese de que o",(Vector2){14.5f, 45.0f }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "socialismo era idealizado desde os tempos antigos.",(Vector2){14.5f, 70.0f }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "Infelizmente, sua exploracao nao estava o levando a lugar nenhum, entao ele decidiu 'turistar' um",(Vector2){50.0f, 95.0f }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "pouco para espairecer a mente. Durante seu passeio, andando a esmo, ele ve algo brilhando perdido",(Vector2){14.5f, 120.0f }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "em meio ao deserto escaldante. Ao se aproximar do estranho objeto brilhante ele se depara com",(Vector2){14.5f, 145.0f }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "uma estranha bussola que nao apontava para o norte. Ele decide entao seguir o caminho indicado pela",(Vector2){14.5f, 170.0f }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "bussola que o leva exatamente para o centro entre as duas patas da Esfinge de Gize.",(Vector2){14.5f, 195.0f }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "La ele vislumbra um orificio com o diametro exato da bussola e em um momento de epifania, quase ",(Vector2){50.0f, 220.0f }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "como se os deuses o guiassem para isso, ele decide inserir a bussola no buraco, entao, a Esfinge ",(Vector2){14.5f, 245.0f }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "de forma retumbante e ecoante bradou: 'ser insignificante, eu tenho ciencia do porque voce me despertou,",(Vector2){14.5f, 270.0f }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "porem eu so irei lhe dar a direcao para encontrar o que voce procura caso voce consiga responder ",(Vector2){14.5f, 295.0f }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "as 10 perguntas aritmeticas que tenho preparado, caso voce erre, isso mostrara que voce nao tem ",(Vector2){14.5f, 320.0f }, (float)hist.baseSize, 0.0f, WHITE);
            DrawTextEx(hist, "determinacao o suficiente e eu terei que lhe engolir!!!'.",(Vector2){4.5f, 345.0f }, (float)hist.baseSize, 0.0f, WHITE);
            DrawText("Clique S para prosseguir ao jogo", 75,400,40,WHITE);
            }
            break;
        case CONTROLE:
            {
              DrawText("Como jogar", 10,10,30,WHITE);
              DrawText("Use as teclas numericas para responder as perguntas realizadas", 20,150,20,WHITE);
              DrawText("Use a tecla 'ENTER' para confirmar sua resposta", 20,200,20,WHITE);
              DrawText("Pressione 'V' para voltar a tela inicial", 20,400,20,WHITE);
            } break;
        case GAMEPLAY:
        {
            // TODO: Draw GAMEPLAY screen here!
            DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
            DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
            DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

        }
        break;
        case RANK:
            {
                    DrawText("mama",0,0,14,WHITE);

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

    }
    //----------------------------------------------------------------------------------
    UnloadTexture(texture2);
     UnloadFont(fonte);
    UnloadImage(credito);
    CloseWindow();
    return 0;


}

