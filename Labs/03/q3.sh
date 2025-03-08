 if [ -e "$1" ]; then
	 echo "$(date)" >> "$1"
 else
 	echo "file not found"
        exit 1
 fi 

