from os import path
import SCons.Action
import SCons.Builder

def _set_variables(env):
    env['ICE2CPP_INCPREFIX'] = '-I'
    env['ICE2CPP_OUTDIRPREFIX'] = '--output-dir '
    env['ICE2CPP_NULLSTR'] = ''
    env['_ICE2CPP_INCPATH'] = '${_concat(ICE2CPP_INCPREFIX, ICE2CPP_INCPATH, ICE2CPP_NULLSTR, __env__, RDirs)}'
    env['_ICE2CPP_FLAGS'] = '${_concat(ICE2CPP_NULLSTR, ICE2CPP_FLAGS, ICE2CPP_NULLSTR, __env__)}'
    env['_ICE2CPP_OUTDIR'] = '${_concat(ICE2CPP_OUTDIRPREFIX, ICE2CPP_OUTDIR, ICE2CPP_NULLSTR, __env__, RDirs)}'
    env['_ICE2CPP_CMD'] = 'slice2cpp $_ICE2CPP_INCPATH $_ICE2CPP_FLAGS $_ICE2CPP_OUTDIR $SOURCES'

def _emitter(env, target, source):
    srcs = [str(i) for i in source]
    names = [path.splitext(path.basename(i))[0] for i in srcs]
    target = [i+'.cpp' for i in names]
    target += [i+'.h' for i in names]
    if env.has_key('ICE2CPP_OUTDIR'):
        return [path.join(env['ICE2CPP_OUTDIR'], t) for t in target], source
    return target, source

def generate(env):
    _set_variables(env)
    action = SCons.Action.Action('$_ICE2CPP_CMD', '$_ICE2CPP_CMD')
    builder = SCons.Builder.Builder(action=action, src_suffix='.ice', emitter=_emitter)
    env['BUILDERS']['Slice2Cpp'] = builder

def exists(env):
    return env.Detect(['slice2cpp'])
