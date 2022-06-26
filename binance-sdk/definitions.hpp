#ifndef BINANCE_DEFINITIONS_H
#define BINANCE_DEFINITIONS_H

#include <string>
#include <string_view>
#include <unordered_map>
#include <type_traits>
#include <iostream>
#include <optional>

namespace binance
{
    namespace defs
    {
        enum class SymbolStatus
        {
            PRE_TRADING,
            TRADING,
            POST_TRADING,
            END_OF_DAY,
            HALT,
            AUCTION_MATCH,
            BREAK,
        };

        enum class SymbolPermissions
        {
            SPOT,
            MARGIN,
            LEVERAGED,
            TRD_GRP_002,
            TRD_GRP_003,
            TRD_GRP_004,
        };

        enum class OrderStatus
        {
            NEW,
            PARTIALLY_FILLED,
            FILLED,
            CANCELED,
            PENDING_CANCEL,
            REJECTED,
            EXPIRED,
        };

        enum class OCOStatus
        {
            RESPONSE,
            EXEC_STARTED,
            ALL_DONE,
        };

        enum class OCOOrderStatus
        {
            EXECUTING,
            ALL_DONE,
            REJECT,
        };

        enum class ContingencyType
        {
            OCO,
        };

        enum class OrderType
        {
            LIMIT,
            MARKET,
            STOP_LOSS,
            STOP_LOSS_LIMIT,
            TAKE_PROFIT,
            TAKE_PROFIT_LIMIT,
            LIMIT_MAKER,
        };

        enum class OrderResponseType
        {
            ACK,
            RESULT,
            FULL,
        };

        enum class OrderSide
        {
            BUY,
            SELL,
        };

        enum class TimeInForce
        {
            GTC,
            IOC,
            FOK,
        };

        enum class KLineIntervals
        {
            MIN1,
            MIN3,
            MIN5,
            MIN15,
            MIN30,
            H1,
            H2,
            H4,
            H6,
            H8,
            H12,
            D1,
            D3,
            W1,
            M1,
        };

        enum class RateLimitType
        {
            REQUEST_WEIGHT,
            ORDERS,
            RAW_REQUESTS,
        };

        enum class RateLimitInterval
        {
            SECOND,
            MINUTE,
            DAY,
        };

        template <typename>
        inline constexpr bool dependent_false_v = false;

