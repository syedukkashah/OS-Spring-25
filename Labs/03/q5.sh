
# Check if the directory exists
if [[ -e "$1" ]]; then
    script_dir="$(dirname "$(realpath "$0")")" # Directory of the script
    backup_dir="$script_dir/backup_$(date +'%Y-%m-%d')" # Backup directory with date appended
    mkdir -p "$backup_dir"  # Create the backup directory if it doesn't exist
    
    # Copy all files and subdirectories from the source directory to the backup
    cp -r "$1"/* "$backup_dir" # $1 refers to the directory passed as the argument to the script

    # Count files and directories in the source directory
    file_count=$(find "$1" -type f | wc -l) # Count files in the source directory
    dir_count=$(find "$1" -type d | wc -l) # Count directories in the source directory

    # Output success message
    echo "Backup successful"
    echo "Backed up files: $file_count"
    echo "Backed up dirs: $dir_count"
    echo "Backup location: $backup_dir"
else
    echo "Directory doesn't exist"
    exit 1
fi


