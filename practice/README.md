# Linux Command Cheat Sheet

## File permissions
4 -> read


2 -> write


1 -> execute 

user - group - others

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



