# Linux Command Cheat Sheet

## System Information Commands

- **Show architecture of the machine:**
  ```sh
  uname -m
  ```
- **Show CPU info:**
  ```sh
  lscpu
  ```
- **Show version of the kernel:**
  ```sh
  uname -r
  ```
- **Show system date:**
  ```sh
  date
  ```
- **Display information about active processes:**
  ```sh
  ps aux
  ```

## Date & Time Commands

- **Set date and time:**
  ```sh
  sudo date MMDDhhmmYYYY
  ```
  Example: Set date to **March 11, 2025, 14:30 (2:30 PM)**
  ```sh
  sudo date 031114302025
  ```
  Or using `timedatectl`:
  ```sh
  sudo timedatectl set-time "2025-03-11 14:30:00"
  ```

## File and Directory Commands

- **Show details of files and directories:**
  ```sh
  ls -l
  ```
- **Show hidden files:**
  ```sh
  ls -a
  ```
- **Show files and directories containing numbers:**
  ```sh
  ls -l | grep '[0-9]'
  ```
- **Create a directory called 'dir1':**
  ```sh
  mkdir dir1
  ```
- **Create two directories simultaneously:**
  ```sh
  mkdir dir2 dir3
  ```
- **Show the path of the working directory:**
  ```sh
  pwd
  ```

## File and Directory Deletion Commands

- **Delete a file called 'file1':**
  ```sh
  rm file1
  ```
- **Remove a directory called 'dir1' and its contents recursively:**
  ```sh
  rm -rf dir1
  ```
- **Delete an empty directory called 'dir1':**
  ```sh
  rmdir dir1
  ```

## Modify Timestamps

- **Modify timestamp of a file or directory:**
  ```sh
  touch -t YYYYMMDDhhmm filename
  ```
  Example: Change timestamp to **March 11, 2025, at 14:30**
  ```sh
  touch -t 202503111430 filename
  ```

## File Permissions

- **Change file permissions (e.g., make a file executable):**
  ```sh
  chmod +x filename
  ```
- **Change file ownership:**
  ```sh
  sudo chown user:group filename
  ```

## Disk Space Usage

- **Show disk space usage:**
  ```sh
  df -h
  ```
- **Show disk usage for a specific directory:**
  ```sh
  du -sh directory_name
  ```

## Copying Files

- **Copy a file:**
  ```sh
  cp source_file destination_file
  ```
- **Copy a directory recursively:**
  ```sh
  cp -r source_directory destination_directory
  ```

## Searching for Patterns in a Text File

- **Search for a pattern in a file:**
  ```sh
  grep 'pattern' filename
  ```
- **Search recursively in multiple files:**
  ```sh
  grep -r 'pattern' directory_name
  ```
  
---

#!/bin/bash

# Check if the user provided a directory to back up
if [[ -z "$1" || -z "$2" ]]; then
    echo "Usage: $0 <source_directory> <backup_directory>"
    exit 1
fi

SOURCE_DIR=$(realpath "$1")  # Convert to absolute path
BACKUP_DIR=$(realpath "$2")  # Convert to absolute path

# Check if source directory exists
if [[ ! -d "$SOURCE_DIR" ]]; then
    echo "Error: Source directory '$SOURCE_DIR' does not exist!"
    exit 1
fi

# Ensure backup directory exists
mkdir -p "$BACKUP_DIR"

# Create a timestamped backup folder
TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
BACKUP_PATH="$BACKUP_DIR/backup_$(basename "$SOURCE_DIR")_$TIMESTAMP"

# Copy the source directory into the backup directory
cp -r "$SOURCE_DIR" "$BACKUP_PATH"

# Count directories and files
NUM_DIRS=$(find "$BACKUP_PATH" -type d | wc -l)
NUM_FILES=$(find "$BACKUP_PATH" -type f | wc -l)

# Display backup details
echo "✅ Backup Completed!"
echo "📁 Source: $SOURCE_DIR"
echo "📂 Backup Location: $BACKUP_PATH"
echo "📦 Total Directories Backed Up: $NUM_DIRS"
echo "📜 Total Files Backed Up: $NUM_FILES"



