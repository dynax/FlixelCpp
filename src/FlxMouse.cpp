#include "FlxMouse.h"
#include "FlxG.h"


FlxMouse::FlxMouse(int id) {
    lastLeftDown = lastRightDown = lastMiddleDown = false;
    leftDown = middleDown = rightDown = false;
    leftPressed = middlePressed = rightPressed = false;
    leftReleased = middleReleased = rightReleased = false;

    x = endX = 0.f;
    y = endY = 0.f;

    index = id;
}


void FlxMouse::show() {
    FlxG::backend->showMouse(true);
}


void FlxMouse::hide() {
    FlxG::backend->showMouse(false);
}


void FlxMouse::updateState() {

    #ifndef FLX_MOBILE
        leftDown = FlxG::backend->getMouseButtonState(0, index);
        middleDown = FlxG::backend->getMouseButtonState(1, index);
        rightDown = FlxG::backend->getMouseButtonState(2, index);

        // pressed
        if(leftDown && !lastLeftDown) leftPressed = true;
        else leftPressed = false;

        if(middleDown && !lastMiddleDown) middlePressed = true;
        else middlePressed = false;

        if(rightDown && !lastRightDown) rightPressed = true;
        else rightPressed = false;

        // released
        if(!leftDown && lastLeftDown) leftReleased = true;
        else leftReleased = false;

        if(!middleDown && lastMiddleDown) middleReleased = true;
        else middleReleased = false;

        if(!rightDown && lastRightDown) rightReleased = true;
        else rightReleased = false;

        // save last frame buttons state
        lastLeftDown = leftDown;
        lastMiddleDown = middleDown;
        lastRightDown = rightDown;

        // save position
        FlxVector pos = FlxG::backend->getMousePosition(index);
        x = pos.x;
        y = pos.y;
    #endif
}


void FlxMouse::onTouchBegin(int pointer, float X, float Y) {

    FlxMouse *touch = new FlxMouse(pointer);

    touch->x = X;
    touch->y = Y;

    #ifdef FLX_MOBILE
    touch->leftPressed = true;
    touch->leftDown = true;
    #endif

    FlxG::mousesList.push_back(touch);
}

void FlxMouse::onTouchEnd(int pointer, float X, float Y) {

    for(unsigned int i = 0; i < FlxG::mousesList.size(); i++) {
        if(FlxG::mousesList[i]->index == pointer) {
            FlxG::mousesList[i]->leftReleased = true;
            FlxG::mousesList[i]->endX = X;
            FlxG::mousesList[i]->endY = Y;

            return;
        }
    }
}

