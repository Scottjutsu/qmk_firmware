# Overview

This is my personal userspace file.  This file allows me to share code between different keyboard configurations.

QMK automatically includes the `rules.mk` here _after_ the `rules.mk` from the keymap. 
> This allows you to have features in your userspace rules.mk that depend on individual QMK features that may or may not be available on a specific keyboard.  

`rules.mk` includes `scottjutsu.c` which includes `scottjutsu.h`.

Additionally, QMK processes the `config.h` here like the same file in the keymap folder. Note that including the `<name>.h` file in any `config.h` files will result in compile issues because it is not added in time.
> You should use the config.h for configuration options, and the \<name>.h file for user or keymap specific settings (such as the enum for layer or keycodes).  

Thanks to drashna for the well-documented userfiles, on which this is based.