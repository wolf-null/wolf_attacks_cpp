/*
 * My minor experiments with C++
 */

#include <iostream>
#include <utility>
#include <vector>
#include <string>

// Yes. The .cpp inclusion. Will figure out is there a normal way to include template shit
#include "lib/dumb_templates/orderable_pair.cpp"
#include "lib/dumb_templates/triplet_on_variant.cpp"

// ------------------------------------------ CUSTOM REPR PART ---------------------------------------------------------

template <class RepresentedType>
class CustomRepr : public AbstractRepresentation <std::ostream , RepresentedType>
{
public:
    void represent(std::ostream & stream, RepresentedType & object) override
    {
        stream << object;
    }
};

template <>
class CustomRepr <std::string> : public AbstractRepresentation <std::ostream , std::string>
{
public:
    void represent(std::ostream & stream, std::string & object) override
    {
        stream << '\'' << object << '\'';
    }
};

// ------------------------------------------------- BODY --------------------------------------------------------------

int main()
{
    Triplet <int, int, std::string> :: Repr <BasicRepresentation, BasicRepresentation, CustomRepr> repr_triplet {1, 1, "sadf"};
    std::cout << repr_triplet;
}

