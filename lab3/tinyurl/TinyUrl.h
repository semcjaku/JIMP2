//
// Created by semcjaku on 13.03.18.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <utility>
#include <string>
#include <array>
#include <memory>
#include <vector>
#include <algorithm>

namespace tinyurl
{
    struct TinyUrlCodec
    {
        std::vector<std::string> LongUrls;
        std::vector<std::string> ShortUrls;
        std::array<char, 6> CurrentHash;

    };
    std::unique_ptr<TinyUrlCodec> Init();
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}

#endif //JIMP_EXERCISES_TINYURL_H
