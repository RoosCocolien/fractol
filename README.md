# fractol

## Codam Coding College Fractol

![Screen Shot 2021-06-29 at 20 36 01](https://user-images.githubusercontent.com/28932387/123850970-efc56400-d91a-11eb-926f-9023c6619a40.png)


### Description
fract'ol is a program written in C that displays a fractal of the users choice. The program allows the user to manipulate the displayed fractal and change between the four different fractals handled by the program as instructed by a user interface. The fractals available for this project are Mandelbrot, Julia, Burning Ship and Mandelbrot.
The purpose of this project was to gain a better understanding of miniLibX library, to discover and use the mathematical notion of complex numbers, and to take a peak at the concept of optimzation in computer graphics through multithreading.

This program was written on LinuxOS and complies with a Makefile.

#### Installation
From terminal, the program can be install with git clone from the repository followed by name of directory you wish to download repository to.

#### Example

<code>
$ git clone https://github.com/RoosCocolien/fractol.git [prefered-name]
</code>

### Usage
In terminal, go into the project directory. This program uses a makefile to compile. To compile, run:

<code>
$ make
</code>

The executable name is fractol. To run, chose one of the four optional fractal as a parameter. Run program with:

<code>
$ ./fractol [name-of-desire-fractol]
</code>

### Example:

<code>
$ ./fractol Julia
</code>

If incorrect fractal is name, a usage error will but given. The user interface provides information for the use and exit of the program.

To delete all object files from directory, run:

<code>
$ make clean
</code>

To delete executable from directory, run:

<code>
$ make fclean
</code>

### Fractals:

#### Madelbrot
![Screen Shot 2021-06-29 at 20 35 11](https://user-images.githubusercontent.com/28932387/123851008-fd7ae980-d91a-11eb-8970-501be4a2df57.png)

#### Julia
![Screen Shot 2021-06-29 at 20 34 35](https://user-images.githubusercontent.com/28932387/123851034-08357e80-d91b-11eb-8d2d-eb10bedad39f.png)

