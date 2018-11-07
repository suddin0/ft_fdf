## Introduction
[FDF](https://fr.wikipedia.org/wiki/Fil_de_fer_%283D%29) (Fil De Fer) also known as [wire-frame](https://en.wikipedia.org/wiki/Wire-frame_model)  is the first project in the graphic branch at [42](http://www.42.fr/) where you must create a 3D wire-frame model of a given [map](https://github.com/suddin0/ft_fdf/tree/master/maps). This project had to use the special graphic library called [mlx](link to the mllx section) as it was required by [42](http://www.42.fr/). You can find more information about this project [here](https://github.com/suddin0/ft_fdf/tree/master/res/subjects).

## Build And Usage
### requirements

 - Linux
	 - [libx11](https://www.x.org/)
	 - [gl](https://www.opengl.org/resources/libraries/)
 - macOS
	 - [cocoa](http://cocoa.dima.unige.it/)
	 - [gl](https://www.opengl.org/resources/libraries/)

### Build
```bash
git clone https://github.com/suddin0/ft_fdf.git fdf
cd fdf
make
```
> Note: This version of `fdf`  has been tested on `linux` and `macOS`

> Compiler used: `clang`, as it is the default compiler at 42 you can change it in [Makefile](https://github.com/suddin0/ft_fdf/blob/master/Makefile#L42)

> Compilation flags: `-Werror`  `-Wall` `-Wextra`	`-lm` `-O3`


###  usage
To execute the the binary `fdf` you must pass a [map](https://github.com/suddin0/ft_fdf/tree/master/maps) in it's argument as such:
`$,/fdf maps/42.fdf`
You can find some maps here  [here](https://github.com/suddin0/ft_fdf/tree/master/maps)

## Map
### maf file
Maps are simple files with the extention `.fdf` that contains numerical values representing the hight if a puint represented in space.


## mlx
`Mini Lib X` is a small library which act as a wrapper some complex high level `gui` more complex and complete library. This library is aims the new comers in `gui` programming, thus the functionality of this library are petty limited. This library was written by **Olivier Crouzet** aka **ol** and it was written for the students of [42](http://www.42.fr/) and [Epitech](http://www.epitech.eu/fr/).

`mlx` is written for `linux` and `macOS`.
 - The version for `Linux` uses `x11` ([X server](https://en.wikipedia.org/wiki/X_Window_System)) and `gl` ([openGL](https://www.opengl.org/resources/libraries/))
 for automate some higher level functionalit such as window management and rendering.
- And the version for macOS it uses [cocoa](http://cocoa.dima.unige.it/) and also `gl`

**mlx** has a lot of limits such as:
-	A window created by `mlx` can not be resized.
 -	 `mlx` provide only one type of font.
 -	Very limited documentations.
 -	No extra function provided for `widgets` nor for drawing anything.
 -	No functions provided to change many window properties once it is rendered (e.g title).

And this is normal, because it is meant to be a easy to use introductory gui library, where the user **must** create everything. So when you are using `mlx` and you want to create a `text area` then you must create the `text area` your self by which i mean you are going to have to manage everything related to that `text area`, such as if it is `active` or `not active` or how should it treat `inputs` ,`outputs`, `color`, `size`, `hidden`,`visible`, etc... This way one can understand in depth how gui programming works.

Basically the following things could be done with **mlx**
 - Create / Destroy Windows.
 - Custom `Tiitle bar` text.
 - Draw colored pixels inside window.
 - Get events (clicks, key presses / release, etc...).
 - A buffer where user can draw and then render the buffer.
 - Update the visible part of window (the inside of the window).
