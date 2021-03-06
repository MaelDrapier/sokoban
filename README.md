# sokoban
This project was one of my first projects from my first year at EPITECH (2016-2017)

The goal was to create a copy of the [sokoban](https://en.wikipedia.org/wiki/Sokoban) game in terminal mode, using the [ncurses](https://www.gnu.org/software/ncurses/) library.

<br>

Language: **C**

Group size: **1**

Compilation: **on GNU/Linux via Makefile**

Project duration: **~2 weeks** (05/12/2016 - 20/12/2016)

#### Required library: [ncurses](https://www.gnu.org/software/ncurses/)
To install it:
* on Debian / Ubuntu:
`sudo apt-get install libncurses5-dev libncursesw5-dev`
* on Arch Linux:
`sudo pacman -S ncurses`
* on Fedora:
`sudo dnf install ncurses-devel`
* on other distributions, download it on `ftp://ftp.gnu.org/gnu/ncurses/`

<br>

## Usage
```
./my_sokoban -h
USAGE
		./my_sokoban map.txt
DESCRIPTION
map.txt		File representing the warehouse map, containing '#' for walls,
		'P' for the player, 'X' for boxes and 'O' for storage locations.
HOW TO PLAY
		Press 'ZQSD' keys to move, -SPACE- to reset the game and 'Q' to quit.
		Push all the boxes on storage locations to win.
AUTHOR
		Made by Mael Drapier
```

## Authorized functions for this project:

* malloc, free, exit
* (f)open, (f)close, (f)read, (f)write
* getline, ioctl, usleep, sigaction, signal
* Every functions from the [ncurses](https://www.gnu.org/software/ncurses/) library

## Screenshots

<p align="center">
  <img src="screenshots/screenshot1.png">
</p>

<p align="center">
  <img src="screenshots/screenshot2.png">
</p>

<p align="center">
  <img src="screenshots/screenshot3.png">
</p>
