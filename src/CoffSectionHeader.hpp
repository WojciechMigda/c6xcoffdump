/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: CoffSectionHeader.hpp
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
 *  [x] ctors (only those required) are public
 *  [x] ctors explicitly call interface ctor in the initialisation list
 *  [x] implemented interface methods are private
 *  [x] dtor is virtual
 */

#ifndef COFFSECTIONHEADER_HPP_
#define COFFSECTIONHEADER_HPP_

#include "ICoffSectionHeader.hpp"
#include "TrivialTypeClass.hpp"
#include "IFileObject.hpp"

#include <array>
#include <bitset>

namespace Coff
{

class SectionHeader : public ICoffSectionHeader
{
public:

typedef ICoffSectionHeader::size_type size_type;

static ICoffSectionHeader::uptr fromFileObject(IFileObject::sptr i_file, size_type const i_pos);

~SectionHeader(){}

private:

typedef std::array<std::uint8_t, 8> name_array_type;

TRIVIAL_TYPE(name_array_type, SectionName);
TRIVIAL_TYPE(std::uint32_t, PhysicalAddress);
TRIVIAL_TYPE(std::uint32_t, VirtualAddress);
TRIVIAL_TYPE(std::size_t, SectionSize);
TRIVIAL_TYPE(std::uint32_t, RawDataPtr);
TRIVIAL_TYPE(std::uint32_t, RelocEntriesPtr);
TRIVIAL_TYPE(std::uint32_t, RelocEntriesNum);
TRIVIAL_TYPE(std::bitset<32>, Flags);
TRIVIAL_TYPE(std::uint16_t, MemoryPageNum);

SectionHeader(
    SectionName const           sectionName,
    PhysicalAddress const       physicalAddress,
    VirtualAddress const        virtualAddress,
    SectionSize const           sectionSize,
    RawDataPtr const            rawDataPtr,
    RelocEntriesPtr const       relocEntriesPtr,
    RelocEntriesNum const       relocEntriesNum,
    Flags const                 flags,
    MemoryPageNum const         memoryPageNum
);

std::string toString(void) const;
//std::size_t sectionHeadersNum(void) const;
//std::size_t symbolTableOffset(void) const;
//std::size_t symbolTableEntriesNum(void) const;
//bool hasOptionalHeader(void) const;
size_type size(void) const;

SectionName const           mSectionName;
PhysicalAddress const       mPhysicalAddress;
VirtualAddress const        mVirtualAddress;
SectionSize const           mSectionSize;
RawDataPtr const            mRawDataPtr;
RelocEntriesPtr const       mRelocEntriesPtr;
RelocEntriesNum const       mRelocEntriesNum;
Flags const                 mFlags;
MemoryPageNum const         mMemoryPageNum;

};

}

#endif /* COFFSECTIONHEADER_HPP_ */
