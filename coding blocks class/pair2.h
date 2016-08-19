#ifndef PAIR2_H
#define PAIR2_H 1
template <typename T1,typename T2>
class pair2
{
public:
    T1 height;
    T2 diameter;
    pair1(T1 height,T2 diameter)
    {
        this->height=height;
        this->diameter=diameter;
    }
};
#endif
