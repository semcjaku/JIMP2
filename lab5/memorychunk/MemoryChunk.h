//
// Created by semcjaku on 27.03.18.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <cstdint>
#include <algorithm>

namespace memorychunk
{
    class MemoryChunk {
    public:
        MemoryChunk();
        MemoryChunk(size_t sz);
        ~MemoryChunk();

        MemoryChunk(const MemoryChunk& mc);
        MemoryChunk & operator=(const MemoryChunk& mc);

        MemoryChunk(MemoryChunk &&mc) : array {nullptr};
        MemoryChunk & operator=(MemoryChunk &&mc);

        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;


    private:
        int8_t *array;
    };
}


#endif //JIMP_EXERCISES_MEMORYCHUNK_H
