#include <iostream>
#include <SDL2/SDL.h>
#include <mainGame.h>
#include <GL/glew.h>

int main(int argc, char** argv){
    mainGame MainGame;
    MainGame.run();
    return 0;

}
