#include <iostream>
#include "library.h"

int main() {
    String s("Labaaaaaa 5555555");
    String s2 = s;
    String s3(" 10 10 10 10 10");
    String s4;

    s2[2] = 'G';

    std::cout << s  << '\n' << s2 << '\n';

    std::cout << (s < s2) << '\n';
    std::cout << (s == s2) << '\n';
    std::cout << (s != s2) << '\n';

    s += " XDXDXDXD";
    std::cout << s << '\n';
    s2 += s3;
    std::cout << s2 << '\n';

    s4 = "     ";
    String::memcpy(s4.begin(), s2.begin(), 5);
    std::cout << s4 << '\n';

    String::strcpy(s4.begin(), s3.begin());
    std::cout << s4 << '\n';

    String::strncpy(s4.begin(), s2.begin(), 3);
    std::cout << s4 << "\n\n";

    std::cout << "s : " << s << '\n';
    std::cout << "s2 : " << s2 << '\n';
    String::strncat(s.begin(), s2.begin(), 4);
    std::cout << s << "\n\n";

    std::cout << String::strchr(s.begin(), 'b') - s.begin() << '\n';
    s = "apple Mac";
    String s5("Mac");
    String::strtok(s.begin(), s5.begin());

    std::cout << s;

    return 0;
}