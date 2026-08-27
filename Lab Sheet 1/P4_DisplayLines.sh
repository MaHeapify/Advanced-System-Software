# Write a shell script to display all the lines in a single file in the current 
# directory having manipal as a word.

echo -e "The lines in a single file in the current directory having manipal as a word are:\n"

grep -w "manipal" file1.txt
