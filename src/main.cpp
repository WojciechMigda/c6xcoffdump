/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: main.cpp
 *
 * Description:
 *      description
 *
 * Authors:
 *          Wojciech Migda (wm)
 *
 *******************************************************************************
 * History:
 * --------
 * Date         Who  Ticket     Description
 * ----------   ---  ---------  ------------------------------------------------
 * 2013-11-02   wm              Initial version
 *
 ******************************************************************************/

#include "CoffFile.hpp"
#include "IFileObject.hpp"
#include "ICoffFile.hpp"
#include "FileObjectFactory.hpp"

#include <iostream>

int main()
{
    IFileObject::sptr   file_object = createFileObject("sample.obj");

    ICoffFile::uptr   file = Coff::File::fromFileObject(file_object, 0);

    std::cout << file->toString() << std::endl;

    {
        extern void dupa();
        dupa();
    }

    return 0;
}

//////////////////////////////////////////

#include "AbstractVisitable.hpp"
#include "TrivialTypeClass.hpp"

struct TextNode;
struct ImageNode;

struct Visitor
{
typedef std::unique_ptr<Visitor> uptr;

    void visit(const TextNode& textNode) const { std::cout<<"TextNode."<<std::endl; }
    void visit(const ImageNode& imageNode) const { std::cout<<"ImageNode."<<std::endl; }
};

struct TextNode : public AbstractVisitable<Visitor, TextNode> {}; // CRTP
struct ImageNode : public AbstractVisitable<Visitor, ImageNode> {}; // CRTP

template<typename _Tp, unsigned long long _uniqId>
class TrivialTypeMixin : public AbstractVisitable<Visitor, TrivialTypeMixin<_Tp, _uniqId>>
{
public:
    typedef _Tp type;
//    static_assert(std::is_trivial<_Tp>::value == true, "template argument must be a trivial type");

    constexpr TrivialTypeMixin() = default;
    constexpr TrivialTypeMixin(const type & value) : m_value(value){}
    operator type &(){return m_value;}
    operator type const &() const {return m_value;}
private:
    type    m_value;
};

typedef TrivialType<int, (unsigned long long)("Dude"_hash)> Dude;
//typedef TrivialTypeMixin<int, (unsigned long long)("Dude2"_hash), AbstractVisitable<Visitor, TrivialTypeMixin>> Dude2;

void dupa()
{
    TextNode textNode;

    ImageNode imageNode;

    Visitor::uptr visitor(new Visitor);

    IVisitable<Visitor> *visitable = &textNode;

    visitor = visitable->accept(std::move(visitor)); // TextNode.

    visitable = &imageNode;

    visitor = visitable->accept(std::move(visitor)); // ImageNode.

}