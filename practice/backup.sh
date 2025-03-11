#!/bin/bash

# Check if the user provided a directory to back up
if [[ -z "$1" ]]; then
    echo "Usage: $0 <source_directory>"
    exit 1
fi

SOURCE_DIR=$(realpath "$1")  # Convert to absolute path
BACKUP_DIR="$HOME/backup"     # Set backup directory to ~/backup

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
