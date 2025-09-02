/*
 * Created by v1tr10l7 on 02.09.2025.
 * Copyright (c) 2024-2025, Szymon Zemke <v1tr10l7@proton.me>
 *
 * SPDX-License-Identifier: GPL-3
 */
#pragma once

#include <Prism/Utility/PathView.hpp>

namespace Neon
{
    using namespace Prism;
    enum class FileAccessMode : usize
    {
        eNone    = 0,
        eRead    = 1,
        eWrite   = 2,
        eExecute = 3,
    };

    class File
    {
      public:
        static bool Access(Prism::PathView path, FileAccessMode mode);
    };
}; // namespace Neon
