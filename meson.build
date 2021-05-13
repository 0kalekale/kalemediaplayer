project('kmp', 'c')
incdir = include_directories('include')
gst = dependency('gstreamer-1.0')

kmp_source = [
		   'src/main.c',
		   'src/kmp.c',
		   'src/argparse.c'
]
executable('kmp', kmp_source, dependencies : gst, include_directories : incdir,)
