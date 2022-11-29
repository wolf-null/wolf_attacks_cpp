//
// Created by Mann on 29.11.2022.
//

#include <iostream>
#include <string>

template <class OStreamClass, class RepresentedType>
class AbstractRepresentation
{
public:
    virtual void represent(OStreamClass & stream, RepresentedType & object) = 0;
    AbstractRepresentation() = default;
    friend OStreamClass& operator << (OStreamClass & steam, RepresentedType & object)
    {
        return object.represent(steam, object);
    }
};

template <class RepresentedType>
class AbstractRepresentation <std::ostream , RepresentedType>
{
public:
    AbstractRepresentation() = default;
    virtual void represent(std::ostream & stream, RepresentedType & object) = 0;

    friend std::ostream& operator << (std::ostream & steam, RepresentedType & object)
    {
        return object.represent(steam, object);
    }
};

template <class Type0, class Type1, class Type2>
class Triplet
{
private:
    Type0 item_0_;
    Type1 item_1_;
    Type2 item_2_;

public:
    typedef AbstractRepresentation<std::ostream , Type0> AbstReprModel0;
    typedef AbstractRepresentation<std::ostream , Type1> AbstReprModel1;
    typedef AbstractRepresentation<std::ostream , Type2> AbstReprModel2;

    Triplet(Type0 item_0, Type1 item_1, Type2 item_2) : item_0_{item_0}, item_1_{item_1}, item_2_{item_2} {};

    template<template <class , class> class ReprModel0, template <class , class> class ReprModel1, template <class , class> class ReprModel2>
    struct Repr
    {
        ReprModel0 <std::ostream, Type0> repr_0_;
        ReprModel1 <std::ostream, Type1> repr_1_;
        ReprModel2 <std::ostream, Type2> repr_2_;

        Repr(ReprModel0 <std::ostream, Type0> item_0, ReprModel0 <std::ostream, Type1> item_1, ReprModel0 <std::ostream, Type2> item_2) : repr_0_{}, repr_1_{}, repr_2_{} {};

        friend std::ostream& operator << (std::ostream& stream, Triplet<Type0, Type1, Type2>::Repr<ReprModel0, ReprModel1, ReprModel2> & obj)
        {
            stream << '(';
            obj.repr_0_.represent(stream, obj.repr_0_);
            stream << ", ";
            obj.repr_1_.represent(stream, obj.repr_1_);
            stream << ", ";
            obj.repr_2_.represent(stream, obj.repr_2_);
            stream << ')';
            return stream;
        }
    };
};

template <class RepresentedType>
class BasicRepresentation : public AbstractRepresentation <std::ostream , RepresentedType>
{
public:
    void represent(std::ostream & stream, RepresentedType & object) override
    {
        stream << object;
    }
};

template <>
class BasicRepresentation <std::string> : public AbstractRepresentation <std::ostream , std::string>
{
public:
    void represent(std::ostream & stream, std::string & object) override
    {
        stream << '"' << object << '"';
    }
};
