#pragma once


struct Focusable {
    virtual bool handleInputs(/* need to handle inputs here*/) = 0;

    virtual void focus() = 0;

    virtual void unfocus() = 0;

    virtual void draw() const = 0;

    virtual void update() = 0;
};
