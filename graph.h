#include <raylib.h>

#pragma once

class Plot {
public:
    Vector2 size;
    Vector2 origin;
    float mapUnit;

    Plot(Vector2 size, Vector2 origin, float mapUnit);

    float getUnitX() const;
    float getUnitY() const;
};

//---------------------------------------------------------------------------------

Vector2 transform(Vector2 i, Vector2 j, Vector2 target);

Vector2 rotateVector(float degree, Vector2 target);

Vector2 toScreenPos(const Plot& plot, Vector2 target);

//---------------------------------------------------------------------------------

void drawVector(const Plot& plot, float thick, Color color, Vector2 i, Vector2 j, 
                                                        Vector2 target);

void drawVector(const Plot& plot, float thick, Color color, Vector2 i, Vector2 j,
                                               Vector2 start, Vector2 end);

//---------------------------------------------------------------------------------

void drawFunction(const Plot& plot, float thick, Color color, Vector2 i, Vector2 j, 
                                                     float (*func)(float x));

//---------------------------------------------------------------------------------

void drawGrid(const Plot& plot, float thick, Color color, Vector2 i, Vector2 j);

void drawAxes(const Plot& plot, float thick, Color color, Vector2 i, Vector2 j);

void drawBorder(const Plot& plot, float thick, Color color, Vector2 i, Vector2 j);
