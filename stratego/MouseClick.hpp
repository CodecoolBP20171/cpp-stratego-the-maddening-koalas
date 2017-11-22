//
// Created by bekor on 11/22/17.
//

#ifndef STRATEGO_MOUSECLICK_HPP
#define STRATEGO_MOUSECLICK_HPP


#include <memory>

class MouseClick {
public:
    MouseClick(){ x = 0; y = 0;}
//    void setMouseClick(int x, int y) {this->x = x; this->y =y; }
    int* clickX(){ return &x; }
    int* clickY(){ return &y; }
    int getClickX(){ return x; }
    int getClickY(){ return y; }
private:
    int x;
    int y;
};


#endif //STRATEGO_MOUSECLICK_HPP
