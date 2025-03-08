echo "$1" | grep -o "[aeiouAEIOU]" | wc -l 
#grep -o ["pattern"] prints every letter in the pattern on a new line
# | (pipe) used to send the output of one command to another
# wc -l counts lines

