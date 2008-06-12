opts = Options()
opts.Add('DESTDIR', 'Directory to install', '')
env = Environment(options=opts)
Help(opts.GenerateHelpText(env))

NAME = "libnss_tartarus"
SUFFIX = ".so.2"
SONAME = NAME + SUFFIX

env['BUILDERS']['Ice'] = Builder(action = 'slice2cpp $SOURCE', src_suffix='.ice', suffix='.cpp')
env["CCFLAGS"] = '-O2 -I. -DDEBUG'
env["SHLIBSUFFIX"] = [SUFFIX + '.0.0']
env["LINKFLAGS"] = ['-Wl,-soname,' + SONAME]

file = env.Ice('SysDB', '/usr/share/Tartarus/slice/SysDB/SysDB.ice')
so = env.SharedLibrary(NAME, ['nss_tartarus_grp.cpp', 'nss_tartarus_pwd.cpp', 'nss_tartarus.cpp', file])

#i = env.Install('$DESTDIR/lib', so)
#env.Alias('install', i)

#if 'install' in COMMAND_LINE_TARGETS:
#        i = env.Command(NAME + '.so', so[0], 'ln -sf %s $DESTDIR/lib/%s' % ( SONAME+'.0.0', SONAME))
#        env.Alias('install', i)

