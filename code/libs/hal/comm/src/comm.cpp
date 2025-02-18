#include <cstdio>
#include <cstdint>


template<typename T, size_t SizeRx, size_t SizeTx>
class Comm{
    private:
    T data;
    size_t instance;
    std::array<T, SizeRx> bufferRx;
    std::array<T, SizeTx> bufferTx;
    public:
    Comm(){
        init();
    }
    void init();
    void send(T data);
    void receive(T data);
    void deinit();
};


struct s_iic{
    uint8_t instance;
    uint8_t bufferToSend;
    uint8_t bufferToReceive;    
};

Comm iic<s_iic>;
// Comm spi;
// Comm can;
// Comm uart;
// Comm socket;

int main(){

    return 0;
}