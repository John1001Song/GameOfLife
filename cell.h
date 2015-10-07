//
//  cell.h
//  Game of Life
//
//  Created by Jinyue Song on 2015-10-06.
//  Copyright © 2015 Jinyue Song. All rights reserved.
//

#ifndef cell
#define cell

#include <stdio.h>

class Cell {
public:
    //int x, y;
    bool cellState;
    Cell();
    //Cell(int x, int y, bool cellState);
    Cell(bool cellState);
};

#endif /* cell_h */

