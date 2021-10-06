import os, inspect


def main():
    with open("codeup_git_commit.cmd", "w") as file:
        file.write("@echo off\n")

        file_list = os.listdir("./")
        file_list_py = [file for file in file_list if file.endswith(".py")]

        my_name = os.path.basename(inspect.getfile(inspect.currentframe()))
        for py in file_list_py:
            if py == my_name:
                continue
            file.write("git add %s && git commit -m \"Code Up %s by Python\"\n" % (py, py))

        file.write("git push origin master\n")
        file.write("pause\n")

    print("완료")


main()
