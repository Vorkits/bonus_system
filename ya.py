import yadisk

y = yadisk.YaDisk(token="AgAAAAAbq87zAAY94cZG_utJbUw4qDHJf3NT1WY")
# или
# y = yadisk.YaDisk("<id-приложения>", "<secret-приложения>", "<токен>")

# Проверяет, валиден ли токен
print(y.check_token())

# Получает общую информацию о диске

# Выводит содержимое "/some/path"
print(list(y.listdir("/снаряга")))

# Загружает "file_to_upload.txt" в "/destination.txt"

# То же самое
with open("bonus.db", "rb") as f:
    y.upload(f, "/снаряга/bonus.db")
#y.remove("/file-to-remove", permanently=True)

# Скачивает "/some-file-to-download.txt" в "downloaded.txt"
#y.download("/some-file-to-download.txt", "downloaded.txt")
