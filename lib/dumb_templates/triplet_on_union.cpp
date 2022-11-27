#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <assert.h>

#include "./element_printer.cpp"

// --------------------------------------------------- DECLARATION -----------------------------------------------------

template <typename T0, typename T1, typename T2>
class Triplet
{
private:
    T0 _elem_0;
    T1 _elem_1;
    T2 _elem_2;

    static const std::string _out_of_range_str;
public:
    explicit Triplet() : _elem_0{}, _elem_1{}, _elem_2{} {};
    explicit Triplet(T0 elem_0, T1 elem_1, T2 elem_2) : _elem_0{std::move(elem_0)}, _elem_1{std::move(elem_1)}, _elem_2{std::move(elem_2)} {};

    union TripletElementValue {
        T0 elem_0;
        T1 elem_1;
        T2 elem_2;
        bool is_malformed = true;
    };

    struct TripletElement
    {
        TripletElementValue value;
        int active_field = -1;

        TripletElement() : active_field{-1} {value = TripletElementValue(); value.is_malformed = true;}

        ~TripletElement()
        {
            if (value.is_malformed)
                return; // Will it cause memory leaks?
            switch (active_field) {
                case 0: value.elem_0.~T0(); break;
                case 1: value.elem_1.~T1(); break;
                case 2: value.elem_2.~T2(); break;
            }
        }

        friend std::ostream & operator << (std::ostream &stream, typename Triplet <T0, T1, T2>::TripletElement item)
        {
            assert (-1 <= item.active_field < 3);
            switch (item.active_field) {
                case 0: ElementPrinterClass<T0>::print(stream, item.value.elem_0); break;
                case 1: ElementPrinterClass<T1>::print(stream, item.value.elem_1); break;
                case 2: ElementPrinterClass<T2>::print(stream, item.value.elem_2); break;
            }
            return stream;
        }

    };

    TripletElement operator[](int item);

    friend std::ostream & operator << (std::ostream& stream, Triplet<T0, T1, T2> object)
    {
        stream << "(" << object[0] << ", " << object[1] << ", " << object[2] << ")";
        return stream;
    }

};

template <typename T0, typename T1, typename T2>
const std::string Triplet<T0,T1,T2>::_out_of_range_str {"template Triplet: not supported index: "};

// ------------------------------------------------- IMPLEMENTATION ----------------------------------------------------

template <typename T0, typename T1, typename T2>
std::ostream& operator<< (std::ostream& stream, Triplet<T0, T1, T2>) {
    return stream;
};

template <typename T0, typename T1, typename T2>
typename Triplet<T0, T1, T2>::TripletElement Triplet<T0, T1, T2>::operator[](int item) {
    item = (item>=0) ? (item % 3) : (3 - (item % 3));
    Triplet <T0, T1, T2>::TripletElement result;
    switch (item) {
        case 0: result.value.elem_0 = this->_elem_0; break;
        case 1: result.value.elem_1 = this->_elem_1; break;
        case 2: result.value.elem_2 = this->_elem_2; break;
        default:
            const std::string err_msg = this->_out_of_range_str + std::to_string(item);
            throw std::out_of_range(err_msg);
    };
    result.active_field = item;
    return result;
}


