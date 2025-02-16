#include <array>
#include <cstdio>

class Led {
    public:
    int id;
    constexpr Led(int _id = 0) : id(_id) {}
};

template<int N>
constexpr std::array<Led, N> getLeds(){
std::array<Led, N> ret{};
    for (int i = 0; i < N; ++i) {
        ret[i].id = i;
    }
return ret;
}

template <int N>
class Branch{
    public:
    std::array<Led, N> leds;
    constexpr Branch():leds(getLeds<N>()){}
};

constexpr Branch<10> branch;

int main (){
    printf("Led id: %i \n", branch.leds[2].id);
    return 0;
}