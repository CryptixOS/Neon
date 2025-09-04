/*
 * Created by v1tr10l7 on 02.09.2025.
 * Copyright (c) 2024-2025, Szymon Zemke <v1tr10l7@proton.me>
 *
 * SPDX-License-Identifier: GPL-3
 */
#include <Neon/Filesystem/Filesystem.hpp>

#include <unistd.h>

namespace Neon
{
    namespace Filesystem
    {
        ErrorOr<void> Access(PathView path, FileMode accessMode)
        {
            i32 mode = 0;
            if (accessMode & FileMode::eRead) mode |= R_OK;
            if (accessMode & FileMode::eWrite) mode |= W_OK;
            if (accessMode & FileMode::eExecute) mode |= X_OK;

            i32 status = access(path.Raw(), mode);
            if (!status) return {};

            return Error(errno);
        }
        ErrorOr<void> ChangeDirectory(PathView directory)
        {
            auto err = chdir(directory.Raw());
            if (!err) return {};

            return Error(errno);
        }
    }; // namespace Filesystem
}; // namespace Neon
