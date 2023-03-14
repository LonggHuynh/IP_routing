
#include <iostream>
#include <fstream>
#include <sstream>

#include "LongestPrefixMatcher.h"


int main(int argc, char *argv[]) {



    if (argc < 3) {
        std::cout << "Usage: ./program [routes_file_path] [lookup_file_path]" << std::endl;
        exit(EXIT_FAILURE);
    }


    //Read routes
    std::ifstream routeFile(argv[1]);
    std::string line;
    if (!routeFile.is_open()) {
        std::cout << "Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    LongestPrefixMatcher matcher;
    while (std::getline(routeFile, line)) {

        std::stringstream st(line);
        int prefixLen, port, a, b, c, d;
        char ch; //to temporarily store the skipping character
        st >> a >> ch >> b >> ch >> c >> ch >> d >> ch >> prefixLen >> port;


        int ipBinary = d + (c << 8) + (b << 16) + (a << 24);
        matcher.add(ipBinary, prefixLen, port);
    }
    routeFile.close();


    //Handle lookup
    std::ifstream lookupFile(argv[2]);
    if (!lookupFile.is_open()) {
        std::cout << "Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }
    while (std::getline(lookupFile, line)) {
        std::stringstream st(line);
        int a, b, c, d;
        char ch;
        st >> a >> ch >> b >> ch >> c >> ch >> d;
        int ipBinary = d + (c << 8) + (b << 16) + (a << 24);
        std::cout << matcher.lookup(ipBinary) << "\n";
    }
    routeFile.close();
}

