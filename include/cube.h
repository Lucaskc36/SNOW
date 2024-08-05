#ifndef CUBE_H
#define CUBE_H
/*
Let the Cube posses a scalar c with respect to itself.
*/
#include "object.h"

/*
        P2        P1
        *---------* 
        | \ P3    | \ P0
        |   *---------*
        |   |     |   |
      P6*---|-----*P5 | 
          \ |       \ |
          P7*---------*P4
*/

class Cube : public Object{
    Cube();//default Constructor
    Cube(int scale, struct vec3 Centroid);//Parameterized Constructor
    void draw() override;
    void rotate();

    struct vec3{ //vertice point with respect to the origin
        float x,y,z;
    };
    private:
    struct connect{//connections between vertices
        int a,b;
    };
    int scale;
    std::vector<vec3> points;
    std::vector<connect> connections{
        {0,4},//top points to bottom
        {1,5},
        {2,6},
        {3,7},

        {0,1},//top face
        {1,2},
        {2,3},
        {3,0},

        {4,5},//bottom face
        {5,6},
        {6,7},
        {7,4}

    };

};

#endif