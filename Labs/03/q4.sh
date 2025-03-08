if [ -e "$1" ]; then
	echo "File found -> $1"
	echo "Status:"
	stat "$1"
else 
	echo "File not found"
	exit 1
fi
