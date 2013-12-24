/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the GNU LGPL v3
 *******************************************************************************
 *
 * Filename: IVisitable.hpp
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

/*
 *  Interface class Checklist:
 *  ==========================
 *  [x] Methods are abstract: virtual method() = 0;
 *  [x] No ctor is defined
 *  [x] Destructor is not abstract: virtual ~dtor();
 *  [x] Copy operator is private and undefined: T& operator=(const T &);
 */

#ifndef IVISITABLE_HPP_
#define IVISITABLE_HPP_

template <class VisitorT>
class IVisitable
{
public:
virtual typename VisitorT::uptr accept(typename VisitorT::uptr && visitor) const = 0;
virtual ~IVisitable(){}

private:
IVisitable & operator=(const IVisitable &);
};

#endif /* IVISITABLE_HPP_ */
