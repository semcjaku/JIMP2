//
// Created by semcjaku on 22.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H


#include <string>

namespace factoryMethod {
    class MyType {
    public:
        MyType() = default;

        std::string SayHello() { return "hello"; };
    };

    template<typename T>
    T Create() {
        T result=T();
        return result;
    }
}


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
