#include <bits/extc++.h>

template <typename T> inline void Read(T &x) {
    char ch; bool flag = false;
    for (ch = getchar(); !isdigit(ch); ch = getchar()) flag = ch == '-';
    for (x = 0; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    if (flag) x = -x;
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
