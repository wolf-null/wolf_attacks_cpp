#include <iostream>

// --------------------------------------------------- DECLARATION -----------------------------------------------------

template <typename  TLeft, typename  TRight>
class Pair{
private:
    TLeft _left;
    TRight _right;
public:
    Pair(TLeft left, TRight right) : _left{left}, _right{right} {};

    TLeft getLeft() const;
    TRight getRight() const;
};

// ------------------------------------------------- IMPLEMENTATION ----------------------------------------------------

template <typename  TLeft, typename  TRight>
TLeft Pair<TLeft, TRight>::getLeft() const{
    return this->_left;
}

template <typename  TLeft, typename  TRight>
TRight Pair<TLeft, TRight>::getRight() const {
    return this->_right;
}

template <typename TLeft, typename  TRight>
std::ostream &operator<<(std::ostream &stream, Pair<TLeft, TRight> &val) {
    stream << '(' << val.getLeft() << ", " << val.getRight() << ')';
    return stream;
}


