#pragma once
#include <iostream>
#include <string>
#include <curl/curl.h>
class SteamAPI {
private:
   static  size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
        size_t total_size = size * nmemb;
        output->append((char*)contents, total_size);
        return total_size;
    }
public:
    static std::string getSteamMarketPrice(const std::string& itemName) {
        CURL* curl;
        CURLcode res;
        std::string readBuffer;

        std::string encodedItemName = itemName + " " + wear;
        size_t pos;
        while ((pos = encodedItemName.find(" ")) != std::string::npos) {
            encodedItemName.replace(pos, 1, "%20");
        }
        while ((pos = encodedItemName.find("(")) != std::string::npos) {
            encodedItemName.replace(pos, 1, "%28");
        }
        while ((pos = encodedItemName.find(")")) != std::string::npos) {
            encodedItemName.replace(pos, 1, "%29");
        }
        while ((pos = encodedItemName.find("|")) != std::string::npos) {
            encodedItemName.replace(pos, 1, "%7C");
        }

        std::string url = "https://steamcommunity.com/market/priceoverview/?currency=3&appid=730&market_hash_name=" + encodedItemName;

        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);


            // Perform the request
            res = curl_easy_perform(curl);

            // Get HTTP response code
            long http_code = 0;
            //curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

            // Print debug info
            //std::cout << "Request URL: " << url << std::endl;
            //std::cout << "HTTP Response Code: " << http_code << std::endl;

            if (res != CURLE_OK) {
                std::cerr << "cURL Error: " << curl_easy_strerror(res) << std::endl;
            }
            else {
                /*std::cout << "Response: " << readBuffer << std::endl;*/
            }

            curl_easy_cleanup(curl);
        }
        else {
            std::cerr << "Failed to initialize cURL" << std::endl;
        }

        return readBuffer;
    }
};