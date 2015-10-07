//
//  main.cpp
//  Game of Life
//
//  Created by Jinyue Song on 2015-10-06.
//  Copyright © 2015 Jinyue Song. All rights reserved.
//

/*

 The universe of the Game of Life is an infinite two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead. Every cell interacts with its eight neighbours, which are the cells that are directly horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:
    
    1. Any live cell with fewer than two live neighbours dies, as if caused by under- population.
    2. Any live cell with more than three live neighbours dies, as if by overcrowding.
    3. Any live cell with two or three live neighbours lives on to the next generation.
    4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
 
 The initial pattern constitutes the seed of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed—births and deaths occur simultaneously, and the discrete moment at which this happens is sometimes called a tick (in other words, each generation is a pure function of the preceding one). The rules continue to be applied repeatedly to create further generations.

*/

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>

int window_size = 200;

int cellStateStack[200][200];

void display(){
    //glClear(GL_COLOR_BUFFER_BIT);
    //glClearColor(1, 1, 1, 1);
    glFlush();
}

void mouse(int btn, int state, int x, int y){
    y = window_size - y;
    
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        cellStateStack[x][y] = 1;
        glBegin(GL_POINTS);
        glColor3f(.0f, .0f, 1.0f);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        printf("%d,%d\n", x, y);
    }
}

void motion(int x, int y){
    y = window_size - y;
    
    cellStateStack[x][y] = 1;
    glBegin(GL_POINT);
    glColor3i(1, 0, 0);
    glVertex2i(x, y);
    glEnd();
    glFlush();
    
    printf("%d, %d\n", x, y);
};

int count_neighbor(int x, int y){
    int count;
    if (x == 0) {
        if (y == 0) {
            count = cellStateStack[x+1][y] + cellStateStack[x][y+1] + cellStateStack[x+1][y+1];
        } else {
            count = cellStateStack[x][y-1] + cellStateStack[x+1][y-1] +
                    cellStateStack[x+1][y] +
                    cellStateStack[x][y+1] + cellStateStack[x+1][y+1];
        }
    } else {
        if (y == 0) {
            count = cellStateStack[x-1][y] + cellStateStack[x+1][y] +
                    cellStateStack[x-1][y+1] + cellStateStack[x][y+1] + cellStateStack[x+1][y+1];
        } else {
            count = cellStateStack[x-1][y-1] + cellStateStack[x][y-1] + cellStateStack[x+1][y-1] +
                    cellStateStack[x-1][y]                            + cellStateStack[x+1][y]   +
                    cellStateStack[x-1][y+1] + cellStateStack[x][y+1] + cellStateStack[x+1][y+1];
        }
    }
    return count;
}

void idle(){
    glutPostRedisplay();
}


void light(int x, int y){
    y = window_size - y;
    glColor3i(1, 0, 0);
    if (cellStateStack[x][y] == 1) {
        glBegin(GL_POINT);
        glVertex2i(x, y);
        glEnd();
        glFlush();
    }
}

void live_or_dead(int x, int y){
    int thisCount = count_neighbor(x, y);
    if (thisCount < 2 || thisCount > 3) {
        cellStateStack[x][y] = 0;
        glBegin(GL_POINT);
        glColor3i(1, 1, 1);
        glVertex2i(x, y);
        glEnd();
        glFlush();
    } else {
        cellStateStack[x][y] = 1;
        glBegin(GL_POINT);
        glColor3i(1, 0, 0);
        glVertex2i(x, y);
        glEnd();
        glFlush();
    }
    printf("%d\n", thisCount);
}

void initCellStack(){
    for (int x=0; x < window_size; x++) {
        for (int y; y < window_size; y++) {
            cellStateStack[x][y] = 1;
        }
    }
}

void timeRedisplay(int value){
    glutTimerFunc(30, timeRedisplay, 0);
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(window_size, window_size);
    glutCreateWindow("Game of Life");
    
    
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
<<<<<<< Updated upstream
    glutIdleFunc(idle);
    gluOrtho2D(0, window_size, 0, window_size);
     timeRedisplay(0);
=======
    //glutIdleFunc(idle);
>>>>>>> Stashed changes
    
    glPointSize(3);
    
    initCellStack();
    
    for (int x; x < window_size; x++) {
        for (int y; y < window_size; y++) {
            light(x, y);
            live_or_dead(x, y);
        }
    }
    
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3i(1, 0, 0);
    gluOrtho2D(0, window_size, 0, window_size);
    
    glutMainLoop();
    
    return 0;
}
