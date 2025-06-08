#ifndef ITERATOR_H
#define ITERATOR_H

#include <cstddef>

template<typename T>
class Iterator {
private:
    T *it;
public:

    explicit Iterator(T *cur)
    {
        it = cur;
    }

    ~Iterator() = default;

    bool operator == (const Iterator& it2)
    {
        return it == it2.it;
    }

    bool operator != (Iterator it2)
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

    Iterator &operator++()
    {
        ++it;
        return *this;
    }

    Iterator &operator--()
    {
        --it;
        return *this;
    }

    Iterator operator ++(int)
    {
        return Iterator(it++);
    }

    Iterator operator --(int)
    {
        return Iterator(it--);
    }

    Iterator operator +(int n)
    {
        return Iterator(it + n);
    }

    Iterator operator -(int n)
    {
        return Iterator(it - n);
    }

    Iterator &operator +=(int n)
    {
        it += n;
        return *this;
    }

    Iterator &operator -=(int n)
    {
        it -= n;
        return *this;
    }
};


#endif // ITERATOR_H
