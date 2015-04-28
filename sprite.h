#ifndef SPRITE_H
#define SPRITE_H
#pragma once
#include <GL/glew.h>
#include <cstddef>

//A 2D quad that can be rendered to the screen
class sprite
{
    public:
        sprite();
        virtual ~sprite();

        void init(float x, float y, float width, float height);

        void draw();

    protected:
    private:
        float _x;
        float _y;
        float _width;
        float _height;

        GLuint _vboID;
};



#endif // SPRITE_H
