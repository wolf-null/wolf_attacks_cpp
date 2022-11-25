#include "pair.cpp"

template <typename T>
concept Ordered = requires (T a, T b)
{
    a < b;
};


template <Ordered TLeft, Ordered TRight>
class OrderablePair : public Pair <TLeft, TRight>
{
public:
    OrderablePair(TLeft left, TRight right);

    bool operator < (OrderablePair <TLeft, TRight>& other)
    {
        if(this->getLeft() < other.getLeft())
            return true;

        if(this->getRight() < other.getRight())
            return true;

        return false;
    }

};

template<Ordered TLeft, Ordered TRight>
OrderablePair<TLeft, TRight>::OrderablePair(TLeft left, TRight right) : Pair<TLeft, TRight>(left, right) {};
