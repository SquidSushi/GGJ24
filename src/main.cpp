#include <cstdlib>

#include "raylib.h"

#include "config.h"
#include "Player.h"
#include "enumsAndConstants.h"
#include "WalkingEnemy.h"
#include "Map.h"
#include "JumpingEnemy.h"

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);

    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    int frameCount = 0;

    WalkingEnemy karen;
    JumpingEnemy dog;
    Player cattington({0, 0}, {0, 0, 32, 32});
    RenderTexture gameCanvas = LoadRenderTexture(16 * 18, 16 * 13);
    bool f3mode = false;
    Map theGameMap;
    theGameMap.init();
    theGameMap.entities.push_back(&cattington);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (IsKeyPressed(KEY_F3)) {
            f3mode = !f3mode;
        }

        cattington.PlayerMovement();

        theGameMap.update();
        cattington.update(frameCount);
        karen.update(frameCount);
        dog.update(frameCount);


        BeginDrawing();
        ClearBackground(DARKGRAY);
        BeginTextureMode(gameCanvas);
        {
            ClearBackground(BLACK);
            //DrawRectangleGradientV(0, 0, 16 * 18, 16 * 13, GetColor(0xa355dfff), GetColor(0x460074ff));
            //DrawText("Hello, world!", 10, 10, 30, LIGHTGRAY);
            theGameMap.drawMap();
            //cattington.animation(frameCount);
            karen.animation(frameCount);
            dog.animation(frameCount);
            if (f3mode) {
                //draw a grid
                for (int x = 0; x < 16 * 18; x += 16) {
                    DrawLine(x, 0, x, 16 * 13, ColorAlpha(WHITE,0.25));
                }
                for (int y = 0; y < 16 * 13; y += 16) {
                    DrawLine(0, y, 16 * 18, y, ColorAlpha(WHITE,0.25));
                }
                theGameMap.drawCollisions();
            }
        }
        EndTextureMode();
        int scale = GetScreenHeight() / gameCanvas.texture.height;
        DrawTexturePro(
                gameCanvas.texture,
                {0,0,float(gameCanvas.texture.width),float(-gameCanvas.texture.height)},
                {float(GetScreenWidth()/2 - gameCanvas.texture.width*scale/2), float(GetScreenHeight()/2 - gameCanvas.texture.height*scale/2), float(gameCanvas.texture.width*scale), float(gameCanvas.texture.height*scale)},

                {0,0},0,WHITE);
        if (f3mode) {
            DrawFPS(10, 10);
            //Draw cattingtons x and y position in integers
            DrawText(TextFormat("x: %i", (int) cattington.position.x), 10, 30, 10, LIGHTGRAY);
            DrawText(TextFormat("y: %i", (int) cattington.position.y), 10, 40, 10, LIGHTGRAY);
        }

        EndDrawing();
        frameCount++;
    } // Main game loop end

    UnloadTexture(cattington.entityTexture);

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
