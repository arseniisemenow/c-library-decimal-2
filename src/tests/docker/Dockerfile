# Используем базовый образ с установленным gcc и другими необходимыми инструментами
FROM ubuntu:latest

# Устанавливаем пакеты для компиляции и тестирования
RUN apt-get update && \
    apt-get install -y gcc make check subunit lcov vim lcov lynx clang-format valgrind && \
    apt-get clean

# Копируем файлы проекта в контейнер
WORKDIR /app
COPY . /app

CMD ["bash"]