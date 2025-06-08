#ifndef VECTOR_H
#define VECTOR_H

#include "Iterator.h"
#include "ReverseIterator.h"

#include <cstdint>
#include <initializer_list>
#include <QDebug>

template<typename T>
class Vector {
    using b_iterator = Iterator<T>;
    using r_iterator = ReverseIterator<T>;
    using c_iterator = Iterator<const T>;
private:
    T* arr = nullptr;
    size_t sz = 0;
    size_t cap = 0;

public:

    Vector() {
        sz = 0;
        cap = 0;
        arr = nullptr;
    }

    Vector(std::initializer_list<T> l)
    {
        reserve(l.size());
        sz = l.size();
        arr = reinterpret_cast<T *>(new int8_t[sz * sizeof(T)]);
        auto listIt = l.begin();
        for (size_t i = 0; i < sz; i++)
        {
            T cur = *listIt;

            new(arr + i) T(cur);
            listIt++;
        }
    }

    Vector(size_t n, const T& value = T())
    {
        reserve(n);
        sz = n;
        for(int i = 0; i < n; i ++)
        {
            try
            {
                new(arr + i) T(value);
            }
            catch (...)
            {
                throw "bad copy constructor";
            }
        }
    }

    ~Vector()
    {
        for(size_t i = 0; i < sz; i++)
        {
            (arr + i)->~T();
        }
        arr = nullptr;
        sz = 0;
        cap = 0;
    }

    T &operator[](size_t n) const
    {
        return arr[n];
    }

    b_iterator begin() {
        if(sz == 0)
        {
            return end();
        }
        return b_iterator(arr);
    }

    b_iterator end() {
        return b_iterator(arr + sz);
    }

    c_iterator cbegin() {
        return c_iterator(arr);
    }

    r_iterator rend() {
        return r_iterator(arr);
    }

    r_iterator rbegin() {
        return r_iterator(arr + sz - 1);
    }

    size_t size() const
    {
        return sz;
    }

    size_t capacity() const
    {
        return cap;
    }

    bool empty(){
        return (sz == 0);
    }

    void reserve(size_t n) {
        if(n <= cap)
            return;
        T *new_arr = reinterpret_cast<T *>(new int8_t[n * sizeof(T)]);
        for (size_t i = 0; i < sz; ++i) {
            try {
                new (new_arr + i) T(std::move(arr[i]));
            }
            catch (...){
                throw "incorrect constructor";
            }
        }
        for(size_t i = 0; i < sz; i++)
            (arr + i)->~T();
        delete[]reinterpret_cast<int8_t *>(arr);
        arr = new_arr;
        cap = n;
    }

    void resize(size_t n, const T& value = T()){
        if(n > cap)
            reserve(n);

        for(size_t i = sz; i < n; i++)
        {
            try {
                new(arr + i) T(value);
            }
            catch (...){
                throw "incorrect constructor";
            }
        }

        for(size_t i = n; i < sz; i++)
        {
            (arr + i)->~T();
        }
        sz = n;
    }

    size_t max_size() const{
        return INTMAX_MAX / sizeof(T);
    }

    void push_back(const T& value)
    {
        if(cap == sz)
            reserve(sz * 2 + 1);
        try {
            new(arr + sz) T(value);
        }
        catch (...){
            throw "incorrect constructor";
        }
        sz++;
    }

    void pop_back()
    {
        if(sz == 0)
            return;
        (arr + sz - 1)->~T();
        sz--;
    }

    void clear()
    {
        resize(0);
    }

    void assign(size_t count, const T& value)
    {
        clear();
        resize(count, value);
    }

    void insert(size_t p, T&& value) {
        if (sz + 1 > cap)
            reserve(sz * 2 + 1);

        if (p > sz) return;

        for (size_t i = sz; i > p; --i) {
            new (arr + i) T(arr[i - 1]);
            (arr + i - 1)->~T();
        }

        new (arr + p) T(value);
        ++sz;

    }

    template<typename ... Args>
    void emplace(size_t pos, Args &&... args)
    {
        T tmp(args...);
        insert(pos, std::move(tmp));
    }

    template<typename ... Args>
    void emplace_back(Args &&... args)
    {
        T tmp(args...);
        push_back(tmp);
    }

    void erase(b_iterator first, b_iterator last) {
        if (first == last) return;

        size_t f = first.base() - arr;
        size_t l = last.base() - arr;

        if (f >= l || l > sz)
            throw "incorrect data for erase";

        for (size_t i = f; i < l; ++i) {
            (arr + i)->~T();
        }

        for (size_t i = l; i < sz; ++i) {
            try {
                new(arr + (i - (l - f))) T(std::move(arr[i]));
                (arr + i)->~T();
            } catch (...) {
                throw "mistake in move constructor";
            }
        }

        sz -= (l - f);
    }

    void erase(b_iterator pos) {
        if(sz == 0)
            return;
        erase(pos, pos + 1);
    }

    void swap(Vector<T>& b)
    {
        auto temp = arr;
        this->arr = b.arr;
        b.arr = temp;
        size_t temp2 = this->sz;
        this->sz = b.sz;
        b.sz = temp2;
        temp2 = this->cap;
        this->cap = b.cap;
        b.cap = temp2;
    }

    T &at(size_t pos)
    {
        if(pos >= sz)
            throw "out of range";
        return arr[pos];
    }

    T &back()
    {
        return arr[sz - 1];
    }

    T& front()
    {
        return arr[0];
    }

    T* data()
    {
        if(sz == 0)
            return nullptr;
        return arr;
    }
};

#endif // VECTOR_H
