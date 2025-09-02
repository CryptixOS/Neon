/*
 * Created by v1tr10l7 on 02.09.2025.
 * Copyright (c) 2024-2025, Szymon Zemke <v1tr10l7@proton.me>
 *
 * SPDX-License-Identifier: GPL-3
 */
#include <Neon/Core/Environment.hpp>

namespace Neon
{
    namespace Environment
    {
        StringView Get(StringView name) { return getenv(name.Raw()); }
        void       Set(StringView name, StringView value)
        {
            setenv(name.Raw(), value.Raw(), false);
        }
        void Overwrite(StringView name, StringView value)
        {
            setenv(name.Raw(), value.Raw(), true);
        }
    }; // namespace Environment
}; // namespace Neon
