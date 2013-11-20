/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: ICoffFile.hpp
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
 * 2013-11-05   wm              Initial version
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

#ifndef ICOFFFILE_HPP_
#define ICOFFFILE_HPP_

#include <string>
#include <memory>

class ICoffFile
{
public:
typedef std::unique_ptr<ICoffFile> uptr;
typedef std::shared_ptr<ICoffFile> sptr;

virtual ~ICoffFile(){}
virtual std::string toString(void) const = 0;

private:
ICoffFile & operator=(const ICoffFile &) = delete;
};

#endif /* ICOFFFILE_HPP_ */
