#include <iostream>

template <typename TX>
struct ElementPrinterClass
{
    static void print(std::ostream &stream, TX item) {
        stream << item;
    }
};

template <typename TX>
struct ElementPrinterClass <TX*>
{
    static void print(std::ostream &stream, TX *item) {
        stream << *item;
    }
};

template <>
struct ElementPrinterClass <char*>
{
    static void print(std::ostream &stream, char *item) {
        stream << item;
    }
};

