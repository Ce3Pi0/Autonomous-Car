#ifndef IRSENSORARRAY_HPP
#define IRSENSORARRAY_HPP

class IrSensorArray {
public:
    static constexpr unsigned int _NUM_SENSORS = 6;

    IrSensorArray(const int sensValues[]);
    bool isValid();
    float sumWeights();
    int* getValues();

private:
    
    static constexpr float _DIST = 4.0f / 2; // Distance between middle sensors is 4cm, so from middle to each sensor is 2cm
    static constexpr float _DIST_2 = 3.0f + _DIST; // Distance between adjacent sensors is 3cm
    static constexpr float _DIST_3 = 2.0f + _DIST_2; // Distance between adjacent sensors is 2cm

    const float _WEIGHTS[_NUM_SENSORS / 2] = {-_DIST, -_DIST_2, -_DIST_3};

    int _sensValues[_NUM_SENSORS];

    float getWeight(char, int);
    float sumSide(char, unsigned int, unsigned  int);
};

#endif
