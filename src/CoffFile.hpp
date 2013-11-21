/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: CoffFile.hpp
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
 * 2013-11-02   wm              Initial version
 *
 ******************************************************************************/


#ifndef COFFFILE_HPP_
#define COFFFILE_HPP_

#include "IFileObject.hpp"
#include "ICoffFileHeader.hpp"
#include "ICoffFile.hpp"
#include "ICoffSectionHeaderColl.hpp"

namespace Coff
{

class File : public ICoffFile
{
public:

File(ICoffFileHeader::uptr i_file_header, ICoffSectionHeaderColl::uptr i_section_hdr_coll);
static ICoffFile::uptr fromFileObject(IFileObject::sptr i_file);

private:
std::string toString(void) const;

ICoffFileHeader::uptr           m_file_header;
//std::shared_ptr<OptionalFileHeader>     m_opt_file_header;
ICoffSectionHeaderColl::uptr    m_section_header_coll;
//std::shared_ptr<SectionRawDataColl>     m_section_raw_data_coll;
//std:;shared_ptr<SectionRelocInfoColl>   m_section_reloc_info_coll;
//std::shared_ptr<SectionLineNumbersColl> m_section_line_numbers_coll;
//std::shared_ptr<SymbolTable>            m_symbol_table;
//std::shared_ptr<StringTable>            m_string_table;
};

}


#endif /* COFFFILE_HPP_ */
