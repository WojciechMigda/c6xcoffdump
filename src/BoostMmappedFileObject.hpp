/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: BoostMmappedFileObject.hpp
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
 * 2013-11-03   wm              Initial version
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

#ifndef BOOSTMMAPPEDFILEOBJECT_HPP_
#define BOOSTMMAPPEDFILEOBJECT_HPP_

#include "boost/iostreams/device/mapped_file.hpp"

#include"IFileObject.hpp"
#include <string>

class BoostMmappedFileObject : public IFileObject
{
public:
typedef IFileObject::size_type  size_type;
typedef IFileObject::byte_type  byte_type;
typedef IFileObject::byte_ptr   byte_ptr;
typedef byte_type const *       cbyte_ptr;

static IFileObject::uptr fromPath(const std::string & in_path);
virtual ~BoostMmappedFileObject();

private:
BoostMmappedFileObject(boost::iostreams::mapped_file_source & in_file);

cbyte_ptr data(void) const;
virtual size_type size(void) const;
virtual byte_type at(size_type const pos) const;
virtual size_type read(byte_ptr const o_buf, size_type const i_size, size_type const i_offset) const;

boost::iostreams::mapped_file_source    m_file;
};

#endif /* BOOSTMMAPPEDFILEOBJECT_HPP_ */
