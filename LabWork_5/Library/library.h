#pragma once
#include <memory>
#include <iostream>
#include <ostream>

#ifdef _WIN32
#ifdef LIBRARY_EXPORTS
        #define LIBRARY_API __declspec(dllexport)
    #else
        #define LIBRARY_API __declspec(dllimport)
    #endif
#else
#define LIBRARY_API
#endif

class LIBRARY_API String {
private:
    std::unique_ptr<char[]> data;
    size_t length;

public:
    String();
    explicit String(const char* str);
    String(const String& other);
    ~String() = default;

    String& operator=(const String& other);
    String& operator=(const char* str);

    size_t size() const;
    char& operator[](size_t index);

    typedef char* iterator;
    typedef const char* const_iterator;

    iterator begin() const;
    iterator end() const;

    String& operator+=(const String& other);
    String& operator+=(const char* str);

    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;
    bool operator<(const String& other) const;
    bool operator>(const String& other) const;

    void push_back(char c);

    static void* memcpy(void* dest, const void* src, size_t n);
    static void* memmove(void* dest, const void* src, size_t n);
    static char* strcpy(char* dest, const char* src);
    static char* strncpy(char* dest, const char* src, size_t n);
    static char* strcat(char* dest, const char* src);
    static char* strncat(char* dest, const char* src, size_t n);
    static int memcmp(const void* s1, const void* s2, size_t n);
    static int strcmp(const char* s1, const char* s2);
    static int strcoll(const char* s1, const char* s2);
    static int strncmp(const char* s1, const char* s2, size_t n);
    static char* strxfrm(char* dest, const char* src, size_t n);
    static char* strtok(char* str, const char* delim);
    static void* memset(void* s, int c, size_t n);
    static char* strerror(int errnum);
    static size_t strlen(const char* s);
    static char* strchr(const char* str, int c);

    friend LIBRARY_API std::ostream& operator<<(std::ostream& os, const String& str);
};

LIBRARY_API std::ostream& operator<<(std::ostream& os, const String& str);