
echo "before exe:"
ls -lrt /home/abdullah4489/Desktop/lab03
#fucntion
exepermission(){
local folderfile="/home/abdullah4489/Desktop/lab03"
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
ls -lrt /home/abdullah4489/Desktop/lab03



