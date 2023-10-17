//ShippingBin.cpp
#include "ShippingBin.hpp"

ShippingBin::ShippingBin() : m_size(0){
    harvestedCrops = new Crop*[m_size];
    for (int i = 0; i < m_size; i++) {
        harvestedCrops[i] = nullptr;
    }
}

ShippingBin::~ShippingBin() {
    for (int i = 0; i < m_size; i++) {
        delete harvestedCrops[i];
    }
    delete[] harvestedCrops;
}

int ShippingBin::getSize(){
    return m_size;
}

void ShippingBin::increaseSize(){
    Crop** newHarvestedCrops = new Crop*[m_size + 1];
    for (int i = 0; i < m_size; i++) {
        newHarvestedCrops[i] = harvestedCrops[i];
    }
    delete[] harvestedCrops;
    harvestedCrops = newHarvestedCrops;
    m_size++;
} 

void ShippingBin::reset(){
    delete[] harvestedCrops;
    m_size = 0;
    harvestedCrops = new Crop*[m_size];
    for (int i = 0; i < m_size; i++) {
        harvestedCrops[i] = nullptr;
    }
}

Crop** ShippingBin::getHarvestedCrops(){
    return harvestedCrops;
}
