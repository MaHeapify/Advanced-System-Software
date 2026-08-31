# Write a script that displays a special formatted listing showing the permissions, size, filename, last 
# modification time, last access time of filenames supplied as arguments.

printf "%-12s %-10s %-20s %-20s %-20s\n" \

"PERMISSIONS" "SIZE" "FILENAME" "MODIFIED" "ACCESSED"

for filename in "$@"
do
    if [ -e "$filename" ]
    then
        stat -c "%-12A %-10s %-20n %-20y %-20x" "$filename"
    else
        echo "$filename does not exist."
    fi
done
