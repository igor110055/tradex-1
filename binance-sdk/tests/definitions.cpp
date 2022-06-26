#include <catch2/catch_test_macros.hpp>
#include "definitions.hpp"

TEST_CASE("ranges must be properly initialized", "[init_ranges]")
{
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderStatus::CANCELED) == "CANCELED");
    REQUIRE(binance::defs::from_string<binance::defs::OrderStatus>("CANCELED") == binance::defs::OrderStatus::CANCELED);
}