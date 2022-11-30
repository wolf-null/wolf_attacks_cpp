/*
 * Templates used to represent objects of type RepresentedType into a stream OStreamClass.
 */

#include <iostream>

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

// Specialization for std::ostream
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

// ------------------------------------------- BASIC REPRESENTATIONS ---------------------------------------------------


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
