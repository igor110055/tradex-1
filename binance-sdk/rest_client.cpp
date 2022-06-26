#include "rest_client.hpp"

namespace binance
{
    namespace endpoints
    {
        const std::string_view base_api = "https://api.binance.com";
        const std::string_view exchange_info = "/api/v3/exchangeInfo";
    }

    static bool initialized = false;

    void Init()
    {
        Poco::Net::initializeSSL();
    }

    RestClient::RestClient() : ctx_{new Poco::Net::Context(Poco::Net::Context::CLIENT_USE, "")}
    {
        Poco::Net::SSLManager::InvalidCertificateHandlerPtr ptrHandler{
            new Poco::Net::AcceptCertificateHandler{false}};
        Poco::Net::SSLManager::instance().initializeClient(0, ptrHandler, ctx_);
    }

    RestClient::Result RestClient::exchange_info() const
    {
        Poco::URI uri{static_cast<std::string>(endpoints::base_api)};
        Poco::Net::HTTPSClientSession session{uri.getHost(), uri.getPort(), ctx_};

        Poco::Net::HTTPRequest request{
            Poco::Net::HTTPRequest::HTTP_GET,
            static_cast<std::string>(endpoints::exchange_info),
            Poco::Net::HTTPMessage::HTTP_1_1};

        session.sendRequest(request);

        Poco::Net::HTTPResponse resp{};
        auto &ss = session.receiveResponse(resp);
        std::istreambuf_iterator<char> eos;

        return {
            .response = resp,
            .body = std::string{std::istreambuf_iterator<char>{ss}, eos}};
    }
}