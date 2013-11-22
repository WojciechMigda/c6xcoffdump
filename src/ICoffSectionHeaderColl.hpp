/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: ICoffSectionHeaderColl.hpp
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
 * 2013-11-21   wm              Initial version
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

#ifndef ICOFFSECTIONHEADERCOLL_HPP_
#define ICOFFSECTIONHEADERCOLL_HPP_

#include "ICoffSectionHeader.hpp"

#include <cstdarg>
#include <string>
#include <memory>
#include <vector>

class ICoffSectionHeaderColl
{
public:
typedef std::size_t                             size_type;
typedef std::unique_ptr<ICoffSectionHeaderColl> uptr;
typedef std::shared_ptr<ICoffSectionHeaderColl> sptr;
typedef std::vector<ICoffSectionHeader::sptr>   coll;

virtual ~ICoffSectionHeaderColl(){}

virtual size_type size(void) const = 0;

virtual std::string toString(void) const = 0;

private:
ICoffSectionHeaderColl & operator=(const ICoffSectionHeaderColl &) = delete;
};

#endif /* ICOFFSECTIONHEADERCOLL_HPP_ */
