
echo "Enter a text you want to enter in the files"
read to_written

func(){
local folderfile="/home/abdullah4489/Desktop/lab03/in_lab_task-3/"
for file in "$folderfile"/*; do
	echo "$to_written" >> "$file"
done

}
func
