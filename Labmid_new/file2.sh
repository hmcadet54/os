gcc -c sort_array.c 
gcc sort.o -o output

wait(1)
./file3.sh

if [ $1 -eq '1' ]
then
	ls -a sort_array.c