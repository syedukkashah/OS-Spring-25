if [[ -e "$1" ]]; then
	line_cnt=$(wc -l < "$1")
	echo $line_cnt
else
	echo "File not found"
fi
