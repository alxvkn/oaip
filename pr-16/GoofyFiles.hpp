#ifndef GOOFY_FILES_HPP
#define GOOFY_FILES_HPP

#include <vector>
#include <string>

class GoofyFiles {
public:
    std::vector<std::string> created_files;
    bool create_file(const std::string& pathname, const std::string& content);
    bool delete_file(const std::string& pathname);
    const std::string read_file(const std::string& pathname);
    bool rewrite_file(const std::string& pathname, const std::string& content);
    bool append_file(const std::string& pathname, const std::string& content);
};

#endif
