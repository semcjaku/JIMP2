//
// Created by Jakub on 25-03-18.
//

#include "SimpleJson.h"

namespace nets
{
    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const
    {
        if(type==6)
        {
            auto map_check=m_value.find(name);
            if(map_check!=m_value.end())
                return map_check->second;
        }
    }

    std::string JsonValue::ToString() const
    {
        std::string output;
        switch (type)
        {
            case 1:
                output=std::to_string(i_value);
                break;
            case 2:
                output=std::to_string(d_value);
                while(output[output.length()-1]=='0')
                    output.erase(output.length()-1,1);
                if(output[output.length()-1]=='.')
                    output+="0";
                break;
            case 3:
                if(b_value)
                    output="true";
                else
                    output="false";
                break;
            case 4:
                output="\""+s_value+"\"";
                break;
            case 5:
                output="[";
                for(auto n:v_value)
                    output+=n.ToString()+", ";
                output.erase(output.length()-2,2);
                output+="]";
                break;
        }
        return output;
    }
}