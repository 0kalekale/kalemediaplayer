# kmp - kale's media player

simple media player with gstreamer

## installing/Building

- You need to have gstreamer installed, find the proper packages for your distro
- To build you will need the gstreamer headers, glib headers, gtk headers, meson, ninja and a C compiler

```
git clone https://github.com/0kalekale/kmp
cd kmp
meson build
ninja -C build
```

## usage

- playing a normal video/audio

```
$ kmp [file]
```

- playing a video/audio from http/s

```
$ kmp https://url.to/file
```

- playing from youtube-dl (proper support soon^TM)

```
$ youtube-dl --get-url https://youtu.be/FtutLA63Cp8 | xargs kmp --youtube
```
