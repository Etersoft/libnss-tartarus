from glob import glob
from subprocess import Popen, PIPE

opts = Options()
opts.Add('DESTDIR', 'Directory to install', '')
env = Environment(options=opts)
Help(opts.GenerateHelpText(env))

NAME = "libnss_tartarus"
SUFFIX = ".so.2"
SONAME = NAME + SUFFIX

env['BUILDERS']['Ice'] = Builder(action = 'slice2cpp $SOURCE', src_suffix='.ice', suffix='.cpp')
env['CCFLAGS'] = ['-O2']
env['CPPPATH'] = ['.']
env['LIBS'] = ['pthread']

if 'DEBUG' in ARGUMENTS and ARGUMENTS['DEBUG'] == 'yes':
    env['CPPFLAGS'] = '-DDEBUG'

libenv = env.Clone();
libenv["SHLIBSUFFIX"] = [SUFFIX + '.0.0']
libenv["LINKFLAGS"] = ['-Wl,-soname,' + SONAME]

#Export('env')
#Export('libenv')
#json_spirit = SConscript('json_spirit/SConscript')

env['LIBS'] += ['Ice']
ice = env.Ice('SysDB', '/usr/share/Tartarus/slice/SysDB/SysDB.ice')

env['CCFLAGS'] += Popen(["/usr/bin/krb5-config", "--cflags"], stdout=PIPE).communicate()[0].split()
env['LIBS'] += Popen(["/usr/bin/krb5-config", "--libs"], stdout=PIPE).communicate()[0].split()

tnscd = env.Program('tnscd', ['TartarusNSCD.cpp', 'TartarusNSCDInit.cpp', 'TartarusNSCDKinit.cpp', 'TartarusServer.cpp', 'TartarusServerI.cpp', 'TartarusSysDB.cpp', 'boost_error_code.cpp', 'TartarusDebug.cpp', glob('json_spirit/*.cpp'), ice])

so = libenv.SharedLibrary(NAME, ['TartarusNSCDInit.cpp', 'nss_tartarus_grp.cpp', 'nss_tartarus_pwd.cpp', 'TartarusClient.cpp', 'TartarusClientI.cpp', 'boost_error_code.cpp', 'TartarusDebug.cpp', glob('json_spirit/*.cpp')])

i = libenv.Install('$DESTDIR/lib', so)
libenv.Alias('install', i)
i = env.Install('$DESTDIR/usr/sbin', tnscd)
env.Alias('install', i)

if 'install' in COMMAND_LINE_TARGETS:
#        i = libenv.Command(NAME + '.so', so[0], 'ln -sf $SOURCE $TARGET' SONAME+'.0.0', SONAME))
        i = libenv.Command(NAME + '.so', so[0], 'ln -sf $SOURCE $TARGET')
        libenv.Alias('install', i)

