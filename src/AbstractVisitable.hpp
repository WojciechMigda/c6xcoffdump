/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the GNU LGPL v3
 *******************************************************************************
 *
 * Filename: AbstractVisitable.hpp
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

#ifndef ABSTRACTVISITABLE_HPP_
#define ABSTRACTVISITABLE_HPP_

#include "IVisitable.hpp"

template <class VisitorT, class DerivedT>
class AbstractVisitable : public IVisitable<VisitorT>
{
public:
virtual typename VisitorT::uptr accept(typename VisitorT::uptr && visitor_p) const
{
    visitor_p->visit(*(static_cast<const DerivedT *>(this)));

    return std::move(visitor_p);
}

protected:
virtual ~AbstractVisitable(){};
};

#endif /* ABSTRACTVISITABLE_HPP_ */
