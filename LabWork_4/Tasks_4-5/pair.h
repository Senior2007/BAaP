#ifndef PAIR_H
#define PAIR_H

template<typename T1, typename T2>
struct pair {
    T1 first;
    T2 second;

    pair() = default;
    pair(const pair& other) : first(other.first), second(other.second) {}
    pair(T1 a, T2 b) {
        this->first = a;
        this->second = b;
    }
    void operator=(pair const &pair_) {
        first = pair_.first;
        second = pair_.second;
    }
};

#endif // PAIR_H
