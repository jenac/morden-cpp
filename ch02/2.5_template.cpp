# include <vector>
template class std::vector<bool>; //force instantiation
extern template class std::vector<double>; // not in current file

//after C++ 11, the following is ok
std::vector<std::vector<int>> matrix;


template<bool T>
class MagicType {
    bool magic = T;
};

//in main, you can
//not recommended
std::vector<MagicType<(1>2)>> magic;

