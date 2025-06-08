#ifndef REVERSEITERATOR_H
#define REVERSEITERATOR_H

#include <cstddef>

template<typename T>
class ReverseIterator {
private:
    T *it;
public:

    explicit ReverseIterator(T *cur)
    {
        it = cur;
    }

    ~ ReverseIterator() = default;

    bool operator == (const ReverseIterator& it2)
    {
        return it == it2.it;
    }

    bool operator != (ReverseIterator it2)
    {
        return it != it2.it;
    }

    T operator [] (size_t n)
    {
        return it[n];
    }

    const T *base() const
    {
        return it;
    }

    T &operator*() const
    {
        return *it;
    }

    T *operator->() const
    {
        return it;
    }

    ReverseIterator &operator++()
    {
        --it;
        return *this;
    }

    ReverseIterator &operator--()
    {
        ++ it;
        return *this;
    }

    ReverseIterator operator ++(int)
    {
        return ReverseIterator(it--);
    }

    ReverseIterator operator --(int)
    {
        return ReverseIterator(it++);
    }

    ReverseIterator operator +(int n)
    {
        return ReverseIterator(it - n);
    }

    ReverseIterator operator -(int n)
    {
        return ReverseIterator(it + n);
    }

    ReverseIterator &operator +=(int n)
    {
        it -= n;
        return *this;
    }

    ReverseIterator &operator -=(int n)
    {
        it += n;
        return *this;
    }
};


#endif // REVERSEITERATOR_H
