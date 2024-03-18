

# for i in {1..10}
# do
# 	echo "hllo"
# done


# items="home/abdullah4489/Desktop/LabMid/shell/items.txt"
# for i in $(cat $items)
# do
# 	echo $i
# done

num=10
count=0

while [ $count -le $num ]
do
	echo "i am in $count iterate with number $num\n"
	let count++
	let num--
done