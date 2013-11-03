/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: FileObjectFactory.hpp
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

#ifndef FILEOBJECTFACTORY_HPP_
#define FILEOBJECTFACTORY_HPP_

#include "IFileObject.hpp"
#include <memory>
#include <string>

std::shared_ptr<IFileObject> createFileObject(const std::string & in_path);

#endif /* FILEOBJECTFACTORY_HPP_ */
