/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: main.cpp
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

#include "CoffFile.hpp"
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<Coff::File>   Coff::File::createFromStream(std::cin);

    return 0;
}
