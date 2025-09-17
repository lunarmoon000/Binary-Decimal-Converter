# Binary-Decimal-Converter

![main_gif](https://media1.tenor.com/m/LhIRX8QqRj0AAAAC/futurama-fry.gif)
## General Description
A Binary to Decimal conversion program coded in C.
## Instructions
download the python file gcd.py, run it on your terminal and you will see this:

download the C file to_decimal.c, and write this onto your terminal once you change your directory to where the C file has ended up in:

```
gcc to_decimal.c -o to_decimal -lm
```
> Note: If you are on Windows, WSL is reccomended.

this generates a new binary file called to_decimal, to run the program you type this and press enter:

```
./to_decimal
```

Once the program is running, you will see this:

```
Welcome to Binary to Decimal Converter

Enter -1 to exit,
Insert a binary number:
```

The program will run indefinitley until you press -1 or if you enter a number that is beyond 31 digits long.

Here are the list of invalid inputs:
* anything not numerical (e.g. 'a')
* any number that isn't just '1' or '0'
* any number that is more than 31 digits long (due to limitations of the int data type, this may be changed later on if a different data type is used)

invalid input aside from the beyond 31 ones will not stop the running of the program, it will simply prompt you to try again. Currently an input of greater than 31 digits ends the program to avoid issues with leftover values in the input stream (stdin) in subsequent loops. This may be changed such that the program keeps going if the input stream issue is resolved in subsequent updates.