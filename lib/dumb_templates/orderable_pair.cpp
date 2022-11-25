#include "pair.cpp"

// --------------------------------------------------- DECLARATION -----------------------------------------------------

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
};

// ------------------------------------------------- IMPLEMENTATION ----------------------------------------------------

template <Ordered TLeft, Ordered TRight>
bool operator < (const OrderablePair <TLeft, TRight>& a, const OrderablePair <TLeft, TRight>& b)
{
    if(b.getLeft() < a.getLeft())
        return false;

    if(b.getRight() < a.getRight())
        return false;

    return true;
}

template<Ordered TLeft, Ordered TRight>
OrderablePair<TLeft, TRight>::OrderablePair(TLeft left, TRight right) : Pair<TLeft, TRight>(left, right) {};
