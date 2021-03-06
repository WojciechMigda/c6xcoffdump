/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: CoffFileHeader.hpp
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
 * 2013-11-04   wm              Initial version
 *
 ******************************************************************************/


#ifndef COFFFILEHEADER_HPP_
#define COFFFILEHEADER_HPP_

#include "TrivialTypeClass.hpp"

#include "IFileObject.hpp"
#include "ICoffFileHeader.hpp"

#include <string>
#include <bitset>

namespace Coff
{

class FileHeader : public ICoffFileHeader
{
public:
typedef ICoffFileHeader::size_type size_type;

static ICoffFileHeader::uptr fromFileObject(IFileObject::sptr i_file, size_type const i_pos);

~FileHeader(){}

private:

TRIVIAL_TYPE(std::uint16_t,     VersionId);
TRIVIAL_TYPE(std::size_t,       SectionHeadersNum);
TRIVIAL_TYPE(std::uint32_t,     DateTimeStamp);
TRIVIAL_TYPE(std::size_t,       SymbolTableOffset);
TRIVIAL_TYPE(std::size_t,       SymbolTableEntriesNum);
TRIVIAL_TYPE(std::size_t,       OptionalHeaderSize);
TRIVIAL_TYPE(std::bitset<16>,   Flags);
TRIVIAL_TYPE(std::uint16_t,     TargetId);


FileHeader(
    VersionId const             versionId,
    SectionHeadersNum const     sectionHeadersNum,
    DateTimeStamp const         dateTimeStamp,
    SymbolTableOffset const     symbolTableOffset,
    SymbolTableEntriesNum const symbolTableEntriesNum,
    OptionalHeaderSize const    optionalHeaderSize,
    Flags const                 flags,
    TargetId                    targetId
    );

std::string toString(void) const;
size_type sectionHeadersNum(void) const;
size_type symbolTableOffset(void) const;
size_type symbolTableEntriesNum(void) const;
bool hasOptionalHeader(void) const;
size_type size(void) const;

VersionId const             mVersionId;
SectionHeadersNum const     mSectionHeadersNum;
DateTimeStamp const         mDateTimeStamp;
SymbolTableOffset const     mSymbolTableOffset;
SymbolTableEntriesNum const mSymbolTableEntriesNum;
OptionalHeaderSize const    mOptionalHeaderSize;
Flags const                 mFlags;
TargetId const              mTargetId;

};

}

#endif /* COFFFILEHEADER_HPP_ */
