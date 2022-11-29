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

int main()
{
    Triplet <int, int, std::string> :: Repr <BasicRepresentation<int>, BasicRepresentation<int>, BasicRepresentation<std::string>> triplet {1, 1, "sadf"};
    std::cout << triplet;
}
