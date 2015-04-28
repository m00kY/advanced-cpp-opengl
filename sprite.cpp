#include "sprite.h"
#include "vertex.h"

sprite::sprite(){
    //Always initialize your buffer IDs to 0
    _vboID = 0;
}

sprite::~sprite(){
    //Always remember to delete your buffers when
    //you are done!
    if (_vboID != 0){
        glDeleteBuffers(1, &_vboID);
    }
}

//Initializes the sprite VBO. x, y, width, and height are
//in the normalized device coordinate space. so, [-1, 1]
void sprite::init(float x, float y, float width, float height){
    //Set up our private vars
    _x = x;
    _y = y;
    _width = width;
    _height = height;

    //Generate the buffer if it hasn't already been generated
    if(_vboID == 0){
        glGenBuffers(1, &_vboID);
    }

    //This array will hold our vertex data.
    //We need 6 vertices, and each vertex has 2
    //floats for X and Y
    Vertex vertexData[6];

    //First triangle
    vertexData[0].position.x = x + width;
    vertexData[0].position.y = y + width;

    vertexData[1].position.x = x;
    vertexData[1].position.y = y + height;

    vertexData[2].position.x = x;
    vertexData[2].position.y = y;

    //Second triangle
    vertexData[3].position.x = x;
    vertexData[3].position.y = y;

    vertexData[4].position.x = x + width;
    vertexData[4].position.y = y;

    vertexData[5].position.x = x + width;
    vertexData[5].position.y = y + height;

    // set all colors to magenta
    for (int i = 0; i< 6; i++){
        vertexData[i].color.r = 255;
        vertexData[i].color.g = 0;
        vertexData[i].color.b = 255;
        vertexData[i].color.a = 255;
    }
    //Tell opengl to bind our vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    //Tell opengl to bind our vertex buffer object
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    //Unbind the buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

//Draws the sprite to the screen
void sprite::draw(){
    // bind the VBO
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    // enable the vertex position array
    glEnableVertexAttribArray(0);
    // this is the position attribute pointer
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    // enable the vertex color attribute array
    glEnableVertexAttribArray(1);
    // vertex color array
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    // draw 6 vertices to the screen
    glDrawArrays(GL_TRIANGLES, 0, 6);
    // disable the position attribute pointer
    glDisableVertexAttribArray(0);
    // disable the color attribute pointer
    glDisableVertexAttribArray(1);
    // unbind the VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
