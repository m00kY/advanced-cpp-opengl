# pragma once
#ifndef MAINGAME_H
#define MAINGAME_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <GLSLProgram.h>

#include <sprite.h>

enum class GameState{PLAY, EXIT};

class mainGame
{
    public:
        mainGame();
        ~mainGame();
        void run();

    protected:
    private:
        void initSystems();
        void initShaders();
        void processInput();
        void gameLoop();
        void drawGame();

        SDL_Window* _window;
        int _screenWidth;
        int _screenHeight;
        GameState _gameState;

        sprite _sprite;

        GLSLProgram _colorProgram;
};

#endif // MAINGAME_H
