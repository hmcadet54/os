

file=/home/abdullah4489/Desktop/LabMid/shell/demo/demo1
New_copied=/home/abdullah4489/Desktop/LabMid/shell/New_spied
if [ ! -d "$New_copied" ]
then
	mkdir "$New_copied"
fi
for files in $file/*
do
	cp "$files" "$New_copied"
done