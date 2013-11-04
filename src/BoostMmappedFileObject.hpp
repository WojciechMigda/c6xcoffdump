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
#include <cstdint>
#include <string>
#include <cstddef>
#include <memory>

class BoostMmappedFileObject : public IFileObject
{
public:
static std::shared_ptr<BoostMmappedFileObject> fromPath(const std::string & in_path);
virtual ~BoostMmappedFileObject();

private:
BoostMmappedFileObject(boost::iostreams::mapped_file_source & in_file);

//virtual const std::uint8_t * data(void) const;
virtual std::size_t size(void) const;
virtual std::uint8_t at(const std::size_t pos) const;

boost::iostreams::mapped_file_source    m_file;
};

#endif /* BOOSTMMAPPEDFILEOBJECT_HPP_ */
