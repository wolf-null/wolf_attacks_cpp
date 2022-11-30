/*
 * The idea was to face some basic template and inheritance functionality by implementing a Triplet object, (which is
 * like a Tuple but with three elements).
 */

#include <iostream>
#include <string>

#include "abstract_representation.cpp"

template <class Type0, class Type1, class Type2>
class Triplet
{
protected:
    Type0 item_0_;
    Type1 item_1_;
    Type2 item_2_;

public:
    Triplet(Type0 item_0, Type1 item_1, Type2 item_2) : item_0_{item_0}, item_1_{item_1}, item_2_{item_2} {};

    Type0& link_get_0(){return item_0_; }
    Type1& link_get_1(){return item_1_; }
    Type2& link_get_2(){return item_2_; }

    // A template of nested class used for the represented Triplet
    template <template <class> class ReprModel0, template <class> class ReprModel1, template <class> class ReprModel2>
    class Repr : public Triplet<Type0, Type1, Type2>
    {
        typedef ReprModel0 <Type0> Repr_0_;
        typedef ReprModel1 <Type1> Repr_1_;
        typedef ReprModel2 <Type2> Repr_2_;

        Repr_0_ repr_0_;
        Repr_1_ repr_1_;
        Repr_2_ repr_2_;

    public:
        Repr(Type0 item_0, Type1 item_1, Type2 item_2) : repr_0_{}, repr_1_{}, repr_2_{}, Triplet<Type0, Type1, Type2> (item_0, item_1, item_2) {};

        friend std::ostream& operator << (std::ostream& stream, Triplet<Type0, Type1, Type2>::Repr<ReprModel0, ReprModel1, ReprModel2> & obj)
        {
            stream << '(';
            obj.repr_0_.represent(stream, obj.link_get_0());
            stream << ", ";
            obj.repr_1_.represent(stream, obj.link_get_1());
            stream << ", ";
            obj.repr_2_.represent(stream, obj.link_get_2());
            stream << ')';
            return stream;
        }
    };
};
