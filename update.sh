#!/bin/bash

set -e
set -u
set -o pipefail

echo ">>> git add ."
git add .
echo "<<< git add ."

read -p "commit message: " msg
echo ">>> git commit"
git commit -m "$msg"
echo "<<< git commit"

echo ">>> git push"
git push -u origin main
echo "<<< git push"

echo "$(date +'%Y-%m-%d %H:%M:%S') $msg" >> ./commit.log
