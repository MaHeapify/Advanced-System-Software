# Write a shell script to display the current date and time and 
# also the number of users logged into the system.

echo "Current date: $(date +%d:%m:%Y)"
echo -e "\nCurrent time: $(date +%H:%M:%S)"
echo -e "\nNumber of users logged into the system currently: $(who | wc -l)"
