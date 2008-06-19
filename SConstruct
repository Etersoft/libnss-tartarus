opts = Options()
opts.Add('DESTDIR', 'Directory to install', '')
env = Environment(options=opts)
Help(opts.GenerateHelpText(env))

NAME = "libnss_tartarus"
SUFFIX = ".so.2"
SONAME = NAME + SUFFIX

env['BUILDERS']['Ice'] = Builder(action = 'slice2cpp $SOURCE', src_suffix='.ice', suffix='.cpp')
env["CCFLAGS"] = '-O2 -I. -DDEBUG'
env["LIBS"] = ['-lIce']

file = env.Ice('SysDB', '/usr/share/Tartarus/slice/SysDB/SysDB.ice')

tnscd = env.Program('tnscd', ['TartarusNSCD.cpp', 'TartarusNSCDInit.cpp', 'TartarusSysDB.cpp', 'SysDBI.cpp', file])

libenv = env.Clone();
libenv["SHLIBSUFFIX"] = [SUFFIX + '.0.0']
libenv["LINKFLAGS"] = ['-Wl,-soname,' + SONAME]

so = libenv.SharedLibrary(NAME, ['TartarusNSCDInit.cpp', 'nss_tartarus_grp.cpp', 'nss_tartarus_pwd.cpp', 'nss_tartarus.cpp', file])

i = libenv.Install('$DESTDIR/lib', so)
libenv.Alias('install', i)

if 'install' in COMMAND_LINE_TARGETS:
        i = libenv.Command(NAME + '.so', so[0], 'ln -sf %s $DESTDIR/lib/%s' % ( SONAME+'.0.0', SONAME))
        libenv.Alias('install', i)

