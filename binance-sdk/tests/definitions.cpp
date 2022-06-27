#include <catch2/catch_test_macros.hpp>
#include "definitions.hpp"

TEST_CASE("serialization and deserialization must work correctly", "[binance::defs]")
{
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::MIN1) == "1m");
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::MIN3) == "3m");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderStatus::CANCELED) == "CANCELED");
    REQUIRE(binance::defs::to_string(binance::defs::OrderStatus::CANCELED) == "CANCELED");
    REQUIRE(binance::defs::from_string<binance::defs::OrderStatus>("CANCELED") == binance::defs::OrderStatus::CANCELED);
}