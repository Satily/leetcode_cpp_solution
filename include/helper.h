#include<iostream>
#include<vector>
#include<string>
#include<sstream>


template<typename T>
std::string flatten(const std::vector<T> &data) 
{
    std::ostringstream sout;
    sout << "[";
    for (std::vector<int>::const_iterator i = data.cbegin(); i != data.cend() - 1; ++i) 
    {
        sout << *i << ", ";
    }
    scout << *(data.cend() - 1) << "]";
    return sout.str();
}


template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &data) 
{
    out << flatten(data);
    return out;
}
