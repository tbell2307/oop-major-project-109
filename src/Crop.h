#ifndef CROPS_H
#define CROPS_H

#include <string>

class Crop
{
public:
    Crop();
    virtual ~Crop();

    // Virtual functions to allow overriding in derived classes
    virtual void grow();
    virtual void harvest();
    virtual std::string getType() const
    {
        return "Generic Crop";
    }
};

#endif
