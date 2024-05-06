
echo "before exe:"
ls -lrt /home/path...
#fucntion
exepermission(){
local folderfile="/home/path..."
if [[ -d "$folderfile" ]];then
	for file in "$folderfile"/*; do
		if [[ -f "$file" ]]; then
			chmod +x "$file"
		fi
	done
else
	echo "not found"
fi
}

exepermission
echo "after exe:"
ls -lrt /home/path...



