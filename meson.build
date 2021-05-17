project('kmp', 'c',
    license : 'GPLv3',
    version : '0.1')
incdir = include_directories('include')
gst = dependency('gstreamer-1.0')
glib = dependency('glib-2.0')
gtk3 = dependency('gtk+-3.0')
gstvideo = dependency('gstreamer-video-1.0')
python3 = dependency('python3')
python3_embed = dependency('python3-embed')
kmp_source = [
		   'src/main.c',
		   'src/kmp.c',
		   'src/argparse.c',
		   'src/av_fork.c',
		   'src/gtk-ui.c',
		   'src/youtube_dl.c'	
]
executable('kmp', kmp_source, dependencies : [gst, glib, gtk3, gstvideo, python3, python3_embed], include_directories : incdir,install : true)
