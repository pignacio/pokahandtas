
release_env = Environment(
    CC='clang',
    CCFLAGS=['-O2'],
)  # yapf: disable

debug_env = release_env.Copy(
    CCFLAGS=['-g', '-fsanitize=address'],
    LINKFLAGS=['-fsanitize=address'],
)  # yapf: disable

SConscript('SConscript',
           variant_dir='build/release',
           duplicate=0,
           exports={'env': release_env})
SConscript('SConscript',
           variant_dir='build/debug',
           duplicate=0,
           exports={'env': debug_env})


# vim: set ft=python :
