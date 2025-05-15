## Savannah Sesum (UMBC/313/10-11:15am, Mon/Wed 8:44PM 5-14-25)
### Purpose of Software -------- 
In assembly, convert the given hex values, 0x83,0x6A,0x88,0xDE,0x9A,0xC3,0x54,0x9A into their ASCII equivalent. Then,
print the ASCII so that the result is "83 61 88 DE 9A C3 54 9A" with a trailing \n

### Files --------
**README.md -** The file that explains this submission for HW 11 <br>
**AsciiTranslation -** The file that contains the assembly that'll convert hex to ASCII

### Build Instructions --------
After downloading all files in the hw11 directory, do this for the .asm file to compile: <br>
nasm -f elf32 -g -F dwarf -o AsciiTranslation.o AsciiTranslation.asm

And then, to link, do this: <br>
ld -m elf_i386 -o AsciiTranslation AsciiTranslation.o

Upon completion of compiling and linking, run by doing: <br>
./AsciiTranslation

### Testing Methodology --------
I first asked Prof. Kidd in class to get an introduction to the type of coding I'd be dealing with. <br>
He introduced the method of masking by doing "and 0xF0/0x0F" to get the lower and higher bit from the hex value, and then converting it
to ASCII while still maintaining the lower and higher positions. <br>
Realizing that a hefty amount was based on memory control and knowing where your iterators were, I made sure to 
draw a visual to help guide me through the work. <br>
Beforehand, I did the hex -> ASCII correctly by googling to affirm my calculations. <br>
Knowing that I got the conversions correctly, I tested the "if-statement" of 0-9 and 10-15 hex values since you'd need to add <br>
0x30 or 0x37 depending on which threshold the hex value matched. Afterwards, I was fully set on the hex -> ASCII so <br>
the remainding testing was the printing of the \n.
### Additional Information --------
In order to "advance to the next line", within the code, you'll see that I added in 2 \n. This is because for some reason, <br>
the terminal needed some sort of extra prompt to visually print a \n, so hence I needed 2 just so it would trigger the first \n properly.


