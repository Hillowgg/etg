#include "AutoAnimTexture.h"



void AutoAnimTexture::draw(const RRectangle &outShape, const float &rotation) const {
    TextureBase::draw(outShape, rotation);
}



void AutoAnimTexture::update() {
    double t = GetTime();

    if ( t > lastChange + delta) {
        this->animNext();
        lastChange = t;
    }
}
