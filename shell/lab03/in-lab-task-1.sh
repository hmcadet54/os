


ls /home/abdullah4489/Downloads> file_names.txt

# sorting using built in command
sort file_names.txt -o sorted_file_names.txt


echo "The number of files start with d's are:"
grep -c '^d' sorted_file_names.txt

echo "The file_names.txt contents are:"
cat /home/abdullah4489/Desktop/lab03/file_names.txt

echo "The sorted Items in sorted_file_names.txt are"
#local foilename=/home/abdullah4489/Desktop/lab03/file_names.txt
#we cn also make fucntion hre miss cuz the local keyword is only restricted to use in fuction
cat /home/abdullah4489/Desktop/lab03/sorted_file_names.txt


