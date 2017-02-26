#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[]) {
	 // argc -- will be the count of input arguments to program
	 // argv -- will be a pointer to all the input arguments
	 char *fileName = argv[1];
	 int bytes = 0;
	 int words = 0;
	 int newLine = 0;
	 char buffer[1];
	 
	 int file = open(fileName, O_RDONLY);
	 enum states { WHITESPACE, WORD }; // easier when use finite state
	 int state = WHITESPACE;
	 if (file == -1) {
		 printf("can not find: %s\n", fileName);
	 } else {
		char last = ' ';
		while (read(file, buffer, 1) == 1)  {
			bytes++;
			if (buffer[0] == ' ' || buffer[0] == '\t') {
				state = WHITESPACE;
			} else if (buffer[0] == '\n') {
				newLine++;
				state = WHITESPACE;
			} else {
				if (state == WHITESPACE) {
					words++;
				}
				state = WORD;
			}
			last = buffer[0];
		}
		printf("%d %d %d %s\n", newLine, words, bytes, fileName);
	 }
}
