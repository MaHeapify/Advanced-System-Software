# Write a shell script that displays the factorial of a given number.

echo "Enter a number to compute the factorial:"
read number

fact=1

if [ "$number" -eq 0 ]
then
	echo -e "\nFactorial of $number is $fact."
	exit 0
fi

for (( i=number; i>0; i-- ))
do
	fact=$(expr "$fact" \* "$i")
done

echo -e "\nFactorial of $number is $fact."
