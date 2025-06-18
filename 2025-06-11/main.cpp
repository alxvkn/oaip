#include <cctype>
#include <iostream>

std::string compress(const std::string& input) {
    int count = 1;
    std::string compressed;

    for (int i = 0; i < input.length(); i++){
        if (input[i] == input[i + 1]){
            count += 1;
        }
        else {
            compressed += (count == 1 ? "" : std::to_string(count)) + input[i];
            count = 1;
        }
    }

    return compressed;
}

std::string decompress(const std::string& compressed) {
    std::string decompressed;

    for (unsigned i = 0; i < compressed.length(); i++) {
        char c = compressed[i];
        if (std::isdigit(c)) {
            char next = compressed[++i];
            for (unsigned j = 0; j < c - '0'; j++) {
                decompressed.push_back(next);
            }
        } else {
            decompressed.push_back(c);
        }
    }

    return decompressed;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        return 1;
    }
    std::string input(argv[1]);

    bool compressed = false;

    for (char c : input) {
        if (std::isdigit(c)) {
            compressed = true;
            break;
        }
    }

    std::cout << (compressed ? decompress(input) : compress(input)) << std::endl;;
    return 0;
}
