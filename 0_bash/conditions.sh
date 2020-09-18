check_path="$1"

if [ -f "$check_path" ]; then
  echo "File exists. $check_path"
else
  echo "File doesn't exists. $check_path"
fi
