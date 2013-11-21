/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: ICoffSectionHeader.hpp
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
 *  [ ] Methods are abstract: virtual method() = 0;
 *  [ ] No ctor is defined
 *  [ ] Destructor is not abstract: virtual ~dtor();
 *  [ ] Copy operator is private and undefined: T& operator=(const T &);
 */

#ifndef ICOFFSECTIONHEADER_HPP_
#define ICOFFSECTIONHEADER_HPP_

#include <cstdarg>
#include <string>
#include <memory>

class ICoffSectionHeader
{
public:
typedef std::unique_ptr<ICoffSectionHeader> uptr;
typedef std::shared_ptr<ICoffSectionHeader> sptr;

virtual ~ICoffSectionHeader(){}

virtual std::size_t size(void) const = 0;

virtual std::string toString(void) const = 0;

private:
ICoffSectionHeader & operator=(const ICoffSectionHeader &) = delete;
};

#endif /* ICOFFSECTIONHEADER_HPP_ */
