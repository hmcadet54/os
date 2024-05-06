

file=/home/path...
New_copied=/home/path...
if [ ! -d "$New_copied" ]
then
	mkdir "$New_copied"
fi
for files in $file/*
do
	cp "$files" "$New_copied"
done