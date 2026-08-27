# Write a shell script that accepts a file name, starting and ending line numbers 
# as arguments and displays all lines between the given line numbers.

echo "Enter the file name:"
read fileName

echo -e "\nEnter the start line number:"
read startLineNumber

echo -e "\nEnter the end line number:"
read endLineNumber

i=1

echo ""
while read line
do
    if [ "$i" -gt "$startLineNumber" ] && [ "$i" -lt "$endLineNumber" ]
    then
        echo "Line $i: $line"
    fi
    i=$((i+1))
done < "$fileName"
