/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: CoffSectionHeaderColl.hpp
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
 *  Implementation class Checklist:
 *  ===============================
 *  [ ] ctors (only those required) are public
 *  [ ] ctors explicitly call interface ctor in the initialisation list
 *  [ ] implemented interface methods are private
 *  [ ] dtor is virtual
 */

#ifndef COFFSECTIONHEADERCOLL_HPP_
#define COFFSECTIONHEADERCOLL_HPP_

#include "ICoffSectionHeaderColl.hpp"
#include "ICoffSectionHeader.hpp"
#include "IFileObject.hpp"

#include <vector>
#include <string>
#include <cstdarg>

namespace Coff
{

class SectionHeaderColl : public ICoffSectionHeaderColl
{
public:

SectionHeaderColl(ICoffSectionHeaderColl::coll && i_coll);
static ICoffSectionHeaderColl::uptr fromFileObject(IFileObject::sptr i_file, std::size_t const i_hdr_count);

private:
std::string toString(void) const;
std::size_t size(void) const;

ICoffSectionHeaderColl::coll    m_coll;

};

}

#endif /* COFFSECTIONHEADERCOLL_HPP_ */
