/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: CoffSectionHeaderColl.cpp
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

#include "CoffSectionHeaderColl.hpp"

#include <cstdarg>
#include <string>

ICoffSectionHeaderColl::uptr Coff::SectionHeaderColl::fromFileObject(IFileObject::sptr i_file, std::size_t const i_hdr_count)
{
    ICoffSectionHeaderColl::coll    coll;

    ICoffSectionHeaderColl * const instance = new Coff::SectionHeaderColl{std::move(coll)};

    ICoffSectionHeaderColl::uptr   result{instance};

    return result;
}

Coff::SectionHeaderColl::SectionHeaderColl(ICoffSectionHeaderColl::coll && i_coll) :
    ICoffSectionHeaderColl(),
    m_coll(std::move(i_coll))
{
    ;
}

std::string Coff::SectionHeaderColl::toString(void) const
{
    return "dupa";
}

std::size_t Coff::SectionHeaderColl::size(void) const
{
    return 0;
}
