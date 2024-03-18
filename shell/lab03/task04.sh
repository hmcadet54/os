logfile="$1"
req=$(wc -l < "$logfile")
#content=$(sed -n '1p' "$logfile")
echo $req

u_ip=$(awk '{print $1}' "$logfile" | sort | uniq | wc -l)
echo $u_ip

t_ip=$(awk '{print $1}' "$logfile" | sort | uniq -c | sort -nr)
echo $t_ip

size=$(awk '{sum+=$10} END {print sum}' "$logfile")
echo $size

summary="<=summary=>

No of req's=$req
No of uniques IP's=$u_ip
No of freq IP's=$t_ip
size of mb=$size
"

echo "$summary" > "summary.txt"
