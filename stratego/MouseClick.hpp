//
// Created by bekor on 11/22/17.
//

#ifndef STRATEGO_MOUSECLICK_HPP
#define STRATEGO_MOUSECLICK_HPP


#include <memory>

class MouseClick {
public:
    MouseClick(){ x = std::make_shared<int>(0); y = std::make_shared<int>(0);}
//    void setMouseClick(int x, int y) {this->x = x; this->y =y; }
    const std::shared_ptr<int> getClickX(){ return x; }
    const std::shared_ptr<int> getClickY(){ return y; }
private:
    std::shared_ptr<int> x;
    std::shared_ptr<int> y;
};


#endif //STRATEGO_MOUSECLICK_HPP
