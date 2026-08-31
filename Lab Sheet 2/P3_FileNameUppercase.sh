# Write a script that accepts filenames as arguments. For every filename, it should first check whether it 
# exists in the current directory and then converts its name to uppercase, but only if a file with the new name 
# doesn't exist.

for filename in "$@"
do
    if [ -f "$filename" ]
    then
        uppercase=$(echo "$filename" | tr 'a-z' 'A-Z')
        
        if [ -e "$uppercase" ]
        then
            echo -e "\nCannot rename $filename: $uppercase already exists."
        else
            mv "$filename" "$uppercase"
            echo -e "\n$filename renamed to $uppercase"
        fi
    else
        echo -e "\n$filename does not exist in the current directory."
    fi
done
