//
// Created by semcjaku on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <vector>
#include <experimental/optional>
#include <iostream>
#include <functional>

namespace academia
{
    class Serializable;

    class Serializer
    {
    public:
        explicit Serializer(std::ostream *out);

        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value)=0;
        virtual void SerializableField(const std::string &field_name, const Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;

    protected:
        std::ostream *out_;
    };

    class JsonSerializer : public Serializer
    {
    public:
        explicit JsonSerializer(std::ostream *out);

        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value)override;
        void StringField(const std::string &field_name, const std::string &value)override;
        void BooleanField(const std::string &field_name, bool value)override;
        void SerializableField(const std::string &field_name, const Serializable &value)override;
        void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value)override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name)override;
        void CheckIfFirst();

    private:
        bool first_=true;
    };

    class XmlSerializer : public Serializer
    {
    public:
        explicit XmlSerializer(std::ostream *out);

        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value)override;
        void StringField(const std::string &field_name, const std::string &value)override;
        void BooleanField(const std::string &field_name, bool value)override;
        void SerializableField(const std::string &field_name, const Serializable &value)override;
        void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value)override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name)override;
    };

//----------------------------------------------------------------------------------------------------------------------

    class Serializable
    {
    public:
        virtual void Serialize(Serializer *s)=0;
        virtual void Serialize(Serializer *s) const =0;
    };

    class Room : public Serializable
    {
    public:
        enum class Type{LECTURE_HALL, COMPUTER_LAB, CLASSROOM};
        std::string Type_to_string(Type t) const;

        Room(int nr, std::string name,Type type) : nr_(nr), name_(name), type_(type) {}

        void Serialize(Serializer *s) override;
        void Serialize(Serializer *s) const override;
    private:
        int nr_;
        std::string name_;
        Type type_;
    };

    class Building : public Serializable
    {
    public:
        Building(int nr, std::string name, std::initializer_list<std::reference_wrapper<const academia::Serializable>> roomlist) : nr_(nr), name_(name), rooms_(roomlist) {}

        int Id() const;

        void Serialize(Serializer *s) override;
        void Serialize(Serializer *s) const override;
    private:
        int nr_;
        std::string name_;
        const std::vector<std::reference_wrapper<const academia::Serializable>> rooms_;
    };

    class BuildingRepository : public Serializable
    {
    public:
        BuildingRepository(std::initializer_list<Building> buildlist) : buildings_(buildlist) {}

        const std::experimental::optional<Building>& operator[](int idx) const;

        void Add(Building b);
        void StoreAll(Serializer *s);

        void Serialize(Serializer *s) override;
    private:
        std::vector<Building> buildings_;
    };
}


#endif //JIMP_EXERCISES_SERIALIZATION_H
