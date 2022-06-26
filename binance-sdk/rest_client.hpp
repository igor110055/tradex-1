#ifndef BINANCE_REST_CLIENT_HPP_
#define BINANCE_REST_CLIENT_HPP_

#include <Poco/URI.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/Net/HTTPSStreamFactory.h>
#include <Poco/Net/HTTPStreamFactory.h>
#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/AcceptCertificateHandler.h>

#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPMessage.h>

#include <iostream>
#include <string_view>
#include <memory>
#include <optional>

#ifndef binance_sdk_EXPORT
#define binance_sdk_EXPORT
#endif

namespace binance
{
    binance_sdk_EXPORT void Init();

    binance_sdk_EXPORT class RestClient
    {
        using request_type = Poco::Net::HTTPRequest;
        using response_type = Poco::Net::HTTPResponse;
        struct Result
        {
            response_type response;
            std::optional<std::string> body;
        };

    public:
        explicit RestClient();
        Result exchange_info() const;

    private:
        Poco::Net::Context::Ptr ctx_;
    };
}

#endif

// #include <iostream>
// #include <string_view>
// #include <string>

// #include <Poco/URIStreamOpener.h>
// #include <Poco/JSON/Parser.h>
// #include <Poco/JSON/Object.h>
// #include <Poco/Dynamic/Var.h>
// #include <Poco/JSON/Array.h>

// #include <Poco/Net/SSLManager.h>
// #include <Poco/Net/HTTPSStreamFactory.h>
// #include <Poco/Net/HTTPStreamFactory.h>
// #include <Poco/Net/HTTPSClientSession.h>
// #include <Poco/Net/AcceptCertificateHandler.h>

// const std::string baseApi = "https://api.binance.com";
// const std::string endpoint = "/api/v3/exchangeInfo";
// const std::string postgresUrl = "postgres://postgres:postgres@localhost:5432/postgres?sslmode=disable";

// int main(int argc, char *argv[])
// {
//     Poco::Net::initializeSSL();

//     // build request uri ...
//     Poco::URI uri{baseApi};
//     uri.setPath(endpoint);

//     Poco::Net::HTTPRequest request{
//         Poco::Net::HTTPRequest::HTTP_GET,
//         uri.getPath(),
//         Poco::Net::HTTPMessage::HTTP_1_1};
//     request.setKeepAlive(true);
//     request.set("User-Agent", "boost-beast/1.79.0");
//     session.sendRequest(request);

//     Poco::JSON::Parser parser{};
//     Poco::Net::HTTPResponse resp{};
//     std::istream &is = session.receiveResponse(resp);
//     try
//     {
//         Poco::Dynamic::Var dynVar = parser.parse(is);
//         Poco::JSON::Object::Ptr doc = dynVar.extract<Poco::JSON::Object::Ptr>();
//         Poco::JSON::Array::Ptr symbols = doc->getArray("symbols");
//         for (auto &&i : *symbols)
//         {
//             Poco::JSON::Object::Ptr obj = i.extract<Poco::JSON::Object::Ptr>();
//             std::cout << obj->getValue<std::string>("symbol") << std::endl;
//         }
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     return 0;
// }