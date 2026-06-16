#include <raylib.h>
#include <math.h>

class Plot {
public:
    Vector2 size;
    Vector2 origin;
    float mapUnit;

    Plot(Vector2 size, Vector2 origin, float mapUnit);

    float getUnitX() const;
    float getUnitY() const;
};

Plot::Plot(Vector2 size, Vector2 origin, float mapUnit) :
    size(size), origin(origin), mapUnit(mapUnit) {}

float Plot::getUnitX() const {
    return size.x / mapUnit / 2;
}

float Plot::getUnitY() const {
    return size.y / mapUnit / 2;
}

//---------------------------------------------------------------------------------

Vector2 transform(Vector2 i, Vector2 j, Vector2 target) {
    return {
        target.x * i.x + target.y * j.x,
        target.x * i.y + target.y * j.y
    };
}

Vector2 rotateVector(float degree, Vector2 target) {
    float rad = degree * DEG2RAD;
    return transform({cos(rad), sin(rad)}, {-sin(rad), cos(rad)}, target);
}

Vector2 toScreenPos(const Plot& plot, Vector2 target) {
    return {
         target.x * plot.mapUnit + plot.origin.x,
        -target.y * plot.mapUnit + plot.origin.y
    };
}

//---------------------------------------------------------------------------------

void drawVector(const Plot& plot, float thick, Color color, Vector2 i, Vector2 j, 
                                                           Vector2 target) {
    DrawLineEx(plot.origin, toScreenPos(plot, transform(i, j, target)), thick, color);
}

void drawVector(const Plot& plot, float thick, Color color, Vector2 i, Vector2 j,
                                               Vector2 start, Vector2 end) {
     DrawLineEx(toScreenPos(plot, transform(i, j, start)),
                toScreenPos(plot, transform(i, j, end)), thick, color);
}

//---------------------------------------------------------------------------------

void drawFunction(const Plot& plot, float thick, Color color, Vector2 i, Vector2 j, 
                                                     float (*func)(float x)) {
    float unitsX = plot.getUnitX();
    float unitsY = plot.getUnitY();

    Vector2 prevPoint;
    bool isFirstPoint = true;

    for (float x = -unitsX; x <= unitsX; x += 0.01) {
        float y = func(x);

        if (y > unitsY || y < -unitsY) {
            isFirstPoint = true;
            continue;
        }

        Vector2 currPoint = {x, y};

        if (isFirstPoint) {
            isFirstPoint = false;
            prevPoint = currPoint;
            continue;
        }

        drawVector(plot, thick, color, i, j, prevPoint, currPoint);
        prevPoint = currPoint;
    }
}

//---------------------------------------------------------------------------------

void drawGrid(const Plot& plot, float thick, Color color, Vector2 i, Vector2 j) {     
    float unitsX = plot.getUnitX();
    float unitsY = plot.getUnitY();

    for (float y = 0; y <= unitsY; y++)
        drawVector(plot, thick, color, i, j, {-unitsX, y}, {unitsX, y});
    for (float y = 0; y >= -unitsY; y--)
        drawVector(plot, thick, color, i, j, {-unitsX, y}, {unitsX, y});

    for (float x = 0; x <= unitsX; x++)
        drawVector(plot, thick, color, i, j, {x, -unitsY}, {x, unitsY});
    for (float x = 0; x >= -unitsX; x--)
        drawVector(plot, thick, color, i, j, {x, -unitsY}, {x, unitsY});
}

void drawAxes(const Plot& plot, float thick, Color color, Vector2 i, Vector2 j) {
    float unitsX = plot.getUnitX();
    float unitsY = plot.getUnitY();

    drawVector(plot, thick, color, i, j, {-unitsX, 0}, {unitsX, 0});
    drawVector(plot, thick, color, i, j, {0, -unitsY}, {0, unitsY});
}

void drawBorder(const Plot& plot, float thick, Color color, Vector2 i, Vector2 j) {
    float unitsX = plot.getUnitX();
    float unitsY = plot.getUnitY();

    drawVector(plot, thick, color, i, j, {-unitsX, unitsY}, {unitsX, unitsY});
    drawVector(plot, thick, color, i, j, {unitsX, unitsY}, {unitsX, -unitsY});
    drawVector(plot, thick, color, i, j, {unitsX, -unitsY}, {-unitsX, -unitsY});
    drawVector(plot, thick, color, i, j, {-unitsX, -unitsY}, {-unitsX, unitsY});
}
