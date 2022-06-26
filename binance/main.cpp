#include <binance-sdk.h>
#include <iostream>
#include <sstream>

int main()
{
    binance::Init();
    binance::RestClient cl{};
    auto res = cl.exchange_info();
    // std::cout << res.body.value_or("empty") << std::endl;
    return 0;
}