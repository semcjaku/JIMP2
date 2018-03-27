//
// Created by semcjaku on 27.03.18.
//

#include "MemoryChunk.h"

namespace memorychunk
{
    MemoryChunk::MemoryChunk() : array{new int8_t[1024]}{

    }

    MemoryChunk::MemoryChunk(size_t sz)
    {
        array=new int8_t[sz];
    }

    MemoryChunk::~MemoryChunk()
    {
        delete [] array;
    }

    MemoryChunk::MemoryChunk(const MemoryChunk& mc)
    {
        size_t sz = sizeof(mc.array);
        array = new int8_t[sz];
        std::copy(array,array+sz,mc.array);
    }

    MemoryChunk & MemoryChunk::operator=(const MemoryChunk& mc)
    {
        if (this == &mc) {
            return *this;
        }

        delete[] array;

        size_t sz = sizeof(mc.array);
        array = new int8_t[sz];
        std::copy(array,array+sz,mc.array);
    }

    MemoryChunk::MemoryChunk(MemoryChunk &&mc) : array {nullptr}
    {
        std::swap(array, mc.array);
    }

    MemoryChunk & MemoryChunk::operator=(MemoryChunk &&mc)
    {

    }

    int8_t *MemoryChunk::MemoryAt(size_t offset) const
    {

    }

    size_t MemoryChunk::ChunkSize() const
    {

    }
}