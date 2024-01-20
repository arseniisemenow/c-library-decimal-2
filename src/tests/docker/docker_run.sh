#!/bin/bash

rm -rf ~/Library/Containers/com.docker.docker
mkdir -p ~/goinfre/Docker/Data
ln -s ~/goinfre/Docker ~/Library/Containers/com.docker.docker


if !(docker ps) &>/dev/null; then
  open -a Docker
else
  echo "Docker запущен"
fi

while true; do
  if docker ps &>/dev/null; then
    echo "Docker запущен и готов к использованию."
    break
  else
    echo "Docker ещё не готов. Повторная проверка через 1 секунду..."
    sleep 1
  fi
done

docker build -t ubuntu_for_tests .
# SHOULD BE DIFFERENT ON ANOTHER MACHINE WITH ANOTHER USER
docker run -it -v /Users/evangelm/Documents/Projects/library-decimal/C5_s21_decimal-2/:/app ubuntu_for_tests

# valgrind --leak-check=full \
#          --show-leak-kinds=all \
#          --track-origins=yes \
#          --verbose \
#          --log-file=valgrind-out.txt \
#          ./executable exampleParam1

