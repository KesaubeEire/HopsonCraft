#ifndef ARRAY3D_H_INCLUDED
#define ARRAY3D_H_INCLUDED

#include <array>
#include <cstdlib>

//A 3D array with constant width, height and depth
template<typename T, uint32_t Size>
class Array3D
{
    public:
        T& at(uint32_t xPos, uint32_t yPos, uint32_t zPos)
        {
            return m_array[yPos *
                           m_AREA + zPos *
                           Size + xPos];
        }

        const T& at(uint32_t xPos, uint32_t yPos, uint32_t zPos) const
        {
            return m_array[yPos *
                           m_AREA + zPos *
                           Size + xPos];
        }

        template<typename Vector>
        T& at(const Vector& pos)
        {
            return m_array[pos.y *
                           m_AREA + pos.z *
                           Size + pos.x];
        }

        template<typename Vector>
        const T& at(const Vector& pos) const
        {
            return m_array[pos.y *
                           m_AREA + pos.z *
                           Size + pos.x];
        }

    private:
        std::array<T, Size * Size * Size> m_array;

        const uint32_t m_AREA = Size * Size;
};

#endif // ARRAY3D_H_INCLUDED
