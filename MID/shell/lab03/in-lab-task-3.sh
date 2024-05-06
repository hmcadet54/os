
echo "Enter a text you want to enter in the files"
read to_written

func(){
local folderfile="/home/path..."
for file in "$folderfile"/*; do
	echo "$to_written" >> "$file"
done

}
func
