//
// Created by semcjaku on 27.03.18.
//

#include "MemoryChunk.h"

namespace memorychunk
{
    MemoryChunk::MemoryChunk() : array{new int8_t[1024]}{
        elements=1024;
    }

    MemoryChunk::MemoryChunk(size_t sz)
    {
        array=new int8_t[sz];
        elements=sz;
    }

    MemoryChunk::~MemoryChunk()
    {
        delete [] array;
        elements=0;
    }

    MemoryChunk::MemoryChunk(const MemoryChunk& mc)
    {
        array = new int8_t[mc.elements];
        elements=mc.elements;
        std::copy(mc.array,mc.array+mc.elements,array);
    }

    MemoryChunk & MemoryChunk::operator=(const MemoryChunk& mc)
    {
        if (this == &mc) {
            return *this;
        }

        delete[] array;
        elements=0;

        array = new int8_t[mc.elements];
        elements=mc.elements;
        std::copy(mc.array,mc.array+mc.elements,array);
    }

    MemoryChunk::MemoryChunk(MemoryChunk &&mc)
    {
        array=mc.array;
        elements=mc.elements;
        mc.array=nullptr;
        mc.elements=0;
    }

    MemoryChunk & MemoryChunk::operator=(MemoryChunk &&mc)
    {
        if (this == &mc) {
            return mc;
        }

        delete[] array;
        elements=0;

        array=mc.array;
        elements=mc.elements;
        mc.array=nullptr;
        mc.elements=0;
    }

    int8_t *MemoryChunk::MemoryAt(size_t offset) const
    {
        return &array[offset];
    }

    size_t MemoryChunk::ChunkSize() const
    {
        return elements;
    }
}