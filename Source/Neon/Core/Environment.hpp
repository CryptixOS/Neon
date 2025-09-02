/*
 * Created by v1tr10l7 on 02.09.2025.
 * Copyright (c) 2024-2025, Szymon Zemke <v1tr10l7@proton.me>
 *
 * SPDX-License-Identifier: GPL-3
 */
#pragma once

#include <Prism/String/StringView.hpp>

namespace Neon
{
    namespace Environment
    {
        using namespace Prism;
        StringView Get(StringView name);
        void       Set(StringView name, StringView value);
        void       Overwrite(StringView name, StringView value);
    }; // namespace Environment
}; // namespace Neon
