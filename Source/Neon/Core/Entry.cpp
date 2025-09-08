/*
 * Created by v1tr10l7 on 02.09.2025.
 * Copyright (c) 2024-2025, Szymon Zemke <v1tr10l7@proton.me>
 *
 * SPDX-License-Identifier: GPL-3
 */
#include <Prism/Containers/Vector.hpp>
#include <Prism/Core/Error.hpp>
#include <Prism/Core/Types.hpp>
#include <Prism/String/StringView.hpp>

using namespace Prism;

extern ErrorOr<void> NeonMain(const Vector<StringView>& argv,
                              const Vector<StringView>& envp);
int                  main(int argc, char** argv, char** envp)
{
    Vector<StringView> argArr;
    Vector<StringView> envArr;
    for (isize i = 0; i < argc && argv[i]; i++) argArr.EmplaceBack(argv[i]);
    for (usize i = 0; envp[i]; i++) envArr.EmplaceBack(envp[i]);

    auto status = NeonMain(argArr, envArr);
    if (!status) return status.Error();

    return 0;
}
