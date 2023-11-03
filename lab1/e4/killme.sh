#!/bin/sh

user="$1"

#store the output in processid
processids=$(ps aux --sort=user | grep "$user" | awk '{print $2}') 

# awk command like in exercise 3
# Kill each process by its PID

for pid in $processids; do
  kill -9 "$pid"
done
# -9 command to end them by force. 


