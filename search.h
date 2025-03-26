#ifndef SEARCH_H
#define SEARCH_H
#include <vector>
#include <string>

class Search
{
public:
    Search();
    static std::vector<int> bruteForce(const std::string &T,std::string &P);
};

#endif // SEARCH_H
