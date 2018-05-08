//
// Created by semcjaku on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>

namespace academia
{
    class Serializable;

    class Serializer
    {

    };

    class JsonSerializer : public Serializer
    {

    };

    class XmlSerializer : public Serializer
    {

    };

//----------------------------------------------------------------------------------------------------------------------

    class Serializable
    {
        virtual void Serialize(Serializer *s)=0;
    };

    class Room : public Serializable
    {
    public:
        enum class Type{LECTURE_HALL, COMPUTER_LAB};

        Room(int nr, std::string &name,Type type) : nr_(nr), name_(name), type_(type) {}

        void Serialize(Serializer *s) override;
    private:
        int nr_;
        std::string name_;
        Type type_;
    };

    class Building : public Serializable
    {

    };

    class BuildingRepository : public Serializable
    {

    };
}


#endif //JIMP_EXERCISES_SERIALIZATION_H
