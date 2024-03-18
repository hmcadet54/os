# Q1: Extracting and Sorting Linux Installation Files
#  Write a shell script to list all files in your Linux installation.
#  Save the file names in a text file.
#  Utilize shell built-in commands to sort the files.
#  Count the files that start with the letter &#39;d&#39;.
# Hint: Approach this task as a shell programmer, focusing on shell programming concepts
# rather than traditional sorting of integer arrays.


path=/home/abdullah4489/Desktop/LabMid/shell/demo/demo1
touch fileSave.txt

filePath=/home/abdullah4489/Desktop/LabMid/shell/fileSave.txt
for files in "$path"/*
do
	if [ -f "$files" ]
	then 
		echo "$(basename "$file")" >> "$filePath"
	fi
done

grep 