        template <typename T>
        constexpr std::string_view to_string_view(T s)
        {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            if constexpr (std::is_same_v<T, RateLimitInterval>)
            {
                switch (s)
                {
                case RateLimitInterval::SECOND:
                    return "SECOND";
                case RateLimitInterval::MINUTE:
                    return "MINUTE";
                case RateLimitInterval::DAY:
                    return "DAY";
                default:
                    throw;
                }
            }
            else if constexpr (std::is_same_v<T, RateLimitType>)
            {
                switch (s)
                {
                case RateLimitType::REQUEST_WEIGHT:
                    return "REQUEST_WEIGHT";
                case RateLimitType::ORDERS:
                    return "ORDERS";
                case RateLimitType::RAW_REQUESTS:
                    return "RAW_REQUESTS";
                default:
                    throw;
                }
            }
            else if constexpr (std::is_same_v<T, KLineIntervals>)
            {
                switch (s)
                {
                case KLineIntervals::MIN1:
                    return "1m";
                case KLineIntervals::MIN3:
                    return "3m";
                case KLineIntervals::MIN5:
                    return "5m";
                case KLineIntervals::MIN15:
                    return "15m";
                case KLineIntervals::MIN30:
                    return "30m";
                case KLineIntervals::H1:
                    return "1h";
                case KLineIntervals::H2:
                    return "2h";
                case KLineIntervals::H4:
                    return "4h";
                case KLineIntervals::H6:
                    return "6h";
                case KLineIntervals::H8:
                    return "8h";
                case KLineIntervals::H12:
                    return "12h";
                case KLineIntervals::D1:
                    return "1d";
                case KLineIntervals::D3:
                    return "3d";
                case KLineIntervals::W1:
                    return "1w";
                case KLineIntervals::M1:
                    return "1M";
                default:
                    throw;
                }
            }
            else if constexpr (std::is_same_v<T, TimeInForce>)
            {
                switch (s)
                {
                case TimeInForce::GTC:
                    return "GTC";
                case TimeInForce::IOC:
                    return "IOC";
                case TimeInForce::FOK:
                    return "FOK";
                default:
                    throw;
                }
            }
            else if constexpr (std::is_same_v<T, OrderSide>)
            {
                switch (s)
                {
                case OrderSide::BUY:
                    return "BUY";
                case OrderSide::SELL:
                    return "SELL";
                default:
                    throw;
                }
            }
            else if constexpr (std::is_same_v<T, OrderResponseType>)
            {
                switch (s)
                {
                case OrderResponseType::ACK:
                    return "ACK";
                case OrderResponseType::RESULT:
                    return "RESULT";
                case OrderResponseType::FULL:
                    return "FULL";
                default:
                    throw;
                }
            }
            else if constexpr (std::is_same_v<T, OrderType>)
            {
                switch (s)
                {
                case OrderType::LIMIT:
                    return "LIMIT";
                case OrderType::MARKET:
                    return "MARKET";
                case OrderType::STOP_LOSS:
                    return "STOP_LOSS";
                case OrderType::STOP_LOSS_LIMIT:
                    return "STOP_LOSS_LIMIT";
                case OrderType::TAKE_PROFIT:
                    return "TAKE_PROFIT";
                case OrderType::TAKE_PROFIT_LIMIT:
                    return "TAKE_PROFIT_LIMIT";
                case OrderType::LIMIT_MAKER:
                    return "LIMIT_MAKER";
                default:
                    throw;
                }
            }
            else if constexpr (std::is_same_v<T, ContingencyType>)
            {
                switch (s)
                {
                case ContingencyType::OCO:
                    return "OCO";
                default:
                    throw;
                }
            }
            else if constexpr (std::is_same_v<T, OCOOrderStatus>)
            {
                switch (s)
                {
                case OCOOrderStatus::EXECUTING:
                    return "EXECUTING";
                case OCOOrderStatus::ALL_DONE:
                    return "ALL_DONE";
                case OCOOrderStatus::REJECT:
                    return "REJECT";
                default:
                    throw;
                }
            }
            else if constexpr (std::is_same_v<T, OCOStatus>)
            {
                switch (s)
                {
                case OCOStatus::RESPONSE:
                    return "RESPONSE";
                case OCOStatus::EXEC_STARTED:
                    return "EXEC_STARTED";
                case OCOStatus::ALL_DONE:
                    return "ALL_DONE";
                default:
                    throw;
                }
            }
            else if constexpr (std::is_same_v<T, OrderStatus>)
            {
                switch (s)
                {
                case OrderStatus::NEW:
                    return "NEW";
                case OrderStatus::PARTIALLY_FILLED:
                    return "PARTIALLY_FILLED";
                case OrderStatus::FILLED:
                    return "FILLED";
                case OrderStatus::CANCELED:
                    return "CANCELED";
                case OrderStatus::PENDING_CANCEL:
                    return "PENDING_CANCEL";
                case OrderStatus::REJECTED:
                    return "REJECTED";
                case OrderStatus::EXPIRED:
                    return "EXPIRED";
                default:
                    throw;
                }
            }
            else if constexpr (std::is_same_v<T, SymbolPermissions>)
            {
                switch (s)
                {
                case SymbolPermissions::SPOT:
                    return "SPOT";
                case SymbolPermissions::MARGIN:
                    return "MARGIN";
                case SymbolPermissions::LEVERAGED:
                    return "LEVERAGED";
                case SymbolPermissions::TRD_GRP_002:
                    return "TRD_GRP_002";
                case SymbolPermissions::TRD_GRP_003:
                    return "TRD_GRP_003";
                case SymbolPermissions::TRD_GRP_004:
                    return "TRD_GRP_004";
                default:
                    throw;
                }
            }
            else if constexpr (std::is_same_v<T, SymbolStatus>)
            {
                switch (s)
                {
                case SymbolStatus::PRE_TRADING:
                    return "PRE_TRADING";
                case SymbolStatus::TRADING:
                    return "TRADING";
                case SymbolStatus::POST_TRADING:
                    return "POST_TRADING";
                case SymbolStatus::END_OF_DAY:
                    return "END_OF_DAY";
                case SymbolStatus::HALT:
                    return "HALT";
                case SymbolStatus::AUCTION_MATCH:
                    return "AUCTION_MATCH";
                case SymbolStatus::BREAK:
                    return "BREAK";
                default:
                    throw;
                }
            }
            else
            {
                static_assert(dependent_false_v<T>, "unsupported type");
            }
        }

        template <typename T>
        constexpr std::string to_string(T s)
        {
            return static_cast<std::string>(to_string_view(s));
        }

        static std::unordered_map<std::string_view, OrderStatus> order_status_mapping = {
            {to_string_view<OrderStatus>(OrderStatus::NEW), OrderStatus::NEW},
            {to_string_view<OrderStatus>(OrderStatus::CANCELED), OrderStatus::CANCELED},
            {to_string_view<OrderStatus>(OrderStatus::FILLED), OrderStatus::FILLED},
            {to_string_view<OrderStatus>(OrderStatus::PARTIALLY_FILLED), OrderStatus::PARTIALLY_FILLED},
            {to_string_view<OrderStatus>(OrderStatus::EXPIRED), OrderStatus::EXPIRED},
            {to_string_view<OrderStatus>(OrderStatus::PENDING_CANCEL), OrderStatus::PENDING_CANCEL},
            {to_string_view<OrderStatus>(OrderStatus::REJECTED), OrderStatus::REJECTED},
        };

        template <typename T>
        constexpr std::optional<T> from_string(const std::string_view s)
        {
            if constexpr (std::is_same_v<T, OrderStatus>)
            {
                if (order_status_mapping.contains(s))
                {
                    return order_status_mapping[s];
                }
                else
                {
                    return std::nullopt;
                }
            }
            else
            {
                static_assert(dependent_false_v<T>, "unsupported type");
            }
        }
    }
}

#endif