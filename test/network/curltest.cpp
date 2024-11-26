#include <gtest/gtest.h>

#include "network/Network.hpp"
#include "coders/json.hpp"

TEST(curltest, curltest) {
    NetworkSettings settings {};
    auto network = network::Network::create(settings);
    network->get(
        "https://raw.githubusercontent.com/MihailRis/VoxelEngine-Cpp/refs/"
        "heads/curl/res/content/base/blocks/lamp.json",
        [](std::vector<char> data) {
            if (data.empty()) {
                return;
            }
            auto view = std::string_view(data.data(), data.size());
            auto value = json::parse(view);
            std::cout << value << std::endl;
        }, [](auto){}
    );
    if (true) {
        auto socket = network->getConnection(network->connect("google.com", 80));
        const char* string = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
        socket->send(string, strlen(string));
        char data[1024];

        int len = socket->recv(data, 1024);
        std::cout << len << " " << std::string(data, len) << std::endl;
    }

    std::cout << "upload: " << network->getTotalUpload() << " B" << std::endl;
    std::cout << "download: " << network->getTotalDownload() << " B" << std::endl;
}
