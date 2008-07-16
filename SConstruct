from subprocess import Popen, PIPE

opts = Options()
opts.Add('DESTDIR', 'Directory to install', '')
env = Environment(options=opts)
Help(opts.GenerateHelpText(env))

NAME = "libnss_tartarus"
SUFFIX = ".so.2"
SONAME = NAME + SUFFIX

env['BUILDERS']['Ice'] = Builder(action = 'slice2cpp $SOURCE', src_suffix='.ice', suffix='.cpp')
env["CCFLAGS"] = ['-O2', '-DDEBUG']
env['CPPPATH'] = ['.']
env["LIBS"] = ['-lIce']

file = env.Ice('SysDB', '/usr/share/Tartarus/slice/SysDB/SysDB.ice')

libenv = env.Clone();
libenv["SHLIBSUFFIX"] = [SUFFIX + '.0.0']
libenv["LINKFLAGS"] = ['-Wl,-soname,' + SONAME]

env["CCFLAGS"] += Popen(["/usr/bin/krb5-config", "--cflags"], stdout=PIPE).communicate()[0].split()
env["LIBS"] += Popen(["/usr/bin/krb5-config", "--libs"], stdout=PIPE).communicate()[0].split()

tnscd = env.Program('tnscd', ['TartarusNSCD.cpp', 'TartarusNSCDInit.cpp', 'TartarusNSCDKinit.cpp', 'TartarusSysDB.cpp', 'SysDBI.cpp', file])

so = libenv.SharedLibrary(NAME, ['TartarusNSCDInit.cpp', 'nss_tartarus_grp.cpp', 'nss_tartarus_pwd.cpp', 'nss_tartarus.cpp', file])

i = libenv.Install('$DESTDIR/lib', so)
libenv.Alias('install', i)
i = env.Install('$DESTDIR/usr/sbin', tnscd)
env.Alias('install', i)

if 'install' in COMMAND_LINE_TARGETS:
#        i = libenv.Command(NAME + '.so', so[0], 'ln -sf $SOURCE $TARGET' SONAME+'.0.0', SONAME))
        i = libenv.Command(NAME + '.so', so[0], 'ln -sf $SOURCE $TARGET')
        libenv.Alias('install', i)

