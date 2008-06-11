opts = Options()
opts.Add('DESTDIR', 'Directory to install', '')
env = Environment(options=opts)
Help(opts.GenerateHelpText(env))

NAME = "libnss_role"
SUFFIX = ".so.2"
SONAME = NAME + SUFFIX

env["CCFLAGS"] = '-O2'
env["SHLIBSUFFIX"] = [SUFFIX + '.0.0']
env["LINKFLAGS"] = ['-Wl,-soname,' + SONAME]

so = env.SharedLibrary(NAME, ['nss_role.cpp'])

i = env.Install('$DESTDIR/lib', so)
env.Alias('install', i)

if 'install' in COMMAND_LINE_TARGETS:
        i = env.Command(NAME + '.so', so[0], 'ln -sf %s $DESTDIR/lib/%s' % ( SONAME+'.0.0', SONAME))
        env.Alias('install', i)
