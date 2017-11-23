//
// Created by bekor on 11/22/17.
//

#ifndef STRATEGO_MOUSECLICK_HPP
#define STRATEGO_MOUSECLICK_HPP


#include <memory>

class MouseClick {
public:
    MouseClick(){
        x.reset(new int(0));
        y.reset(new int(0));
    }
//    void setMouseClick(int x, int y) {this->x = x; this->y =y; }
    std::shared_ptr<int> clickX(){ return x; }
    std::shared_ptr<int> clickY(){ return y; }
    int getClickX(){ return *x; }
    int getClickY(){ return *y; }
private:
    std::shared_ptr<int> x;
    std::shared_ptr<int> y;
};


#endif //STRATEGO_MOUSECLICK_HPP
