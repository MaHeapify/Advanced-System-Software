# Write a shell code to accept a string from the terminal, and echo a suitable message if it doesn't have at 
# least 10 characters using case and expr command.

echo "Enter a string:"
read data

stringLength=$(expr length "$data")

case "$stringLength" in [0-9])
	echo -e "\nThe string does not have at least 10 characters."
	;;

*)
	echo -e "\nThe string has at least 10 characters."
	;;
esac

echo "The string length is $stringLength characters."
