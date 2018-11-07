## Introduction
[FDF](https://fr.wikipedia.org/wiki/Fil_de_fer_%283D%29) (Fil De Fer) also known as [wire-frame](https://en.wikipedia.org/wiki/Wire-frame_model)  is the first project in the graphic branch at [42](http://www.42.fr/) where you must create a 3D wire-frame model of a given [map](https://github.com/suddin0/ft_fdf/tree/master/maps). This project had to use the special graphic library called [mlx](https://github.com/suddin0/ft_fdf#mlx) as it was required by [42](http://www.42.fr/). You can find more information about this project [here](https://github.com/suddin0/ft_fdf/tree/master/res/subjects).

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
> git clone https://github.com/suddin0/ft_fdf.git fdf
> cd fdf
> make
```
> Note: This version of `fdf`  has been tested on `linux` and `macOS`

> Compiler used: `clang`, as it is the default compiler at 42 you can change it in [Makefile](https://github.com/suddin0/ft_fdf/blob/master/Makefile#L42)

> Compilation flags: `-Werror`  `-Wall` `-Wextra`	`-lm` `-O3`


###  usage
To execute the the binary `fdf` you must pass a [map](https://github.com/suddin0/ft_fdf/tree/master/maps) in it's argument as such:
```bash
> ./fdf maps/42.fdf
```

You can find some maps here  [here](https://github.com/suddin0/ft_fdf/tree/master/maps)
you can use the following keys once you have a window to manipulate the `map`:


>`ESC` : Quite the program
>`q`     : Quite the program

>`z` :  Rotate in the Z (+) direction
>`a` :  Rotate in the Z (-) direction
>`x` :  Rotate in the X (+) direction
>`s` :  Rotate in the X (-) direction
>`y` :  Rotate in the Y (+) direction
>`u` :  Rotate in the Y (-) direction

>`←` :  Translate (move / slide) the map left
>`→` :  Translate (move / slide) the map right
>`↑` :  Translate (move / slide) the map up
>`↓` :  Translate (move / slide) the map down

>`+` :  Zoom `in`
>`-` :  Zoom `out`

you can select different maps from the `map` menu.
## Map
### map files
Maps are simple files with the extension `.fdf` that contains numerical values representing the height (the `Z` axis) of a point represented in space. If a map contain unsupported data then the map will not be displayed.


### Map representation
The map is pares and the valued received from the `map file` will be used as the height or the `Z` axis value. each number is treated as a point and the value the number represents is treated that point's `Z` axis, so 2 points horizontally (in the same line left to right) will be represented as a line. This horizontal line has a width which has a default value of `30 pixels`, this value is defined in `main.h` as `# define STEP 30.0f`. Much like a horizontal line a vertical line is represented by 2 numbers tat is in the same line but top to bottom and it's height is also represented by the same value `30 pixel` by the same define `# define STEP 30.0f`.

### preview
**Default**
![Default options](https://github.com/suddin0/ft_fdf/raw/master/res/__fdf_exemples__/default.png)
**Map Menu**
![Map Menu](https://github.com/suddin0/ft_fdf/raw/master/res/__fdf_exemples__/menu%20preview.png)
**Error Map**
![Error Map](https://github.com/suddin0/ft_fdf/raw/master/res/__fdf_exemples__/error%20preview.png)

## mlx
`Mini Lib X` is a small library which act as a wrapper some complex high level `gui` more complex and complete library. This library is aims the new comers in `gui` programming, thus the functionality of this library are petty limited. This library was written by **Olivier Crouzet** aka **ol** and it was written for the students of [42](http://www.42.fr/) and [Epitech](http://www.epitech.eu/fr/).

`mlx` is written for `linux` and `macOS`.
 - The version for `Linux` uses `x11` ([X server](https://en.wikipedia.org/wiki/X_Window_System)) and `gl` ([openGL](https://www.opengl.org/resources/libraries/))
 for automate some higher level functionality such as window management and rendering.
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
