/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the GNU LGPL v3
 *******************************************************************************
 *
 * Filename: VisitableTrivialType.hpp
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
 * Dec 2, 2013   wm              Initial version
 *
 ******************************************************************************/


#ifndef VISITABLETRIVIALTYPE_HPP_
#define VISITABLETRIVIALTYPE_HPP_

#include "StaticStringHash.hpp"
#include <type_traits>

template<typename _Tp, unsigned long long _uniqId, class VisitorT>
class VisitableTrivialType
{
public:
    typedef _Tp type;
//    static_assert(std::is_trivial<_Tp>::value == true, "template argument must be a trivial type");

    constexpr VisitableTrivialType() = default;
    constexpr VisitableTrivialType(const type & value) : m_value(value){}
    operator type &(){return m_value;}
    operator type const &() const {return m_value;}
private:
    type    m_value;
};

#define VISITABLE_TRIVIAL_TYPE(type, name, visitor) typedef VisitableTrivialType<type, (unsigned long long)(#name##_hash), visitor> name

#endif /* VISITABLETRIVIALTYPE_HPP_ */
