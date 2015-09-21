
release_env = Environment(
    CC='clang',
    CCFLAGS=[
        '-Wall',
        '-fcolor-diagnostics',
        '-O2',
    ],
)  # yapf: disable

debug_env = release_env.Copy(
    CCFLAGS=[
        '-Wall',
        '-g',
        '-fsanitize=address',
        '-fcolor-diagnostics',
    ],
    LINKFLAGS=[
        '-fsanitize=address',
    ],
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
