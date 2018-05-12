//
// Created by semcjaku on 08.05.18.
//

#include <stdexcept>
#include "Serialization.h"

namespace academia
{
    Serializer::Serializer(std::ostream *out)
    {
        out_=out;
    }

    //---------------------------------------------------------------------

    XmlSerializer::XmlSerializer(std::ostream *out) : Serializer(out) {}

    void XmlSerializer::IntegerField(const std::string &field_name, int value)
    {
        *out_<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value)
    {
        *out_<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value)
    {
        *out_<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value)
    {
        *out_<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const Serializable &value)
    {
        value.Serialize(this);
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const Serializable>> &value)
    {
        *out_<<"<"<<field_name<<">";
        for(auto n:value)
            SerializableField(field_name,n.get());
        *out_<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::Header(const std::string &object_name)
    {
        *out_<<"<"<<object_name<<">";
    }

    void XmlSerializer::Footer(const std::string &object_name)
    {
        *out_<<"<\\"<<object_name<<">";
    }

    //---------------------------------------------------------------------

    JsonSerializer::JsonSerializer(std::ostream *out) : Serializer(out) {}

    void JsonSerializer::IntegerField(const std::string &field_name, int value)
    {
        CheckIfFirst();
        *out_<<"\""<<field_name<<"\": "<<value;
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value)
    {
        CheckIfFirst();
        *out_<<"\""<<field_name<<"\": "<<value;
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value)
    {
        CheckIfFirst();
        *out_<<"\""<<field_name<<"\": \""<<value<<"\"";
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value)
    {
        CheckIfFirst();
        *out_<<"\""<<field_name<<"\": "<<value;
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const Serializable &value)
    {
        CheckIfFirst();
        value.Serialize(this);
    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const Serializable>> &value)
    {
        CheckIfFirst();
        *(out_)<<"\""<<field_name<<"\": [";
        for(int i = 0; i<value.size();i++)
        {
            first_ = true;
            if(i==0)
            {

                value[0].get().Serialize(this);
            }
            else {
                *out_<<", ";
                value[i].get().Serialize(this);
            }
        }

        *(out_)<<"]";
    }

    void JsonSerializer::Header(const std::string &object_name)
    {
        *out_<<"{";
    }

    void JsonSerializer::Footer(const std::string &object_name)
    {
        *out_<<"}";
    }

    void JsonSerializer::CheckIfFirst()
    {
        if(first_)
            first_=false;
        else
            *out_<<", ";
    }

    //-------------------------------------------------------------------------------------------------------------------

    std::string Room::Type_to_string(Room::Type t) const
    {
        switch (t)
        {
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::CLASSROOM:
                return "CLASSROOM";
        }
    }

    void Room::Serialize(Serializer *s)
    {
        s->Header("room");
        s->IntegerField("id",nr_);
        s->StringField("name",name_);
        s->StringField("type",Type_to_string(type_));
        s->Footer("room");

    }

    void Room::Serialize(Serializer *s) const
    {
        s->Header("room");
        s->IntegerField("id",nr_);
        s->StringField("name",name_);
        s->StringField("type",Type_to_string(type_));
        s->Footer("room");
    }

    //----------------------------------------------------

    int Building::Id() const
    {
        return nr_;
    }

    void Building::Serialize(Serializer *s)
    {
        s->Header("building");
        s->IntegerField("id",nr_);
        s->StringField("name",name_);
        s->ArrayField("rooms",rooms_);
        s->Footer("building");
    }

    void Building::Serialize(Serializer *s) const
    {
        s->Header("building");
        s->IntegerField("id",nr_);
        s->StringField("name",name_);
        s->ArrayField("rooms",rooms_);
        s->Footer("building");
    }

    //----------------------------------------------------------------------------------------

    const std::experimental::optional<Building> &BuildingRepository::operator[](int idx) const
    {
        for(auto &n:buildings_)
            if(n.Id()==idx)
                return n;
    }

    void BuildingRepository::Add(Building b)
    {
        buildings_.emplace_back(b);
    }

}