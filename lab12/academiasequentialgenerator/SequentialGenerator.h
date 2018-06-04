//
// Created by Kuba on 04-06-18.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template <typename T1, typename T2>
class SequentialIdGenerator
{
public:
    SequentialIdGenerator()
    {
        curid=T2();
    }
    explicit SequentialIdGenerator(T2 current) : curid(current) {}
    T1 NextValue()
    {
        T1 object(curid);
        ++curid;
        return object;
    }
private:
    T2 curid;
};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
