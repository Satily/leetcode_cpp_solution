#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<type_traits>


// template<typename T>
// std::string flatten(const std::vector<T> &data, const std::string &prefix = "")
// {    
//     std::ostringstream sout;
//     sout << prefix << "[" << endl;
//     for (std::vector<T>::const_iterator i = data.cbegin(); i != data.cend() - 1; ++i) 
//     {
//         sout << prefix << flatten(*i, prefix + "\t") << ", ";
//     }
//     sout << *(data.cend() - 1) << "]" << endl;    
//     return sout.str();
// }

// std::string flatten(int datum, const std::string &prefix = "") {
//     return (std::ostringstream() << datum).str();
// }

// std::string flatten(std::string datum, const std::string &prefix = "") {
//     return (std::ostringstream() << datum).str();
// }


template<typename T>
std::string flatten(const std::vector<T> &data) 
{
    std::ostringstream sout;
    sout << "[";
    for (std::vector<T>::const_iterator i = data.cbegin(); i != data.cend() - 1; ++i) 
    {
        sout << *i << ", ";
    }
    sout << *(data.cend() - 1) << "]";
    return sout.str();
}

template<typename T>
std::string flatten(const std::vector<std::vector<T>> &matrix) 
{
    std::ostringstream sout;
    sout << "[" << std::endl;
    for (std::vector<std::vector<T>>::const_iterator i = matrix.cbegin(); i != matrix.cend() - 1; ++i) 
    {
        sout << "\t" << flatten(*i) << ", " << endl;
    }
    sout << "\t" << *(matrix.cend() - 1) << endl << "]";
    return sout.str();
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &data) 
{
    out << flatten(data);
    return out;
}
