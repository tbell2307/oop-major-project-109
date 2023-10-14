#ifndef CROPS_H
#define CROPS_H

class Crop
{
public:
    Crop();
    virtual ~Crop();

    // Virtual functions to allow overriding in derived classes
    virtual void grow();
    virtual void harvest();
};

#endif
