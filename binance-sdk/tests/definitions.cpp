#include <catch2/catch_test_macros.hpp>
#include "definitions.hpp"

TEST_CASE("serialization and deserialization must work correctly", "[binance::defs]")
{
    // SymbolStatus ...
    REQUIRE(binance::defs::to_string_view(binance::defs::SymbolStatus::PRE_TRADING) == "PRE_TRADING");
    REQUIRE(binance::defs::to_string_view(binance::defs::SymbolStatus::TRADING) == "TRADING");
    REQUIRE(binance::defs::to_string_view(binance::defs::SymbolStatus::POST_TRADING) == "POST_TRADING");
    REQUIRE(binance::defs::to_string_view(binance::defs::SymbolStatus::END_OF_DAY) == "END_OF_DAY");
    REQUIRE(binance::defs::to_string_view(binance::defs::SymbolStatus::HALT) == "HALT");
    REQUIRE(binance::defs::to_string_view(binance::defs::SymbolStatus::AUCTION_MATCH) == "AUCTION_MATCH");
    REQUIRE(binance::defs::to_string_view(binance::defs::SymbolStatus::BREAK) == "BREAK");

    REQUIRE(binance::defs::to_string(binance::defs::SymbolStatus::PRE_TRADING) == "PRE_TRADING");
    REQUIRE(binance::defs::to_string(binance::defs::SymbolStatus::TRADING) == "TRADING");
    REQUIRE(binance::defs::to_string(binance::defs::SymbolStatus::POST_TRADING) == "POST_TRADING");
    REQUIRE(binance::defs::to_string(binance::defs::SymbolStatus::END_OF_DAY) == "END_OF_DAY");
    REQUIRE(binance::defs::to_string(binance::defs::SymbolStatus::HALT) == "HALT");
    REQUIRE(binance::defs::to_string(binance::defs::SymbolStatus::AUCTION_MATCH) == "AUCTION_MATCH");
    REQUIRE(binance::defs::to_string(binance::defs::SymbolStatus::BREAK) == "BREAK");

    REQUIRE(binance::defs::from_string<binance::defs::SymbolStatus>("PRE_TRADING") == binance::defs::SymbolStatus::PRE_TRADING);
    REQUIRE(binance::defs::from_string<binance::defs::SymbolStatus>("TRADING") == binance::defs::SymbolStatus::TRADING);
    REQUIRE(binance::defs::from_string<binance::defs::SymbolStatus>("POST_TRADING") == binance::defs::SymbolStatus::POST_TRADING);
    REQUIRE(binance::defs::from_string<binance::defs::SymbolStatus>("END_OF_DAY") == binance::defs::SymbolStatus::END_OF_DAY);
    REQUIRE(binance::defs::from_string<binance::defs::SymbolStatus>("HALT") == binance::defs::SymbolStatus::HALT);
    REQUIRE(binance::defs::from_string<binance::defs::SymbolStatus>("PRE_TRADING") == binance::defs::SymbolStatus::PRE_TRADING);
    REQUIRE(binance::defs::from_string<binance::defs::SymbolStatus>("AUCTION_MATCH") == binance::defs::SymbolStatus::AUCTION_MATCH);
    REQUIRE(binance::defs::from_string<binance::defs::SymbolStatus>("BREAK") == binance::defs::SymbolStatus::BREAK);

    // SymbolPermissions ...
    REQUIRE(binance::defs::to_string_view(binance::defs::SymbolPermissions::SPOT) == "SPOT");
    REQUIRE(binance::defs::to_string_view(binance::defs::SymbolPermissions::MARGIN) == "MARGIN");
    REQUIRE(binance::defs::to_string_view(binance::defs::SymbolPermissions::LEVERAGED) == "LEVERAGED");
    REQUIRE(binance::defs::to_string_view(binance::defs::SymbolPermissions::TRD_GRP_002) == "TRD_GRP_002");
    REQUIRE(binance::defs::to_string_view(binance::defs::SymbolPermissions::TRD_GRP_003) == "TRD_GRP_003");
    REQUIRE(binance::defs::to_string_view(binance::defs::SymbolPermissions::TRD_GRP_004) == "TRD_GRP_004");

    REQUIRE(binance::defs::to_string(binance::defs::SymbolPermissions::SPOT) == "SPOT");
    REQUIRE(binance::defs::to_string(binance::defs::SymbolPermissions::MARGIN) == "MARGIN");
    REQUIRE(binance::defs::to_string(binance::defs::SymbolPermissions::LEVERAGED) == "LEVERAGED");
    REQUIRE(binance::defs::to_string(binance::defs::SymbolPermissions::TRD_GRP_002) == "TRD_GRP_002");
    REQUIRE(binance::defs::to_string(binance::defs::SymbolPermissions::TRD_GRP_003) == "TRD_GRP_003");
    REQUIRE(binance::defs::to_string(binance::defs::SymbolPermissions::TRD_GRP_004) == "TRD_GRP_004");

    REQUIRE(binance::defs::from_string<binance::defs::SymbolPermissions>("SPOT") == binance::defs::SymbolPermissions::SPOT);
    REQUIRE(binance::defs::from_string<binance::defs::SymbolPermissions>("MARGIN") == binance::defs::SymbolPermissions::MARGIN);
    REQUIRE(binance::defs::from_string<binance::defs::SymbolPermissions>("LEVERAGED") == binance::defs::SymbolPermissions::LEVERAGED);
    REQUIRE(binance::defs::from_string<binance::defs::SymbolPermissions>("TRD_GRP_002") == binance::defs::SymbolPermissions::TRD_GRP_002);
    REQUIRE(binance::defs::from_string<binance::defs::SymbolPermissions>("TRD_GRP_003") == binance::defs::SymbolPermissions::TRD_GRP_003);
    REQUIRE(binance::defs::from_string<binance::defs::SymbolPermissions>("TRD_GRP_004") == binance::defs::SymbolPermissions::TRD_GRP_004);

    // OrderStatus ...
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderStatus::NEW) == "NEW");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderStatus::PARTIALLY_FILLED) == "PARTIALLY_FILLED");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderStatus::FILLED) == "FILLED");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderStatus::CANCELED) == "CANCELED");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderStatus::PENDING_CANCEL) == "PENDING_CANCEL");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderStatus::REJECTED) == "REJECTED");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderStatus::EXPIRED) == "EXPIRED");

    REQUIRE(binance::defs::to_string(binance::defs::OrderStatus::NEW) == "NEW");
    REQUIRE(binance::defs::to_string(binance::defs::OrderStatus::PARTIALLY_FILLED) == "PARTIALLY_FILLED");
    REQUIRE(binance::defs::to_string(binance::defs::OrderStatus::FILLED) == "FILLED");
    REQUIRE(binance::defs::to_string(binance::defs::OrderStatus::CANCELED) == "CANCELED");
    REQUIRE(binance::defs::to_string(binance::defs::OrderStatus::PENDING_CANCEL) == "PENDING_CANCEL");
    REQUIRE(binance::defs::to_string(binance::defs::OrderStatus::REJECTED) == "REJECTED");
    REQUIRE(binance::defs::to_string(binance::defs::OrderStatus::EXPIRED) == "EXPIRED");

    REQUIRE(binance::defs::from_string<binance::defs::OrderStatus>("NEW") == binance::defs::OrderStatus::NEW);
    REQUIRE(binance::defs::from_string<binance::defs::OrderStatus>("PARTIALLY_FILLED") == binance::defs::OrderStatus::PARTIALLY_FILLED);
    REQUIRE(binance::defs::from_string<binance::defs::OrderStatus>("FILLED") == binance::defs::OrderStatus::FILLED);
    REQUIRE(binance::defs::from_string<binance::defs::OrderStatus>("CANCELED") == binance::defs::OrderStatus::CANCELED);
    REQUIRE(binance::defs::from_string<binance::defs::OrderStatus>("PENDING_CANCEL") == binance::defs::OrderStatus::PENDING_CANCEL);
    REQUIRE(binance::defs::from_string<binance::defs::OrderStatus>("REJECTED") == binance::defs::OrderStatus::REJECTED);
    REQUIRE(binance::defs::from_string<binance::defs::OrderStatus>("EXPIRED") == binance::defs::OrderStatus::EXPIRED);

    // OCOStatus ...
    REQUIRE(binance::defs::to_string_view(binance::defs::OCOStatus::RESPONSE) == "RESPONSE");
    REQUIRE(binance::defs::to_string_view(binance::defs::OCOStatus::EXEC_STARTED) == "EXEC_STARTED");
    REQUIRE(binance::defs::to_string_view(binance::defs::OCOStatus::ALL_DONE) == "ALL_DONE");

    REQUIRE(binance::defs::to_string(binance::defs::OCOStatus::RESPONSE) == "RESPONSE");
    REQUIRE(binance::defs::to_string(binance::defs::OCOStatus::EXEC_STARTED) == "EXEC_STARTED");
    REQUIRE(binance::defs::to_string(binance::defs::OCOStatus::ALL_DONE) == "ALL_DONE");

    REQUIRE(binance::defs::from_string<binance::defs::OCOStatus>("RESPONSE") == binance::defs::OCOStatus::RESPONSE);
    REQUIRE(binance::defs::from_string<binance::defs::OCOStatus>("EXEC_STARTED") == binance::defs::OCOStatus::EXEC_STARTED);
    REQUIRE(binance::defs::from_string<binance::defs::OCOStatus>("ALL_DONE") == binance::defs::OCOStatus::ALL_DONE);
    // OCOOrderStatus ...
    REQUIRE(binance::defs::to_string_view(binance::defs::OCOOrderStatus::EXECUTING) == "EXECUTING");
    REQUIRE(binance::defs::to_string_view(binance::defs::OCOOrderStatus::ALL_DONE) == "ALL_DONE");
    REQUIRE(binance::defs::to_string_view(binance::defs::OCOOrderStatus::REJECT) == "REJECT");

    REQUIRE(binance::defs::to_string(binance::defs::OCOOrderStatus::EXECUTING) == "EXECUTING");
    REQUIRE(binance::defs::to_string(binance::defs::OCOOrderStatus::ALL_DONE) == "ALL_DONE");
    REQUIRE(binance::defs::to_string(binance::defs::OCOOrderStatus::REJECT) == "REJECT");

    REQUIRE(binance::defs::from_string<binance::defs::OCOOrderStatus>("EXECUTING") == binance::defs::OCOOrderStatus::EXECUTING);
    REQUIRE(binance::defs::from_string<binance::defs::OCOOrderStatus>("ALL_DONE") == binance::defs::OCOOrderStatus::ALL_DONE);
    REQUIRE(binance::defs::from_string<binance::defs::OCOOrderStatus>("REJECT") == binance::defs::OCOOrderStatus::REJECT);
    // ContingencyType ...
    REQUIRE(binance::defs::to_string_view(binance::defs::ContingencyType::OCO) == "OCO");

    REQUIRE(binance::defs::to_string(binance::defs::ContingencyType::OCO) == "OCO");

    REQUIRE(binance::defs::from_string<binance::defs::ContingencyType>("OCO") == binance::defs::ContingencyType::OCO);

    // OrderType ...
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderType::LIMIT) == "LIMIT");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderType::MARKET) == "MARKET");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderType::STOP_LOSS) == "STOP_LOSS");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderType::STOP_LOSS_LIMIT) == "STOP_LOSS_LIMIT");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderType::TAKE_PROFIT) == "TAKE_PROFIT");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderType::TAKE_PROFIT_LIMIT) == "TAKE_PROFIT_LIMIT");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderType::LIMIT_MAKER) == "LIMIT_MAKER");

    REQUIRE(binance::defs::to_string(binance::defs::OrderType::LIMIT) == "LIMIT");
    REQUIRE(binance::defs::to_string(binance::defs::OrderType::MARKET) == "MARKET");
    REQUIRE(binance::defs::to_string(binance::defs::OrderType::STOP_LOSS) == "STOP_LOSS");
    REQUIRE(binance::defs::to_string(binance::defs::OrderType::STOP_LOSS_LIMIT) == "STOP_LOSS_LIMIT");
    REQUIRE(binance::defs::to_string(binance::defs::OrderType::TAKE_PROFIT) == "TAKE_PROFIT");
    REQUIRE(binance::defs::to_string(binance::defs::OrderType::TAKE_PROFIT_LIMIT) == "TAKE_PROFIT_LIMIT");
    REQUIRE(binance::defs::to_string(binance::defs::OrderType::LIMIT_MAKER) == "LIMIT_MAKER");

    REQUIRE(binance::defs::from_string<binance::defs::OrderType>("LIMIT") == binance::defs::OrderType::LIMIT);
    REQUIRE(binance::defs::from_string<binance::defs::OrderType>("MARKET") == binance::defs::OrderType::MARKET);
    REQUIRE(binance::defs::from_string<binance::defs::OrderType>("STOP_LOSS") == binance::defs::OrderType::STOP_LOSS);
    REQUIRE(binance::defs::from_string<binance::defs::OrderType>("STOP_LOSS_LIMIT") == binance::defs::OrderType::STOP_LOSS_LIMIT);
    REQUIRE(binance::defs::from_string<binance::defs::OrderType>("TAKE_PROFIT") == binance::defs::OrderType::TAKE_PROFIT);
    REQUIRE(binance::defs::from_string<binance::defs::OrderType>("TAKE_PROFIT_LIMIT") == binance::defs::OrderType::TAKE_PROFIT_LIMIT);
    REQUIRE(binance::defs::from_string<binance::defs::OrderType>("LIMIT_MAKER") == binance::defs::OrderType::LIMIT_MAKER);

    // OrderResponseType ...
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderResponseType::ACK) == "ACK");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderResponseType::RESULT) == "RESULT");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderResponseType::FULL) == "FULL");

    REQUIRE(binance::defs::to_string(binance::defs::OrderResponseType::ACK) == "ACK");
    REQUIRE(binance::defs::to_string(binance::defs::OrderResponseType::RESULT) == "RESULT");
    REQUIRE(binance::defs::to_string(binance::defs::OrderResponseType::FULL) == "FULL");

    REQUIRE(binance::defs::from_string<binance::defs::OrderResponseType>("ACK") == binance::defs::OrderResponseType::ACK);
    REQUIRE(binance::defs::from_string<binance::defs::OrderResponseType>("RESULT") == binance::defs::OrderResponseType::RESULT);
    REQUIRE(binance::defs::from_string<binance::defs::OrderResponseType>("FULL") == binance::defs::OrderResponseType::FULL);

    // OrderSide ...
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderSide::BUY) == "BUY");
    REQUIRE(binance::defs::to_string_view(binance::defs::OrderSide::SELL) == "SELL");

    REQUIRE(binance::defs::to_string(binance::defs::OrderSide::BUY) == "BUY");
    REQUIRE(binance::defs::to_string(binance::defs::OrderSide::SELL) == "SELL");

    REQUIRE(binance::defs::from_string<binance::defs::OrderSide>("BUY") == binance::defs::OrderSide::BUY);
    REQUIRE(binance::defs::from_string<binance::defs::OrderSide>("SELL") == binance::defs::OrderSide::SELL);

    // TimeInForce ...
    REQUIRE(binance::defs::to_string_view(binance::defs::TimeInForce::GTC) == "GTC");
    REQUIRE(binance::defs::to_string_view(binance::defs::TimeInForce::IOC) == "IOC");
    REQUIRE(binance::defs::to_string_view(binance::defs::TimeInForce::FOK) == "FOK");

    REQUIRE(binance::defs::to_string(binance::defs::TimeInForce::GTC) == "GTC");
    REQUIRE(binance::defs::to_string(binance::defs::TimeInForce::IOC) == "IOC");
    REQUIRE(binance::defs::to_string(binance::defs::TimeInForce::FOK) == "FOK");

    REQUIRE(binance::defs::from_string<binance::defs::TimeInForce>("GTC") == binance::defs::TimeInForce::GTC);
    REQUIRE(binance::defs::from_string<binance::defs::TimeInForce>("IOC") == binance::defs::TimeInForce::IOC);
    REQUIRE(binance::defs::from_string<binance::defs::TimeInForce>("FOK") == binance::defs::TimeInForce::FOK);

    // KLineIntervals ...
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::MIN1) == "1m");
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::MIN3) == "3m");
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::MIN5) == "5m");
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::MIN15) == "15m");
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::MIN30) == "30m");
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::H1) == "1h");
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::H2) == "2h");
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::H4) == "4h");
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::H6) == "6h");
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::H8) == "8h");
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::H12) == "12h");
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::D1) == "1d");
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::D3) == "3d");
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::W1) == "1w");
    REQUIRE(binance::defs::to_string_view(binance::defs::KLineIntervals::M1) == "1M");

    REQUIRE(binance::defs::to_string(binance::defs::KLineIntervals::MIN1) == "1m");
    REQUIRE(binance::defs::to_string(binance::defs::KLineIntervals::MIN3) == "3m");
    REQUIRE(binance::defs::to_string(binance::defs::KLineIntervals::MIN5) == "5m");
    REQUIRE(binance::defs::to_string(binance::defs::KLineIntervals::MIN15) == "15m");
    REQUIRE(binance::defs::to_string(binance::defs::KLineIntervals::MIN30) == "30m");
    REQUIRE(binance::defs::to_string(binance::defs::KLineIntervals::H1) == "1h");
    REQUIRE(binance::defs::to_string(binance::defs::KLineIntervals::H2) == "2h");
    REQUIRE(binance::defs::to_string(binance::defs::KLineIntervals::H4) == "4h");
    REQUIRE(binance::defs::to_string(binance::defs::KLineIntervals::H6) == "6h");
    REQUIRE(binance::defs::to_string(binance::defs::KLineIntervals::H8) == "8h");
    REQUIRE(binance::defs::to_string(binance::defs::KLineIntervals::H12) == "12h");
    REQUIRE(binance::defs::to_string(binance::defs::KLineIntervals::D1) == "1d");
    REQUIRE(binance::defs::to_string(binance::defs::KLineIntervals::D3) == "3d");
    REQUIRE(binance::defs::to_string(binance::defs::KLineIntervals::W1) == "1w");
    REQUIRE(binance::defs::to_string(binance::defs::KLineIntervals::M1) == "1M");

    REQUIRE(binance::defs::from_string<binance::defs::KLineIntervals>("1m") == binance::defs::KLineIntervals::MIN1);
    REQUIRE(binance::defs::from_string<binance::defs::KLineIntervals>("3m") == binance::defs::KLineIntervals::MIN3);
    REQUIRE(binance::defs::from_string<binance::defs::KLineIntervals>("5m") == binance::defs::KLineIntervals::MIN5);
    REQUIRE(binance::defs::from_string<binance::defs::KLineIntervals>("15m") == binance::defs::KLineIntervals::MIN15);
    REQUIRE(binance::defs::from_string<binance::defs::KLineIntervals>("30m") == binance::defs::KLineIntervals::MIN30);
    REQUIRE(binance::defs::from_string<binance::defs::KLineIntervals>("1h") == binance::defs::KLineIntervals::H1);
    REQUIRE(binance::defs::from_string<binance::defs::KLineIntervals>("2h") == binance::defs::KLineIntervals::H2);
    REQUIRE(binance::defs::from_string<binance::defs::KLineIntervals>("4h") == binance::defs::KLineIntervals::H4);
    REQUIRE(binance::defs::from_string<binance::defs::KLineIntervals>("6h") == binance::defs::KLineIntervals::H6);
    REQUIRE(binance::defs::from_string<binance::defs::KLineIntervals>("8h") == binance::defs::KLineIntervals::H8);
    REQUIRE(binance::defs::from_string<binance::defs::KLineIntervals>("12h") == binance::defs::KLineIntervals::H12);
    REQUIRE(binance::defs::from_string<binance::defs::KLineIntervals>("1d") == binance::defs::KLineIntervals::D1);
    REQUIRE(binance::defs::from_string<binance::defs::KLineIntervals>("3d") == binance::defs::KLineIntervals::D3);
    REQUIRE(binance::defs::from_string<binance::defs::KLineIntervals>("1w") == binance::defs::KLineIntervals::W1);
    REQUIRE(binance::defs::from_string<binance::defs::KLineIntervals>("1M") == binance::defs::KLineIntervals::M1);

    // RateLimitType ...
    REQUIRE(binance::defs::to_string_view(binance::defs::RateLimitType::REQUEST_WEIGHT) == "REQUEST_WEIGHT");
    REQUIRE(binance::defs::to_string_view(binance::defs::RateLimitType::ORDERS) == "ORDERS");
    REQUIRE(binance::defs::to_string_view(binance::defs::RateLimitType::RAW_REQUESTS) == "RAW_REQUESTS");

    REQUIRE(binance::defs::to_string(binance::defs::RateLimitType::REQUEST_WEIGHT) == "REQUEST_WEIGHT");
    REQUIRE(binance::defs::to_string(binance::defs::RateLimitType::ORDERS) == "ORDERS");
    REQUIRE(binance::defs::to_string(binance::defs::RateLimitType::RAW_REQUESTS) == "RAW_REQUESTS");

    REQUIRE(binance::defs::from_string<binance::defs::RateLimitType>("REQUEST_WEIGHT") == binance::defs::RateLimitType::REQUEST_WEIGHT);
    REQUIRE(binance::defs::from_string<binance::defs::RateLimitType>("ORDERS") == binance::defs::RateLimitType::ORDERS);
    REQUIRE(binance::defs::from_string<binance::defs::RateLimitType>("RAW_REQUESTS") == binance::defs::RateLimitType::RAW_REQUESTS);

    // RateLimitInterval ...
    REQUIRE(binance::defs::to_string_view(binance::defs::RateLimitInterval::SECOND) == "SECOND");
    REQUIRE(binance::defs::to_string_view(binance::defs::RateLimitInterval::MINUTE) == "MINUTE");
    REQUIRE(binance::defs::to_string_view(binance::defs::RateLimitInterval::DAY) == "DAY");

    REQUIRE(binance::defs::to_string(binance::defs::RateLimitInterval::SECOND) == "SECOND");
    REQUIRE(binance::defs::to_string(binance::defs::RateLimitInterval::MINUTE) == "MINUTE");
    REQUIRE(binance::defs::to_string(binance::defs::RateLimitInterval::DAY) == "DAY");

    REQUIRE(binance::defs::from_string<binance::defs::RateLimitInterval>("SECOND") == binance::defs::RateLimitInterval::SECOND);
    REQUIRE(binance::defs::from_string<binance::defs::RateLimitInterval>("MINUTE") == binance::defs::RateLimitInterval::MINUTE);
    REQUIRE(binance::defs::from_string<binance::defs::RateLimitInterval>("DAY") == binance::defs::RateLimitInterval::DAY);
}