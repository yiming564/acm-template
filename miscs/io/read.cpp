#include <bits/extc++.h>

template <typename T> inline void Read(T &x) {
    char ch;
    for (ch = getchar(); !isdigit(ch); ch = getchar());
    for (x = 0; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
}
template <typename T, typename ...Tr>
inline void Read(T &x, Tr &...arg) { 
    Read(x), Read(arg...); 
}

int a, b, c;

int main() {
    Read(a, b, c);
    std::println("{} {} {}", a, b, c);
    return 0;
}
