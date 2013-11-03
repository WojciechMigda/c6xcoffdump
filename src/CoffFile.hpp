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

#include <istream>
#include <algorithm>
#include <memory>

namespace Coff
{

class FileHeader
{

};

class File
{
public:
    static std::shared_ptr<File> createFromStream(std::istream & in_stream);

    File(std::unique_ptr<FileHeader> in_file_header);
private:
std::shared_ptr<FileHeader>             m_file_header;
//std::shared_ptr<OptionalFileHeader>     m_opt_file_header;
//std::shared_ptr<SectionHeaderColl>      m_section_header_coll;
//std::shared_ptr<SectionRawDataColl>     m_section_raw_data_coll;
//std:;shared_ptr<SectionRelocInfoColl>   m_section_reloc_info_coll;
//std::shared_ptr<SectionLineNumbersColl> m_section_line_numbers_coll;
//std::shared_ptr<SymbolTable>            m_symbol_table;
//std::shared_ptr<StringTable>            m_string_table;
};

}


#endif /* COFFFILE_HPP_ */
