//
// Created by semcjaku on 13.03.18.
//

#include "TinyUrl.h"

namespace tinyurl
{
    std::unique_ptr<TinyUrlCodec> Init()
    {
        std::unique_ptr<TinyUrlCodec> codec = std::make_unique<TinyUrlCodec>();
        for(int i=0;i<6;i++)
            (codec->CurrentHash)[i]='0';
        codec->ShortUrls.clear();
        codec->LongUrls.clear();
        return std::move(codec);
    }

    void NextHash(std::array<char, 6> *state)
    {
        for(int i=5;i>=0;i--)
        {
            if ((*state)[i]=='9')
            {
                (*state)[i] = 'A';
                break;
            }
            else if((*state)[i]=='Z')
            {
                (*state)[i] = 'a';
                break;
            }
            else if((*state)[i]=='z')
            {
                (*state)[i] = '0';
                continue;
            }
            else
            {
                (*state)[i]++;
                break;
            }
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<tinyurl::TinyUrlCodec> *codec)
    {
        std::string Hash;
        for(int i=0;i<6;i++)
            Hash.push_back((*codec)->CurrentHash[i]);
        (*codec)->LongUrls.push_back(url);
        (*codec)->ShortUrls.push_back(Hash);
        NextHash(&((*codec)->CurrentHash));
        return Hash;
    }

    std::string Decode(const std::unique_ptr<tinyurl::TinyUrlCodec> &codec, const std::string &hash)
    {
        int index;
        std::string Url;
        std::vector<std::string>::iterator iter;
        iter = std::find(codec->ShortUrls.begin(), codec->ShortUrls.end(), hash);
        if(iter!=codec->ShortUrls.end())
        {
            index=iter-codec->ShortUrls.begin();
            Url=codec->LongUrls[index];
        }
        return Url;
    }
}