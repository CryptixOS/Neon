/*
 * Created by v1tr10l7 on 02.09.2025.
 * Copyright (c) 2024-2025, Szymon Zemke <v1tr10l7@proton.me>
 *
 * SPDX-License-Identifier: GPL-3
 */
#pragma once

#include <Prism/Core/Core.hpp>
#include <Prism/Core/Error.hpp>
#include <Prism/Utility/PathView.hpp>

namespace Neon
{
    enum class FileMode : Prism::usize
    {
        eNone    = 0,
        eRead    = 1,
        eWrite   = 2,
        eExecute = 4,
    };
    constexpr FileMode operator|=(FileMode& lhs, FileMode rhs)
    {
        return lhs = static_cast<FileMode>(Prism::ToUnderlying(lhs)
                                           | Prism::ToUnderlying(rhs)),
               lhs;
    }
    constexpr bool operator&(FileMode lhs, FileMode rhs)
    {
        return Prism::ToUnderlying(lhs) & Prism::ToUnderlying(rhs);
    }

    namespace VFS
    {
        using namespace Prism;
        ErrorOr<void> Access(PathView path, FileMode mode);
        ErrorOr<void> ChangeDirectory(PathView directory);
    }; // namespace VFS
}; // namespace Neon
