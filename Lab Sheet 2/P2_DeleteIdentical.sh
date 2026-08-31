# Device a script that accepts two directory names d1 and d2, and deletes those file in d2 which are identical 
# to their names in d1.

echo "Enter the first directory name:"
read d1

echo -e "\nEnter the second directory name:"
read d2

if [ ! -d "$d1" ] || [ ! -d "$d2" ]
then
	echo -e "\nOne or both directories do not exist."
	exit 1
fi

for file in "$d1"/*
do
	fileName=$(basename "$file")
	
	if [ -f "$file" ] && [ -f "$d2/$filename" ]
	then
		if cmp -s "$file" "$d2/$filename"
		then
			rm "$d2/$filename"
			echo -e "\nDeleted: $d2/$filename"
		fi
	fi
done
