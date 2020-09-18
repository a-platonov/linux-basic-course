for i in {1..5}
do
  mkdir "$i"
  for j in {1..5}
  do
    echo "$j" > "$i/$j"
  done
done
echo "Done!"