#include <iostream>
#include <vector>

// Yes. The CPP inclusion. Will figure out is there a normal way to include template shit
#include "lib/dumb_templates/orderable_pair.cpp"

typedef OrderablePair<int, int> OIntPair;

void print(std::vector <OIntPair> & vec)
{
    for(auto element : vec)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

int main() {

    OIntPair element_1 (1, 2);
    OIntPair element_2 (2, 2);
    OIntPair element_3 (2, 1);
    OIntPair element_4 (1, 1);

    std::vector <OIntPair> items {element_1, element_2, element_3, element_4};
    print(items);

    std::sort(items.begin(), items.end());

    print(items);

    return 0;
}
