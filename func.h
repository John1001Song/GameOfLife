//
//  func.h
//  
//
//  Created by Jinyue Song on 2015-10-06.
//
//

#ifndef func_h
#define func_h

#include <stack>
#include <stdio.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "cell.h"

extern int window_size;

int cellStack[100][100];



class CellFunc{
public:
    int count_nebor(Cell c){
        int count;
        
        return 0;
    }
    
    void light_the_cell(Cell c){
        if (c.cellState == 1){
            glBegin(GL_POINT);
            glColor3i(1, 0, 0);
            glVertex2i(c.x, c.y);
            glEnd();
            glFlush();
        }
    }
    
    
};


#endif /* func_h */
